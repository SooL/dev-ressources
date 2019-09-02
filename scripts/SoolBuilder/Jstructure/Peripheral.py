import xml.etree.ElementTree as ET
import typing as T
import logging
from Jstructure.Register import Register
from Jstructure.ChipSet import ChipSet
from Jstructure.utils import get_node_text
from Jstructure.Group import Group
from copy import copy, deepcopy
# from deprecated import deprecated
logger = logging.getLogger()


class Peripheral:
	def __init__(self, xml_base : ET.Element, chip : ChipSet = ChipSet()):
		"""
		Build a Peripheral representation based upon XML node.
		If relevant, build all registers.
		:param xml_base: xml <peripheral> node, extracted from SVD file
		"""
		self.xml_data: ET.Element = xml_base

		self.name: str = None
		brief: str = get_node_text(self.xml_data, "description")\
			.lower()\
			.replace("-", " ")\
			.replace("\n", " ")
		self.brief = " ".join(brief.split())


		self.group: Group = None
		self.registers: T.List = list()
		self.chips = chip

		self.variance_id: str = None
		self.instances: T.List[PeripheralInstance] = list()
		self.mappings: T.List[PeripheralMapping] = list()

		self.fill_from_xml()

	# self.address = int(self.xml_data.find("baseAddress").text,0)

	def __repr__(self):
		return f"{self.name:20s} : {' '.join(sorted(self.chips.chips))}"

	def __eq__(self, other):
		if isinstance(other, Peripheral) :
			return (self.name == other.name and
					self.brief == other.brief and
					self.mapping_equivalent_to(other))

		elif isinstance(other, str) :
			return other == self.name
		else :
			raise TypeError()

	def __getitem__(self, item) -> Register:
		if isinstance(item, Register) or isinstance(item,str) :
			for register in self.registers :
				if item == register :
					return register
			raise KeyError()
		elif isinstance(item,int) :
			return self.registers[item]
		else :
			raise TypeError()
		
	def fill_from_xml(self):
		# TODO Name ?
		new_mapping = PeripheralMapping(self, self.chips)

		for xml_reg in self.xml_data.findall("registers/register"):
			new_register = Register(xml_reg, self.chips)
			self.registers.append(new_register)
			new_mapping.register_mapping[int(get_node_text(xml_reg, "addressOffset"), 0)] = new_register
		self.mappings.append(new_mapping)

	def add_instance(self, instance):
		self.instances.append(instance)

	def add_instances(self, instances):
		self.instances.extend(instances)
	
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

	def compatible(self, other: "Peripheral") -> bool :
		if self.mapping_equivalent_to(other) :
			return True

		for pos in other.mappings[0].register_mapping :
			if pos in self.mappings[0].register_mapping :
				if not other.mappings[0].register_mapping[pos]\
						.compatible(self.mappings[0].register_mapping[pos]):
					return False
		return True

	def merge_peripheral(self,other : "Peripheral"):
		"""
		Will merge another peripheral to this one. Adding instances and mapping.
		
		**The other peripheral is supposed to have one mapping and one or more instance.**
		
		:param other: The peripheral to merge into this one.
		:return:
		"""
		equivalent_mapping = None
		equivalent_instance = None

		# Merge chips
		self.chips.add(other.chips)

		# Merge registers
		for reg in other :
			if reg.name in self :
				""# TODO self[reg].merge_register(reg)
			else :
				self.registers.append(reg)

		# If a mapping, equivalent to the one of the other peripheral, is found, we will use it
		# In this case, we only have to append the chip(s) of the other peripheral.
		if len(other.mappings) != 1 :
			logger.error("multiple mappings on new peripheral")
		for mapping in self.mappings:
			if mapping == other:
				equivalent_mapping = mapping
				break

		# If no equivalent mapping is found, we create a new one based on the other one.
		if equivalent_mapping is None:
			# copy mapping
			equivalent_mapping = PeripheralMapping(self, other.chips)
			equivalent_mapping.register_mapping = other.mappings[0].register_mapping
			# change registers references
			for pos in equivalent_mapping.register_mapping :
				reg = equivalent_mapping.register_mapping[pos]
				equivalent_mapping.register_mapping[pos] = self[reg.name]

			self.mappings.append(equivalent_mapping)
			self.chips.add(other.chips)
		else:
			equivalent_mapping.chips.add(other.chips)
			self.chips.add(other.chips)

		# Same principle with instances
		for other_instance in other.instances :

			for instance in self.instances:
				if instance == other_instance:
					equivalent_instance = instance
					break

			# Same for instances
			if equivalent_instance is None:
				equivalent_instance = PeripheralInstance(self,
														 other_instance.name,
														 other_instance.address,
														 other.chips)
				self.instances.append(equivalent_instance)
				self.chips.add(other_instance.chips)
			else:
				equivalent_instance.chips.add(other.chips)
				self.chips.add(other_instance.chips)
		
		
class PeripheralMapping:
	def __init__(self, reference: Peripheral, chips: ChipSet):
		self.reference = reference
		self.name: str = None # the name will be determined when the whole structure is built
		self.chips: ChipSet = chips
		
		self.register_mapping: T.Dict[int, Register] = dict()
	
	def __repr__(self):
		return " ".join([f"{self.register_mapping[pos]}{pos}" for pos in self.register_mapping.keys()]) + " : " \
			   + str(self.chips)
		
	def __eq__(self, other):
		if isinstance(other, PeripheralMapping):
			positions = self.register_mapping.keys()
			if set(positions).symmetric_difference(set(other.register_mapping.keys())) != 0:
				return False
			for pos in positions :
				if self.register_mapping[pos] is not other.register_mapping[pos]:
					return False
			return True
		elif isinstance(other, Peripheral):
			for mapping in other.mappings:
				if mapping == self:
					return True
		else:
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
		if isinstance(other, PeripheralInstance) :
			return self.name == other.name and self.address == other.address
		elif isinstance(other, Peripheral) :
			for instance in other.instances :
				if instance == self :
					return True
		else :
			raise TypeError()
		return False

#@deprecated
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
