from copy import copy, deepcopy
from math import ceil

from structure.Component import Component
from structure.Field import Field
from structure.Register import Register
from tools.msglog import log
from tools.utils import ChipSeriesManager
from typing import *

# <editor-fold desc="Templates">

FILE_TEMPLATE = """
#ifndef __SOOL_{name}_H
#define __SOOL_{name}_H

{chips}

#include "lib_utils/peripheral_include.h"
//SOOL-{name}-INCLUDES
//region defines
{defines}
//endregion
namespace sool
{{
	namespace core
	{{
//region related-types
		//SOOL-{name}-RELATED-TYPES
//endregion
//region peripheral-declaration
		{declaration}
//endregion
//region instances
		{instances}
//endregion
//region peripheral-definition
		//SOOL-{name}-DEFINITION
//endregion
	}};
}};
//region undef
{undef}
//endregion
{endif}
#endif //__SOOL_{name}_H
"""
PERIPH_STRUCT_TEMPLATE = """
class {periph}
{{
	//SOOL-{periph}-NESTED-TYPES
	
	public :
	{registers}
	union
	{{
		{mappings}
	}};
	private:
	{periph}() = delete;
	//SOOL-{periph}-DECLARATION
}};
"""
PERIPH_STRUCT_EMPTY_TEMPLATE = """
class {periph}
{{
	//SOOL-{periph}-NESTED-TYPES
	{registers}
	
	private:
	{periph}() = delete;
	//SOOL-{periph}-DECLARATION
}};
"""

DIVERGENCE_TEMPLATE = """
struct {name}_plugin: {periph}_base_plugin {{
	{content}
}};
"""


# </editor-fold>

def create_padding(size: int, indent: int = 0, for_define=False):
	i = 1
	j = 2
	out = ""
	size /= 8
	while size > 0:
		if size % j == i:
			out = "{}__SOOL_PERIPH_PADDING_{};".format("\t" * indent, i) + ("" if for_define else "\n") + out
			size -= i
		i = j
		j *= 2
	return out[:-1]


class Mapping(Component):
	def __init__(self, reg: Union[Register, "Peripheral"], chips: ChipSeriesManager, pos: int, name: str = None,
					array_size: int = 1, array_offset: int = 0, array_item_size: int = 0):
		Component.__init__(self, "", chips)
		self.reg = reg
		self.array_size = array_size
		self.pos = pos
		self.name = name if name is not None else reg.name
		self.index = -1
		self.array_offset = array_offset
		self.array_item_size = array_item_size

	def _define(self):
		name = "{parent}_MAP{m.index}_{m.name}".format(
			parent=self.parent.prefixed_name(),
			m=self)
		result = ""
		if self.array_size > 1:
			if self.array_item_size == 0:
				result = "#define {name:20} {reg_use} {m.name}[{m.array_size}]"
			else:
				result = "#define {name:20} BigArrayReg_t<{reg_use}, {m.array_offset}, {m.array_item_size}, {m.array_size}> {m.name}"
		else:
			result = "#define {name:20} {reg_use} {m.name}"

		return result.format(
			name=name,
			reg_use=self.reg if isinstance(self.reg, str) else self.reg.use(),
			m=self)

	def _notDefined(self):
		return "#define {0}_MAP{1.index}_{1.name} ".format(self.parent.prefixed_name(), self) + \
		       create_padding(size=self.reg.size * self.array_size, for_define=True)

	def _undefine(self):
		return "#undef {parent}_MAP{m.index}_{m.name}".format(
			parent=self.parent.prefixed_name(),
			m=self)

	def use(self):
		if self.chips == self.parent.chips:
			if self.array_item_size == 0:
				return self.reg.use() + " " + self.name + \
				       (";" if self.array_size == 1 else "[{}];".format(self.array_size))
			else:
				return "BigArrayReg_t<{reg_use}, {m.array_offset}, {m.array_item_size}, {m.array_size}> {m.name};".format(
					m=self,
					reg_use=self.reg.use()
				)

		else:
			return "{parent}_MAP{m.index}_{m.name};".format(
				parent=self.parent.prefixed_name(),
				m=self)

	def finalize(self, full_chips):
		if self.chips.is_empty():  # register created manually
			self.chips.merge(self.reg.chips)

		Component.finalize(self, full_chips)
		if self.index < 0:
			raise Exception("mapping does not have an index.")

	def size(self):
		# noinspection PyUnresolvedReferences
		return self.reg.size * self.array_size

	def __eq__(self, other):
		return type(other) == Mapping and \
		       other.reg == self.reg and \
		       other.array_size == self.array_size and \
		       other.pos == self.pos and \
		       other.name == self.name

	def merge(self, other: "Mapping"):
		self.reg.merge(other.reg)  # probably not necessary
		self.chips.merge(other.chips)


