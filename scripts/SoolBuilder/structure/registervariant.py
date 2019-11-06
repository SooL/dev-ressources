import typing as T

from structure import TabManager
from structure import Field
from structure import ChipSet
from structure import Component

REG_VAR_DECLARATION : str = """{indent}struct
{indent}{{
{fields}{indent}}};
"""

class RegisterVariant(Component) :
	def __init__(self, chips: T.Union[None, ChipSet] = None) :
		super().__init__(chips=chips)
		self.fields : T.List[Field] = list()

	def __iter__(self):
		return iter(self.fields)

	def __contains__(self, item):
		if isinstance(item, str) :
			for f in self :
				if f.name == item :
					return True
			return False
		elif isinstance(item, Field) :
			for f in self :
				if f == item :
					return True
			return False

	def __getitem__(self, item):
		if isinstance(item, str) :
			for f in self :
				if f.name == item :
					return f
			raise KeyError()
		elif isinstance(item, Field) :
			for f in self :
				if f == item :
					return f
			raise KeyError()
		elif isinstance(item, int) :
			for f in self :
				if f.position == item :
					return f
			raise KeyError()
		else :
			raise KeyError()

	def __eq__(self, other):
		if not(isinstance(other, RegisterVariant)) : return False

		s_len = len(self.fields)
		o_len = len(other.fields)
		if s_len != o_len : return False

		self.sort_fields()
		other.sort_fields()
		for i in range(0, s_len) :
			if self.fields[i] != other.fields[i] : return False

		return True

################################################################################
#                                DEFINE AND USE                                #
################################################################################

	# define is the same as parent class : only alias, if needed

	def declare(self, indent: TabManager = TabManager()) -> T.Union[None,str] :
		if len(self.parent.variants) == 1 :
			return "".join(
			map(lambda f : f.declare(indent=indent), self.fields))
		else :
			indent.increment()
			fields_declaration = "".join(
				map(lambda f : f.declare(indent= indent), self.fields))
			indent.decrement()
			out = REG_VAR_DECLARATION.format(indent= indent, fields= fields_declaration)

		if self.needs_define :
			out = f"{indent}#ifdef {self.defined_name}\n{out}{indent}#endif\n"
		return out

################################################################################
#                              FIELDS MANAGEMENT                               #
################################################################################

	def has_room_for(self, field: Field) :
		for f in self.fields :
			if f.overlap(field) :
				return False
		return True

	def add_field(self, field: Field) :
		self.fields.append(field)
		self.chips.add(field.chips)

	def sort_fields(self):
		self.fields.sort(key=(lambda f: f.position))

	def merge(self, other: "RegisterVariant") :
		raise AssertionError("the merge method should not be called on RegisterVariant")

	def fill_holes(self):
		"""
		Fills the holes in the bitfield by creating unnamed fields.
		Needs the fields to be sorted by position
		Called by the 'finalize' method.
		"""
		pos: int = 0
		fillers: T.List[Field] = list()
		for f in self.fields :
			if f.position > pos :
				fillers.append(Field(position = pos, size = f.position - pos))
			pos = f.position + f.size
		if pos < self.parent.size :
			fillers.append(Field(position=pos, size = f.parent.size - pos))
		self.fields.extend(fillers)
		self.sort_fields()

	def finalize(self):
		self.sort_fields()
		self.fill_holes()
		if len(self.parent.variants) > 1 :
			self.name = str(self.parent.variants.index(self))
		super().finalize()
