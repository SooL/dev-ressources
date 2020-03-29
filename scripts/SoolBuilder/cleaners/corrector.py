import re
import typing as T
from fnmatch import fnmatch

from cleaners import *
from structure import Component

def change_name(obj, name) :
	obj.name = name

def change_type(obj, new_type) :
	obj.type = new_type

def change_brief(obj, new_brief) :
	obj.brief = new_brief

def clone_field(field, name=None, pos=None, brief=None, size=None) :
	newField = Field(field.chips,
	                 field.name if name is None else name,
	                 field.brief if brief is None else brief,
	                 field.position if pos is None else pos,
	                 field.size if size is None else size)
	if newField not in field.parent.parent :
		field.parent.parent.add_field(newField)

def remove_periph_prefix(obj : Component) :
	from structure import Peripheral
	periph = obj.parent
	instances = list()
	while not isinstance(periph, Peripheral) :
		periph = periph.parent
	instances = periph.instances
	if periph.name is None :
		periph = periph.parent # use group name instead

	if periph.name in ["DFSDM"] :
		return # shitty peripherals

	pattern = fr"^{periph.name}[A-Za-z\d]*_\w+$"
	if re.match(pattern, obj.name) :
		if len(instances) == 1 and periph.name == instances[0].name :
			# one-instance peripheral. if prefix is different from name, leave as is
			if not obj.name.startswith(periph.name+"_") :
				return
		obj_name = obj.name[obj.name.index("_", len(periph.name))+1:]
		if obj_name in obj.parent :
			logger.warning(periph.name +" contains registers " + obj_name + " and " + obj.name)
		elif obj_name.isidentifier() :
			obj.name = obj_name

def cmsis_remove_reg_prefix(reg : Component) :
	parent_name = reg.parent.name
	if reg.name.startswith(parent_name+"_") :
		reg.name = reg.name[len(parent_name)+1:]

def create_array(periph, component, name = None, keep_originals = False) :
	if isinstance(component, str) :
		component = periph[component]

	if name is None :
		name = component.name

	for m in periph.mappings :
		if name in m and m[name].array_size != 0 :
			return
	for m in periph.mappings :
		if component in m :
			m.create_array_for_component(component, name, keep_originals)

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



# /!\ Group name correctors are used before peripherals are added.
# So when a corrector is used to change the group name,
# the corrector cannot be used to change peripherals or registers

base_root_corrector = Corrector({

	"ADC"       : { "*" : ADC_periph_cleaner },
	"AES?"      : lambda group : change_name(group, "AES"),
	"CAN"       : { "*" : CAN_periph_base_cleaner },
	"COMP?"      : lambda group : change_name(group, "COMP"),
	"CRC"       : {
		"*"         : (CRC_periph_cleaner, {
			"DR"        : { "*" : {"Data_register" : lambda f : change_name(f, "DR") }},
			"IDR"       : { "*" : {"Independent_data_register" : lambda f : change_name(f, "IDR") }},
			"POL"       : { "*" : {"Polynomialcoefficients" : lambda f : change_name(f, "POL") }},
		})
	},
	"DAC"       : { "*" : DAC_periph_cleaner },
	"DMAMUX*"   : lambda group: change_name(group, "DMAMUX"),
	"ETHERNET"  : { "*" : ETHERNET_periph_cleaner },
	"FDCAN"     : { "*" : FDCAN_periph_cleaner },
	"FLASH"     : {
		"*"         : {
			"PCROP*"    : { "*" : {
				"PCROP*_*"  : lambda field : change_name(field, field.name[field.name.index('_')+1:])
			}},
			"WRP*"    : { "*" : {
				"WRP*_*"  : lambda field : change_name(field, field.name[field.name.index('_')+1:]),
				"WRP?"    : lambda field : change_name(field, field.name[:-1])
			}}
		}
	},
	"GIC*"    : lambda group: change_name(group, "GIC"),
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
	"GTZC"		: lambda group: change_name(group, "TZC"),
	"HASH"     : {
		"*"         : {
			"HASH_HR*"  : (lambda reg : change_name(reg, reg.name[5:]), { "*" : {
				"H*"        : lambda field : change_name(field, "H")
			}}),
			"HR*"       : { "*" : {
				"H*"        : lambda field : change_name(field, "H")
			}},
			"CSR*"      : { "*" : {
				"CS*"       : lambda field : change_name(field, "CS")
			}}
		},
	},
	"HRTIM"     : { "*" : HRTIM_periph_cleaner },
	"I2C"       : { "*" : I2C_periph_cleaner },
	"LPUART"    : lambda group: change_name(group, "USART"),
	"RAMECC"    : { "*" : lambda periph: change_name(periph, "RAMECC") },
	"RCC"           : {
		"*"             : {
			"*ENR"          : { "*" : {
				"GPIOP?EN" : lambda field : change_name(field, f"GPIO{field.name[-3]}EN")
			}},
			"xA?B*EN*R*"  : lambda reg : change_name(reg, reg.name[1 :]),
			"MxA?B*EN*R*" : lambda reg : change_name(reg, reg.name[2 :])
		}
	},
	"SERIALCONTROLL" : lambda group : change_name(group, "SERIAL_CONTROL"),
	"SYSCFG"    : {
		"*"         : {
			"EXTICR?"   : { "*" : {
				"EXTI?*"    : lambda field : change_brief(field, f"EXTI {field.name[4:]} configuration")
			}}
		}
	},
	"TIM?*"     : lambda group: change_name(group, "TIM"),
	"TIM"       : { "*" : TIM_periph_cleaner },
	"TZC"		: {"*" : TZC_periph_cleaner},
	"USART"     : {
		"*"         : (USART_periph_cleaner, {
			"0x00000000": lambda reg : change_name(reg,"CR1"),
			"CR2"       : { "*" : {
				"TAINV" : lambda field : change_name(field, "DATAINV")
			}}
		}),
	},
	"USB_*"     : lambda group: change_name(group, "USB"),
	"USB"       : { "*" : USB_periph_cleaner },
	"RNG1"     : lambda group: change_name(group, "RNG"),
	"SERIAL_CONTROL" : (SERIAL_CONTROL_group_cleaner, {
		"*"         : (SERIAL_CONTROL_periph_cleaner, {
			"SC?_*"     : lambda reg : change_name(reg, reg.name[4:])
		}),
	}),

	"STGENR" : lambda group : change_name(group,"STGEN"),

	"*"	        : {
		"*"         : {
			"*_*"       : remove_periph_prefix,
			"*"         : {"*" : {"*_*" : remove_periph_prefix }}
	}},
})


advanced_root_corrector = Corrector({
	"CAN"       : { "*" : CAN_periph_advanced_cleaner},
	"GPIO"      : { "*" : GPIO_periph_advanced_cleaner},
	"HASH"      : {
		"*"         : {
			"HRx"       : lambda reg : create_array(reg.parent, component=reg, name="HR"),
			"CSRx"       : lambda reg : create_array(reg.parent, component=reg, name="CSR"),
		}
    },
	"RCC"       : {
		"*"         : {
			"*ENR"      : { "*" : {
				"IOP?EN"  : lambda field : clone_field(field, name=f"GPIO{field.name[-3]}EN")
			}},
			"xA?B*EN*R*"  : lambda reg : change_name(reg,reg.name[1:]),
			"MxA?B*EN*R*" : lambda reg : change_name(reg,reg.name[2:])
		}
	},
	"SYSCFG"    : { "*" : SYSCFG_periph_advanced_cleaner},
})

cmsis_root_corrector = Corrector({
	"*"	        : {
		"*_*"       : cmsis_remove_reg_prefix
	},
})