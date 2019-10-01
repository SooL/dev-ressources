import xml.etree.ElementTree as ET


def get_node_text(root : ET.Element, node : str) -> str :
	return str() if root.find(node) is None else root.find(node).text


class TabManager :
	def __init__(self):
		self.level : int = 0
		self.char : str = "\t"
		self.multiple: int = 1

	def __iadd__(self, other):
		if isinstance(other,int) :
			if self.level + other < 0 :
				raise ValueError("Tab level should always be positive or equal to zero")
			else :
				self.level += other
		else :
			raise TypeError("Can only add integers")

	def __isub__(self, other):
		self.__iadd__(-other)

	def __add__(self, other) -> str:
		if isinstance(other,int) :
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