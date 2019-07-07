import string
from typing import List


class Chip :
	def __init__(self, name: string, svd: string, families: List[string]):
		self.name = name
		self.svd = svd
		self.families = families


class ChipSet :
	def __init__(self):
		self.chips: List[Chip] = list()

	def add_chips(self, chips: List[Chip]):
		self.chips.extend(chips)

