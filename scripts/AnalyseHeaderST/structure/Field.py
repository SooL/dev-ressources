from typing import Union

from structure.Component import Component
from tools.utils import ChipSeriesManager


class Field(Component):
	"""
	The Field component. Its parent is the RegisterVariant.
	"""

	def __init__(self, name: Union[None, str], chips: ChipSeriesManager, pos: int, size: int):
		super().__init__(name, chips)
		self.pos: int = pos
		"""position of the LSB in the register"""
		self.size: int = size
		"""number of bits used by the field"""

	def define(self):
		return super().define() + " {f.name:20} // {f.size} bits @ {f.pos}".format(f=self)

	def no_define(self):
		return f"#define {self.alias()}"

	def undefine(self):
		return f"#undef {self.alias()}"

	def need_define(self):
		return super().need_define() and self.name is not None and len(self.name) > 0

	def declare(self)->str:
		# noinspection PyUnresolvedReferences
		return "uint{type_size}_t {name:20} :{bit_size};{brief}".format(
			type_size=min(self.parent.parent.size, 32),
			name=self.alias() if self.defined else self.name,
			bit_size=self.size,
			brief="" if self.brief is None else f"\t//!<{self.brief}")

	def finalize(self):
		if self.parent is None:
			raise Exception(f"{self.name} as no parent")
		if self.pos < 0 or self.pos + self.size > self.parent.parent.size:
			raise Exception(
				"Field {0} does not fit in the register size :"
				" pos = {2.pos}, size = {2.size}, register size = {1.size}".format(
					self.alias(), self.parent.parent, self))
		super().finalize()

	def mask(self)->int:
		"""
		:return: the bit mask of the field
		"""
		return (0xFFFFFFFFFFFFFFFF >> (64-self.size)) << self.pos

	def __eq__(self, other):
		return super().__eq__(other) and other.pos == self.pos and other.size == self.size
