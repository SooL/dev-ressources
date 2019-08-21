import typing as T

from Jstructure import Peripheral
import logging

logger = logging.getLogger()


class Group :

	name_correction: T.Dict[str, str] = {
		"TIM1" : "TIM",
		"TIMs" : "TIM",
		"TIMER": "TIM"
	}

	def __init__(self, name, name_helper: T.Callable = None):
		self.name = name if (name not in Group.name_correction) else Group.name_correction[name]
		self.peripherals: T.List[Peripheral] = list()
		self.name_helper = name_helper

	def add_peripheral(self, peripheral):
		self.peripherals.append(peripheral)
		if peripheral.group is None:
			peripheral.group = self
		elif peripheral.group != self:
			raise AssertionError()

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

				if periph_1 == periph_2 : # registers, fields and descriptions are the same.
					periph_1.add_instances(periph_2.instances)
					self.peripherals.remove(periph_2)
					length -= 1

				else :
					j += 1

		# ---------- step 2 : assign the peripheral name.
		unnamed = [p for p in self.peripherals if p.name is None]

		# special cases, that require a particular function to determine the name
		if self.name_helper is not None:
			for p in unnamed :
				self.name_helper(p)

		# if there is only 1 peripheral in the group, the peripheral shall take the name of the group (if no exception)
		elif len(unnamed) == 1:
			unnamed[0].name = self.name

		# if there is more than 1 peripheral in the group, the name cannot be chosen. A name helper must be created
		else :
			logger.error(f"Peripherals {str(p.instances[0].name for p in unnamed)}"
			             f" for chip {unnamed[0].chips.chips[0].name}"
			             f" cannot be named.")

		# TODO step 3 : merge new peripherals with existing peripherals

	def __str__(self):
		return self.name
