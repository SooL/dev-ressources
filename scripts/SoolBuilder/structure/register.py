import typing as T
import xml.etree.ElementTree as ET

import logging

from structure import Field
from structure import RegisterVariant
from structure import get_node_text, TabManager
from structure import ChipSet
from structure import Component

logger = logging.getLogger()

################################################################################
################################### REGISTER ###################################
################################################################################
REGISTER_DEFAULT_SIZE: int = 32
REGISTER_DECLARATION: str = """{indent}struct {name}_t: Reg{size}_t
{indent}{{
{variants}
{indent}}};"""

class Register(Component) :

################################################################################
#                                 CONSTRUCTORS                                 #
################################################################################

	@staticmethod
	def create_from_xml(chips: ChipSet, xml_data: ET.Element) -> "Register":
		name = get_node_text(xml_data, "name").strip(None)
		brief = get_node_text(xml_data, "description").strip(None)
		access = get_node_text(xml_data, "access").strip(None)

		# check if displayName is different from name
		disp_name = get_node_text(xml_data, "displayName").strip(None)
		if disp_name != name :
			logger.warning(f"Register name and display discrepancy :"
			               f" {name} displayed as {disp_name}")

		read_size_value = get_node_text(xml_data, "size")
		size = REGISTER_DEFAULT_SIZE if (read_size_value == str()) \
			else int(read_size_value, 0)

		# self.rst = int(get_node_text(xml_base,"resetValue"),0)  # Is a mask
		register = Register(chips=chips, name=name, brief=brief,
		                    size=size, access=access)

		xml_fields = xml_data.findall("fields/field")
		if xml_fields is not None :
			for xml_field in xml_fields :
				register.add_field(Field.create_from_xml(chips, xml_field))

		return register

	def __init__(self,
	             chips: T.Union[ChipSet, None] = None,
	             name: T.Union[str, None] = None,
	             brief: T.Union[str, None] = None,
	             size: int = 32,
	             access: T.Union[str, None] = None) :
		super().__init__(chips=chips, name=name, brief=brief)
		self.size = size
		self.access = access
		self.variants: T.List[RegisterVariant] = list()

	def __iter__(self) :
		return iter(self.variants)

	def __contains__(self, item) :
		if isinstance(item, RegisterVariant) :
			return super().__contains__(item)
		elif isinstance(item,Field) :
			for var in self :
				if item in var  :
					return True
			return False
		raise TypeError()

	def __getitem__(self, item: str) -> Field:
		result: T.Union[Field, None] = None
		for var in self :
			result = var[item]
			if result is not None :
				return result
		raise KeyError()

	def __eq__(self, other):
		if isinstance(other, Register) :
			for var in self :
				for field in var :
					if field not in other :
						return False
			for var in other :
				for field in var :
					if field not in self :
						return False
			return True
		raise TypeError(f"Provided type {type(other)}")

	def add_field(self, field: Field) :
		self.chips.add(field.chips)

		var: T.Union[RegisterVariant, None] = None
		for v in self.variants :
			if field.name in v :
				v[field.name].merge(field)
				return
			if v.has_room_for(field) :
				var = v

		if var is None :
			var = RegisterVariant()
		var.add_field(field)

	def merge(self, other: "Register"):
		for v in other :
			for f in v:
				self.add_field(f)
		super().merge(other)

	def self_merge(self):
		mapping_index = 0
		while mapping_index < len(self.variants):
			mapping_offset = 1

			while mapping_index + mapping_offset < len(self.variants):
				if self.variants[mapping_index] == self.variants[mapping_index + mapping_offset] :
					self.variants.pop(mapping_index + mapping_offset)
					continue
				else :
					mapping_offset += 1
			mapping_index += 1

	def declare(self, indent: TabManager = TabManager()) -> T.Union[None,str] :
		out: str = ""
		is_union = len(self.variants) > 1
		if is_union :
			indent.increment()
			out = f"{indent}union\n{indent}{{\n"

		indent.increment()
		var_declaration = "\n".join(
			map(lambda v : v.declare(indent), self.variants))
		indent.decrement()

		if is_union :
			out += var_declaration + f"\n{indent}}}"
			indent.decrement()

		out = REGISTER_DECLARATION.format(
			indent=indent, name=self.name, size=self.size,
			variants=out)
		if self.needs_define() :
			out = f"#ifdef {self.alias}\n{out}\n#endif"
		return out

################################################################################
#                              REGISTER PLACEMENT                              #
################################################################################


class RegisterPlacement(Component) :

	@staticmethod
	def create_from_xml(chips: ChipSet, register: Register,
	                    xml_data: ET.Element) -> "RegisterPlacement":
		name = get_node_text(xml_data, "name").strip(None)
		offset = int(get_node_text(xml_data, "addressOffset"), 0)
		return RegisterPlacement(chips=chips, name=name, register=register,
		                         address=offset)

	def __init__(self, chips: ChipSet, name: T.Union[str, None],
	             register: Register, address: int, array_size: int = 0) :
		super().__init__(chips=chips, name=name)
		self.register : Register = register
		self.address: int  = address
		self.array_size : int = array_size

	def __eq__(self, other) -> bool:
		if isinstance(other, RegisterPlacement) :
			return self.name == other.name and\
			       self.address == other.address and\
			       self.array_size == other.array_size and\
			       self.register.name == other.register.name and\
			       self.register.size == other.register.size
		else :
			return False

	# def finalize(self):
	# 	pass

	@property
	def computed_size(self) -> int:
		return self.register.size * (1 if self.array_size == 0 else self.array_size)

	def overlap(self, other: "RegisterPlacement"):
		if other.address < self.address :
			size = other.register.size *\
			       (1 if other.array_size == 0 else other.array_size)
			return other.address + size > self.address
		else : # self.address <= other.address
			size = self.register.size *\
			       (1 if self.array_size == 0 else self.array_size)
			return self.address + size > other.address

	def define(self) -> T.Union[str, None] :
		if not(self.needs_define()) :
			return None
		else :
			template = "#define {0.alias} {1.name}_t {0.name}"
			if self.array_size > 0 :
				template += "[{0.array_size}]"
			return template.format(self, self.register)

	def define_not(self) -> T.Union[str, None] :
		if self.needs_define() :
			return f"#define {self.alias}"
		else :
			return None

	def declare(self, indent: TabManager = TabManager()) -> T.Union[None, str] :
		if self.needs_define() :
			return self.alias + ";"
		elif self.array_size == 0 :
			return f"{indent}{self.register.name}_t {self.name}"
		else :
			return f"{indent}{self.register.name}_t {self.name}[{self.array_size}]"



