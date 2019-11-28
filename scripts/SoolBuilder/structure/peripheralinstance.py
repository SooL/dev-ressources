from structure import Component, ChipSet, TabManager, RegisterVariant, Register
import typing as T

from structure.utils import DefinesHandler
from tools import global_parameters

class PeripheralInstance(Component):
	#TODO consider templates
	generate_nophy : bool = False

	def __init__(self, chips: T.Union[ChipSet, None] = None,
	             name: T.Union[str, None] = None,
	             brief: T.Union[str, None] = None,
	             address: T.Union[int, None] = None) :
		super().__init__(chips=chips, name=name, brief=brief)

		self.address = address

	def __eq__(self, other):
		return isinstance(other, PeripheralInstance) and \
		       self.name == other.name and \
		       self.address == other.address

	def __lt__(self, other: "PeripheralInstance"):
		if self.address != other.address :
			return self.address < other.address
		else :
			return self.name < other.name

	@property
	def needs_define(self) -> bool:
		if self.address != 0 :
			return True
		else :
			return super().needs_define

	@property
	def undefine(self) -> bool:
		return False

	@property
	def defined_value(self) -> T.Union[str, None]:
		return f"((uint32_t){self.address:#08x}U"

	@property
	def define_not(self) -> T.Union[bool, str] :
		return False

	@property
	def defined_name(self) -> str :
		return f"{self.name}_BASE_ADDR"

	@property
	def template_reg_variants(self) -> T.List[RegisterVariant]:
		result: T.List[RegisterVariant] = list()
		for reg in self.parent :
			for var in reg :
				if var.for_template :
					for instance in var.linked_instances :
						if instance.name == self.name :
							result.append(var)
							break
		return result

	def define(self, defines: T.Dict[ChipSet, DefinesHandler]):
		# defines the address
		super().define(defines)

		# defines the peripheral it has to be defined to
		if self.parent.needs_define :
			defines[self.chips].add(
				alias=super().defined_name,
				# defined_value=self.defined_value,
				define_not=False,
				undefine=True)


	def declaration_strings(self, indent : TabManager = TabManager()) -> str:
		out = ""
		class_name = self.parent.name
		if self.parent.has_template :
			template_reg_variants = self.template_reg_variants
			if len(template_reg_variants) > 0 :

				class_name += f"<{self.name}_tmpl>"

				template_declaration = f"{indent}struct {self.name}_tmpl\n{indent}{{\n"
				indent.increment()
				registers: T.List[Register] = list()
				for var in template_reg_variants :
					if var.parent not in registers :
						registers.append(var.parent)

				for reg in registers :
					template_declaration += f"{indent}struct {reg.name}_t\n{indent}{{\n"
					indent.increment()
					variants : T.List[RegisterVariant] = list()
					for var in template_reg_variants :
						if var.parent is reg :
							variants.append(var)
					if len(variants) > 1 :
						template_declaration += f"{indent}union\n{indent}{{\n"
						indent.increment()
					for var in variants :
						template_declaration += var.declare(indent)
					if len(variants) > 1 :
						indent.decrement()
						template_declaration += f"{indent}}}\n"
					indent.decrement()
					template_declaration += f"{indent}}}\n"

				indent.decrement()
				template_declaration += f"{indent}}}\n"
				out += template_declaration
			else :
				class_name += f"<>"
		# end if has_template

		normal_instance = str(indent + (
			0 if global_parameters.physical_mapping else 1)) + \
						  "volatile class {0} * const {1} = reinterpret_cast<class {0}* const>({2});" \
			              .format(class_name, self.name, self.defined_name)

		nophy_instance = (str(indent + 1) + "volatile class {0} * const {1} = new {0}();\n" +
		                  str(indent + 1) + "#undef {2}\n" +
		                  str(indent + 1) + "#define {2} reinterpret_cast<uint32_t>({1})") \
			.format(self.parent.name, self.name, self.defined_name)
		if not global_parameters.physical_mapping :
			out += f"{indent}#ifndef __SOOL_DEBUG_NOPHY\n" \
				  f"{normal_instance}\n" \
				  f"{indent}#else\n" \
				  f"{nophy_instance}\n" \
				  f"{indent}#endif"
		else :
			out += normal_instance

		return out

	def declare(self, indent: TabManager = TabManager()) -> T.Union[None,str] :

		ifdef_string : str = ""

		if self.needs_define :
			ifdef_string += f"defined({self.defined_name}) "
		if self.parent.needs_define :
			if ifdef_string != "" :
				ifdef_string += "&& "
			ifdef_string += f"defined({super().defined_name}) "

		if len(ifdef_string) > 0 :
			indent.increment()
			out = f"\n{indent -1 }#if {ifdef_string}\n" \
				  f"{self.declaration_strings(indent)}\n" \
				  f"{indent-1}#endif\n"
			indent.decrement()
		else:
			out = self.declaration_strings(indent) + "\n"
			if not global_parameters.physical_mapping :
				out += "\n"

		return out
