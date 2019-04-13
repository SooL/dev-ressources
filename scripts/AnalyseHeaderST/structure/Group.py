from typing import List, Dict

from AnalyseHeaderST.structure.Component import Component
from AnalyseHeaderST.structure.Peripheral import Peripheral
from AnalyseHeaderST.tools.utils import ChipSeriesManager


class Group(Component):
	def __init__(self, name: str, chips: ChipSeriesManager):
		super().__init__(name, chips)
		self.peripherals: List[Peripheral] = list()
