import string
from typing import List


class Chip :
	def __init__(self, name: str, svd: str, families: List[str]):
		self.name = name
		self.svd = svd
		self.families = families


class ChipSet :
	def __init__(self):
		self.chips: List[Chip] = list()

	def add_chips(self, chips: List[Chip]):
		self.chips.extend(chips)

	def add_chip(self, chip: Chip):
		self.chips.append(chip)