import re
import typing as T
from fnmatch import fnmatch

from cleaners import *
from structure import Component

def change_name(obj, name) :
	obj.name = name

def remove_periph_prefix(obj : Component) :
	from structure import Peripheral
	periph = obj.parent
	instances = list()
	while not isinstance(periph, Peripheral) :
		periph = periph.parent
	instances = periph.instances
	if periph.name is None :
		periph = periph.parent # use group name instead

	if periph.name in ["HASH", "DFSDM"] :
		return # shitty peripherals

	pattern = f"^{periph.name}[A-Za-z\d]*_\w+$"
	if re.match(pattern, obj.name) :
		if len(instances) == 1 and periph.name == instances[0].name :
			# one-instance peripheral. if prefix is different from name, leave as is
			if not obj.name.startswith(periph.name+"_") :
				return
		obj_name = obj.name[obj.name.index("_", len(periph.name))+1:]
		if obj_name in obj.parent :
			logger.warning(periph.name +" contains registers " + obj_name + " and " + obj.name)
		else :
			obj.name = obj_name

class Corrector:
	def __init__(self,
	             arg1: T.Union[T.Callable, T.Dict[str, T.Any]] = None,
	             arg2: T.Union[T.Callable, T.Dict[str, T.Any]] = None) :
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




base_root_corrector = Corrector({

	"ADC"       : { "*" : ADC_periph_cleaner },
	"AES?"      : lambda group : change_name(group, "AES"),
	"CRC"       : {
		"*"         : {
			"DR"        : { "*" : {"Data_register" : lambda f : change_name(f, "DR") }},
			"IDR"       : { "*" : {"Independent_data_register" : lambda f : change_name(f, "IDR") }},
			"POL"       : { "*" : {"Polynomialcoefficients" : lambda f : change_name(f, "POL") }},
		}
	},
	"DMAMUX*"   : lambda group: change_name(group, "DMAMUX"),
	"ETHERNET"  : { "*" : ETHERNET_periph_cleaner },
	"FDCAN"     : { "*" : FDCAN_periph_cleaner },
	"GPIO"      : {
		"*"        : (GPIO_periph_cleaner, {
			"OSPEEDER"  : lambda reg: change_name(reg, "OSPEEDR"),
			"*"         : {
			    "*"         : (GPIO_reg_var_cleaner, {
				    "*"         : GPIO_field_cleaner
			    })
			},
		})
	},
	"HRTIM"     : { "*" : HRTIM_periph_cleaner },
	"I2C"       : { "*" : I2C_periph_cleaner },
	"LPUART"    : lambda group: change_name(group, "USART"),
	"RAMECC"    : { "*" : lambda periph: change_name(periph, "RAMECC") },
	"SERIALCONTROLL" : lambda group : change_name(group, "SERIAL_CONTROL"),
	"TIM?*"     : lambda group: change_name(group, "TIM"),
	"TIM"       : { "*" : TIM_periph_cleaner },
	"USART"     : {"*" : USART_periph_cleaner },
	"USB_*"     : lambda group: change_name(group, "USB"),
	"USB"       : { "*" : USB_periph_cleaner },
	"SERIAL_CONTROL" : (SERIAL_CONTROL_group_cleaner, {
		"*"         : (SERIAL_CONTROL_periph_cleaner, {
			"SC?_*"     : lambda reg : change_name(reg, reg.name[4:])
		}),
	}),
	"*"	        : {
		"*"         : {
			"*_*"       : remove_periph_prefix,
			"*"         : {"*" : {"*_*" : remove_periph_prefix }}
	}},
})

advanced_root_corrector = Corrector({
	"CAN"       : { "*" : CAN_periph_cleaner },
})