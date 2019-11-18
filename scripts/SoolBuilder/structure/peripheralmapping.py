from structure import Component, ChipSet, RegisterPlacement, fill_periph_hole, TabManager
import typing as T
import xml.etree.ElementTree as ET

class PeripheralMapping(Component) :
	def __init__(self, chips: T.Union[ChipSet, None] = None,
	             name: T.Union[str, None] = None) :
		super().__init__(chips=chips, name=name)

		self.register_placements: T.List[RegisterPlacement] = list()

################################################################################
#                                  OPERATORS                                   #
################################################################################
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
		if isinstance(item, str) :
			for x in self.register_placements :
				if x.name == item :
					return x
			raise KeyError()
		if isinstance(item,RegisterPlacement):
			for x in self.register_placements :
				if x == item :
					return x
			raise KeyError()
		raise TypeError()

	def __contains__(self, item):
		if isinstance(item, int):
			try :
				a = self[item]
				return True
			except KeyError :
				return False
		elif isinstance(item, str) :
			try :
				a = self[item]
				return True
			except KeyError :
				return False
		elif isinstance(item, RegisterPlacement) :
			return item in self.register_placements
		raise TypeError()

	@property
	def size(self):
		self.register_placements.sort()
		last = self.register_placements[-1]
		return last.address + last.size

################################################################################
#                        REGISTER PLACEMENTS MANAGEMENT                        #
################################################################################

	def compatible(self, other: "PeripheralMapping"):
		for reg_p in other :
			if reg_p.address in self :
				if self[reg_p.address] != reg_p :
					return False
			elif reg_p.name in self :
				return False
			elif not(self.has_room_for(reg_p)) :
				return False
		return True

	def has_room_for(self, reg_placement: RegisterPlacement) -> bool :
		for p in self.register_placements :
			if p.overlap(reg_placement) :
				return False
			elif p.name == reg_placement.name :
				return False
		return True

	def intra_svd_merge(self, other: "PeripheralMapping"):
		super().intra_svd_merge(other)
		for reg_p in other :
			self.add_register_placement(reg_p, True)

	def inter_svd_merge(self, other: "PeripheralMapping"):
		super().intra_svd_merge(other)
		for reg_p in other :
			self.add_register_placement(reg_p)

	def add_register_placement(self, reg_placement: RegisterPlacement, intra_svd: bool = False) :
		for reg_p in self :
			if reg_p == reg_placement :
				if intra_svd :
					reg_p.intra_svd_merge(reg_placement)
				else :
					reg_p.inter_svd_merge(reg_placement)
				return
			elif reg_p.name == reg_placement.name :
				raise AssertionError(
					f"Two different placements for {reg_p.name}: {reg_placement.address}, {reg_p.address}")

		self.register_placements.append(reg_placement)
		reg_placement.set_parent(self)
		self.edited = True

################################################################################
#                          DEFINE, UNDEFINE & DECLARE                          #
################################################################################

	def declare(self, indent: TabManager = TabManager()) -> str:
		out: str = ""
		pos: int = 0
		last_register : T.Optional[RegisterPlacement] = None
		# add struct and indent only if multiple mappings
		only_mapping: bool = len(self.parent.mappings) == 1
		if not only_mapping :
			out += f"{indent}struct\n{indent}{{\n"
			indent.increment()

		self.register_placements.sort()
		for reg_p in self.register_placements :
			if last_register is None or (reg_p.address + reg_p.size) > (last_register.address + last_register.size) :
				last_register = reg_p
			if reg_p.address > pos :
				# add filler
				out += fill_periph_hole(size=reg_p.address - pos, prefix=f"{indent}", sep=f";\n{indent}", suffix=";\n")
				pos += reg_p.address - pos
			out += reg_p.declare(indent)
			pos += int(reg_p.size/8)
		if not only_mapping :
			parent_size = self.parent.size
			if parent_size > pos *8 + last_register.size :
				# add filler
				out += fill_periph_hole(size=int(parent_size/8) - pos, prefix=f"{indent}", sep=f";\n{indent}", suffix=";\n")
			indent.decrement()
			out += f"{indent}}};\n"

		if self.needs_define :
			out = f"{indent}#ifdef {self.defined_name}\n" \
			      f"{out}" \
			       f"{indent}#endif\n"
		return out