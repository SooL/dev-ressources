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

from structure import Component, ChipSet, TabManager, RegisterVariant, Register
import typing as T
import sqlite3 as sql
from structure.utils import DefinesHandler
from tools import global_parameters

class PeripheralInstance(Component) :
	#TODO consider templates

	def __init__(self, chips: T.Union[ChipSet, None] = None,
	             name: T.Union[str, None] = None,
	             brief: T.Union[str, None] = None,
	             address: T.Union[int, None] = None) :
		super().__init__(chips=chips, name=name, brief=brief)

		self.address = address

	def __eq__(self, other) :
		return isinstance(other, PeripheralInstance) and \
		       self.name == other.name and \
		       self.address == other.address

	def __lt__(self, other: "PeripheralInstance") :
		if self.address != other.address :
			return self.address < other.address
		else :
			return self.name < other.name

	@property
	def needs_define(self) -> bool :
		if self.address != 0 :
			return True
		else :
			return super().needs_define

	@property
	def undefine(self) -> bool :
		return False

	@property
	def defined_value(self) -> T.Union[str, None] :
		return f"((uint32_t){self.address:#08x}U)"

	@property
	def define_not(self) -> T.Union[bool, str] :
		return False

	@property
	def defined_name(self) -> str :
		return f"{self.name}_BASE_ADDR"

	@property
	def template_reg_variants(self) -> T.List[RegisterVariant] :
		return self.parent.get_linked_variants(self)

	@property
	def needs_template(self) -> bool :
		return self.parent.needs_template(self)

	@property
	def has_template(self) -> bool :
		from structure import Peripheral
		return len(self.template_reg_variants) > 0

	def define(self, defines: T.Dict[ChipSet, DefinesHandler]) :
		# defines the address
		super().define(defines)

		# defines the peripheral it has to be defined to
		if self.parent.needs_define :
			defines[self.chips].add(
				alias=super().defined_name,
				# defined_value=self.defined_value,
				define_not=False,
				undefine=True)

		#define the template if necessary
		templates = self.parent.get_template(self)
		remaining = self.chips.chips
		if len(templates) > 0 :
			for tmpl in templates :
				chips = self.chips if self.chips.chips.issubset(tmpl.chips.chips) \
						else ChipSet(self.chips.chips.intersection(tmpl.chips.chips))
				if chips not in defines :
					defines[chips] = DefinesHandler()

				if not chips.chips.issubset(remaining) :
					raise AssertionError("multiple templates defines in parallel for a single instance")
				remaining = remaining.difference(chips.chips)

				defines[chips].add(
					alias=f"{self.name}_TMPL",
					defined_value= tmpl.name,
					define_not=False,
					undefine=True
				)
		if len(templates) == 0 or len(list(remaining)) > 0 :
			chips = self.chips if len(templates) == 0 else ChipSet(remaining)
			if chips not in defines :
				defines[chips] = DefinesHandler()

			defines[chips].add(
				alias=f"{self.name}_TMPL",
				# no value (default template)
				define_not=False,
				undefine=True
			)


	def declaration_strings(self, indent : TabManager = TabManager()) -> str:
		out = ""
		class_name = self.parent.name
		if self.parent.has_template :
			if len(self.parent.get_template(self)) > 0 :
				class_name += f"<{self.name}_TMPL>"
			else :
				class_name += f"<>"
		# end if has_template

		normal_instance = str(indent + (
			0 if global_parameters.physical_mapping else 1)) + \
						  "volatile class {0} * const {1} = reinterpret_cast<class {0}* const>({2});\n" \
							  .format(class_name, self.name, self.defined_name)

		nophy_instance = (str(indent + 1) + "volatile class {0} * const {1} = new class {0}({2});\n")\
			.format(class_name, self.name, self.defined_name)

		if not global_parameters.physical_mapping :
			out += f"{indent}#if __SOOL_DEBUG_NOPHY\n" \
				   f"{nophy_instance}" \
				   f"{indent}#else\n" \
				   f"{normal_instance}" \
				   f"{indent}#endif\n"
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
				  f"{self.declaration_strings(indent)}" \
				  f"{indent-1}#endif\n"
			indent.decrement()
		else:
			out = self.declaration_strings(indent)
			if not global_parameters.physical_mapping :
				out += "\n"

		return out

	def generate_sql(self,cursor : sql.Cursor,parent_id : int):
		cursor.execute("INSERT INTO instances (name,address,periph_id) VALUES (:n,:a,:p)",
					   {"n":self.name,"p":parent_id,"a":self.address})
		this_id  = cursor.lastrowid
		chip_names = ','.join([f"'{x.name}'" for x in self.chips])
		cursor.execute(f"SELECT id FROM chips WHERE name IN ({chip_names}) ")
		result = cursor.fetchall()
		if result :
			data = [{"i":this_id,"c":c[0]} for c in result]
			cursor.executemany("INSERT INTO inst_chip (inst_id,chip_id) VALUES (:i,:c)",data)
		return this_id
