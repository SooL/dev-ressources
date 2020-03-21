import os
import sqlite3 as sql
import typing as T
from structure import ChipSet
from structure import Peripheral, PeripheralInstance
from structure import default_tabmanager as indent
from copy import copy

class Record:
	def __init__(self,field_name, instance : PeripheralInstance):
		self.instance : PeripheralInstance = instance
		self.field_name : str = field_name
		self.values_pos: T.Dict[int,ChipSet] = dict()
		self.values_reg: T.Dict[int, ChipSet] = dict()
		self.instance.chips.update_families()

	def output_fpos(self):
		out = ""
		out += f"{indent}#ifdef {self.instance.name}_BASE_ADDR\n"
		indent.increment()
		out += f"{indent}case {self.instance.name}_BASE_ADDR :\n"
		indent.increment()
		for i in range(len(self.values_pos)):
			v = list(self.values_pos.keys())[i]
			cs = self.values_pos[v]

			if i == 0:
				out += f"{indent}#if {cs.defined_list()}\n"
			else:
				out += f"{indent}#elif {cs.defined_list()}\n"

			out += f"{indent + 1}return 1 << {v};\n"

		indent.decrement()
		out += f"{indent}#endif\n"
		indent.decrement()
		out += f"{indent}#endif"
		return out

	def output_register(self):
		out = ""
		out += f"{indent}#ifdef {self.instance.name}_BASE_ADDR\n"
		out += f"{indent+1}case {self.instance.name}_BASE_ADDR :\n"
		for i in range(len(self.values_reg)):
			v = list(self.values_reg.keys())[i]
			cs = self.values_reg[v]


			if i == 0:
				out += f"{indent+1}#if {cs.defined_list()}\n"
			else:
				out += f"{indent+1}#elif {cs.defined_list()}\n"

			out += f"{indent+2}return RCC->{v};\n"
		out += f"{indent+1}#endif\n"
		out += f"{indent}#endif"
		return out

def generate_records(periph : Peripheral, rcc : Peripheral) -> T.Dict[str,Record] :
	names = [(f"{x.name}EN",x) for x in periph.instances]
	records_dict : T.Dict[str,Record] = dict()
	for fname,instance in names :
		curr_cs = copy(instance.chips)
		for reg in rcc :
			if "ENR" not in reg.name :
				continue
			fieldlist = list()
			for v in reg :
				fieldlist += v.fields
			for field in [f for f in fieldlist if f.name == fname] :
				common_chips : ChipSet = curr_cs & field.chips
				if not common_chips.empty :
					curr_cs = curr_cs - common_chips
					if fname not in records_dict :
						records_dict[fname] = Record(fname,instance)
					if field.position not in records_dict[fname].values_pos :
						records_dict[fname].values_pos[field.position] = ChipSet()
					if reg.name not in records_dict[fname].values_reg :
						records_dict[fname].values_reg[reg.name] = ChipSet()
					records_dict[fname].values_pos[field.position].add(common_chips)
					records_dict[fname].values_reg[reg.name].add(reg.chips)

	return records_dict


def generate_get_bit(records_dict : T.Dict[str,Record],periph : Peripheral) -> str :
	out = ""
	need_template = False
	for inst in periph.instances :
		if periph.needs_template(inst) :
			need_template = True
			break
	if need_template :
		out += "template<typename T>\n"

	out += f"inline constexpr uint32_t {periph.name}{'<T>' if need_template else ''}::get_clock_enable_bit(const uintptr_t addr)\n"
	out += f"{{\n"
	indent.increment()
	out += f"{indent}switch (addr) \n{indent}{{\n"

	for n, rec in records_dict.items():
		out += f"{indent}//Output for {n}\n"
		out += rec.output_fpos()
		out += "\n"
	out += f"{indent}}}\n"
	indent.decrement()
	out += "}\n"
	return out


def generate_get_reg(records_dict: T.Dict[str, Record],periph : Peripheral) -> str:
	out = ""
	need_template = False
	for inst in periph.instances :
		if periph.needs_template(inst) :
			need_template = True
			break
	if need_template :
		out += "template<typename T>\n"

	out += f"inline constexpr volatile Reg32_t& {periph.name}{'<T>' if need_template else ''}::get_clock_enable_reg(const uintptr_t addr)\n"
	out += f"{{\n"
	indent.increment()
	out += f"{indent}switch (addr) \n{indent}{{\n"

	for n, rec in records_dict.items():
		out += f"{indent}//Output for {n}\n"
		out += rec.output_register()
		out += "\n"
	out += f"{indent}}}\n"
	indent.decrement()
	out += "}\n"
	return out
