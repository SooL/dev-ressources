import typing as T
import xml.etree.ElementTree as ET

import logging

from structure.Field import Field
from structure.RegisterVariant import RegisterVariant
from structure.utils import get_node_text, TabManager
from structure.chipset import ChipSet
from structure.Component import Component

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

	def add_field(self, field: Field) :
		var: T.Union[RegisterVariant, None] = None
		for v in self.variants :
			if v.has_room_for(field) :
				var = v

		if var is None :
			var = RegisterVariant()
		var.add_field(field)

	def finalize(self) :
		for v in self.variants :
			v.set_parent(self)
			v.finalize()
		pass

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
############################## REGISTER PLACEMENT ##############################
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
		self.register = register
		self.address = address
		self.array_size = array_size

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



