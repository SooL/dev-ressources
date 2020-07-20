# ******************************************************************************
#  Copyright (c) 2018-2020 FAUCHER Julien & FRANCE Loic.                       *
#                                                                              *
#  This file is part of SooL generator.                                        *
#                                                                              *
#  SooL generator is free software: you can redistribute it and/or modify      *
#  it under the terms of the GNU Lesser General Public License                 *
#  as published by the Free Software Foundation, either version 3              *
#  of the License, or (at your option) any later version.                      *
#                                                                              *
#  SooL core Library is distributed in the hope that it will be useful,        *
#  but WITHOUT ANY WARRANTY; without even the implied warranty of              *
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                *
#  GNU Lesser General Public License for more details.                         *
#                                                                              *
#  You should have received a copy of the GNU Lesser General Public License    *
#  along with SooL core Library. If not, see  <https://www.gnu.org/licenses/>. *
# ******************************************************************************

import os
import sqlite3 as sql
import typing as T
from structure import ChipSet
from structure import Group
from structure import Peripheral, PeripheralInstance, Field
from structure import default_tabmanager as indent
from copy import copy

class Record:
	def __init__(self,field_name, instance : PeripheralInstance):
		self.instance : PeripheralInstance = instance
		self.overall_chipset = ChipSet()
		self.field_name : str = field_name
		self.values_pos: T.Dict[int,ChipSet] = dict()
		self.values_reg: T.Dict[int, ChipSet] = dict()
		self.instance.chips.update_families()
		self.parent = self.instance.parent.inheritFrom if self.instance.parent.inherits else self.instance.parent

	def output_fpos(self):
		out = ""
		# Check if whether the instance is in all chips which support the peripheral.
		univ_peripheral_instance = self.instance.chips == self.parent.chips
		unique_position = len(self.values_pos) == 1
		if not univ_peripheral_instance :
			out += f"{indent}#ifdef {self.instance.name}_BASE_ADDR\n"
			indent.increment()
		out += f"{indent}case {self.instance.name}_BASE_ADDR :\n"
		indent.increment()


		for i in range(len(self.values_pos)):
			v = list(self.values_pos.keys())[i]
			cs = self.values_pos[v]

			if not unique_position :
				if i == 0:
					out += f"{indent}#if {cs.defined_list(newline_prefix=f'{indent}    ',reference_chipset=self.overall_chipset)}\n"
				else:
					out += f"{indent}#elif {cs.defined_list(newline_prefix=f'{indent}      ',reference_chipset=self.overall_chipset)}\n"

			out += f"{indent + (1 if not univ_peripheral_instance else 0)}return 1 << {v};\n"

		if not unique_position:
			out += f"{indent}#endif\n"
			indent.decrement()
		if not univ_peripheral_instance:
			indent.decrement()
			out += f"{indent}#endif"
		else :
			indent.decrement()
		indent.level = 1
		return out

	def output_register(self):
		out = ""
		# Parent points to periph which does not makes sense when there is inheritance.
		univ_peripheral_instance = self.instance.chips == self.parent.chips
		unique_register = len(self.values_reg) == 1
		if not univ_peripheral_instance:
			out += f"{indent}#ifdef {self.instance.name}_BASE_ADDR\n"
			indent.increment()
		out += f"{indent}case {self.instance.name}_BASE_ADDR :\n"
		indent.increment()
		for i in range(len(self.values_reg)):
			v = list(self.values_reg.keys())[i]
			cs = self.values_reg[v]

			if not unique_register :
				if i == 0:
					out += f"{indent}#if {cs.defined_list(newline_prefix=f'{indent}    ',reference_chipset=self.overall_chipset)}\n"
				else:
					out += f"{indent}#elif {cs.defined_list(newline_prefix=f'{indent}      ',reference_chipset=self.overall_chipset)}\n"

			out += f"{indent + (1 if not unique_register else 0)}return RCC->{v};\n"

		if not unique_register:
			out += f"{indent}#endif\n"
			indent.decrement()
		if not univ_peripheral_instance:
			indent.decrement()
			out += f"{indent}#endif"
		else:
			indent.decrement()
		indent.level = 1
		return out


