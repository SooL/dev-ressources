from structure.Peripheral import Component
from tools.utils import ChipSeriesManager


class Field(Component):
	def __init__(self, name: str, chips: ChipSeriesManager, pos: int, size: int):
		Component.__init__(self, name, chips)
		self.pos: int = pos
		self.size: int = size

	def _define(self):
		return "#define {alias:20} {f.name:20} // {f.size} bits @ {f.pos}".format(
			alias=self.prefixed_name(),
			f=self)

	def _notDefined(self):
		return "#define {}".format(self.prefixed_name())

	def _undefine(self):
		return "#undef {}".format(self.prefixed_name())

	def need_def(self):
		return Component.need_def(self) and self.name is not None and len(self.name) > 0

	def use(self):
		# noinspection PyUnresolvedReferences
		return "uint{type_size}_t {name:20} :{bit_size};".format(
			type_size=min(self.parent.parent.size, 32),
			name=self.prefixed_name() if self.need_def() else self.name,
			bit_size=self.size)

	def finalize(self, full_chips):
		Component.finalize(self, full_chips)
		# noinspection PyUnresolvedReferences
		if self.pos < 0 or self.pos + self.size > self.parent.parent.size:
			raise Exception(
				"Field {0} does not fit in the register size : pos = {2.pos}, size = {2.size}, register size = {1.size}"
					.format(self.prefixed_name(), self.parent.parent, self))

	def __eq__(self, other):
		return isinstance(other, Field) and\
		       other.name == self.name and\
		       other.pos == self.pos and\
		       other.size == self.size
