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
		#TODO Name ?
		new_mapping = PeripheralMapping(self,self.name,self.chips)
		
		for xml_reg in self.xml_data.findall("registers/register"):
			new_mapping.register_list.append(Register(xml_reg, self.chips))
			#self.registers.append(Register(xml_reg, self.chips))
		self.mappings.append(new_mapping)

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

	def merge_peripheral(self,other : "Peripheral"):
		"""
		Will merge another peripheral to this one. Adding instances and mapping.
		
		**The other peripheral is supposed to have only one instance and one mapping.**
		
		
		:param other: The peripheral to merge into this one.
		:return:
		"""
		equivalent_mapping = None
		equivalent_instance = None
		
		# If a mapping, equivalent to the one of the other peripheral, is found, we will use it
		# In this case, we only have to append the chip(s) of the other peripheral.
		for mapping in self.mappings:
			if mapping == other:
				equivalent_mapping = mapping
				break
		
		# Same principle with instances
		for instance in self.instances:
			if instance == other:
				equivalent_instance = instance
				break
		
		# If no equivalent mapping is found, we create a new one based on the other one.
		if equivalent_mapping is None:
			equivalent_mapping = PeripheralMapping(self, other.name, other.chips)
			equivalent_mapping.register_list = other.mappings[0].register_list
			self.mappings.append(equivalent_mapping)
		else :
			equivalent_mapping.chips.add(other.chips)
		
		# Same for instances
		if equivalent_instance is None:
			equivalent_instance = PeripheralInstance(self,
													 other.instances[0].name,
													 other.instances[0].address,
													 other.chips)
			self.instances.append(equivalent_instance)
		else:
			equivalent_instance.chips.add(other.chips)
		
		
class PeripheralMapping:
	def __init__(self, reference: Peripheral, name: str, chips : ChipSet):
		self.reference = reference
		self.name = name
		self.chips = chips
		
		self.register_list = list()
	
	def __repr__(self):
		return " ".join([repr(x) for x in self.register_list]) + " : " + " ".join(sorted(list(self.chips.chips)))
		
	def __eq__(self, other):
		if isinstance(other,PeripheralMapping):
			return len(set(self.register_list).difference(other.register_list)) == 0
		elif isinstance(other,Peripheral) :
			for mapping in other.mappings :
				if mapping == self :
					return True
		else :
			raise TypeError()
		return False
		
		
class PeripheralInstance :
	def __init__(self, reference : Peripheral, name : str, address : int, chips: ChipSet):
		self.reference : Peripheral = reference
		self.name = name
		self.address = address
		self.chips = chips
	
	def __repr__(self):
		return f"{self.name:20s} {self.chips}"
	
	def __eq__(self, other):
		if isinstance(other,PeripheralInstance):
			return self.name == other.name and self.address == other.address
		elif isinstance(other,Peripheral) :
			for instance in other.instances :
				if instance == self :
					return True
		else :
			raise TypeError()
		return False


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