class Peripheral(Component):
	def __init__(self, name: str, chips: ChipSeriesManager):
		Component.__init__(self, name, chips)
		self.registers: List[Union[Register, "Peripheral"]] = list()  # List[position, register*, array_size]
		# *: or sub-peripherals like CAN mailbox
		self.mappings: List[Mapping] = list()  # one Mapping instance per register
		self.size = -1
		self.linked_peripherals: List[Peripheral] = list()
		self.main = True
		self.instances: List[Tuple[str, ChipSeriesManager, int]] = list()  # list (name, chips, addr)
		self.divergences: List[PeriphDivergence] = list()

	def need_def(self):
		return True

	def _define(self):
		if not self.main:
			return "#define {}".format(self.name)

	def _notDefined(self):
		return ""

	def define_output(self, dictionary: Dict[str, List[Tuple[str, str, str]]]):
		for r in self.registers:
			r.define_output(dictionary)

		for linked in self.linked_peripherals:
			linked.define_output(dictionary)

		for m in self.mappings:
			m.define_output(dictionary)

		for d in self.divergences:
			d.define_output(dictionary)

	# if not self.main:
	#	Component.define_output(self, dictionary)
	def _split_mappings(self):
		self.mappings.sort(key=lambda m: m.index)
		groups: List[List[Mapping]] = [[]]
		map_index = 0
		for mapping in self.mappings:
			if map_index == mapping.index:
				groups[map_index].append(mapping)
			else:
				groups.append([mapping])
				map_index = map_index + 1
		return groups

	def use(self):
		return self.name

	def declare(self):
		if self.size == -1:
			self.compute_size()
		if self.size == 0:
			return ""
		reg_declare = ""
		map_declare = ""
		for reg in self.registers:
			if isinstance(reg, Peripheral) or not reg.divergent:
				reg_declare += reg.declare().replace("\n", "\n\t")
		mapping_groups = self._split_mappings()
		for group in mapping_groups:
			map_declare += "\n\t\tstruct\n\t\t{"
			cursor: int = 0
			for mapping in group:
				if mapping.pos < cursor:
					raise Exception("mappings overlap in peripheral " + self.name)
				elif mapping.pos > cursor:
					size = mapping.pos - cursor
					if size % 8 != 0:
						raise Exception("filler without a integral number of bytes : " + self.name + "_" + mapping.name)
					map_declare += "\n" + create_padding(size, 3)
				map_declare += "\n\t\t\t{:20} // @0x{:03x}".format(mapping.use(), int(mapping.pos / 8))
				cursor = mapping.pos + mapping.size()
			if cursor != self.size:
				size = self.size - cursor
				if size % 8 != 0:
					raise Exception(
						"filler without a integral number of bytes : " + self.name + " at " + str(cursor) + " " + str(
							self.size))
				map_declare += "\n" + create_padding(size, 3)
			map_declare += "\n\t\t};"
		template = ""
		if len(self.divergences) > 0:
			# output base variant
			template = "\nstruct {}_base_plugin\n{{\n".format(self.name)
			for r in self.registers:
				if r.divergent:
					template += r.declare(True).replace("\n", "\n\t")
			template += "};\n"
			template += "template<typename plugin={}_base_plugin>".format(self.name)
		return template + (PERIPH_STRUCT_TEMPLATE if len(self.mappings) > 0 else PERIPH_STRUCT_EMPTY_TEMPLATE) \
			.format(periph=self.name, registers=reg_declare, mappings=map_declare)

	def add_register(self, register: Union[Register, "Peripheral"], pos: int, chips: ChipSeriesManager = None,
	                 name: Union[str, None] = None, arr_size: int = 1, array_offset: int = 0, array_item_size: int = 0):
		if chips is None:
			chips = register.chips

		self.chips.merge(chips)

		ok = False
		# 1. add register to list or merge with existing one
		for reg in self.registers:
			if reg == register:
				reg.merge(register)
				register = reg
				ok = True
		if not ok:
			register.set_parent(self)
			self.registers.append(register)
		else:
			ok = False  # reset to False for next step

		if pos < 0: return  # register without direct usage

		# 2. add appropriate mapping or merge with existing one if attributes match
		m = Mapping(register, chips, pos, name, arr_size, array_offset, array_item_size)
		for mapping in self.mappings:
			if mapping == m:
				mapping.merge(m)
				ok = True
		if not ok:
			m.set_parent(self)
			self.mappings.append(m)

	def compute_size(self):
		if len(self.mappings) > 0:
			self.mappings.sort(key=lambda m: m.pos + m.size())
			mapping = self.mappings[len(self.mappings) - 1]
			# noinspection PyUnresolvedReferences
			self.size = mapping.pos + mapping.size()
			return self.size
		else:
			self.size = 0
			return 0

	def finalize(self, full_chips):
		Component.finalize(self, full_chips)
		if self.parent is not None:
			self.main = False
		self.registers.sort(key=lambda r: r.name)
		for reg in self.registers:

			if isinstance(reg, Register) and reg.divergent:
				for d in self.divergences:
					div_reg = d.get_register(reg.name)
					if div_reg is not None:
						div_reg.merge(reg)

			reg.finalize(full_chips)

		for d in self.divergences:
			d.finalize(full_chips)

		self.mappings.sort(key=lambda m: m.pos)

		last_pos: List[int] = [0]
		used_names: List[List[str]] = list()
		used_names.append(list())
		for mapping in self.mappings:
			map_index = 0
			while (mapping.pos < last_pos[map_index]) or (mapping.name in used_names[map_index]):
				map_index = map_index + 1
				if map_index == len(last_pos):
					last_pos.append(0)
					used_names.append(list())
			last_pos[map_index] = mapping.pos + mapping.size()
			used_names[map_index].append(mapping.name)
			mapping.index = map_index
			mapping.finalize(full_chips)

	def merge(self, other: "Peripheral"):
		self.chips.merge(other.chips)
		for m in other.mappings:
			self.add_register(m.reg, m.pos, m.chips, m.name, m.array_size, m.array_offset, m.array_item_size)

	def file_output(self):
		if not self.main:
			raise Exception("Peripheral {0.name} is a sub peripheral. It can't have its own file".format(self))

		define_dict: Dict[str, List[Tuple[str, str, str]]] = dict()
		self.define_output(define_dict)
		with open("out/" + self.name + ".h", "w") as file:
			out_define: str =""
			out_undef: str = ""
			for key in define_dict:
				out_def: str = ""
				out_ndef: str = ""
				for values in define_dict[key]:
					if values[0] is not None and len(values[0]) > 0:
						out_def += values[0] + "\n"
					if values[1] is not None and len(values[1]) > 0:
						out_ndef += values[1] + "\n"
					if values[2] is not None and len(values[2]) > 0:
						out_undef += values[2] + "\n"
				out_define += "\n" + key.format(ifdef=out_def[:-1], ifndef=out_ndef[:-1]).replace("#else\n\n#endif", "#endif")
			out_declare: str = self.declare().replace("\n", "\n\t\t")

			for linked in self.linked_peripherals:
				out_declare += "\n"+linked.declare().replace("\n", "\n\t\t")

			with open('license_header.txt', 'r') as license:
				file.write(license.read() + FILE_TEMPLATE.format(
					chips=self.chips.output_ifdef_template(onlyIf=True),
					name=self.name,
					defines=out_define,
					declaration=out_declare,
					instances=self.output_instances(),
					undef=out_undef,
					endif="#endif // chips selection" if not(self.chips.is_all_chips()) else ""
				))

	def __iter__(self):
		for reg in self.registers:
			yield reg

	def __getitem__(self, item: str):
		if isinstance(item, str):
			for reg in self.registers:
				if reg.name == item:
					return reg
			return None
		else:
			return None

	def getMappings(self, reg: Union[str, Register]):
		"""
		:param reg:
		:return Mapping:
		"""
		mappings: List[Mapping] = list()
		r = reg if isinstance(reg, Register) else self[reg]

		for m in self.mappings:
			if m.reg == r:
				mappings.append(m)
		return mappings

	def create_field(self, reg_name: str, field_name: str, pos: int, size: int, chips: ChipSeriesManager):
		register: Register = None

		for reg in self.registers:
			if reg.name == reg_name:
				register = reg
				break
			elif isinstance(reg, Peripheral):
				if reg.create_field(reg_name, field_name, pos, size, chips):
					return

		if register is None:
			for periph in self.linked_peripherals:
				if periph.create_field(reg_name, field_name, pos, size, chips):
					return

		if register is not None:
			register.add_field(Field(field_name, chips, pos, size))
			return True
		else:
			return False  # TODO go a bit further

	def get_field(self, reg_name: str, field_name: str, chips: ChipSeriesManager):
		for reg in self.registers:
			if reg.name == reg_name:
				for var in reg.variants:
					for field in var.fields:
						if field.name == field_name:
							return field
			elif isinstance(reg, Peripheral):
				field = reg.get_field(reg_name, field_name, chips)
				if field is not None:
					return field
		for periph in self.linked_peripherals:
			field = periph.get_field(reg_name, field_name, chips)
			return field

		return None

	def find_register(self, name: List[str], chips: ChipSeriesManager, divergenceName=None) -> (Register, List[str]):
		divergence = None
		if self.parent is None:
			if name[0].startswith(self.name):
				if self.name != name[0]:  # possible divergence
					divergenceName = name[0]
				name = name[1:]

			elif "_".join(name[:2]).startswith(self.name):
				if self.name != "_".join(name[:2]):  # possible divergence
					divergenceName = "_".join(name[:2])
				name = name[2:]

			elif "".join(name[:2]).startswith(self.name):
				if self.name != "".join(name[:2]):  # possible divergence
					divergenceName = "".join(name[:2])
				name = name[2:]

		for reg in self:
			result = False
			if isinstance(reg, Peripheral):
				result_reg, result_name = reg.find_register(name, chips, divergenceName)
				if result_reg is not None:
					return result_reg, result_name
			elif reg.name == name[0]:
				name = name[1:]
				result = True
			elif reg.name in ["_".join(name[:2]), "".join(name[:2])]:
				name = name[2:]
				result = True

			if result:

				if divergenceName is not None:
					for i in range(0, len(self.divergences)):
						if self.divergences[i].name == divergenceName:
							divergence = self.divergences[i]
							log("I_DIVERGENCE",
							    "Divergence on instance {} for {}.{}".format(divergenceName, self.name, reg.name),
							    chips)
							break
					if divergence is None:
						divergence = PeriphDivergence(self, divergenceName, chips)
						log("I_DIVERGENCE",
						    "Divergence on instance {} for {}.{}".format(divergenceName, self.name, reg.name), chips)
						self.divergences.append(divergence)

					reg.divergent = True
					div_reg = divergence.get_register(reg.name)
					if div_reg is None:
						div_reg = Register(reg.name, chips, reg.reg_type, reg.size)
						divergence.add_register(div_reg)
					reg = div_reg

				return reg, name

		for p in self.linked_peripherals:
			result_reg, result_name = p.find_register(name, chips, divergenceName)
			if result_reg is not None:
				return result_reg, result_name
		# TODO if reg name ends with number, remove number and retry
		return None, None

	def find_field(self, name: List[str], chips: ChipSeriesManager, divergenceName=None) -> Union[Field, None]:
		reg, name = self.find_register(name, chips, divergenceName)
		if reg is None:
			return None

		names: List[str] = [name[0]]
		for i in range(2, len(name)):
			names.append("_".join(name[:i]))

		for var in reg:
			for f in var:
				if f.name in names:
					if (len(name) == len(f.name.split("_")) and "_".join(name) == f.name) or (
							"".join(name) == f.name):
						return f

		return None

	def parse_define(self, name: List[str], pos: int, size: int, chips: ChipSeriesManager, divergenceName=None) -> bool:

		reg, name = self.find_register(name, chips, divergenceName)
		if reg is None:
			return False
		already = False
		names: List[str] = [name[0]]
		for i in range(2, len(name)):
			names.append("_".join(name[:i]))

		for var in reg:
			for f in var:
				if f.name in names:
					# field already in reg. just copy the already existing field to add chips if it is not a sub field
					already = True
					if (len(name) == len(f.name.split("_")) and "_".join(name) == f.name) or ("".join(name) == f.name):
						reg.add_field(Field(f.name, chips, pos, size))
					break

		if not already:
			if name[-1].isdigit():
				if len(name) > 1:
					name[-2] = "".join(name[-2:2])
					name.pop()

			name = "_".join(name)

			if name[0].isdigit():  # first character is digit
				prefix = (reg.name[:-1] if reg.name[-1:] == "R" else reg.name)
				# reg.add_field(Field(prefix + "_" + name, chips, pos, size))
				name = prefix + name

			reg.add_field(Field(name, chips, pos, size))
		return True

	def add_link(self, other: "Peripheral"):
		self.chips.merge(other.chips)
		self.linked_peripherals.append(other)
		other.main = False

	def add_instance(self, name, chips, addr):
		self.instances.append((name, chips, addr))

	def output_instances(self):
		dico = dict()
		divergences = []
		div_names = ""
		divergences.extend(self.divergences)
		for name, chips, addr in self.instances:
			key = ""
			if chips == self.chips:
				key = "{ifdef}"
			else:
				key = chips.output_ifdef_template()
			if key not in dico:
				dico[key] = list()
			dico[key].append((self.name, name, addr, len(self.divergences) > 0))
		for p in self.linked_peripherals:
			divergences.extend(p.divergences)
			for name, chips, addr in p.instances:
				key = chips.output_ifdef_template()
				if key not in dico:
					dico[key] = list()
				dico[key].append((p.name, name, addr, len(p.divergences) > 0))
		for reg in self.registers:
			if isinstance(reg, Peripheral):
				divergences.extend(reg.divergences)
				for name, chips, addr in reg.instances:
					key = chips.output_ifdef_template()
					if key not in dico:
						dico[key] = list()
					dico[key].append((self.name + "::" + reg.name, name, addr, len(reg.divergences) > 0))
		for d in divergences:
			div_names += d.name + "\n"
		if len(divergences) > 0:
			print("divergences for {} :\n{}".format(self.name, div_names[:-2]))

		output = ""
		inst_list: List[str] = list()
		for key in dico:
			ifdef = ""
			for typedef, name, addr, divergent in dico[key]:

				ifdef += "#define {0}_BASE_ADDR ((uint32_t)0x{1:08X}U)\n".format(name, addr)
				if typedef is None:
					continue

				inst = ""

				if divergent:
					divergence = None
					for d in divergences:
						if d.parent.name:
							if d.name == name or d.name in name.split("_"):
								divergence = d
								log("W_DIVERGENCE",
								    "divergence {} used for peripheral instance {}".format(d.name, name))
								if d.name != name:
									divergence.name = name
								# divergences.remove(d)
								break
							# TODO take divergences with '_' in their name into account
							else:
								print("divergence {} not applicable for {}".format(d.name, name))

					if divergence is not None:
						inst = (
								"#ifdef {inst}_BASE_ADDR{div_declare}volatile class {periph}<{inst}_plugin>* const {inst} =" +
								"reinterpret_cast<class {periph}<{inst}_plugin>* const>({inst}_BASE_ADDR);\n#endif").format(
							inst=name, div_declare=divergence.declare(), periph=typedef
						)
					else:
						inst = ("#ifdef {inst}_BASE_ADDR\nvolatile class {periph}<>* const {inst} =" +
						        "reinterpret_cast<class {periph}<>* const>({inst}_BASE_ADDR);\n#endif").format(
							inst=name, periph=typedef
						)
				else:
					inst = "#ifdef {1}_BASE_ADDR\nvolatile class {0} * const {1} = reinterpret_cast<class {0}* const>({1}_BASE_ADDR);\n#endif" \
						.format(typedef, name)

				if inst not in inst_list:
					inst_list.append(inst)

			output += key.format(
				ifdef=ifdef,
				ifndef=""
			).replace("\n#else\n\n#endif", "#endif\n")
		output += "\n".join(inst_list)

		# for d in divergences:
		#	log("E_DIVERGENCE", "unused divergence : {} for {}".format(d.name, d.parent.name))
		return output


