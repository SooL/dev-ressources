from structure import Peripheral
from structure.Component import Component
from tools.utils import ChipSeriesManager


class PeripheralInstance(Component):
	def __init__(self, name: str, chips: ChipSeriesManager, peripheral: Peripheral):
		super().__init__(name, chips)
		self.periph: Peripheral = peripheral
		self.interruption: int = None
