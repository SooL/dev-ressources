import typing as T
import xml.etree.ElementTree as ET
import logging
#from structure import Group

from structure import Register, RegisterPlacement
from structure import get_node_text, TabManager
from structure import ChipSet
from structure import Component

from cleaners import field_association_table, register_association_table

logger = logging.getLogger()

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

	def __contains__(self, item) -> bool:
		if isinstance(item,PeripheralMapping) :
			return item in self.mappings
		raise ValueError()

	def __getitem__(self, item) -> Register:
		if isinstance(item,Register) :
			for reg in self :
				if reg == item :
					return reg
			raise KeyError()
		if isinstance(item,str):
			for reg in self :
				if reg.name == item:
					return reg
			raise KeyError()
		raise TypeError()

	def add_register(self, reg: Register):
		self.chips.add(reg.chips)
		try :
			self_reg = self[reg.name]
			self_reg.merge(reg)
		except KeyError :
			self.registers.append(reg)

	def add_instance(self, other: "PeripheralInstance") :
		if isinstance(other, PeripheralInstance) :
			self.chips.add(other.chips)

			for i in self.instances :
				if i == other :
					i.merge(other)
					return
			other.parent = self
			self.instances.append(other)
		else:
			raise TypeError(f"Expected a peripheral instance. Got {type(other)}.")

	def add_instances(self, other :  T.Union[T.List["PeripheralInstance"], "Peripheral"]):
		if isinstance(other, Peripheral) :
			for inst in other.instances :
				self.add_instance(inst)
		elif isinstance(other,list) :
			for inst in other :
				self.add_instance(inst)
		else :
			raise TypeError(f"Expected a peripheral instances list or peripheral. Got {type(other)}.")

	def place_register(self, reg_placement: RegisterPlacement) :
		mapping: T.Union[PeripheralMapping, None] = None
		for m in self.mappings :
			if reg_placement in m :
				m[reg_placement].merge(reg_placement)
				return
			elif m.has_room_for(reg_placement) :
				mapping = m
		if mapping is None :
			mapping = PeripheralMapping()
			mapping.parent = self
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

	def self_merge(self):
		mapping_index = 0
		for var in self.mappings:
			var.simplify_registers()

		while mapping_index < len(self.mappings):
			mapping_offset = 1

			while mapping_index + mapping_offset < len(self.mappings):
				if self.mappings[mapping_index].merge_mapping(self.mappings[mapping_index + mapping_offset]):
					self.mappings.pop(mapping_index + mapping_offset)
					continue
				else:
					mapping_offset += 1
			mapping_index += 1

	def perform_name_rework(self):
		"""
		Clean all name_edited flags and perform all name fixing tasks
		"""
		self.edited = False
		for reg in self.registers :
			reg.edited = False

			for variant in reg.variants :
				variant.edited = False
				for field in variant.fields :
					field.edited = False
					if reg.name in field_association_table :
						field_association_table[reg.name](field,reg)

	def finalize(self):
		super().finalize()
		for i in self.instances :
			i.finalize()
		for m in self.mappings :
			m.finalize()


	def declare(self, indent: TabManager = TabManager()) -> str:
		out =""
		for map in self.mappings :
			out += map.declare(indent)
		return out


	def mapping_equivalent_to(self,other : "Peripheral") -> bool :
		"""
		This function will check if the current peripheral have a mapping equivalent to the other one.
		As of right now it does not check if mappings are compatible but if an equal mapping is present in other.

		:param other: The other peripheral
		:return:
		"""
		for map in self.mappings :
			if map not in other :
				return False
		return True



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

	def __getitem__(self, item):
		if isinstance(item,int):
			for x in self.register_placements :
				if x.address == item :
					return x
			raise KeyError()
		if isinstance(item,RegisterPlacement):
			for x in self.register_placements :
				if x == item :
					return x
			raise KeyError()
		raise TypeError()

	def __contains__(self, item):
		if isinstance(item,int):
			try :
				a = self[item]
				return True
			except KeyError :
				return False
		if isinstance(item,RegisterPlacement) :
			return item in self.register_placements
		raise TypeError()

	def merge(self, other: "PeripheralMapping"):
		raise AssertionError("the merge method should not be called on PeripheralMapping")

	def merge_mapping(self, other: "PeripheralMapping") -> bool:
		# TODO Use as merge ?
		"""
		This function will merge the other mapping into the current one if
		the other one can fit within the current one. That is either :

		 - Same register name at same position
		 - Hole in the current register to be filled by other.

		This function will not edit anything unless the merge is possible.

		:param other: mapping to merge to the current one.
		:return: True if merged ok, false otherwise
		"""
		other_mapping = [(x.address, x.register) for x in other.register_placements]
		addr: int
		reg : Register
		for (addr, reg) in other_mapping:
			if addr in self:
				local_reg : Register = self[addr].register
				if reg.name != local_reg.name:
					if reg == local_reg:
						local_name = local_reg.name
						other_name = reg.name
						new_name = local_name if len(local_name) <= len(other_name) else other_name
						logger.warning(f"Fixing register name : same mapping for various names in "
									   f"{self.parent.name:10s}. Local : {local_name:15s} - Other : {other_name:15s}")
						local_reg.name = new_name
						reg.name = new_name
					else:
						return False

		for placement in other:
			if placement.address in self:
				self[placement.address].register.merge(placement.register)
			else:
				self.place_register(placement)
		self.chips.add(other.chips)

		return True

	def has_room_for(self, reg_placement: RegisterPlacement) -> bool :
		for p in self.register_placements :
			if p.overlap(reg_placement) :
				return False
		return True

	def simplify_registers(self):
		for register in [x.register for x in self.register_placements] :
			register.self_merge()

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

	# def finalize(self):
	# 	pass

	def define(self) -> T.Union[str,None]:
		return f"#define {self.alias}_BASE_ADDR ({self.address:#08x})"

	def declare(self, indent: TabManager = TabManager()) -> T.Union[None,str] :
		out = "volatile class {0} * const {1} = reinterpret_cast<class {0}* const>({2:#08x});"\
			.format(self.parent.name, self.name, self.address)
		if self.needs_define() :
			out = "#ifdef {self.alias}_BASE_ADDR\n" + out + "\n#endif"

		return out

