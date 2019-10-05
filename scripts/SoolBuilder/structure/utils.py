import xml.etree.ElementTree as ET
from typing import List, Union

from structure import ChipSet


def get_node_text(root : ET.Element, node : str) -> str :
	return str() if root.find(node) is None else root.find(node).text


class TabManager :
	def __init__(self):
		self.level : int = 0
		self.char : str = "\t"
		self.multiple: int = 1

	def __iadd__(self, other):
		if isinstance(other, int) :
			if self.level + other < 0 :
				raise ValueError("Tab level should always be positive or equal to zero")
			else :
				self.level += other
		else :
			raise TypeError("Can only add integers")

	def __isub__(self, other):
		self.__iadd__(-other)

	def __add__(self, other) -> str:
		if isinstance(other, int) :
			if self.level + other < 0:
				raise ValueError("Tab level should always be positive or equal to zero")
			else :
				return (self.level + other)*self.multiple*self.char
		else:
			raise TypeError("Can only add integers")

	def __sub__(self, other):
		return self.__add__(-other)

	def __str__(self):
		return self.level*self.multiple*self.char

	def increment(self):
		self.__iadd__(1)

	def decrement(self):
		self.__isub__(1)

	# def default(self):
	# 	if TabManager.std is None :
	# 		TabManager.std = self


default_tabmanager = TabManager()


class DefinesHandler :
	def __init__(self, chipSet: ChipSet):
		self.chipSet = chipSet

		self.defines: List[str] = list()
		self.not_defines: List[str] = list()
		self.undefines: List[str] = list()

	def add(self, alias, defined_value: Union[str, None] =None, define_not=True, undefine=True):
		if defined_value is not None :
			self.defines.append(alias + defined_value)
		else :
			self.defines.append(alias + defined_value)

		if define_not :
			self.not_defines.append(alias)

		if undefine :
			self.undefines.append(alias)

	def output_defines(self) :
		out: str = "#if\t"
		out += self.chipSet.defined_list().replace("\n", "\n\t")

		for define in self.defines :
			out += f"\n#define {define}"

		if len(self.not_defines) > 0 :
			out += "\n#else"
			for alias in self.not_defines :
				out += f"\n#define {alias}"

		return out

	def output_undef(self) :
		out: str = ""
		for undef in self.undefines :
			out += f"\n#undef {undef}"

		return out
