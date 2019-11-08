import typing as T
from fnmatch import fnmatch

from cleaners.create_peripheral import GPIO_periph_cleaner, I2C_periph_cleaner, ADC_periph_cleaner, USB_periph_cleaner, \
	TIM_periph_cleaner, HRTIM_periph_cleaner, ETHERNET_periph_cleaner
from cleaners.field_name_cleaner import GPIO_field_cleaner
from cleaners.register_name_cleaner import GPIO_reg_cleaner
from structure import Component


def change_name(obj, name) :
	obj.name = name


class Corrector:
	def __init__(self, local_correction: T.Callable = None, child_correctors: T.Dict[T.Union[None, str], "Corrector"] = None) :
		self.function: T.Union[None, T.Callable] = local_correction
		self.child_correctors: T.Union[None, T.Dict[T.Union[None, str], Corrector]] = child_correctors

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

root_corrector = Corrector(None, {
	"TIM?*"      : Corrector(lambda group: change_name(group, "TIM")),
	"USB_*"     : Corrector(lambda group: change_name(group, "USB")),
	"HRTIM"     : Corrector(None, {
		"*"        : Corrector(HRTIM_periph_cleaner)
	}),
	"USB"       : Corrector(None, {
		"*"        : Corrector(USB_periph_cleaner)
	}),
	"I2C"       : Corrector(None, {
		"*"        : Corrector(I2C_periph_cleaner)
	}),
	"ADC"       : Corrector(None, {
		"*"        : Corrector(ADC_periph_cleaner)
	}),
	"ETHERNET"  : Corrector(None, {
		"*"        : Corrector(ETHERNET_periph_cleaner)
	}),
	"TIM"       : Corrector(None, {
		"*"        : Corrector(TIM_periph_cleaner, {
			"*_OR"   : Corrector(lambda reg: change_name(reg, "OR"))
		})
	}),
	"GPIO"      : Corrector(None, {
		"*"        : Corrector(GPIO_periph_cleaner, {
			"GPIO*_*"   : Corrector(lambda reg: change_name(reg, reg.name[reg.name.index('_')+1:])),
			"OSPEEDER"  : Corrector(lambda reg: change_name(reg, "OSPEEDR")),
			"OSPEEDR"   : Corrector(None, {"*":Corrector(None,{ "*": lambda f: change_name(f, f"OSPEED{int(f.position / f.size)}") })}),
			"MODER"     : Corrector(None, {"*":Corrector(None,{ "*": lambda f: change_name(f, f"MODE{  int(f.position / f.size)}") })}),
			"IDR"       : Corrector(None, {"*":Corrector(None,{ "*": lambda f: change_name(f, f"ID{    int(f.position / f.size)}") })}),
			"ODR"       : Corrector(None, {"*":Corrector(None,{ "*": lambda f: change_name(f, f"OD{    int(f.position / f.size)}") })}),
			"PUPDR"     : Corrector(None, {"*":Corrector(None,{ "*": lambda f: change_name(f, f"PUPD{  int(f.position / f.size)}") })})
		})
	})
})
