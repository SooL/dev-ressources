import typing as T

from structure import Peripheral, Component
from structure import ChipSet
from structure import default_tabmanager
from cleaners import base_root_corrector, advanced_root_corrector
from structure.utils import DefinesHandler

import logging

logger = logging.getLogger()

class Group(Component) :
########################################################################################################################
#                                                    GROUP CREATION                                                    #
########################################################################################################################

	@staticmethod
	def get_group(group_dict : T.Dict[str,"Group"], group_name : str) -> "Group":
		"""
		This method will return the given group object if it exists in group dict.
		Otherwise the group will be created and then returned.
		:param group_dict: Dict to lookup
		:param group_name: Group to find
		:return:
		"""
		group = Group(group_name)
		if group.name in base_root_corrector :
			for corrector in base_root_corrector[group] :
				corrector(group) # changes only the group name (if necessary)

		if group.name in group_dict :
			return group_dict[group.name]
		else :
			group_dict[group.name] = group
			return group

	def __init__(self, name: str) :
		super().__init__(name=name)
		self.peripherals: T.List[Peripheral] = list()

	def __contains__(self, item):
		if isinstance(item, Peripheral) :
			for p in self.peripherals :
				if item is p or item == p :
					return True
			return False
		if isinstance(item,str) :
			for p in self.peripherals :
				if item == str(p.name) :
					return True
			return False
		raise TypeError()

	def __getitem__(self, item) -> Peripheral:
		if isinstance(item,str) :
			for p in self.peripherals :
				if str(p.name) == item:
					return p
			raise KeyError()
		elif isinstance(item, Peripheral) :
			for p in self.peripherals :
				if p is item or p == item :
					return p
			raise KeyError()
		raise TypeError()

	def __iter__(self):
		return iter(self.peripherals)

