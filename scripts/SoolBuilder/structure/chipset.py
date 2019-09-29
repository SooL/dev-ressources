from fnmatch import fnmatch
from typing import List, Set, Union


class Chip :
	def __init__(self, name: str, svd: str, families: List[str] = list()):
		self.name = name
		self.svd = svd
		self.families : List[str] = families

	def __str__(self):
		return self.name

	def __repr__(self):
		return str(self.name)

	def match(self,pattern):
		return fnmatch(self.name, pattern)

class ChipSet :
	def __init__(self, chips=None):
		if chips is None:
			chips = set()
		self.chips: Set[Chip] = set()
		self.add(chips)

	def __str__(self):
		return "\t".join(sorted([str(x) for x in self.chips]))
	
	def add(self, other: Union[List[Chip],Set[Chip], 'ChipSet', Chip]):
		if isinstance(other, ChipSet) :
			self.chips.update(other.chips)
		elif isinstance(other, list) :
			self.chips.update(other)
		elif isinstance(other,set) :
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

	def match(self,pattern):
		for chip in self.chips :
			if fnmatch(str(chip), pattern) :
				return True
		return False