def generate_records(periph : Peripheral, rcc : Peripheral) -> T.Dict[str,Record] :
	"""
	Generates records dict to be used for RCCF generation.
	:param periph: Periph to generate RCCF for.
	:param rcc: RCC peripheral description
	:return: Fully formed dict.
	"""
	group : Group = periph.parent
	names : T.List[T.Tuple[str,PeripheralInstance]] = [(f"{x.name}EN",x) for x in periph.instances]

	# If periph is a parent class, we append all childs enable fields.

	for child in [p for p in group if p.inheritFrom is periph] :
		names.extend([(f"{x.name}EN",x) for x in child.instances])
	"""Fields name that will be looked up"""
	records_dict : T.Dict[str,Record] = dict()
	"""Dict which associate a field name with a proper record."""

	# For each instance we try to find the matching fields in RCC for all chips
	for fname,instance in names :
		curr_cs : ChipSet = copy(instance.chips)
		"""Instance chipset"""
		# For all potentially valid RCC registers (Enable Register)
		for reg in [ x for x in rcc if "ENR" in x.name]:

			fieldlist : T.List[Field] = list()
			"""List of all fields across all variant for the given RCC register"""

			for v in reg :
				fieldlist += v.fields

			# We look for a field matching the current fname and update the record accordingly.
			# Since we want something which is valid for the instance's chips, the found fields should have
			# some chips in common with the instance.
			for field in [f for f in fieldlist if f.name == fname] :

				common_chips : ChipSet = curr_cs & field.chips
				if not common_chips.empty :
					curr_cs = curr_cs - common_chips
					if fname not in records_dict :
						records_dict[fname] = Record(fname,instance)
					if field.position not in records_dict[fname].values_pos :
						records_dict[fname].values_pos[field.position] = ChipSet()
					if reg.name not in records_dict[fname].values_reg :
						records_dict[fname].values_reg[reg.name] = ChipSet()
					records_dict[fname].values_pos[field.position].add(common_chips)
					records_dict[fname].overall_chipset.add(common_chips)

					records_dict[fname].values_reg[reg.name].add(common_chips)
					records_dict[fname].overall_chipset.add(common_chips)

	return records_dict


def generate_get_bit(records_dict : T.Dict[str,Record],periph : Peripheral) -> str :
	out = ""
	need_template = False
	for inst in periph.instances :
		if periph.needs_template(inst) :
			need_template = True
			break
	if need_template :
		out += "template<typename T>\n"

	out += f"static constexpr uint32_t {periph.name}{'<T>' if need_template else ''}::get_clock_enable_bit(const uintptr_t addr)\n"
	out += f"{{\n"
	indent.increment()
	out += f"{indent}switch (addr) \n{indent}{{\n"

	for n, rec in records_dict.items():
		out += f"{indent}//Output for {n}\n"
		out += rec.output_fpos()
		out += "\n"
	out += f"{indent}}}\n"
	indent.decrement()
	out += "}\n"
	return out


def generate_get_reg(records_dict: T.Dict[str, Record],periph : Peripheral) -> str:
	out = ""
	need_template = False
	for inst in periph.instances :
		if periph.needs_template(inst) :
			need_template = True
			break
	if need_template :
		out += "template<typename T>\n"

	out += f"static constexpr volatile Reg32_t& {periph.name}{'<T>' if need_template else ''}::get_clock_enable_reg(const uintptr_t addr)\n"
	out += f"{{\n"
	indent.increment()
	out += f"{indent}switch (addr) \n{indent}{{\n"

	for n, rec in records_dict.items():
		out += f"{indent}//Output for {n}\n"
		out += rec.output_register()
		out += "\n"
	out += f"{indent}}}\n"
	indent.decrement()
	out += "}\n"
	return out
