import typing as T
import xml.etree.ElementTree as ET
import logging
#from structure import Group

from structure import Register, MappingElement, PeripheralInstance, PeripheralMapping, PeripheralTemplate, \
	RegisterVariant
from structure import get_node_text, TabManager
from structure import ChipSet
from structure import Component

from structure.utils import DefinesHandler, fill_periph_hole

from tools import global_parameters

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

			reg_placement = MappingElement.create_from_xml(chips=chips, register=new_register, xml_data= xml_reg)
			periph.add_placement(reg_placement)

		return periph

	def __init__(self, chips: T.Union[ChipSet, None] = None,
	             name: T.Union[str, None] = None,
	             brief: T.Union[str, None] = None) :
		super().__init__(chips=chips, name=name, brief=brief)

		self.registers: T.List[T.Union[Peripheral, Register]] = list()
		self.mappings: T.List[PeripheralMapping] = list()
		self.instances: T.List[PeripheralInstance] = list()
		self.templates: T.List[PeripheralTemplate] = list()
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
		elif isinstance(item, Register) or isinstance(item, Peripheral):
			return item in self.registers
		elif isinstance(item, str) :
			for r in self.registers :
				if r.name == item :
					return True
			return False
		raise ValueError()

	def __getitem__(self, item) -> T.Union["Peripheral", Register]:
		if isinstance(item,Register) or isinstance(item, Peripheral):
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
	def size(self):
		max_size: int = 0
		for m in self.mappings :
			s = m.size
			if s > max_size :
				max_size = s
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
	def add_register(self, reg: T.Union["Peripheral", Register]):
		if reg.name is not None and reg.name in self :
			self[reg.name].inter_svd_merge(reg)
		else :
			self.registers.append(reg)
			reg.set_parent(self)
			self.edited = True
	def remove_register(self, reg: T.Union["Peripheral", Register]):
		if reg.name is not None and reg.name in self :
			reg = self[reg.name]
			idx = self.registers.index(reg)
			while idx >= 0 and self.registers[idx].name != reg.name :
				idx = self.registers.index(reg, idx+1)
			if idx >= 0:
				self.registers.pop(idx)
			else :
				raise KeyError(f"{reg} is not in {self}")
			for m in self.mappings :
				m.remove_elements_for(reg)
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

	def get_linked_variants(self, instance) -> T.List[RegisterVariant]:
		linked_variances: T.List[RegisterVariant] = list()
		for child in self :
			linked_variances.extend(child.get_linked_variants(instance))
		return linked_variances

	def needs_template(self, instance) -> bool :
		for child in self :
			if child.needs_template(instance) :
				return True
		return False



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
			self_placements.extend(m.elements)
		for m in other.mappings :
			other_placements.extend(m.elements)

		for elmt in self_placements :
			if elmt not in other_placements :
				diff.append(elmt)
		for elmt in other_placements :
			if elmt not in self_placements :
				diff.append(elmt)

		if ignore_templates :
			for elmt in diff :
				# if the register is only present in one of the two peripherals, merging is allowed only if the register in templated
				if not elmt.component.has_template :
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
		for elmt in mapping :
			self.add_placement(elmt)

	def add_placement(self, element: MappingElement) :
		mapping: T.Union[PeripheralMapping, None] = None

		element.component = self[element.component.name]
		for m in self.mappings :
			if element in m :
				m[element].inter_svd_merge(element)
				return
			elif m.has_room_for(element) :
				mapping = m
		if mapping is None :
			mapping = PeripheralMapping()
			mapping.parent = self
			self.mappings.append(mapping)
			self.edited = True
		mapping.add_element(element)

	def remove_placements_for(self, reg: T.Union["Peripheral", Register]):
		for m in self.mappings :
			m.remove_placements_for(reg)

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
					self.mappings[m_idx].intra_svd_merge(self.mappings[m_idx + m_offset])
					self.mappings.pop(m_idx + m_offset)
					self.edited = True
					continue
				else :
					m_offset += 1
			m_idx += 1

		r_idx = 0
		while r_idx < len(self.registers) :
			r_offset = 1
			while r_idx + r_offset < len(self.registers) :
				if self.registers[r_idx] == self.registers[r_idx + r_offset]:
					self.registers[r_idx].inter_svd_merge(self.registers[r_idx + r_offset])
					for mapping in self.mappings :
						for elmt in mapping :
							if elmt.component is self.registers[r_idx + r_offset] :
								elmt.component = self.registers[r_idx]
					self.registers.pop(r_idx + r_offset)
					self.edited = True
					continue
				else :
					r_offset += 1
			r_idx += 1

	def after_svd_compile(self, parent_corrector):
		super().after_svd_compile(parent_corrector)

	def intra_svd_merge(self, other: "Peripheral") :
		super().intra_svd_merge(other)
		for r in other.registers : self.add_register(r)
		for i in other.instances : self.add_instance(i)
		for m in other.mappings  : self.add_mapping(m)

	def inter_svd_merge(self, other: "Peripheral") :
		super().inter_svd_merge(other)
		for r in other.registers : self.add_register(r)
		for i in other.instances : self.add_instance(i)
		for m in other.mappings  : self.add_mapping(m)

	def finalize(self):
		super().finalize()
		for i in self.instances :
			i.set_parent(self)
			i.finalize()

		if self.has_template :
			for inst in self.instances :
				if inst.has_template :
					template = None
					for tmpl in self.templates :
						if tmpl.compatible_with(inst) :
							template = tmpl
					if template is None :
						template = PeripheralTemplate(f"{self.name}_tmpl_{len(self.templates)}", parent=self)
						self.templates.append(template)
					template.add_instance(inst)

			self.templates.append(PeripheralTemplate(f"{self.name}_tmpl_default", parent=self))

			for tmpl in self.templates :
				tmpl.finalize()

		map_idx: int = 0
		for m in self.mappings :
			m.set_parent(self)
			m.name = f"MAP{map_idx}"
			map_idx += 1
			m.finalize()

################################################################################
#                          DEFINE, UNDEFINE, DECLARE                           #
################################################################################

	def declare_templates(self, indent: TabManager = TabManager()) -> str :
		out = ""
		if self.has_template :
			for tmpl in self.templates :
				out += tmpl.declare(indent)
		return out

	def declare(self, indent: TabManager = TabManager()) -> str :
		out =""
		if self.needs_define :
			out += f"{indent}#if {self.defined_name}\n"
		if self.has_template and not isinstance(self.parent, Peripheral):
			out += f"{indent}template<typename tmpl={self.templates[-1].name}>\n"
		out += f"{indent}class {self.name} /// {self.brief}\n" \
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

		out += f"{indent}private:\n"
		if not global_parameters.physical_mapping :
			out += f"{indent}#ifndef __SOOL_DEBUG_NOPHY\n"
		out += f"{indent +1 }{self.name}() = delete;\n"
		if not global_parameters.physical_mapping:
			out += f"{indent}#endif\n"
		out += f"{indent}//SOOL-{self.alias}-DECLARATIONS\n"

		indent.decrement()
		out += f"{indent}}};\n"

		if isinstance(self.parent, Peripheral) and self.needs_define :
			out = f"{indent}#ifdef {self.defined_name}\n{out}{indent}#endif\n"
		return out

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

		for tmpl in self.templates :
			tmpl.define(defines)

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
