import typing as T

from Jstructure import Peripheral
import logging

from cleaners.create_peripheral import create_association_table

logger = logging.getLogger()


class Group :
########################################################################################################################
#                                                    GROUP CREATION                                                    #
########################################################################################################################

	name_correction: T.Dict[str, str] = {
		"TIM1" : "TIM",
		"TIMS" : "TIM",
		"TIMER": "TIM",
		"USB_OTG": "USB",
		"USB_OTG_FS": "USB",
		"USB_OTG_HS": "USB"
	}

	@staticmethod
	def get_group(group_dict, group_name) :
		group_name = group_name.upper()
		if group_name in Group.name_correction :
			group_name = Group.name_correction[group_name]

		if group_name in group_dict :
			return group_dict[group_name]

		name_helper = create_association_table[group_name] if (group_name in create_association_table) else None

		group = Group(group_name, name_helper)

		group_dict[group_name] = group
		return group

	def __init__(self, name, name_helper: callable = None):
		self.name = name if (name not in Group.name_correction) else Group.name_correction[name]
		self.peripherals: T.List[Peripheral] = list()
		self.name_helper = name_helper

########################################################################################################################
#                                                PERIPHERALS MANAGEMENT                                                #
########################################################################################################################

	def add_peripheral(self, peripheral):
		self.peripherals.append(peripheral)
		if peripheral.group is None:
			peripheral.group = self
		elif peripheral.group != self:
			raise AssertionError()

########################################################################################################################
#                                                  PERIPHERALS FUSION                                                  #
########################################################################################################################

	def merge_peripherals(self):

		# ---------- step 1 : merge identical unnamed peripherals

		length = len(self.peripherals)
		i=0
		while i < (length - 1) :
			periph_1 = self.peripherals[i]
			i += 1

			if periph_1.name is not None: # peripheral already has a name
				continue

			j = i # begin at next peripheral
			while j < length :
				periph_2 = self.peripherals[j]
				if (periph_2.name is not None) or (periph_1 is periph_2) :
					j += 1
					continue

				if periph_1.compatible(periph_2) : # registers, fields are the same.
					if periph_1.brief != periph_2.brief :
						logger.warning(f"peripherals {repr(periph_1.instances)} and {repr(periph_2.instances)}"
						               f" don't have the same description, despite being identical :"
						               f" {periph_1.brief}, {periph_2.brief}")
					periph_1.add_instances(periph_2.instances)
					self.peripherals.pop(j)
					length -= 1

				else :
					j += 1

		# ---------- step 2 : assign the peripheral name.

		new_peripherals = [p for p in self.peripherals if p.name is None]
		old_peripherals = [p for p in self.peripherals if p.name is not None]
		unnamed = [p for p in new_peripherals]

		# special cases, that require a particular function to determine the name
		if self.name_helper is not None:
			for p in unnamed :
				self.name_helper(p)
			unnamed = [p for p in unnamed if p.name is None] #update the 'unnamed' list

		# if there is only 1 peripheral in the group, the peripheral shall take the name of the group (if no exception)
		elif len(unnamed) == 1:
			unnamed[0].name = self.name
			unnamed.clear()

		# if there is still unnamed peripherals in the group, their name cannot be chosen.
		#  A name helper must be created for them
		if len(unnamed) != 0 :
			logger.error(f"Peripherals {str(list(p.brief for p in list(unnamed)))}"
			             f" for chip {repr(list(unnamed)[0].chips.chips)}"
			             f" cannot be named.")

		# verify that there is no two new peripherals with the same name
		for periph_1 in new_peripherals :
			for periph_2 in new_peripherals :
				if (periph_1 is not periph_2) and (periph_1.name == periph_2.name) :
					logger.error(f"two peripherals fo the name {periph_1.name} :\n"
					             f"{repr(periph_1.instances)} and\n"
					             f"{repr(periph_2.instances)}")
					periph_2.name += "_2"

		# look for already-defined peripherals with the same name as the new ones
		for new_p in new_peripherals :
			for old_p in old_peripherals :
				if new_p.name == old_p.name :
					# merge the new peripheral into the old one
					old_p.merge_peripheral(new_p)

					# remove the new peripheral from the list
					i = self.peripherals.index(new_p)
					while i >= 0 and self.peripherals[i] is not new_p :
						i = self.peripherals.index(new_p, i+1)
					if i < 0 :
						raise IndexError(f"peripheral {new_p} is not in the group {self}")
					self.peripherals.pop(i)


########################################################################################################################
#                                                    OTHER METHODS                                                     #
########################################################################################################################

	def __str__(self):
		return self.name
