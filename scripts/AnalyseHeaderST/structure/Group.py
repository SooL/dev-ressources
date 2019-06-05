from typing import List, Dict

from structure.Component import Component
from structure.Peripheral import Peripheral
from tools.utils import ChipSeriesManager


class Group(Component):
	def __init__(self, name: str, chips: ChipSeriesManager):
		super().__init__(name, chips)
		self.peripherals: List[Peripheral] = list()
