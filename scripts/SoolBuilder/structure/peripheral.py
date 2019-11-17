import typing as T
import xml.etree.ElementTree as ET
import logging
#from structure import Group

from structure import Register, RegisterPlacement, PeripheralInstance, PeripheralMapping
from structure import get_node_text, TabManager
from structure import ChipSet
from structure import Component

from structure.utils import DefinesHandler, fill_periph_hole

logger = logging.getLogger()

class Peripheral(Component) :

	@staticmethod
	def create_from_xml(chips: ChipSet, xml_data: ET.Element) -> "Peripheral" :

		brief: str = get_node_text(xml_data, "description")\
			.lower()\
			.replace("-", " ")\
			.replace("\n", " ")
		brief = " ".join(brief.split())

		periph =  Peripheral(chips=chips, name=None, brief=brief)

		for xml_reg in xml_data.findall("registers/register") :
			new_register = Register.create_from_xml(chips, xml_reg)
			periph.add_register(new_register)

			pos = int(get_node_text(xml_reg, "addressOffset"), 0)
			reg_placement = RegisterPlacement(chips=chips, name=new_register.name, register=new_register, address=pos)
			periph.place_register(reg_placement)

		return periph

	def __init__(self, chips: T.Union[ChipSet, None] = None,
	             name: T.Union[str, None] = None,
	             brief: T.Union[str, None] = None) :
		super().__init__(chips=chips, name=name, brief=brief)

		self.registers: T.List[Register] = list()
		self.mappings: T.List[PeripheralMapping] = list()
		self.instances: T.List[PeripheralInstance] = list()
		self.max_size = 0

################################################################################
#                                  OPERATORS                                   #
################################################################################

	def __iter__(self):
		return iter(self.registers)

	def __eq__(self, other):
		if isinstance(other, Peripheral) :
			return (self.name == other.name and
					self.brief == other.brief and
					self.mapping_equivalent_to(other))

		elif isinstance(other, str) :
			return other == self.name
		else :
			raise TypeError()

	def __contains__(self, item) -> bool:
		if isinstance(item,PeripheralMapping) :
			return item in self.mappings
		elif isinstance(item, Register) :
			return item in self.registers
		elif isinstance(item, str) :
			for r in self.registers :
				if r.name == item :
					return True
			return False
		raise ValueError()

	def __getitem__(self, item) -> Register:
		if isinstance(item,Register) :
			for reg in self :
				if reg == item :
					return reg
			raise KeyError()
		if isinstance(item,str):
			for reg in self :
				if reg.name == item:
					return reg
			raise KeyError()
		raise TypeError()

	@property
	def alias(self) -> T.Union[None, str]:
		return self.name
	
	@property
	def computed_size(self):
		max_size: int = 0
		for m in self.mappings :
			size = m.computed_size
			if size > max_size :
				max_size = size
		return max_size

	@property
	def has_template(self):
		for reg in self :
			if reg.has_template :
				return True
		return False

################################################################################
#                             REGISTERS MANAGEMENT                             #
################################################################################

	def add_register(self, reg: Register):
		if reg.name is not None and reg.name in self :
			self[reg.name].inter_svd_merge(reg)
		else :
			self.registers.append(reg)
			reg.set_parent(self)
			self.edited = True

################################################################################
#                             INSTANCES MANAGEMENT                             #
################################################################################

	def add_instance(self, other: "PeripheralInstance") :
		if isinstance(other, PeripheralInstance) :
			self.chips.add(other.chips)

			for i in self.instances :
				if i == other :
					i.inter_svd_merge(other)
					return
			other.set_parent(self)
			self.instances.append(other)
			self.edited = True
		else:
			raise TypeError(f"Expected a peripheral instance. Got {type(other)}.")

	def add_instances(self, other :  T.Union[T.List["PeripheralInstance"], "Peripheral"]):
		if isinstance(other, Peripheral) :
			for inst in other.instances :
				self.add_instance(inst)
		elif isinstance(other,list) :
			for inst in other :
				self.add_instance(inst)
		else :
			raise TypeError(f"Expected a peripheral instances list or peripheral. Got {type(other)}.")

################################################################################
#                              MAPPING MANAGEMENT                              #
################################################################################

	def mapping_equivalent_to(self,other : "Peripheral", ignore_templates: bool=True) -> bool :
		"""
		This function will check if the current peripheral has a mapping equivalent to the other one.
		:param ignore_templates: True if template registers should be ignored
		 (two peripherals can be identical, even if they have different template registers)
		:param other: The other peripheral
		:return:
		"""
		self_placements = list()
		other_placements = list()
		diff = list()
		for m in self.mappings :
			self_placements.extend(m.register_placements)
		for m in other.mappings :
			other_placements.extend(m.register_placements)

		for reg_p in self_placements :
			if reg_p not in other_placements :
				diff.append(reg_p)
		for reg_p  in other_placements :
			if reg_p not in self_placements :
				diff.append(reg_p)

		if ignore_templates :
			for reg_p in diff :
				# if the register is only present in one of the two peripherals, merging is allowed only if the register in templated
				if not reg_p.register.has_template :
					return False

			for i in range(0, len(diff)-1) :
				for j in range(i+1, len(diff)) :
					# if the templated register's address is used by another templated register with the same name,
					# the two peripherals can be merged together. Otherwise, merging is possible only if the address is not used
					if diff[i].overlap(diff[j]) and diff[i].name != diff[j].name :
						return False
			return True
		else :
			return len(diff) == 0

	def add_mapping(self, mapping: PeripheralMapping) :
		for reg_p in mapping :
			self.place_register(reg_p)

	def place_register(self, reg_placement: RegisterPlacement) :
		mapping: T.Union[PeripheralMapping, None] = None

		reg_placement.register = self[reg_placement.register.name]
		for m in self.mappings :
			if reg_placement in m :
				m[reg_placement].inter_svd_merge(reg_placement)
				return
			elif m.has_room_for(reg_placement) :
				mapping = m
		if mapping is None :
			mapping = PeripheralMapping()
			mapping.parent = self
			self.mappings.append(mapping)
			self.edited = True
		mapping.add_register_placement(reg_placement)

