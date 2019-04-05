from structure.Component import Component
from tools.utils import ChipSeriesManager


class PeripheralMapping(Component):
	def __init__(self, name: str, chips: ChipSeriesManager):
		super().__init__(name, chips)
