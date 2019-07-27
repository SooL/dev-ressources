import string
from typing import Union, List

from structure.Register import Register
from Jstructure import ChipSet


class PeripheralInstance:
	def __init__(self, name, address, chips):
		self.name = name
		self.address = address
		self.chips = chips
		self.parent = None

	def set_parent(self, parent):
		self.parent = parent


class Peripheral:
	def __init__(self, name: Union[None, str], chips: ChipSet):
		"""

		:param name: name of the field (or None)
		:param chips: chips for which the register is defined
		"""
		self.name = name
		self.parent = None
		self.chips = chips
		self.registers: List[Union[Register, Peripheral]] = list()
		self.instances: List[PeripheralInstance] = list()

	def set_parent(self, parent):
		self.parent = parent

	def add_register(self, register: Union[Register, "Peripheral"]):
		register.set_parent(self)
		self.registers.append(register)

	def add_instance(self, instance: PeripheralInstance):
		self.instances.append(instance)
