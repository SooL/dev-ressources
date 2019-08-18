import xml.etree.ElementTree as ET
import typing as T
import logging
from Jstructure.Register import Register
from Jstructure.ChipSet import ChipSet
from Jstructure.utils import get_node_text
from Jstructure.Group import Group
logger = logging.getLogger()


class Peripheral:
	def __init__(self, xml_base : ET.Element, chip : ChipSet = ChipSet()):
		"""
		Build a Peripheral representation based upon XML node.
		If relevant, build all registers.
		:param xml_base: xml <peripheral> node, extracted from SVD file
		"""
		self.xml_data : ET.Element = xml_base

		self.name : str = self.xml_data.find("name").text
		self.brief = get_node_text(self.xml_data, "description")

		self.group : Group 		= None
		self.registers : T.List = list()
		self.chips = chip
		
		self.variance_id: str = None
		self.instances: T.List[PeripheralInstance] = list()
		self.mappings: T.List[PeripheralMapping] = list()

		self.fill_from_xml()

		#self.address = int(self.xml_data.find("baseAddress").text,0)
		
		
		
	def __repr__(self):
		return f"{self.name:20s} : {' '.join(sorted(self.chips.chips))}"
		
	def __eq__(self, other):
		if isinstance(other,Peripheral) :
			return (self.name == other.name and
					self.mapping_equivalent_to(other))
			#return (self.name == other.name and
			#		self.address == other.address)
		elif isinstance(other,str):
			return other == self.name
		else:
			raise TypeError()
		
	def __le__(self, other):
		if isinstance(other,Peripheral):
			return self.address <= other.address
		else:
			raise TypeError()
		
	def __getitem__(self, item) -> Register:
		if isinstance(item, Register or isinstance(item,str)) :
			for register in self.registers :
				if item == register :
					return register
			raise KeyError()
		elif isinstance(item,int) :
			return self.registers[item]
		else :
			raise TypeError()
		
	def fill_from_xml(self):
		for xml_reg in self.xml_data.findall("registers/register"):
			self.registers.append(Register(xml_reg, self.chips))

	def add_instance(self, instance):
		self.instances.append(instance)
	
	def mapping_equivalent_to(self,other : "Peripheral") -> bool :
		"""
		Check if the mapping is equivalent between self and other.
		That is if both peripheral are equals and their contents recursively are too.
		:param other:
		"""
		
		for register in self :
			if register not in other or not other[register].mapping_equivalent_to(register) :
				return False
		return True
		
class PeripheralInstance :
	def __init__(self, reference : Peripheral, name : str, address : int, chips: ChipSet):
		self.reference = reference
		self.name = name
		self.address = address
		self.chips = chips
	
	def __repr__(self):
		return f"{self.name:20s} {self.chips}"
		
class PeripheralMapping:
	def __init__(self, reference : Peripheral, name : str, chips):
		self.reference = reference
		self.name = name
		self.chips = chips
		
		self.register_list = list()
	

def resolve_peripheral_derivation(periph_list : T.List[Peripheral]) :
	"""
	This function takes a finished list of peripherals and will resolve all derivation.
	Therefore, a periph with derivation will receive the same structure as the one it derives from
	and will be considered as complete.
	
	It will, however, not affect the memory base address and the name.
	:param periph_list: A list containing all peripheral to look at. Both references and derivates.
	"""
	logger.info("Starting peripheral derivation resolution")
	name_ref : T.Dict[str,Peripheral] = dict()
	
	logger.info("\tBuilding reference dictionary")
	for p in periph_list :
		name_ref[p.name] = p
	
	for p in periph_list :
		if not p.complete :
			
			ref = name_ref[p.derivation]
			logger.info(f"\tResolving {p.name} to {ref.name}")
			p.brief: str = ref.brief
			p.group: str = ref.group
			p.registers = ref.registers
			
			p.complete = True