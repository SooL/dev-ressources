import typing as T
import re
from fnmatch import fnmatch


def DEFAULT_reg_cleaner(register : "Register", periph_name = None) :
	pass

def TIM_reg_cleaner(register: "Register", p_name = None) :
	if register.name in ["TIM2_OR"] :
		register.name = "OR"

def GPIO_reg_cleaner(register : "Register", p_name = None):

	if re.match("^GPIO[A-Zx]_", register.name) :
		register.name = register.name[len("GPIOx_"):]

	if register.name in ["OSPEEDER", "GPIOB_OSPEEDR"] :
		register.name = "OSPEEDR"


# For a given group, provide a proper cleaner function. None is the default one.
register_association_table : T.Dict[T.Union[None,str],T.Callable] = {
	"GPIO"		: GPIO_reg_cleaner,
	"TIM"       : TIM_reg_cleaner,
	None        : DEFAULT_reg_cleaner
}