import typing as T
from fnmatch import fnmatch


# noinspection PyUnresolvedReferences
def GPIO_field_cleaner(field : "Field", ):
	reg = field.parent.parent
	if reg.name == "OSPEEDR"    : field.name = f"OSPEED{int(field.position / field.size)}"
	elif reg.name == "MODER"    : field.name = f"MODE{  int(field.position / field.size)}"
	elif reg.name == "IDR"      : field.name = f"ID{    int(field.position / field.size)}"
	elif reg.name == "ODR"      : field.name = f"OD{    int(field.position / field.size)}"
	elif reg.name == "PUPDR"    : field.name = f"PUPD{  int(field.position / field.size)}"
	elif reg.name == "AFRH"     : field.name = f"AFSEL{ int((field.position +32) / field.size)}"
	elif reg.name == "AFRL"     : field.name = f"AFSEL{ int(field.position / field.size)}"

	field.brief = field.brief\
		.replace(" (y = 0..15)", "")\
		.replace(" (y = 0..7)", "")\
		.replace(" (y = 8..15)", "")\
		.replace("These bits are ", "")
