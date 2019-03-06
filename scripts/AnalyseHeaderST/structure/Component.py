from copy import copy
from typing import Union, Dict, List, Tuple

from tools.utils import ChipSeriesManager


class Component:
	"""
	the base class of Field, Register and Peripheral
	"""
	def __init__(self, name: Union[None,str], chips: ChipSeriesManager):
		"""
		:param name: name of the component
		:param chips: list of chips that have this specific component
		"""
		self.name: str = copy(name)
		self.chips: ChipSeriesManager = ChipSeriesManager(chips.chip_list)
		self.parent: "Component" = None

	def set_parent(self, parent: "Component"):
		if self.parent is not None:
			raise Exception(
				"{0} {1.name} already has a parent: {2.name}. parent {3.name} cannot be added".format(
					type(self), self, self.parent, parent)
			)
		else :
			self.parent = parent

	def finalize(self, full_chips):
		"""
		called before out file generation. Check possible mistakes, optimise imports and do all necessary stuff
		:return:
		"""
		from structure.Peripheral import Peripheral
		if (not isinstance(self, Peripheral)) and self.parent is None:
			raise Exception("{0} {1.name} does not have a parent".format(type(self), self))

		self.chips.build_chip_family()
		full_chips.simplify(self.chips)

	def _define(self):
		"""
		returns the line used to define the component when it needs to be defined
		"""
		return ""

	def _notDefined(self):
		"""
		returns the line used to define the component when it needs to be absent
		"""
		return ""

	def _undefine(self):
		"""
		returns the line used to undefined the previously defined preprocessor constant
		"""
		return ""

	def need_def(self):
		return (not self.chips.is_empty()) and (not self.chips.is_all_chips()) and (self.parent is None or self.parent.chips != self.chips)

	def define_key(self):
		return self.chips.output_ifdef_template()

	def define_output(self, dictionary: Dict[str,List[Tuple[str, str, str]]]):
		"""
		fills the dictionary with

		#define (defined value),
		#define (not-defined value),
		#undef

		only if the parent chips is not the same as this component's chips
		:param dictionary:
		:return:
		"""
		if self.need_def():
			key = self.define_key()

			if key not in dictionary:
				dictionary[key] = list()

			dictionary[key].append((self._define(), self._notDefined(), self._undefine()))
	def use(self):
		"""
		called by the parent component when it want to use this component
		"""
		return ""

	def declare(self):
		"""
		Declare the component before using it
		"""
		return ""

	def prefixed_name(self):
		if self.parent is None:
			return self.name
		elif self.name is None or len(self.name) == 0:
			return self.parent.prefixed_name()
		else :
			return self.parent.prefixed_name() + "_" + self.name