########################################################################################################################
#                                                PERIPHERALS MANAGEMENT                                                #
########################################################################################################################

	def add_peripheral(self, peripheral):
		self.peripherals.append(peripheral)
		peripheral.set_parent(self)
		self.edited = True

	def __struct_based_periph_merge(self) :
		length = len(self.peripherals)
		i = 0
		while i < (length - 1) :
			periph_1 : Peripheral = self.peripherals[i]
			i += 1
			j = i
			while j < length :
				periph_2 : Peripheral = self.peripherals[j]
				# Structures are strictly identical
				same_struct = periph_1.mapping_equivalent_to(periph_2, ignore_templates=False)
				# If only one mapping per peripheral and mappings are compatibles
				compatible_mappings = len(periph_1.mappings) == 1 and len(periph_2.mappings) == 1\
				                      and periph_1.mappings[0].compatible(periph_2.mappings[0])
				different_names = periph_1.name is not None and\
				                  periph_2.name is not None and\
				                  periph_1.name != periph_2.name

				if (same_struct or compatible_mappings) and not different_names :
					if periph_1.name != periph_2.name :
						if periph_1.name is None :
							periph_1.name = periph_2.name
							logger.info(f"unnamed peripheral {repr(periph_1.instances)} is identical"
							            f" to peripheral {repr(periph_2.instances)}."
							            " First peripheral's name set as second one's,"
							            " and second one merged into first one")
						elif periph_2.name is None :
							logger.info(f"peripheral {repr(periph_1.instances)} is identical"
							            f" to unnamed peripheral {repr(periph_2.instances)}."
							            " Second periph merged into first")
					else :
						if periph_1.brief != periph_2.brief:
							logger.warning(f"peripherals {repr(periph_1.instances)} and {repr(periph_2.instances)}"
							               f" don't have the same description, despite being strictly identical :"
							               f" {periph_1.brief}, {periph_2.brief}")

						periph_1.intra_svd_merge(periph_2)
						self.peripherals.pop(j)
						self.edited = True
						length -= 1
				else :
					if same_struct and different_names :
						logger.warning(f" {periph_1} ({repr(periph_1.instances)}) and"
						               f" {periph_2} ({repr(periph_2.instances)})"
						                " have different names, but strictly the same structure")
					j += 1

	def __name_base_periph_merge(self) :
		length = len(self.peripherals)
		i = 0
		while i < (length - 1) :
			periph_1: Peripheral = self.peripherals[i]
			i += 1
			if periph_1.name is None :
				continue
			j = i
			while j < length :
				periph_2: Peripheral = self.peripherals[j]
				if periph_1.name == periph_2.name :
					if periph_1.brief != periph_2.brief:
						logger.warning(f"peripherals {repr(periph_1.instances)} and {repr(periph_2.instances)}"
						               f" don't have the same description, despite having the same name :"
						               f" {periph_1.brief}, {periph_2.brief}")
					periph_1.inter_svd_merge(periph_2)
					self.peripherals.pop(j)
					self.edited = True
					length -= 1
				else :
					j += 1

	def __identify_unnamed(self, final:bool):

		# only 1 peripheral in the group => the peripheral takes the name of the group
		if len(self.peripherals) == 1 and self.peripherals[0].name is None :
			self.peripherals[0].name = self.name
			return

		if final :

			unnamed = [p for p in self.peripherals if p.name is None]

			for periph in unnamed:
				if len(periph.instances) == 1:
					logger.info(f"Name unspecified for single-instance peripheral {periph.instances[0]}"
					            f" in group {self.name}, where multiple peripheral are left unnamed."
					            f" {periph.instances[0].name} chosen as peripheral class name.")
					periph.name = periph.instances[0].name

			unnamed = [p for p in unnamed if p.name is None]  # update the 'unnamed' list

			# if there is still unnamed peripherals in the group, their name cannot be chosen.
			#  A name helper must be created for them
			if len(unnamed) != 0:
				logger.error(f"Peripherals in group {self.name} with brief {str(list(p.brief for p in list(unnamed)))}"
				             f" for chipset {repr(list(unnamed)[0].chips.chips)}"
				             f" cannot be named.")

	def before_svd_compile(self, parent_corrector=base_root_corrector):
		super().before_svd_compile(parent_corrector)
		self.__struct_based_periph_merge() # merge equal structures

	def svd_compile(self):
		super().svd_compile()
		if not self.edited :
			self.__identify_unnamed(final=False)
			self.__name_base_periph_merge()

	def after_svd_compile(self, parent_corrector=advanced_root_corrector):
		super().after_svd_compile(parent_corrector)
		self.__identify_unnamed(final=True)
		for i in range(0, len(self.peripherals)-1) :
			for j in range(i+1, len(self.peripherals)) :
				if self.peripherals[i].name == self.peripherals[j].name :
					periph_1 = self.peripherals[i]
					periph_2 = self.peripherals[j]
					raise AssertionError(f"Peripherals {periph_1.instances} and {periph_2.instances}"
					                     f" share the name {periph_1.name}, but are not identical")

	def inter_svd_merge(self, other: "Group"):
		if other.name != self.name :
			logger.error(f"Merging two groups with different names : {other.name} into {self.name}")
		for p in other :
			if (p.name is not None) and (p.name in self) :
				self[p.name].inter_svd_merge(p)
			else :
				self.add_peripheral(p)
		
	def cpp_output(self):

		defines: T.Dict[ChipSet, DefinesHandler] = dict()
		out = ""
		licence_text = ""
		includes_text = "#include \"lib_utils/peripheral_include.h\"\n" \
		                f"//SOOL-{self.name}-INCLUDES\n"

		# default_tabmanager += 2
		with open("license_header.txt", "r") as license_file :
			licence_text = license_file.read() + "\n\n"
		tmp = ""
		tmp += f"{default_tabmanager}namespace sool {{\n"
		default_tabmanager.increment()
		tmp += f"{default_tabmanager}namespace core {{\n"
		default_tabmanager.increment()

		for peripheral in self.peripherals :
			tmp += peripheral.declare_templates(default_tabmanager)

		for peripheral in self.peripherals :
			tmp += peripheral.declare(default_tabmanager)
			peripheral.define(defines)

		self_chips = self.computed_chips

		if self_chips not in defines :
			defines[self_chips] = DefinesHandler()

		# add all defines to the group handler
		for chips in defines :
			if chips == self_chips : continue
			defines[self_chips].add_raw(
				defined=defines[chips].output_defines(chips),
				undefine=defines[chips].undefines)

		# add structure definition to the group DefinesHandler
		defines[self_chips].add_raw(defined=tmp)

		# clear defines dictionary
		tmp_define_handler = defines[self_chips]
		defines = dict()
		defines[self_chips] = tmp_define_handler

		# get instances addresses and declarations
		tmp = ""
		for peripheral in self.peripherals :
			peripheral.define_instances(defines)
			tmp += peripheral.declare_instances(default_tabmanager)

		tmp += f"{default_tabmanager}//SOOL-{self.name}-DEFINES\n"
		tmp += f"{default_tabmanager}//SOOL-{self.name}-DEFINITIONS\n"
		# add all defines to the group handler
		for chips in defines :
			if chips == self_chips : continue
			defines[self_chips].add_raw(
				defined=defines[chips].output_defines(chips),
				undefine=defines[chips].undefines)

		default_tabmanager.decrement()
		tmp += f"{default_tabmanager}}};\n"
		default_tabmanager.decrement()
		tmp += f"{default_tabmanager}}};\n"
		# add instances declaration to the group DefinesHandler
		defines[self_chips].add_raw(defined=f"{tmp}{defines[self_chips].output_undef()}")

		out += defines[self_chips].output_defines(self_chips, use_else=False)
		out = (f"{licence_text}"
		       f"#ifndef __SOOL_CORE_{self.name}_H\n"
		       f"#define __SOOL_CORE_{self.name}_H\n"
		       f"{includes_text}\n"
			   f"{out}\n"
			   f"#endif //__SOOL_CORE_{self.name}_H")

		# default_tabmanager -= 2

		return out
