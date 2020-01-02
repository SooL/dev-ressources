from structure import Component, ChipSet, MappingElement, fill_periph_hole, TabManager, Register
import typing as T
import xml.etree.ElementTree as ET

class PeripheralMapping(Component) :
	def __init__(self, chips: T.Union[ChipSet, None] = None,
	             name: T.Union[str, None] = None) :
		super().__init__(chips=chips, name=name)

		self.elements: T.List[MappingElement] = list()

################################################################################
#                                  OPERATORS                                   #
################################################################################
	def __iter__(self):
		return iter(self.elements)

	def __eq__(self, other):
		if not(isinstance(other, PeripheralMapping)):
			return False
		if len(self.elements) != len(other.elements) :
			return False
		for elmt in self :
			if elmt not in other :
				return False
		return True

	def __getitem__(self, item):
		if isinstance(item,int):
			for x in self.elements :
				if x.address == item :
					return x
			raise KeyError()
		if isinstance(item, str) :
			for x in self.elements :
				if x.name == item :
					return x
			raise KeyError()
		if isinstance(item, MappingElement):
			for x in self.elements :
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
		elif isinstance(item, MappingElement) :
			return item in self.elements
		raise TypeError()

	@property
	def size(self):
		self.elements.sort()
		last = self.elements[-1]
		return last.address*8 + last.size

################################################################################
#                        REGISTER PLACEMENTS MANAGEMENT                        #
################################################################################

	def compatible(self, other: "PeripheralMapping"):
		for elmt in other :
			if elmt.address in self :
				if self[elmt.address] != elmt :
					return False
			elif elmt.name in self :
				return False
			elif not(self.has_room_for(elmt)) :
				return False
		return True

	def has_room_for(self, element: MappingElement) -> bool :
		for p in self.elements :
			if p.overlap(element) :
				return False
			elif p.name == element.name :
				return False
		return True

	def intra_svd_merge(self, other: "PeripheralMapping"):
		super().intra_svd_merge(other)
		for elmt in other :
			self.add_element(elmt, True)

	def inter_svd_merge(self, other: "PeripheralMapping"):
		super().intra_svd_merge(other)
		for elmt in other :
			self.add_element(elmt)

	def add_element(self, element: MappingElement, intra_svd: bool = False) :
		for elmt in self :
			if elmt == element :
				if intra_svd :
					elmt.intra_svd_merge(element)
				else :
					elmt.inter_svd_merge(element)
				return
			elif elmt.name == element.name :
				raise AssertionError(
					f"Two different placements for {elmt.name}: {element.address}, {elmt.address}")

		self.elements.append(element)
		element.set_parent(self)
		self.edited = True

	def remove_elements_for(self, reg: Register) :
		i = 0
		while i < len(self.elements) :
			if self.elements[i].component is reg :
				self.elements.pop(i)
			else :
				i+=1

	def remove_element(self, element: MappingElement):
		idx = self.elements.index(element)
		if idx >= 0 :
			self.elements.pop(idx)

	def after_svd_compile(self, parent_corrector):
		super().after_svd_compile(parent_corrector)
		reg_dict: T.Dict[str, T.List[MappingElement]] = dict()
		for reg in self.parent :
			reg_dict[reg.name] = list()

		for elmt in self :
			reg_dict[elmt.component.name].append(elmt)

		for reg_name in reg_dict :
			elmts = reg_dict[reg_name]
			if len(elmts) > 1 :
				""
				# array might be possible
				# TODO create array

	def finalize(self):
		self.chips = self.computed_chips


################################################################################
#                          DEFINE, UNDEFINE & DECLARE                          #
################################################################################

	def declare(self, indent: TabManager = TabManager()) -> str:
		out: str = ""
		pos: int = 0
		last_register : T.Optional[MappingElement] = None
		# add struct and indent only if multiple mappings
		only_mapping: bool = len(self.parent.mappings) == 1
		if not only_mapping :
			out += f"{indent}struct\n{indent}{{\n"
			indent.increment()

		self.elements.sort()
		for elmt in self.elements :
			if last_register is None or (elmt.address + elmt.byte_size) > (last_register.address + last_register.byte_size) :
				last_register = elmt
			if elmt.address > pos :
				# add filler
				out += fill_periph_hole(size=elmt.address - pos, prefix=f"{indent}", sep=f";\n{indent}", suffix=";\n")
				pos += elmt.address - pos
			out += elmt.declare(indent)
			pos += elmt.byte_size
		if not only_mapping :
			parent_size = self.parent.byte_size
			if parent_size > pos:
				# add filler
				out += fill_periph_hole(size=parent_size - pos, prefix=f"{indent}", sep=f";\n{indent}", suffix=";\n")
			indent.decrement()
			out += f"{indent}}};\n"

		if self.needs_define :
			out = f"{indent}#ifdef {self.defined_name}\n" \
			      f"{out}" \
			      f"{indent}#endif\n"
		return out