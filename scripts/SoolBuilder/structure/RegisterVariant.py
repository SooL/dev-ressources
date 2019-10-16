import typing as T

from structure.utils import TabManager
from structure.Field import Field
from structure.chipset import ChipSet
from structure.Component import Component

REG_VAR_DECLARATION : str = """{indent}struct
{indent}{{
{fields}
{indent}}};"""

class RegisterVariant(Component) :
	def __init__(self, chips: T.Union[None, ChipSet] = None) :
		super().__init__(chips=chips)
		self.fields : T.List[Field] = list()


	def __contains__(self, item) :
		if isinstance(item, Field) :
			if item in self.fields :
				return True
		return False

	def __getitem__(self, item):
		if isinstance(item, str):
			for field in self.fields :
				if field.name == item :
					return field
		else :
			raise TypeError()
################################################################################
#                                DEFINE AND USE                                #
################################################################################

	def define(self) -> T.Union[str,None] :
		if self.needs_define() :
			return f"#define {self.alias}"
		else :
			return None

	def define_not(self) -> T.Union[str, None] :
		return None

	def declare(self, indent: TabManager = TabManager()) -> T.Union[None,str] :
		if len(self.parent.variants) == 1 :
			return "\n".join(
			map(lambda f : f.declare(indent=indent), self.fields))
		else :
			indent.increment()
			fields_declaration = "\n".join(
				map(lambda f : f.declare(indent= indent), self.fields))
			indent.decrement()
			out = REG_VAR_DECLARATION.format(indent= indent, fields= fields_declaration)

		if self.needs_define() :
			out += f"#ifdef {self.alias}\n" + out + "\n#endif"
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
				fillers.append(Field(position = pos, size = f.position-pos))
			pos = f.position + f.size

		self.fields.extend(fillers)
		self.sort_fields()

	def finalize(self):
		for f in self.fields :
			f.set_parent(self)
		self.sort_fields()
		self.fill_holes()
		if len(self.parent.variants) > 1 :
			self.name = str(self.parent.variants.index(self))
		pass
