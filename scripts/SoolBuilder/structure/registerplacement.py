from structure import Component, ChipSet, Register, get_node_text, fill_periph_hole, TabManager
import typing as T
import xml.etree.ElementTree as ET


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

################################################################################
#                                  OPERATORS                                   #
################################################################################

	def __eq__(self, other) -> bool:
		if isinstance(other, RegisterPlacement) :
			return self.name == other.name and\
			       self.address == other.address and\
			       self.array_size == other.array_size and\
			       self.register.name == other.register.name and\
			       self.register.size == other.register.size
		else :
			return False

	def __cmp__(self, other) -> int:
		if isinstance(other, RegisterPlacement) :
			return self.address - other.address
		else :
			raise TypeError()
	def __lt__(self, other) -> bool:
		if isinstance(other, RegisterPlacement) :
			if self.address != other.address :
				return self.address < other.address
			else :
				return self.name < other.name
		else :
			raise TypeError()

	def __gt__(self, other) -> bool:
		if isinstance(other, RegisterPlacement) :
			if self.address != other.address :
				return self.address > other.address
			else :
				return self.name > other.name
		else :
			raise TypeError()

	@property
	def computed_size(self) -> int:
		return self.register.size * (1 if self.array_size == 0 else self.array_size)

################################################################################
#                               PLACE MANAGEMENT                               #
################################################################################

	def overlap(self, other: "RegisterPlacement"):
		if other.address < self.address :
			size = other.register.size *\
			       (1 if other.array_size == 0 else other.array_size)
			return other.address + size > self.address
		else : # self.address <= other.address
			size = (self.register.size/8) *\
			       (1 if self.array_size == 0 else self.array_size)
			return self.address + size > other.address

################################################################################
#                          DEFINE, UNDEFINE & DECLARE                          #
################################################################################
	@property
	def defined_value(self) -> T.Union[str, None]:
		template = "{1.name}_t {0.name}"
		if self.array_size > 0 :
			template += "[{0.array_size}]"
		return template.format(self, self.register)

	@property
	def define_not(self) -> str:
		return fill_periph_hole(int(self.computed_size/8), sep=";")

	def declare(self, indent: TabManager = TabManager()) -> T.Union[None, str] :
		out: str
		if self.needs_define :
			out = f"{indent}{self.defined_name};"
		else :
			out = f"{indent}{self.defined_value};"
		if self.brief is not None :
			out += f"/// {self.register.brief}"
		return out + "\n"
