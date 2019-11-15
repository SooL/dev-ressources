import typing as T
from fnmatch import fnmatch


# noinspection PyUnresolvedReferences
def GPIO_field_cleaner(field : "Field", ):
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
		field.name = f"AFSEL{int((field.position +32) / field.size)}"
	if field.parent.name in ["AFRL"]:
		field.name = f"AFSEL{int(field.position / field.size)}"

	field.brief.replace("(y = 0..15) ", "").replace("These bits are ", "")
