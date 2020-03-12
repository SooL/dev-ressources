import os
import sqlite3 as sql
import typing as T
from structure import ChipSet
from structure import Peripheral, PeripheralInstance

class Record:
	def __init__(self,field_name, instance : PeripheralInstance):
		self.instance : PeripheralInstance = instance
		self.field_name : str = field_name
		self.values : T.Dict[ChipSet,T.Union[int,str]] = dict()

		self.instance.chips.update_families()

	def output_fpos(self):
		out = ""
		out += f"#ifdef {self.instance.name}_BASE_ADDR\n"
		out += f"\tcase {self.instance.name}_BASE_ADDR :\n"
		for i in range(len(self.values)):
			cs = list(self.values.keys())[i]
			v = self.values[cs]

			if i == 0:
				out += f"\t#if {cs.defined_list()}\n"
			else:
				out += f"\t#elif {cs.defined_list()}\n"

			out += f"\t\treturn 1 << {v};\n"
		out += "\t#endif\n"
		out += "#endif"
		return out


def generate_get_bit(db : sql.Connection, periph : Peripheral) -> str :
	cursor = db.cursor()
	cursor.row_factory = sql.Row
	out = "uint32_t get_enable_bit(uintptr_t addr){\n"
	peripheral_name = periph.name
	with open("sql/find_enable_bits.sql","r") as query_file :
		query = query_file.read()
		cursor.execute(query,{"pname":peripheral_name})

		results = cursor.fetchall()
		if results :
			out += "case (addr) {"

		rec_list : T.Dict[str,Record] = dict()
		for row in results :
			fname = row['fname']
			fpos = int(row['fpos'])
			clist= row['cname'].split(',')

			cs = ChipSet()
			cs.fill_from_name_list(clist)

			if fname not in rec_list :
				iname = fname[:-2]
				rec_list[fname] = Record(fname,{i.name:i for i in periph.instances}[iname])
			rec_list[fname].values[cs] = fpos

		for n, rec in rec_list.items():
			out += f"//Output for {n}\n"
			out += rec.output_fpos()
			out += "\n"
		out += "}\n"
		out += "}\n"
		return out




