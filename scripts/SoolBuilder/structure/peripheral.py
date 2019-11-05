import typing as T
import xml.etree.ElementTree as ET
import logging
#from structure import Group

from structure import Register, RegisterPlacement
from structure import get_node_text, TabManager
from structure import ChipSet
from structure import Component

from cleaners import field_association_table, register_association_table
from structure.utils import DefinesHandler, fill_periph_hole

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
		elif isinstance(item, Register) :
			return item in self.registers
		elif isinstance(item, str) :
			for r in self.registers :
				if r.name == item :
					return True
			return False
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

	@property
	def alias(self) -> T.Union[None, str]:
		return self.name
	
	@property
	def computed_size(self):
		max_size: int = 0
		for m in self.mappings :
			size = m.computed_size
			if size > max_size :
				max_size = size
		return max_size

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

		reg_placement.register = self[reg_placement.register.name]
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

	def merge(self, other: "Peripheral") :
		for r in other.registers :
			self.add_register(r)
		for i in other.instances :
			self.add_instance(i)
		for m in other.mappings :
			for r_p in m :
				self.place_register(r_p)

		super().merge(other)

	def self_merge(self) :
		mapping_index = 0
		for r in self.registers :
			r.self_merge()

		while mapping_index < len(self.mappings) :
			mapping_offset = 1

			while mapping_index + mapping_offset < len(self.mappings) :
				if self.mappings[mapping_index].compatible(self.mappings[mapping_index + mapping_offset]) :
					self.mappings[mapping_index].merge(self.mappings[mapping_index + mapping_offset])
					self.mappings.pop(mapping_index + mapping_offset)
					continue
				else :
					mapping_offset += 1
			mapping_index += 1
		
		reg_idx = 0
		reg_offset = 0
		
		while reg_idx < len(self.registers) :
			reg_offset = 1
			while reg_idx + reg_offset < len(self.registers) :
				if self.registers[reg_idx].name == self.registers[reg_idx + reg_offset].name :
					self.registers[reg_idx].merge(self.registers[reg_idx + reg_offset])
					for mapping in self.mappings :
						for placement in mapping :
							if placement.register is self.registers[reg_idx + reg_offset] :
								placement.register = self.registers[reg_idx]
								self.registers[reg_idx].chips.add(placement.chips)
					self.registers.pop(reg_idx + reg_offset)
					continue
				else:
					reg_offset += 1
			reg_idx += 1
		

	def perform_name_rework(self) :
		"""
		Clean all name_edited flags and perform all name fixing tasks
		"""
		self.edited = False
		for reg in self.registers :
			reg.edited = False
			if self.name in register_association_table :
				reg_name = reg.name
				register_association_table[self.name](reg)
				# change register placements that had the register name before the fix
				if reg.name != reg_name :
					for m in self.mappings :
						for reg_p in m :
							if reg_p.register is reg and reg_p.name == reg_name:
								reg_p.name = reg.name

			for variant in reg.variants :
				variant.edited = False
				for field in variant.fields :
					field.edited = False
					if reg.name in field_association_table :
						field_association_table[reg.name](field,reg)

	def finalize(self):
		super().finalize()
		for i in self.instances :
			i.set_parent(self)
			i.finalize()

		map_idx: int = 0
		for m in self.mappings :
			m.set_parent(self)
			m.name = str(map_idx)
			map_idx += 1
			m.finalize()

	def declare(self, indent: TabManager = TabManager()) -> str:
		out =""
		if self.needs_define :
			out += f"#if {self.defined_name}\n"
		out += f"{indent}class {self.name}\n" \
		       f"{indent}{{\n"
		indent.increment()
		for reg in self.registers :
			out += reg.declare(indent)

		out += f"{indent}struct\n" \
		       f"{indent}{{\n"
		indent.increment()
		if len(self.mappings) > 1 :
			out += f"{indent}union\n" \
			       f"{indent}{{\n"
			indent.increment()
		for m in self.mappings :
			out += m.declare(indent)
		if len(self.mappings) > 1 :
			indent.decrement()
			out += f"{indent}}};\n"
		
		indent.decrement()
		out += f"{indent}}};\n"
		indent.decrement()
		out += f"{indent}}};\n"

		# Instances are declared after all classes of the group.
		# Instances declaration is handled in the 'cpp_output' method fo the class Group
		return out

	@property
	def defined_name(self) -> str :
		return self.alias if self.parent.alias is not None else f"PERIPH_{self.alias}"

	def define(self, defines: T.Dict[ChipSet, DefinesHandler]):
		super().define(defines)
		for mapping in self.mappings :
			mapping.define(defines)

	def define_instances(self,defines: T.Dict[ChipSet, DefinesHandler]):
		for instance in self.instances :
			instance.define(defines)

	def declare_instances(self, tab_manager : TabManager) -> str:
		out = ""
		virtual_instances: T.Dict[str, PeripheralInstance] = dict()
		for instance in self.instances:
			if instance.name in virtual_instances:
				virtual_instances[instance.name].chips.add(instance.chips)
			else:
				# The actual address is not relevant
				virtual_instances[instance.name] = PeripheralInstance(instance.chips, instance.name, instance.brief, 0)
				virtual_instances[instance.name].parent = self
				virtual_instances[instance.name].force_define = False

		for i in sorted(virtual_instances.keys()):
			out += virtual_instances[i].declare(tab_manager)
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

	@property
	def computed_size(self):
		self.register_placements.sort()
		last = self.register_placements[-1]
		return last.address + int(last.computed_size/4)

	def merge(self, other: "PeripheralMapping"):
		for reg_p in other :
			self.place_register(reg_p)

	def compatible(self, other: "PeripheralMapping"):
		for reg_p in other :
			if reg_p.address in self :
				if self[reg_p.address] != reg_p :
					return False
			elif not(self.has_room_for(reg_p)) :
				return False
		return True

	def has_room_for(self, reg_placement: RegisterPlacement) -> bool :
		for p in self.register_placements :
			if p.overlap(reg_placement) :
				return False
		return True

	def place_register(self, reg_placement: RegisterPlacement) :
		for reg_p in self :
			if reg_p == reg_placement :
				reg_p.merge(reg_placement)
				return
		self.register_placements.append(reg_placement)
		self.chips.add(reg_placement.chips)

	def finalize(self):
		self.register_placements.sort()
		for reg_p in self.register_placements :
			reg_p.finalize()
		super().finalize()

	def declare(self, indent: TabManager = TabManager()) -> str:
		out: str = ""
		pos: int = 0
		last_register : RegisterPlacement = None
		# add struct and indent only if multiple mappings
		only_mapping: bool = len(self.parent.mappings) == 1
		if not only_mapping :
			out += f"{indent}struct\n{indent}{{\n"
			indent.increment()
		for reg_p in self.register_placements :
			if last_register is None or (reg_p.address + reg_p.computed_size) > (last_register.address + last_register.computed_size) :
				last_register = reg_p
			if reg_p.address > pos :
				# add filler
				out += fill_periph_hole(size=reg_p.address - pos, prefix=f"{indent}", sep=f";\n{indent}", suffix=";\n")
				pos += reg_p.address - pos
			out += reg_p.declare(indent)
			pos += int(reg_p.computed_size/8)
		if not only_mapping :
			parent_size = self.parent.computed_size
			if parent_size > pos *8 + last_register.computed_size :
				# add filler
				out += fill_periph_hole(size=int(parent_size/8) - pos, prefix=f"{indent}", sep=f";\n{indent}", suffix=";\n")
			indent.decrement()
			out += f"{indent}}};\n"

		if self.needs_define :
			out = f"#ifdef {self.defined_name}\n" \
			      f"{out}" \
			       "#endif\n"
		return out

class PeripheralInstance(Component):
	def __init__(self, chips: T.Union[ChipSet, None] = None,
	             name: T.Union[str, None] = None,
	             brief: T.Union[str, None] = None,
	             address: T.Union[int, None] = None) :
		super().__init__(chips=chips, name=name, brief=brief)

		self.address = address
		self.force_define = True

	def __eq__(self, other):
		return isinstance(other, PeripheralInstance) and \
		       self.name == other.name and \
		       self.address == other.address

	@property
	def undefine(self) -> bool:
		return False

	@property
	def defined_value(self) -> T.Union[str, None]:
		return f"{self.address:#08x}"

	@property
	def define_not(self) -> T.Union[bool, str] :
		return False

	@property
	def defined_name(self) -> str :
		return f"{self.name}_BASE_ADDR"

	def declare(self, indent: TabManager = TabManager()) -> T.Union[None,str] :
		out = "volatile class {0} * const {1} = reinterpret_cast<class {0}* const>({2});\n"\
			.format(self.parent.name, self.name, self.defined_name)
		if self.needs_define :
			out = f"\n#ifdef {self.defined_name}\n{out}#endif\n"

		return out

