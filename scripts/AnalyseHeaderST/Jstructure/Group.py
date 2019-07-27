from typing import List

#from structure import Peripheral
from Jstructure import Peripheral


class Group:
	def __init__(self, name):
		self.name = name
		self.peripherals: List[Peripheral] = list()

	def add_peripheral(self, peripheral):
		self.peripherals.append(peripheral)
		if peripheral.group is None:
			peripheral.group = self
		elif peripheral.group != self:
			raise AssertionError()
		
	def __str__(self):
		return self.name