class PeriphDivergence(Component):
	def __init__(self, peripheral, instanceName, chips):
		Component.__init__(self, instanceName, chips)
		self.set_parent(peripheral)
		self.registers: List[Register] = list()

	def declare(self):
		out = ""
		for r in self.registers:
			out += r.declare().replace("\n", "\n\t")
		return DIVERGENCE_TEMPLATE.format(name=self.name, periph=self.parent.name, content=out)

	def finalize(self, full_chips):
		for r in self.registers:
			r.finalize(full_chips)
			self.chips.merge(r.chips)
		Component.finalize(self, full_chips)

	def get_register(self, registerName):
		for i in range(0, len(self.registers)):
			if self.registers[i].name == registerName:
				return self.registers[i]
		return None

	def add_register(self, register):
		self.chips.merge(register.chips)
		register.set_parent(self)
		self.registers.append(register)

	def add_field(self, registerName, field):
		self.chips.merge(field.chips)
		reg = self.get_register(registerName)
		if reg is None:
			raise Exception("no register {} in divergence {}".format(registerName, self.name))
		reg.add_field(field)

	def define_output(self, dictionary: Dict[str, List[Tuple[str, str, str]]]):
		for r in self.registers:
			r.define_output(dictionary)

	def prefixed_name(self):
		return self.name

	def __eq__(self, other):
		if not isinstance(other, PeriphDivergence):
			return False
		if self.parent != other.parent:
			return False
		if len(self.registers) != len(other.registers):
			return False
		for i in range(0, len(self.registers)):
			if self.registers[i] != other.registers[i]:
				return False
		return True
