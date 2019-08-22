import string
from typing import List, Set, Union


class Chip :
	def __init__(self, name: str, svd: str, families: List[str]):
		self.name = name
		self.svd = svd
		self.families = families


class ChipSet :
	def __init__(self, chips=None):
		if chips is None:
			chips = set()
		self.chips: Set[Chip] = chips

	def __str__(self):
		return "\t".join(self.chips)
	
	def add(self, other: Union[List[Chip], 'ChipSet', Chip]):
		if isinstance(other, ChipSet) :
			self.chips.update(other.chips)
		elif isinstance(other, list) :
			self.chips.update(other)
		elif isinstance(other, Chip) :
			self.chips.add(other)
		else:
			raise TypeError
	
	def __iadd__(self, other: Union[List[Chip], 'ChipSet', Chip]):
		self.add(other)
	
	def __add__(self, other: Union[List[Chip], 'ChipSet', Chip]) -> 'ChipSet':
		ret: ChipSet = ChipSet(self.chips)
		ret.add(other)
		return ret