import typing as T
from fnmatch import fnmatch


def DEFAULT_reg_cleaner(register : "Register", periph_name = None) :
	pass

def GPIO_reg_cleaner(register : "Register", p_name = None):
	if register.name in ["OSPEEDER"] :
		register.name = "OSPEEDR"

# For a given group, provide a proper cleaner function. None is the default one.
register_association_table : T.Dict[T.Union[None,str],T.Callable] = {
	"GPIO"		: GPIO_reg_cleaner,
	None        : DEFAULT_reg_cleaner
}