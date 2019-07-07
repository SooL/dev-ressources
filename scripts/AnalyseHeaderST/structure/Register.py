import string
from typing import Union

from structure import Field
from structure.ChipSet import ChipSet


class Register:
	def __init__(self, name: Union[None, str], offset: int, size: int, chips: ChipSet):
		"""

		:param name: name of the field (or None)
		:param offset: position (in bytes) from the position 0 of the register
		:param size: number of bytes used for this field in the register
		:param chips: chips for which the register is defined
		"""
		self.chips = chips
		self.name = name
		self.offset = offset
		self.size = size
		self.parent = None
		self.fields = []

	def set_parent(self, parent):
		self.parent = parent

	def add_field(self, field: Field):
		field.set_parent(self)
		self.fields.append(field)

