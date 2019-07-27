import string
from typing import Union

from Jstructure import ChipSet


class Field :
	def __init__(self, name: Union[None, str], offset: int, size: int, chips: ChipSet):
		"""

		:param name: name of the field (or None)
		:param offset: position (in bits) from the position 0 of the register
		:param size: number of bits used for this field in the register
		:param chips: chips for which the register is defined
		"""
		self.name = name
		self.offset = offset
		self.size = size
		self.parent = None
		self.chips = chips

	def set_parent(self, parent):
		self.parent = parent

