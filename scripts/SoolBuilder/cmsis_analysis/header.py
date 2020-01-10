import typing as T
import re
from copy import copy


class CMSISRegister:
	def __init__(self):
		self.name : str 		= None
		self.array_size : int 	= 1
		self.element_size : int = 32
		self.comment : str = None
		self.type : str = None
		self.access_type= "IO"

class CMSISPeripheral:
	def __init__(self, name : str= None):
		self.registers : T.List[CMSISRegister] = list()
		self.name : str= name

class CMSISHeader:
	def __init__(self,path : str ):
		self.content_cmsis_data : bool = False
		self.path = path
		self.irq_table : T.Dict[str,int] = None
		self.periph_table: T.Dicr[str,CMSISPeripheral] = None
		self.raw_irq_table : str = None
		self.peripheral_definitions : T.List[str] = None

	def read(self):
		data = ""
		with open(self.path,"r",encoding="latin-1") as f :
			data = f.read()
		end = data.rfind("IRQn_Type;")
		start = data.rfind("enum",0,end)
		self.raw_irq_table = data[start:end]

		start = 0
		self.peripheral_definitions = list()
		while True :
			start = data.find("typedef struct",start+1)
			if start == -1 :
				break
			end = data.find("}", start)
			end = data.find("_TypeDef",end)
			self.peripheral_definitions.append(data[start:end])

	def read_irq_table(self):
		if self.raw_irq_table is None:
			return
		self.irq_table = dict()
		irq_rexp = re.compile(r"(?P<id>\S+)\s+=\s+(?P<val>-?\d+)\s*,?\s*(?P<comment>.+)?")


		for line in [x.strip() for x in self.raw_irq_table.split("\n")] :
			if line == str() :
				continue

			result = irq_rexp.search(line)
			if result :
				data = result.groupdict()
				self.irq_table[data["id"]] = int(data["val"])

	def read_peripheral_definition(self):
		if len(self.peripheral_definitions) == 0:
			return
		if self.periph_table is None :
			self.periph_table = dict()
		periph_rexp = re.compile(r"(?:__(?P<io>[IO]{1,2}))?\s+(?P<type>uint(?P<int_size>\d+)_t|\S+)\s+(?P<name>\w*)(?:\[(?P<arr_size>\d+)\])?\s*;\s*(?:/\*(?:!<)?(?P<com>.+)\*/)?")
		periph_name_rexp = re.compile(r"\\}\s*(?P<name>\w+)_TypeDef")
		
		for raw in self.peripheral_definitions :
			new_peripheral = CMSISPeripheral()
			for line in [x.strip() for x in raw.split("\n")]:
				if line == str():
					continue

				result = periph_rexp.search(line)
				if result :
					new_register = CMSISRegister()
					data = result.groupdict()
					new_register.access_type = data["io"]
					new_register.name		 = data["name"]
					new_register.array_size	 = data["arr_size"] if data["arr_size"] is not None else 1
					new_register.type		 = data["type"]
					new_register.element_size= data["int_size"]
					new_register.comment	 = data["com"]

					new_peripheral.registers.append(new_register)
				elif line[0] == "}":
					new_peripheral.name = line[1:].strip(None)

			self.periph_table[new_peripheral.name] = new_peripheral