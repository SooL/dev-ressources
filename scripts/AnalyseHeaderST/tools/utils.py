from typing import *
#from .typedef import *
from copy import deepcopy, copy

class ChipSeriesManager :
	def __init__(self, chip_list : Set[str] = set()):
		self.chip_list : Set[str] = copy(chip_list)
		self.chip_families : Dict[str, Set[str]] = dict()
		
		self.build_chip_family()
		
	def __eq__(self, other):
		if isinstance(other,self.__class__) :
			return self.chip_list == other.chip_list
		return False
	
	def __hash__(self):
		return hash(tuple(list(self.chip_list)))
	
	def __contains__(self, item):
		return self.contains(item)
	
	def __iter__(self):
		return (i for i in self.chip_list)
	
	def __str__(self):
		return " ".join(["{:12}".format(i) for i in sorted(self)])
		
	
	def clear(self):
		"""
		Empty the object
		"""
		self.chip_list.clear()
		self.chip_families.clear()
		
	def merge(self, other : 'ChipSeriesManager') -> 'ChipSeriesManager':
		"""
		Merge the other CSM into this one.
	
		
		:param ChipSeriesManager other: CSM to get values from
		:return:
		"""
		for dist_chip in other.chip_list :
			if dist_chip in other.chip_families :
				self.chip_list |= other.chip_families[dist_chip]
			else :
				self.chip_list.add(dist_chip)
		self.build_chip_family()
		return self
		
	def from_file_path(self, paths : List[str]) -> Set[str]:
		"""
		Build chip familly from files path/names
		
		:param list of str paths: List of all paths/files to include
		:return: Built chip series list
		:rtype: set of str
		"""
		chip_id = [f[f.find("stm32") :len(f) - 2].upper().replace("X", "x") for f in sorted(paths)]
		self.chip_list = self.chip_list.union(chip_id)
		self.build_chip_family()
		return self.chip_list
	
	def contains(self, chip: str) -> bool:
		"""
		Return true if the ChipSeriesManager contains the given chip.
		
		:rtype: bool
		:param chip: Chip name to test
		:type chip: str
		"""
		if chip in self.chip_families :
			return True
		for family in self.chip_families :
			if chip in self.chip_families[family] :
				return True
		return chip in self.chip_list
	
	def build_chip_family(self):
		"""
		This function will rebuild the full chip family data structure
		"""
		for family in self.chip_families :
			self.chip_list |= self.chip_families[family]
			
		self.chip_families.clear()
		for chip in self.chip_list :
			if len(chip) < 9:
				if chip in self.chip_families :
					continue
				else:
					family = chip
			else:
				family = chip[:7]
				family += "P" if (chip[7] in "RS") else str("") #L4+
			
			if family not in self.chip_families :
				self.chip_families[family] = set()
			self.chip_families[family].add(chip)

	def simplify(self,chips_to_simplify : 'ChipSeriesManager'):
		"""
		This function will perform a simplification against the current ChipManager
		
		:param ChipSeriesManager chips_to_simplify: Chip Manager to simplify
		:rtype: None
		"""
		self.simplify_chip_set(chips_to_simplify.chip_list)
		#Should work since python always use references
	
	def simplify_chip_set(self, chips_to_test : Set[str]) -> Set[str]:
		"""
		This function will replace any full component family from chips_to_test by its shortened name.
		
		The check is made against the current ChipSeriesManager
		
		:param chips_to_test: Chips set to be simplified
		:return: 	the simplified set.
					None if chips_to_test matchs all chips
		"""
		if chips_to_test == self.chip_list :
			chips_to_test.clear()
			chips_to_test.add("ALL_CHIPS")
		else :
			for family in self.chip_families :
				if self.chip_families[family].issubset(chips_to_test) :
					chips_to_test -= self.chip_families[family]
					chips_to_test.add(family)
		return chips_to_test
	
	def select(self, name : str) -> Set[str] :
		"""
		Build a selection of chips based on a partial name
		
		:param str name: Partial name to lookk for
		:return:
		"""
		out = set()
		
		for family in self.chip_families :
			if name in family :
				out |= self.chip_families[family]
		
		temp = set()
		for chip in self.chip_list - out :
			if name in chip :
				temp.add(chip)
		return out | temp
	
	def select_multiple(self, names : List[str]) -> Set[str]:
		"""
		Select all chips which name match something in the provided names list
		
		:param list of str names:
		:return:
		
		..seeal
		"""
		out = set()
		for name in names :
			out |= self.select(name)
		return out
	
	def filter_chips(self, chips_set : Set[str], action : str = "remove") -> Set[str]:
		"""
		Return a set of filtered chips without changing the actutal value of self.chips_set
		
		:param chips_set:
		:param action: can be "remove" to supress given chips from original or "keep" to keep only given chips
		:return:
		"""
		for family in self.chip_families :
			if family in chips_set :
				chips_set.discard(family)
				chips_set |= self.chip_families[family]
	
		if action == "remove" :
			return self.chip_list - chips_set
		elif action == "keep" :
			return self.chip_list & chips_set
		else :
			raise ValueError("Invalid value " + action + " for action. {remove, keep}")
		
	def remove_chips(self, chips_set : Set[str], action : str = "remove") :
		"""
		Filter the chips and edit self.chips_set
		
		:param chips_set: set to use for filtering
		:param action: can be "remove" to supress given chips from original or "filter" to keep only given chips
		:return: the filtered chips set
		:rtype: set of str
		"""
		self.chip_list = self.filter_chips(chips_set, "keep" if action == "filter" else action)
		self.build_chip_family()
		return self.chip_list
	
	def output_ifdef_template(self, cl = None, line_lenght = 4, onlyIf = False) -> str:
		i = 1
		if cl is None :
			cl = self.chip_list

		if len(cl) == 1 and list(cl)[0] == "ALL_CHIPS":
			return "" if onlyIf else "{ifdef}\n"
		else:
			out = "#if"
			for chip in sorted(list(cl)) :
				if i > line_lenght :
					i = 1
					out += "\\\n   "
				i += 1
				out += " defined({0:12s}) ||".format(chip)
			out = out[:-2] + ("\n" if onlyIf else "\n{ifdef}\n#else\n{ifndef}\n#endif\n")
			return out
	
	def is_all_chips(self):
		return len(self.chip_list) == 1 and "ALL_CHIPS" in self.chip_list

	def is_empty(self):
		return len(self.chip_list) == 0;

	def output_series_definition(self):
		out : str = ""
		for family in sorted(self.chip_families) :
			computed_name = family.replace("STM32","")
			
			if computed_name[-1] == "P" : computed_name = computed_name[:-1] + "+"
			if len(computed_name) < 3 : computed_name += " "
			
			computed_name += " Series"
			
			out += "//" + "#" * 78 + "\n"
			out += "//" + "#" + " " * int((78-2-len(computed_name))/2) + computed_name + " " * int((78-2-len(computed_name))/2) + "#\n"
			out += "//" + "#" * 78 + "\n"
	
			for chip in sorted(self.chip_families[family]) :
				out += "//#define " + chip + "\n"
			
			out += "\n" + self.output_ifdef_template(line_lenght=3,cl=self.chip_families[family]).format(ifdef=str("#define " + family), ifndef="")
			
			out = out[:out.rfind("#else")]
			out += "#endif\n\n"

		return out

