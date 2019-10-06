from fnmatch import fnmatch
from functools import reduce
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

	def match(self, pattern):
		return fnmatch(self.name, pattern)

class ChipSet :
	reference_chips_name_list : Set[str] = set()
	def __init__(self, chips=None):
		if chips is None:
			chips = set()
		self.chips: Set[Chip] = set()
		self.add(chips)

	def __str__(self):
		return "\t".join(sorted([str(x) for x in self.chips]))

	def __iadd__(self, other: Union[List[Chip], 'ChipSet', Chip]):
		self.add(other)

	def __add__(self, other: Union[List[Chip], 'ChipSet', Chip]) -> 'ChipSet':
		ret: ChipSet = ChipSet(self.chips)
		ret.add(other)
		return ret

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

	def simplify(self):
		"""
		TODO simplify chips list for output
		:return:
		"""
		""

	def defined_list(self, chips_per_line = 6):
		output: str = ""
		line_size: int = 0
		for chip in self.chips :
			line_size += 1
			if line_size == chips_per_line :
				output += "\\\n"
				line_size = 0
			output += f"defined({chip.name:12s}) || "

		return output[:-4]

	def match(self, pattern):
		for chip in self.chips :
			if fnmatch(str(chip), str(pattern)) :
				return True
		return False
