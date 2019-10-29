import typing as T
import xml.etree.ElementTree as ET

#from structure import Group

from structure import Register, RegisterPlacement
from structure import get_node_text, TabManager
from structure import ChipSet
from structure import Component


class Peripheral(Component) :

	@staticmethod
	def create_from_xml(chips: ChipSet, xml_data: ET.Element) -> "Peripheral" :

		brief: str = get_node_text(xml_data, "description")\
			.lower()\
			.replace("-", " ")\
			.replace("\n", " ")
		brief = " ".join(brief.split())

		periph =  Peripheral(chips=chips, name=None, brief=brief)

		for xml_reg in xml_data.findall("registers/register") :
			new_register = Register.create_from_xml(chips, xml_reg)
			periph.add_register(new_register)

			pos = int(get_node_text(xml_reg, "addressOffset"), 0)
			reg_placement = RegisterPlacement(chips=chips, name=new_register.name, register=new_register, address=pos)
			periph.place_register(reg_placement)

		return periph

	def __init__(self, chips: T.Union[ChipSet, None] = None,
	             name: T.Union[str, None] = None,
	             brief: T.Union[str, None] = None) :
		super().__init__(chips=chips, name=name, brief=brief)

		self.registers: T.List[Register] = list()
		self.mappings: T.List[PeripheralMapping] = list()
		self.instances: T.List[PeripheralInstance] = list()
		self.max_size = 0

	def __iter__(self):
		return iter(self.registers)

	def __eq__(self, other):
		if isinstance(other, Peripheral) :
			return (self.name == other.name and
					self.brief == other.brief and
					self.mapping_equivalent_to(other))

		elif isinstance(other, str) :
			return other == self.name
		else :
			raise TypeError()

	def add_register(self, reg: Register):
		self.chips.add(reg.chips)
		self_reg = self[reg.name]
		if self_reg is not None :
			self_reg.merge(reg)
		else :
			self.registers.append(reg)

	def add_instance(self, instance: "PeripheralInstance") :
		self.chips.add(instance.chips)
		for i in self.instances :
			if i == instance :
				i.merge(instance)
				return
		self.instances.append(instance)

	def place_register(self, reg_placement: RegisterPlacement) :
		mapping: T.Union[PeripheralMapping, None] = None
		for m in self.mappings :
			if reg_placement in m :
				m[reg_placement.name].merge(reg_placement)
				return
			elif m.has_room_for(reg_placement) :
				mapping = m
		if mapping is None :
			mapping = PeripheralMapping()
			self.mappings.append(mapping)
		mapping.place_register(reg_placement)

	def merge(self, other: "Peripheral"):
		for r in other.registers :
			self.add_register(r)
		for i in other.instances :
			self.add_instance(i)
		for m in other.mappings :
			for r_p in m :
				self.place_register(r_p)

		super().merge(other)

	def finalize(self):
		super().finalize()
		for i in self.instances :
			i.finalize()
		for m in self.mappings :
			m.finalize()

class PeripheralMapping(Component) :
	def __init__(self, chips: T.Union[ChipSet, None] = None,
	             name: T.Union[str, None] = None) :
		super().__init__(chips=chips, name=name)

		self.register_placements: T.List[RegisterPlacement] = list()

	def __iter__(self):
		return iter(self.register_placements)

	def __eq__(self, other):
		if not(isinstance(other, PeripheralMapping)):
			return False
		if len(self.register_placements) != len(other.register_placements) :
			return False
		for reg_p in self :
			if reg_p not in other :
				return False
		return True

	def merge(self, other: "PeripheralMapping"):
		raise AssertionError("the merge method should not be called on PeripheralMapping")

	def has_room_for(self, reg_placement: RegisterPlacement) -> bool :
		for p in self.register_placements :
			if p.overlap(reg_placement) :
				return False
		return True
	def place_register(self, reg_placement: RegisterPlacement) :
		self.register_placements.append(reg_placement)

	def finalize(self):
		self.register_placements.sort(key= lambda p: p.address)
		super().finalize()

	def declare(self, indent: TabManager = TabManager()) -> str:
		out: str = ""
		pos: int = 0
		# add struct and indent if multiple mappings
		only_mapping: bool = len(self.parent.mappings) == 1
		if not only_mapping :
			out += f"{indent}struct\n{indent}{{"
			indent.increment()
		for reg_p in self.register_placements :
			if reg_p.address > pos :
				# add filler
				size: int = 1
				while pos < reg_p.address :
					if (reg_p.address - pos) % (size+1) != 0 :
						out += f"\n{indent}__SOOL_PERIPH_PADDING_{size};"
						pos += size
					size *= 2
			out += reg_p.declare(indent)
			pos += reg_p.computed_size
		if not only_mapping :
			parent_size = self.parent.computed_size
			if parent_size > pos :
				size: int = 1
				while pos < parent_size :
					if (parent_size - pos) % (size+1) != 0 :
						out += f"\n{indent}__SOOL_PERIPH_PADDING_{size};"
						pos += size
					size *= 2
			indent.decrement()
			out += f"\n{indent}}}"

		return out





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

