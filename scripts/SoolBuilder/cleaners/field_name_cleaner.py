import typing as T
from fnmatch import fnmatch


def DEFAULT_field_cleaner(register : "Register", r_name = None) :
	pass


def GPIO_reg_cleaner(field : "Field",):
	if field.parent.name in ["OSPEEDR"] :
		field.name = f"OSPEED{int(field.position / field.size)}"
	if field.parent.name in ["MODER"] :
		field.name = f"MODE{int(field.position / field.size)}"
	if field.parent.name in ["IDR"]:
		field.name = f"ID{int(field.position / field.size)}"
	if field.parent.name in ["ODR"]:
		field.name = f"OD{int(field.position / field.size)}"
	if field.parent.name in ["PUPDR"]:
		field.name = f"PUPD{int(field.position / field.size)}"

	if field.parent.name in ["AFRH"]:
		field.name = f"AFSEL{int((field.position +16)/ field.size)}"
	if field.parent.name in ["AFRL"]:
		field.name = f"AFSEL{int((field.position)/ field.size)}"



# For a given group, provide a proper cleaner function. None is the default one.
field_association_table : T.Dict[T.Union[None,str],T.Callable] = {
	"PUPDR" : GPIO_reg_cleaner,
	"IDR"	: GPIO_reg_cleaner,
	"ODR"	: GPIO_reg_cleaner,
	"MODER"		: GPIO_reg_cleaner,
	"OSPEEDR"	: GPIO_reg_cleaner,
	"AFRH"		: GPIO_reg_cleaner,
	"AFRL"		: GPIO_reg_cleaner,
	None        : DEFAULT_field_cleaner
}