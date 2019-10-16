from fnmatch import fnmatch
import typing as T
import logging

logger = logging.getLogger()


class Chip :
	def __init__(self, name: str, svd: str, families: T.List[str] = list()):
		self.name = name
		if self.name == "STM32g484xx" :
			self.name = "STM32G484xx"
			logger.warning("Manual fix of STM32G484xx name")
		self.svd = svd
		self.families : T.List[str] = families

	def __str__(self):
		return self.name

	def __repr__(self):
		return str(self.name)

	def match(self, pattern):
		return fnmatch(self.name, pattern)


class ChipSet :
	reference_chips_name_list : T.Set[str] = set()
	reference_chipset : "ChipSet" = None
	ref_lock = False
	#reference_families : Dict[str,Set[str]] = dict()

	@staticmethod
	def get_family(chip_name : str):
		if not fnmatch(chip_name,"STM32*") :
			raise ValueError("Incompatible name")
		if fnmatch(chip_name,"STM32MP*"):
			return chip_name[:8]
		return chip_name[:7]

	def __init__(self, chips=None):
		if chips is None:
			chips = set()
		self.chips: T.Set[Chip] = set()
		self._families : T.Dict[str,T.Set[Chip]] = dict()
		self._families_up_to_date : bool = False
		self.add(chips)
		if ChipSet.reference_chipset is None and not ChipSet.ref_lock :
			ChipSet.ref_lock = True
			ChipSet.reference_chipset = ChipSet()
		if ChipSet.reference_chipset is not None :
			ChipSet.reference_chipset.add(chips)

	def __eq__(self, other):
		if isinstance(other,Chip) :
			return other.name == self.name

	def __hash__(self):
		return hash(tuple(sorted([x.name for x in self.chips])))

	@property
	def families(self) ->T.Dict[str, T.Set[Chip]]:
		if not self._families_up_to_date :
			self.update_families()
		return self._families

	def __str__(self):
		return "\t".join(sorted([str(x) for x in self.chips]))

	def __iadd__(self, other: T.Union[T.List[Chip], 'ChipSet', Chip]):
		self.add(other)

	def __add__(self, other: T.Union[T.List[Chip], 'ChipSet', Chip]) -> 'ChipSet':
		ret: ChipSet = ChipSet(self.chips)
		ret.add(other)
		return ret

	def add(self, other: T.Union[T.List[Chip], T.Set[Chip], 'ChipSet', Chip]):
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

		self._families_up_to_date = False

	def update_families(self):
		self._families.clear()
		for chip in self.chips :
			family = ChipSet.get_family(str(chip))
			if family not in self._families :
				self._families[family] = set()
			self._families[family].add(chip)
		self._families_up_to_date = True

	def defined_list(self, chips_per_line = 5,reference_chipset = None):
		if reference_chipset is None :
			reference_chipset = ChipSet.reference_chipset

		output: str = ""
		line_size: int = 0
		matched_family : T.Dict[str,bool] = dict()

		for family, chips in reference_chipset.families.items():
			if len(chips - self.chips) == 0 :
				matched_family[family] = True
		if matched_family.keys() == reference_chipset.families.keys() :
			return "1"

		for chip in sorted(self.chips, key=lambda x: x.name) :
			family = ChipSet.get_family(chip.name)
			if family not in matched_family or matched_family[family] :
				if line_size == chips_per_line :
					output += "\\\n    "
					line_size = 0
				if family in matched_family :
					output += f"defined({family:13s}) || "
					matched_family[family] = False
				else :
					output += f"defined({chip.name:13s}) || "
				line_size += 1

		return output[:-4]

	def match(self, pattern):
		for chip in self.chips :
			if fnmatch(str(chip), str(pattern)) :
				return True
		return False
