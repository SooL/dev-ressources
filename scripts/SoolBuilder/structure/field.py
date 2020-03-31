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

import typing as T
import xml.etree.ElementTree as ET
from structure import ChipSet
from structure import Component
from structure import get_node_text, TabManager
from structure.utils import DefinesHandler


class Field(Component) :

################################################################################
#                                 CONSTRUCTORS                                 #
################################################################################

	@staticmethod
	def create_from_xml(chips: ChipSet, xml_data: ET.Element) -> "Field":
		name = get_node_text(xml_data, "name")
		descr = get_node_text(xml_data, "description")
		offset = int(get_node_text(xml_data, "bitOffset"), 0)
		width = int(get_node_text(xml_data, "bitWidth"), 0)
		field = Field(chips=chips, name=name, brief=descr,
		              position=offset, size=width)
		return field

	def __init__(self,
	             chips: T.Union[None, ChipSet] = None,
	             name: T.Union[None, str] = None,
	             brief: T.Union[None, str] = None,
	             position: int = 0,
	             size: int = 1
	             ) :
		super().__init__(chips=chips, name=name, brief=brief)
		self.position = position
		self._size = size

################################################################################
#                                  OPERATORS                                   #
################################################################################
	def __str__(self) :
		return super().__str__() + f" @{self.position}-{self.position + self.size - 1}"

	def __eq__(self, other):
		return isinstance(other, Field) and \
		       self.position == other.position and \
			   self.size == other.size and \
			   self.name == other.name
			   

	def __cmp__(self, other) -> int :
		if isinstance(other, Field) :
			return self.position - other.position
		else :
			raise TypeError()

	def __lt__(self, other) -> bool :
		if isinstance(other, Field) :
			return self.position < other.position
		else :
			raise TypeError()

	def __gt__(self, other) -> bool :
		if isinstance(other, Field) :
			return self.position > other.position
		else :
			raise TypeError()


	def __copy__(self) :
		return Field(chips=self.chips, name=self.name, brief=self.brief, position=self.position, size=self.size)

	@property
	def size(self) -> int :
		return self._size

	@size.setter
	def size(self, new_size: int) :
		self._size = new_size

################################################################################
#                                DEFINE AND USE                                #
################################################################################

	@property
	def defined_value(self) -> T.Union[str, None]:
		return self.name

	def declare(self, indent: TabManager = TabManager()) -> T.Union[None, str] :
		name = self.defined_name if self.needs_define else self.name
		if name is None :
			name = ""
		type_size = \
			self.parent.parent.size if self.parent.parent.size <= 32 else \
			32 if int(self.position/32) == int((self.position+self.size)/32) else \
			64
		out = f"{indent}uint{type_size}_t {name:16} : {self.size};"
		if self.brief is not None :
			out += f" /// {self.brief}"
		return out + "\n"

################################################################################
#                            BITWISE VERIFICATIONS                             #
################################################################################

	def overlap(self, other: "Field") :
		if other.position < self.position :
			return other.position + other.size > self.position
		elif self.position < other.position :
			return self.position + self.size > other.position
		else : # same position
			return True

	def fill_bit_mask(self, bit_mask: T.List[bool]):
		for i in range(self.position, self.position + self.size - 1) :
			bit_mask[i] = True
