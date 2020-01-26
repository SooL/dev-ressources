import typing as T
import re
from fnmatch import fnmatch

from structure import Field, RegisterVariant


def TIM_reg_cleaner(register: "Register") :
	if register.name in ["TIM2_OR"] :
		register.name = "OR"

def GPIO_reg_var_cleaner(var : RegisterVariant):
	reg_name = var.parent.name
	var.force_remove_template()
	if var.parent.name in ["MODER", "ODR", "IDR", "OTYPER", "OSPEEDR", "PUPDR", "BSR", "BRR", "LCKR"] :
		first_field = sorted(var.fields)[0]
		field_size = first_field.size
		prefix = ""
		if first_field.position > 9*field_size :
			prefix = first_field.name[:-2] # remove digit. Assumes at least one pin below 10 is defined
		else :
			prefix = first_field.name[:-1]

		for i in range(0, 16) :
			field_name = prefix+str(i)
			if field_name not in var :
				var.add_field(Field(chips=var.chips, name=field_name, brief=None,
				                    position=i*field_size, size=field_size))
	elif var.parent.name == "BSRR" :
		field_size = sorted(var.fields)[0].size
		for i in range(0, 16) :
			field_name = "BS"+str(i)
			if field_name not in var :
				var.add_field(Field(chips=var.chips, name=field_name, brief=None,
				                    position=i*field_size, size=field_size))
			field_name = "BR"+str(i)
			if field_name not in var :
				var.add_field(Field(chips=var.chips, name=field_name, brief=None,
				                    position=16 + i*field_size, size=field_size))
	elif var.parent.name in ["AFRH", "AFRL"] :

		field_size = sorted(var.fields)[0].size
		start = 8 if var.parent.name == "AFRH" else 0
		for i in range(start, start+8) :
			field_name = "AFSEL"+str(i)
			if field_name not in var :
				var.add_field(Field(chips=var.chips, name=field_name, brief=None,
				                    position= start*4 + i*field_size, size=field_size))