################################################################################
#                             COMPILATION, MERGING                             #
################################################################################

	def svd_compile(self):
		super().svd_compile()

		m_idx = 0

		while m_idx < len(self.mappings) :
			m_offset = 1

			while m_idx + m_offset < len(self.mappings) :
				if self.mappings[m_idx].compatible(self.mappings[m_idx + m_offset]) :
					self.mappings[m_idx].merge(self.mappings[m_idx + m_offset])
					self.mappings.pop(m_idx + m_offset)
					self.edited = True
					continue
				else :
					m_offset += 1
			m_idx += 1

		r_idx = 0
		r_offset = 0

		while r_idx < len(self.registers) :
			r_offset = 1
			while r_idx + r_offset < len(self.registers) :
				if self.registers[r_idx].name == self.registers[r_idx + r_offset].name :
					self.registers[r_idx].inter_svd_merge(self.registers[r_idx + r_offset])
					for mapping in self.mappings :
						for placement in mapping :
							if placement.register is self.registers[r_idx + r_offset] :
								placement.register = self.registers[r_idx]
					self.registers.pop(r_idx + r_offset)
					self.edited = True
					continue
				else :
					r_offset += 1
			r_idx += 1

	def intra_svd_merge(self, other: "Peripheral") :
		super().intra_svd_merge(other)
		for r in other.registers : self.add_register(r)
		for i in other.instances : self.add_instance(i)
		for m in other.mappings  : self.add_mapping(m)

	def inter_svd_merge(self, other: "Peripheral") :
		super().intra_svd_merge(other)
		for r in other.registers : self.add_register(r)
		for i in other.instances : self.add_instance(i)
		for m in other.mappings  : self.add_mapping(m)

	def finalize(self):
		super().finalize()
		for i in self.instances :
			i.set_parent(self)
			i.finalize()

		map_idx: int = 0
		for m in self.mappings :
			m.set_parent(self)
			m.name = f"MAP{map_idx}"
			map_idx += 1
			m.finalize()

################################################################################
#                          DEFINE, UNDEFINE, DECLARE                           #
################################################################################

	def declare(self, indent: TabManager = TabManager()) -> str:
		# TODO consider templates
		out =""
		if self.needs_define :
			out += f"{indent}#if {self.defined_name}\n"
		out += f"{indent}class {self.name}\n" \
		       f"{indent}{{\n"
		indent.increment()
		out += f"{indent}//SOOL-{self.alias}-SUB-TYPES\n"
		for reg in self.registers :
			out += reg.declare(indent)

		if len(self.mappings) > 1 :
			out += f"{indent}union\n" \
			       f"{indent}{{\n"
			indent.increment()
		for m in self.mappings :
			out += m.declare(indent)
		if len(self.mappings) > 1 :
			indent.decrement()
			out += f"{indent}}};\n"

		out += f"{indent}private:\n" \
			   f"{indent}#ifndef __SOOL_DEBUG_NOPHY\n"\
		       f"{indent}{self.name}() = delete;\n" \
			   f"{indent}#endif\n" \
		       f"{indent}//SOOL-{self.alias}-DECLARATIONS\n"

		indent.decrement()
		out += f"{indent}}};\n"

		# Instances are declared after all classes of the group.
		# Instances declaration is handled in the 'cpp_output' method fo the class Group
		return out

	@property
	def defined_name(self) -> str :
		return f"PERIPH_{self.alias}"

	def define(self, defines: T.Dict[ChipSet, DefinesHandler]):
		super().define(defines)
		for mapping in self.mappings :
			mapping.define(defines)

	def define_instances(self,defines: T.Dict[ChipSet, DefinesHandler]):
		for instance in self.instances :
			instance.define(defines)

	def declare_instances(self, tab_manager : TabManager) -> str:
		out = f"\n//Instances for peripheral {self.name}\n"
		virtual_instances: T.Dict[str, PeripheralInstance] = dict()
		for instance in self.instances:
			if instance.name in virtual_instances:
				virtual_instances[instance.name].chips.add(instance.chips)
			else:
				# The actual address is not relevant
				virtual_instances[instance.name] = PeripheralInstance(instance.chips, instance.name, instance.brief, 0)
				virtual_instances[instance.name].parent = self

		for i in sorted(virtual_instances.keys(), key= lambda x : ("1_" if not virtual_instances[x].needs_define else "2_") + virtual_instances[x].name):
			out += virtual_instances[i].declare(tab_manager)

		return out