class AliasAggregator :
	def __init__(self, full_chip_list : ChipSeriesManager = ChipSeriesManager()):
		self.content : Dict[ChipSeriesManager, Dict[str[Tuple[str,str]]]] = dict() #[ID] = if_def, if_ndef
		
		self.chip_list_reference = full_chip_list
		
	def add_entry(self,chips : ChipSeriesManager, define_id : str, name_if_def : str, name_if_ndef : str = None ):
		self.chip_list_reference.simplify(chips)
		
		if chips not in self.content :
			self.content[chips] = dict()
		self.content[chips][define_id] = (name_if_def, name_if_ndef)
		
	def is_entries_grouped(self,entries : Set[str]):
		grouped = False
		for chip_serie in self.content :
			grouped |= set(entries) <= set([self.content[chip_serie][i][0] for i in self.content[chip_serie].keys()])
			if grouped :
				return chip_serie
		return None
		
	def get_id(self, name : str, serie : str = None):
		for c in self.content :
			if serie is not None and c not in serie :
				continue
			for id_to_get in self.content[c].keys() :
				if self.content[c][id_to_get][0] == name : return id_to_get
		return None
	
	def replace_full_group_by_id(self,entries : Set[str],alias : str,val_if_def : str = None,val_if_ndef : str = None) :
		to_delete_serie = self.is_entries_grouped(entries)
		
		if to_delete_serie is None :
			return
		 
		for e in entries :
			self.content[to_delete_serie].pop(self.get_id(e,to_delete_serie))

		self.content[to_delete_serie][alias] = (val_if_def,val_if_ndef)
		
	def output_define_section(self):
		out = ""
		
		for serie in self.content :
			content_ifdef = ""
			content_ifndef = ""
			
			for alias in self.content[serie] :
				content_ifdef  += "\t#define {0:25s} {1}\n".format(alias,
									self.content[serie][alias][0] if self.content[serie][alias][0] is not None else "")
				content_ifndef += "\t#define {0:25s} {1}\n".format(alias,
									self.content[serie][alias][1] if self.content[serie][alias][1] is not None else "")
			
			if serie.is_all_chips() :
				out += content_ifdef
			else :
				out += serie.output_ifdef_template().format(ifdef=content_ifdef,ifndef=content_ifndef) + "\n"
		return out
	
	def output_undefine_section(self):
		out = ""
		for serie in self.content :
			for alias in self.content[serie] :
				out += "#undef " + alias +"\n"
		return out


class GenericAlias :
	# name : defined name, value : structure, if(n)def : defined value
	def __init__(self, define_id: str, ifdef: str, ifndef: str, csm: ChipSeriesManager) :
		"""
		Generic Alias declaration.
		
		:param define_id: Name used after #define statement
		:param ifdef:  Value if the "ifdef" requirement is met
		:param ifndef: Value if the "ifdef" requirement is NOT met
		:param csm: List of chips for which ifdef will be met
		"""
		self.define_id = define_id
		self.ifdef = ifdef
		self.ifndef = ifndef
		self.chips = csm
	
	def get_ifdef_line(self) :
		return self.ifdef
	
	def get_ifndef_line(self) :
		return self.ifndef
#
# class RegisterAlias(GenericAlias) :
#
# 	def __init__(self, reg_typedef : TypedefRegister, peripheral : str, csm : ChipSeriesManager) :
# 		"""
# 		Generic Alias adapted for registers
#
# 		:param TypedefRegister reg_typedef: Register to create alias for
# 		:param str peripheral: Peripheral of that register
# 		:param ChipSeriesManager csm: Chip list
# 		"""
# 		self.reg = reg_typedef
# 		self.peripheral = peripheral
#
#
# 		GenericAlias.__init__(self, peripheral+"_MAP_"+reg_typedef.name
# 							  , "({0:30s} {1})".format(self.peripheral + "_" + self.reg.name + "_TypeDef",self.reg.name)
# 							  , "(uint32_t :32)", csm)
