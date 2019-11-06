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
		self.size = size

################################################################################
#                                  OPERATORS                                   #
################################################################################
	def __str__(self) :
		return super().__str__() + f" @{self.position}-{self.position + self.size - 1}"

	def __eq__(self, other):
		return isinstance(other, Field) and \
		       self.name == other.name and \
		       self.position == other.position and \
			   self.size == other.size

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

	# def finalize(self):
	# 	pass
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
		return f"{indent}uint{min(self.parent.parent.size, 64)}_t {name} : {self.size};\n"

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
