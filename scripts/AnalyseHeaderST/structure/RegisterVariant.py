from typing import List, Union, Dict, Tuple

from structure.Field import Field
from structure.Component import Component
from tools.utils import ChipSeriesManager

REG_VARIANT_TEMPLATE = """
#ifdef {0}
struct
{{
{1}
}};
#endif"""

REG_VARIANT_TEMPLATE_NO_IF = """
struct
{{
{0}
}};"""


class RegisterVariant(Component):
	"""
	The Register Variant component. It represents one of the possible bit mapping of the register.
	Its parent is the Register, and it contains Fields.
	"""

	def __init__(self, chips: ChipSeriesManager):
		super().__init__(None, chips)
		self.fields: List[Field] = list()
		""" list of the fields in this variant of the register"""
		self.id: int = -2
		""" id of the register variant. -2 : not specified yet. -1 : Only variant in register.
		 Other : number of the variant"""

	def alias(self):
		if self.id == -2:
			raise Exception(f"register variant of {self.parent} has not been finalized (id = -2)")
		if self.id == -1:
			return self.parent.alias()
		else:
			return f"{self.parent.alias()}_{self.id}"

	# ____________________________________________________________________________________________________________variant id

	def set_only_variant(self):
		"""
		Sets the variant to be the only one of the register
		:return: None
		"""
		self.id = -1

	def set_variant_id(self, num: int):
		"""
		Sets the variant id to the specified number
		:param num: the new variant id
		:return: None
		"""
		self.id = num

	# _________________________________________________________________________________________________fields, mask, fillers

	def mask(self) -> int:
		"""
		:return: the bit mask of the register variant
		"""
		mask: int = 0x00000000
		for field in self.fields:
			mask |= field.mask()
		return mask

	def has_room(self, field: Field) -> bool:
		"""
		:param field: the field to check room for
		:return: True if the specified field can fit in the register variant without overlapping other fields
		"""
		return self.mask() & field.mask() == 0

	def add_field(self, field: Field):
		"""
		Adds the specified field to the register variant
		:param field: the field to add
		:return: None
		"""
		self.fields.append(field)

	def place_fillers(self):
		"""
		Fills the holes in the register variant by placing unnamed fields to complete the mask.
		:return: None
		"""
		self.fields.sort(key=lambda f: f.pos)
		cursor = 0
		fillers: List[Field] = []
		reg_size = self.parent.size
		item_max_size = min(reg_size, 32)

		for field in self.fields:
			while field.pos > cursor:
				size = min(item_max_size, field.pos - cursor)
				fillers.append(Field(None, self.chips, cursor, size))
				cursor += size
			cursor = field.pos + field.size
		while reg_size > cursor:
			size = min(item_max_size, reg_size - cursor)
			fillers.append(Field(None, self.chips, cursor, size))
			cursor += size

		if len(fillers) > 0:
			for filler in fillers:
				self.add_field(filler)
				filler.finalize()
			self.fields.sort(key=lambda f: f.pos)

	# ________________________________________________________________________________________________________________output

	def finalize(self):
		self.place_fillers()
		cursor = 0
		for field in self.fields:
			self.chips.merge(field.chips)
			field.finalize()
			if field.pos < cursor:
				raise Exception(f"Fields overlap in register {self.alias()} at position {field.pos}")
			cursor = field.pos + field.size
		super().finalize()

	def declare(self) -> Union[str, None]:
		self.fields.sort(key=lambda f: f.pos)
		fields_out = '\t' + "\n\t".join(map(lambda f: f.declare(), self.fields))
		if self.id == -1:  # if this is the only variant, don't use structs, only content
			return fields_out
		elif self.defined:
			return REG_VARIANT_TEMPLATE.format(self.alias(), fields_out)
		else:
			return REG_VARIANT_TEMPLATE_NO_IF.format(fields_out)

	def define(self):
		return "#define {}".format(self.alias())

	def add_to_define_dict(self, define_dict: Dict[str, List[Tuple[str, str]]], undef: str):
		super().add_to_define_dict(define_dict, undef)
		for field in self.fields:
			field.add_to_define_dict(define_dict, undef)

	# _____________________________________________________________________________________________________________operators

	def __iter__(self):
		for field in self.fields:
			yield field

	def __getitem__(self, item: Union[str, int]):
		if type(item) == str:
			for field in self.fields:
				if field.name == item:
					return field
		elif type(item) == int:
			for field in self.fields:
				if field.pos == item:
					return field
		else:
			raise TypeError(f"argument of type {type(item)} is not of the right type.")

	def __eq__(self, other):
		if not super().__eq__(other):
			return False
		for field in self.fields:
			if field not in other.fields:
				return False
		return True
