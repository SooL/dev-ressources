import typing as T
from fnmatch import fnmatch

from cleaners.create_peripheral import GPIO_periph_cleaner, I2C_periph_cleaner, ADC_periph_cleaner, USB_periph_cleaner, \
	TIM_periph_cleaner, HRTIM_periph_cleaner, ETHERNET_periph_cleaner
from cleaners.field_name_cleaner import GPIO_field_cleaner
from cleaners.register_name_cleaner import GPIO_reg_cleaner
from structure import Component


def change_name(obj, name) :
	obj.name = name

def remove_prefix(obj : Component, prefix) -> Component:
	if obj.name[:len(prefix)] == prefix :
		obj.name = obj.name[len(prefix):]

class Corrector:
	def __init__(self, arg1: T.Union[T.Callable, T.Dict[T.Optional[str], "Corrector"]] = None, arg2: T.Dict[T.Optional[str], "Corrector"] = None) :
		if isinstance(arg1, T.Callable) :
			self.function: T.Optional[T.Callable] = arg1
			self.child_correctors: T.Optional[T.Dict[T.Optional[str], Corrector]] = arg2
		elif isinstance(arg1, T.Dict) :
			self.function: T.Optional[T.Callable] = None
			self.child_correctors: T.Optional[T.Dict[T.Optional[str], Corrector]] = arg1
		else :
			self.function: T.Optional[T.Callable] = None
			self.child_correctors: T.Optional[T.Dict[T.Optional[str], Corrector]] = None

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
	"DMAMUX*"   : Corrector(lambda group: change_name(group, "DMAMUX")),
	"TIM?*"     : Corrector(lambda group: change_name(group, "TIM")),
	"USB_*"     : Corrector(lambda group: change_name(group, "USB")),
	"HRTIM"     : Corrector({
		"*"        : Corrector(HRTIM_periph_cleaner)
	}),
	"USB"       : Corrector({
		"*"        : Corrector(USB_periph_cleaner)
	}),
	"I2C"       : Corrector({
		"*"        : Corrector(I2C_periph_cleaner)
	}),
	"ADC"       : Corrector({
		"*"        : Corrector(ADC_periph_cleaner, {
			"ADC*_*"    : Corrector(lambda reg: change_name(reg, reg.name[reg.name.index('_')+1:]))
		})
	}),
	"ETHERNET"  : Corrector({
		"*"        : Corrector(ETHERNET_periph_cleaner)
	}),
	"TIM"       : Corrector({
		"*"        : Corrector(TIM_periph_cleaner, {
			"TIM*_*"    : Corrector(lambda reg: change_name(reg, reg.name[reg.name.index('_')+1:]))
		})
	}),
	"CRC"		: Corrector({
		"*"			: Corrector({
			"CRC_*" : Corrector(lambda reg : remove_prefix(reg,"CRC_"))
		})
	}),
	"GPIO"      : Corrector({
		"*"        : Corrector(GPIO_periph_cleaner, {
			"GPIO*_*"   : Corrector(lambda reg: change_name(reg, reg.name[reg.name.index('_')+1:])),
			"OSPEEDER"  : Corrector(lambda reg: change_name(reg, "OSPEEDR")),
			"OSPEEDR"   : Corrector({"*":Corrector({"*":lambda f: change_name(f,f"OSPEED{int(f.position/f.size)}")})}),
			"MODER"     : Corrector({"*":Corrector({"*":lambda f: change_name(f,f"MODE{  int(f.position/f.size)}")})}),
			"IDR"       : Corrector({"*":Corrector({"*":lambda f: change_name(f,f"ID{    int(f.position/f.size)}")})}),
			"ODR"       : Corrector({"*":Corrector({"*":lambda f: change_name(f,f"OD{    int(f.position/f.size)}")})}),
			"PUPDR"     : Corrector({"*":Corrector({"*":lambda f: change_name(f,f"PUPD{  int(f.position/f.size)}")})})
		})
	})
})
