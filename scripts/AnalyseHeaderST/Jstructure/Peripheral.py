import xml.etree.ElementTree as ET
import typing as T
from .Register import Register
from tools.utils import ChipSeriesManager
import logging

logger = logging.getLogger()


def get_node_text(root : ET.Element, node : str) -> str :
	return str() if root.find(node) is None else root.find(node).text

class Peripheral:
	def __init__(self, xml_base : ET.Element, chip : ChipSeriesManager = ChipSeriesManager()):
		"""
		Build a Peripheral representation based upon XML node.
		If relevant, build all registers.
		:param xml_base: xml <peripheral> node, extracted from SVD file
		"""
		self.name : str 		= None
		self.address : int 		= None
		self.brief : str 		= None
		self.derivation : str 	= None
		self.group : str 		= None
		self.registers : T.List = list()
		
		self.complete : bool = False
		self.xml_data : ET.Element = xml_base
		self.chips = chip
	
		if "derivedFrom" in self.xml_data.attrib:
			self.derivation = self.xml_data.attrib["derivedFrom"]
			self.complete = False
		else :
			self.complete = True
			self.brief = get_node_text(self.xml_data,"description")
			self.group = get_node_text(self.xml_data,"groupName")
			self.fill_from_xml()
		
		self.name = self.xml_data.find("name").text
		self.address = int(self.xml_data.find("baseAddress").text,0)
		
		self.variance_id : str = None
		self.instances : T.List[PeripheralInstance] = list()
		
	def __repr__(self):
		return f"{self.name:20s} var {self.variance_id}"
		
	def __eq__(self, other):
		if isinstance(other,Peripheral) :
			return (self.name == other.name and
					self.address == other.address)
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
		if (isinstance(item,Register) or isinstance(item,str)) :
			for register in self.registers :
				if item == register :
					return register
			return KeyError()
		elif isinstance(item,int) :
			return self.registers[item]
		else :
			raise TypeError()
		
	def fill_from_xml(self):
		for xml_reg in self.xml_data.findall("registers/register"):
			self.registers.append(Register(xml_reg,self.chips))
	
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
	def __init__(self,reference : Peripheral, name : str, address : int, chips):
		self.reference = reference
		self.name = name
		self.address = address
		self.chips = chips
		
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