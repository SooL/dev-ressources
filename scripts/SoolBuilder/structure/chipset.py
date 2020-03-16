import os
import logging
import typing as T
import sqlite3 as sql
import xml.etree.ElementTree as ET
from fnmatch import fnmatch
from cmsis_analysis import CMSISHeader

logger = logging.getLogger()


class Chip:
	def __init__(self,define = None,header = None ,svd = None, processor = None, pdefine = None ):
		self.define : str = define
		self.header : str = header
		self.svd 	: str = svd
		self.processor: str = processor
		self.processor_define : str = pdefine
		self.sql_id : int = None
		self.header_handler : CMSISHeader = None

	def __hash__(self):
		return hash((self.define,self.header,self.svd,self.processor))

	def __eq__(self, other):
		if isinstance(other,Chip) :
			return self.define == other.define and self.header == other.header and self.svd == other.svd and \
				   self.processor == other.processor

	def __repr__(self):
		return f'{self.define}{"" if self.processor is None else "_" + self.processor:<5s} : H = {self.header} S = {self.svd}'

	def __str__(self):
		return self.name

	def match(self, pattern):
		return fnmatch(self.name, pattern)

	@property
	def is_full(self):
		return self.define is not None and self.header is not None and self.svd is not None

	def from_node(self,element : ET.Element):
		headers = element.findall("compile[@header]")
		defines = element.findall("compile[@define]")
		svds = element.findall("debug[@svd]")

		for header_node in headers:
			if self.processor is None or ("Pname" in header_node.attrib and header_node.attrib["Pname"] == self.processor) :
				self.header = header_node.attrib["header"]
		for define_node in defines :
			if self.processor is None or ("Pname" in define_node.attrib and define_node.attrib["Pname"] == self.processor):
				self.define = define_node.attrib["define"]
		for svd_node in svds:
			self.svd = svd_node.attrib["svd"]

		if self.processor is not None :
			pdefs = element.findall("compile[@Pdefine]")
			for pdef_node in pdefs:
				if "Pname" in pdef_node.attrib and pdef_node.attrib["Pname"] == self.processor:
					self.processor_define = pdef_node.attrib["Pdefine"]

	@property
	def computed_define(self):
		return f'{self.define}{"_" + self.processor_define if self.processor_define is not None else ""}'

	@property
	def name(self):
		return self.computed_define

	def legalize(self):
		self.header = self.header.replace("\\","/")
		self.svd = self.svd.replace("\\", "/")
		if 'g' in self.define:
			self.define = self.define.replace("g", "G")

	def fix(self,chip_name : str) -> bool:
		if fnmatch(chip_name,"STM32F401?[BCDE]*"):
			self.svd = os.path.dirname(self.svd) + "/STM32F401xE.svd"
		elif fnmatch(chip_name,"STM32F401?[!BCDE]*"):
			self.svd = os.path.dirname(self.svd) + "/STM32F401x.svd"
		elif fnmatch(chip_name,"STM32G483*"):
			return False
		return True

	@property
	def family(self) -> str:
		if not fnmatch(self.name,"STM32*") :
			raise ValueError("Incompatible name")
		if fnmatch(self.name,"STM32MP*"):
			return self.name[:8]
		return self.name[:7]

	def generate_sql(self,cursor : sql.Cursor):
		cursor.execute("INSERT INTO chips (name) VALUES (?)",(self.name,))
		self.sql_id = cursor.lastrowid

	def update_sql_id(self,cursor : sql.Cursor):
		result = cursor.execute("SELECT id FROM chips WHERE name == :cname",{"cname":self.name}).fetchone()
		if not result :
			self.generate_sql(cursor)
		else :
			self.sql_id = int(result[0]);


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
		if isinstance(other,ChipSet) :
			return len(self.chips.symmetric_difference(other.chips)) == 0
		else :
			raise TypeError()

	def __hash__(self):
		return hash(tuple(sorted([x.name for x in self.chips])))

	def __iter__(self):
		return iter(self.chips)

	def __and__(self, other):
		if isinstance(other,ChipSet) :
			return ChipSet(self.chips ^ other.chips)
	@property
	def families(self) ->T.Dict[str, T.Set[Chip]]:
		if not self._families_up_to_date :
			self.update_families()
		return self._families

	@property
	def empty(self) -> bool:
		return len(self.chips) == 0
	
	def __str__(self):
		return "\t".join(sorted([str(x) for x in self.chips]))

	def __iadd__(self, other: T.Union[T.List[Chip], 'ChipSet', Chip]):
		self.add(other)
		return self

	def __add__(self, other: T.Union[T.List[Chip], 'ChipSet', Chip]) -> 'ChipSet':
		ret: ChipSet = ChipSet(self.chips)
		if not isinstance(other, Chip):
			raise TypeError
		ret.add(other)
		return ret

	def __isub__(self, other):
		self.remove(other)
		return self

	def __sub__(self, other):
		ret : ChipSet = ChipSet(self.chips)
		ret.remove(other)
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
			raise TypeError(f"{type(other)} provided")

		self._families_up_to_date = False

	def remove(self, other: T.Union[T.List[Chip], T.Set[Chip], 'ChipSet', Chip]):
		if isinstance(other, ChipSet) :
			self.chips.difference_update(other.chips)
		elif isinstance(other, list) :
			self.chips.difference_update(other)
		elif isinstance(other,set) :
			self.chips.difference_update(other)
		elif isinstance(other, Chip) :
			self.chips.remove(other)
		else:
			raise TypeError(f"{type(other)} provided")

		self._families_up_to_date = False

	def update_families(self):
		self._families.clear()
		for chip in self.chips :
			family = ChipSet.get_family(str(chip)).upper()
			if family not in self._families :
				self._families[family] = set()
			self._families[family].add(chip)
		self._families_up_to_date = True

	def defined_list(self, chips_per_line = 5,reference_chipset = None, allow_reverse = False):
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

		for family in sorted(matched_family.keys()) :
			if line_size == chips_per_line:
				output += "\\\n    "
				line_size = 0
			output += f"defined({family:13s}) || "
			matched_family[family] = False
			line_size += 1
			
		for chip in sorted(self.chips, key=lambda x: x.name) :
			family = ChipSet.get_family(chip.name)
			if family not in matched_family or matched_family[family] :
				if line_size == chips_per_line :
					output += "\\\n    "
					line_size = 0
				if family not in matched_family :
					output += f"defined({chip.name:13s}) || "
				line_size += 1

		return output[:-4]

	def match(self, pattern):
		for chip in self.chips :
			if fnmatch(str(chip), str(pattern)) :
				return True
		return False

	def reverse(self,reference : T.Optional["ChipSet"]= None) -> None:
		if reference is None :
			reference = ChipSet.reference_chipset
		self.chips = (reference - self).chips
		self._families_up_to_date = False

	def reversed(self,reference : T.Optional["ChipSet"]= None) -> "ChipSet":
		if reference is None :
			reference = ChipSet.reference_chipset
		return reference - self

	def fill_from_name_list(self,name_list : T.List[str], ref : "Chipset" = None):
		if ref is None :
			ref = ChipSet.reference_chipset
		for c in ref.chips :
			if c.name in name_list :
				self.add(c)
				name_list.remove(c.name)

	def generate_sql(self,cursor : sql.Cursor):
		for c in self :
			c.generate_sql(cursor)

