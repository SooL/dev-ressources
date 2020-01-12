import typing as T
import re
import os
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
		
		self.irq_table 		: T.Dict[str,int] 			  = None
		self.periph_table	: T.Dicr[str,CMSISPeripheral] = None
		self.include_table	: T.Dict[str, str] 			  = None
		self.memory_table	: T.Dict[str,int] 			  = None
		
		self.raw_irq_table 	: str 			= None
		self.raw_includes	: str 			= None
		self.raw_peripheral : T.List[str] 	= None
		self.raw_memory 	: str 			= None
		
	@property
	def is_structural(self):
		return self.raw_peripheral is not None
	
	@property
	def is_irq(self):
		return self.irq_table is not None
	
	@property
	def is_include_map(self):
		return self.include_table is not None

	def read(self):
		data = ""
		with open(self.path,"r",encoding="latin-1") as f :
			data = f.read()
		end = data.rfind("IRQn_Type;")
		if end != -1 :
			start = data.rfind("enum",0,end)
			self.raw_irq_table = data[start:end]

		start = 0
		while True :
			start = data.find("typedef struct",start+1)
			if start == -1 :
				break
			if self.raw_peripheral is None :
				self.raw_peripheral = list()
			end = data.find("}", start)
			end = data.find("_TypeDef",end)
			self.raw_peripheral.append(data[start:end])
			
		start = data.find("@addtogroup Device_Included")
		if start != -1 :
			end = data.find("@}",start)
			self.raw_includes = data[start:end]
		
		start = data.find("@addtogroup Peripheral_memory_map")
		if start != -1 :
			end = data.find("@}", start)
			self.raw_memory = data[start:end]

	def clean(self):
		self.raw_irq_table 	= None
		self.raw_peripheral = None
		self.raw_includes 	= None
		self.raw_memory 	= None

	def read_include_table(self):
		if self.raw_includes is None :
			return
		
		self.include_table = dict()
		ifdef_rexp = re.compile(r"\#(?:el)?if\s+defined\s*\(\s*(?P<define>\w+)\)")
		include_rexp = re.compile(r"\#include\s+\"(?P<file>\w+\.h)\"")
		
		define = None
		filename= None
		for line in [x.strip(None) for x in self.raw_includes.split("\n")] :
			if define is None :
				result = ifdef_rexp.search(line)
				if result :
					define = result.groupdict()["define"]
					filename = None
				else:
					continue
			elif filename is None :
				result = include_rexp.search(line)
				if result :
					filename = result["file"]
					self.include_table[define] = f"{os.path.dirname(self.path)}/{filename}"
					define = None
	
	def read_memory_table(self):
		if self.raw_memory is None :
			return
		self.memory_table = dict()
		irq_mem = re.compile(r"\#define\s+(?P<name>\w+)\s+\(?(?P<uint>\(uint32_t\))?(?P<val>[^)\n]+)\)?")
		
		for line in [x.strip() for x in self.raw_memory.split("\n")]:
			if line == str():
				continue
			
			result = irq_mem.search(line)
			if result :
				data = result.groupdict()
				name = data["name"]
				value= data["val"]
				interpreted_values = list()
				val_fields = [x for x in value.split(None) if x != "+"]
				for f in val_fields :
					if f in self.memory_table :
						interpreted_values.append(self.memory_table[f])
					else :
						#Should be an integer
						interpreted_values.append(int(f.strip("L").strip("U"),0))
						
				self.memory_table[name] = sum(interpreted_values)
	
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
		if self.raw_peripheral is None or len(self.raw_peripheral) == 0:
			return
		if self.periph_table is None :
			self.periph_table = dict()
		periph_rexp = re.compile(r"(?:__(?P<io>[IO]{1,2}))?\s+(?P<type>uint(?P<int_size>\d+)_t|\S+)\s+(?P<name>\w*)(?:\[(?P<arr_size>\d+)\])?\s*;\s*(?:/\*(?:!<)?(?P<com>.+)\*/)?")
		periph_name_rexp = re.compile(r"\\}\s*(?P<name>\w+)_TypeDef")
		
		for raw in self.raw_peripheral :
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
