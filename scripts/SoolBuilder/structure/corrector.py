import re
import typing as T
from fnmatch import fnmatch

from cleaners.peripheral_cleaners import *
from cleaners.field_cleaners import *
from cleaners.register_cleaners import *
from structure import Component

def change_name(obj, name) :
	obj.name = name

def reg_remove_periph_prefix(obj : Component) :
	from structure import Peripheral

	periph = obj.parent
	while not isinstance(periph, Peripheral) :
		periph = periph.parent
	if periph.name is None :
		periph = periph.parent # use group name instead

	pattern = f"^{periph.name}[A-Za-z\d]*_\w+$"
	if re.match(pattern, obj.name) :
		obj.name = obj.name[obj.name.index("_", len(periph.name))+1:]

class Corrector:
	def __init__(self,
	             arg1: T.Union[T.Callable, T.Dict[T.Optional[str], "Corrector"]] = None,
	             arg2: T.Union[T.Callable, T.Dict[T.Optional[str], "Corrector"]] = None) :
		if isinstance(arg1, T.Callable) :
			self.function: T.Optional[T.Callable] = arg1
			self.child_correctors: T.Optional[T.Dict[T.Optional[str], Corrector]] = arg2
		elif isinstance(arg1, T.Dict) :
			self.function: T.Optional[T.Callable] = arg2
			self.child_correctors: T.Optional[T.Dict[T.Optional[str], Corrector]] = arg1
		else :
			raise TypeError("Unable to build Corrector with arguments " + repr(arg1) + " & " + repr(arg2))

		if self.child_correctors is not None :
			for key in self.child_correctors :
				corr = self.child_correctors[key]
				if isinstance(corr, T.Callable) :
					self.child_correctors[key] = Corrector(corr)
				elif isinstance(corr, T.Dict) :
					self.child_correctors[key] = Corrector(corr)
				elif isinstance(corr, T.Tuple) :
					if len(corr) != 2 :
						raise TypeError("Cannot create Corrector with a tuple if the tuple has not 2 elments : " + repr(corr))
					self.child_correctors[key] = Corrector(corr[0], corr[1])
				elif not isinstance(self.child_correctors[key], Corrector) :
					raise TypeError("Cannot create Corrector without Dict, function, Set or other corrector")

	def __getitem__(self, item):
		return tuple(self.sub_correctors(item))

	def sub_correctors(self, item):
		if self.child_correctors is None :
			return list()
		if isinstance(item, str) :
			res: T.List[Corrector] = list()
			for key in self.child_correctors :
				if fnmatch(item, key) :
					res.append(self.child_correctors[key])
			return res
		elif isinstance(item, Component) :
			return self.sub_correctors("" if item.name is None else item.name)
		else :
			raise TypeError()

	def __contains__(self, item) :
		if self.child_correctors is None :
			return False
		elif isinstance(item, str) :
			for key in self.child_correctors :
				if fnmatch(item, key) :
					return True
		elif isinstance(item, Component) :
			return item.name in self

	def __call__(self, component: "Component"):
		if self.function is None :
			return
		else :
			return self.function(component)

root_corrector = Corrector({

	"DMAMUX*"   : lambda group: change_name(group, "DMAMUX"),
	"TIM?*"     : lambda group: change_name(group, "TIM"),
	"USB_*"     : lambda group: change_name(group, "USB"),
	"CRC"       : {
		"*"         : {
			"DR"        : {"*":{"Data_register": lambda f: change_name(f, "DR")}},
			"IDR"       : {"*":{"Independent_data_register": lambda f: change_name(f, "IDR")}},
			"POL"       : {"*":{"Polynomialcoefficients": lambda f: change_name(f, "POL")}},
		}
	},
	"HRTIM"     : {"*": HRTIM_periph_cleaner},
	"USB"       : {"*": USB_periph_cleaner},
	"I2C"       : {"*": I2C_periph_cleaner},
	"ADC"       : {"*": ADC_periph_cleaner},
	"ETHERNET"  : {"*": ETHERNET_periph_cleaner},
	"TIM"       : {"*": TIM_periph_cleaner},
	"GPIO"      : {
		"*"        : (GPIO_periph_cleaner, {
			"OSPEEDER"  : lambda reg: change_name(reg, "OSPEEDR"),
			"*"         : {"*":{"*":GPIO_field_cleaner}},
		})
	},
	"*"	: {"*": {
			"*_*": reg_remove_periph_prefix,
			"*"  : {"*_*": reg_remove_periph_prefix}
	}},
})
