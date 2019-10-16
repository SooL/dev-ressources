import typing as T
import xml.etree.ElementTree as ET

from structure.Group import Group

from structure.Register import Register, RegisterPlacement
from structure.utils import get_node_text, TabManager
from structure.chipset import ChipSet
from structure.Component import Component


class Peripheral(Component) :

	@staticmethod
	def create_from_xml(chips: ChipSet, xml_data: ET.Element) -> "Peripheral" :

		brief: str = get_node_text(xml_data, "description")\
			.lower()\
			.replace("-", " ")\
			.replace("\n", " ")
		brief = " ".join(brief.split())

		periph =  Peripheral(chips=chips, name=None, brief=brief)

		# TODO fill peripheral with registers

		return periph

	def __init__(self, chips: T.Union[ChipSet, None] = None,
	             name: T.Union[str, None] = None,
	             brief: T.Union[str, None] = None) :
		super().__init__(chips=chips, name=name, brief=brief)
		self.group: Group = None
		self.registers: T.List[Register] = list()
		self.mappings: T.List[PeripheralMapping] = list()
		self.instances: T.List[PeripheralInstance] = list()
		self.max_size = 0

	def __getitem__(self, item: str) -> T.Union[Register, None] :
		for r in self.registers :
			if r.name == item :
				return r
		raise None

	def __contains__(self, item: str) -> bool :
		for r in self.registers :
			if r.name == item :
				return True
		raise False

	def add_register(self, reg: Register):
		self.chips.add(reg)
		self_reg = self[reg.name]
		if self_reg is not None :
			self_reg.merge(reg)
		else :
			self.registers.append(reg)

	def add_instance(self, instance: "PeripheralInstance") :
		self.chips.add(instance.chips)
		self.instances.append(instance)

	def place_register(self, reg_placement: RegisterPlacement) :
		mapping: T.Union[PeripheralMapping, None] = None
		for m in self.mappings :
			if m.has_room_for(reg_placement) :
				mapping = m
		if mapping is None :
			mapping = PeripheralMapping()
			self.mappings.append(mapping)

		mapping.place_register(reg_placement)

class PeripheralMapping(Component) :
	def __init__(self, chips: T.Union[ChipSet, None] = None,
	             name: T.Union[str, None] = None) :
		super().__init__(chips=chips, name=name)

		self.register_placements: T.List[RegisterPlacement] = list()

	def has_room_for(self, reg_placement: RegisterPlacement) -> bool :
		for p in self.register_placements :
			if p.overlap(reg_placement) :
				return False
		return True

	def fill_holes(self):
		pos: int = 0
		for p in self.register_placements :
			if p.address > pos :
				size = p.address - pos


	def finalize(self):
		for p in self.register_placements :
			p.set_parent(self)
			p.finalize()
		self.register_placements.sort(key= lambda p: p.address)
		pass


class PeripheralInstance(Component):
	def __init__(self, chips: T.Union[ChipSet, None] = None,
	             name: T.Union[str, None] = None,
	             brief: T.Union[str, None] = None,
	             address: T.Union[int, None] = None) :
		super().__init__(chips=chips, name=name, brief=brief)

		self.address = address

	def define(self) -> T.Union[str,None]:
		return f"#define {self.alias}_BASE_ADDR ({self.address:#08x})"

	def declare(self, indent: TabManager = TabManager()) -> T.Union[None,str] :
		out = "volatile class {0} * const {1} = reinterpret_cast<class {0}* const>({2:#08x});"\
			.format(self.parent.name, self.name, self.address)
		if self.needs_define() :
			out = "#ifdef {self.alias}_BASE_ADDR\n" + out + "\n#endif"

