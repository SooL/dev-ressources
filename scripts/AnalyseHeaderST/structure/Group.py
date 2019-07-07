from typing import List

from structure import Peripheral


class Group:
	def __init__(self, name):
		self.name = name
		self.peripherals: List[Peripheral] = list()

	def add_peripheral(self, peripheral):
		self.peripherals.append(peripheral)
