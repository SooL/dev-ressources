import typing as T
import re
from fnmatch import fnmatch

from structure import Field, RegisterVariant


def TIM_reg_cleaner(register: "Register") :
	if register.name in ["TIM2_OR"] :
		register.name = "OR"

def GPIO_reg_var_cleaner(var : RegisterVariant):
	reg_name = var.parent.name
	first_field = var.fields[0]
	if first_field.name.startswith(reg_name[:-1]) and first_field.name[len(reg_name)-1:].isnumeric() :
		field_width = first_field.size
		for i in range(0, 16) :
			if (reg_name[:-1] + str(i)) not in var :
				new_field = Field(chips=var.chips, name=reg_name[:-1] + str(i),
				                  brief=None, position=i * field_width, size=field_width)
				var.add_field(new_field)
