import os
import pickle
import typing as T
from structure import Group, Peripheral, Register, Field, Component
from search import Query
from fnmatch import fnmatch

def get_db(path : str) -> T.Dict[str,Group] :
	with open(path,"rb") as db :
		return pickle.load(db)

def find(db : T.Dict[str,Group], aQuery : Query) -> T.List[Component]:
	ret_collection : T.List[Component] = list()
	if not isinstance(aQuery,Query) :
		query = Query(aQuery)
	else :
		query = aQuery

	for g_name, group in db.items() :
		if query.match(g_name,True) and query.group is not None :
			for peripheral in group :
				#print(peripheral.name)
				if query.match((g_name,peripheral.name),True) and query.peripheral is not None :
					for register in peripheral :
						if query.match((g_name,peripheral.name,register.name),True) and query.register is not None :
							for regvar in register :
								for field in regvar:
									if query.match((g_name,peripheral.name,register.name,field.name),True):
										ret_collection.append(field)
						elif query.register is None :
							ret_collection.append(register)
				elif query.peripheral is  None:
					ret_collection.append(peripheral)
		elif query.group is  None :
			ret_collection.append(group)
	return ret_collection


def report_registers(db : T.Dict[str,Group],group : str = "*", peripheral="*", unique = False, filter = "*") -> str :
	r = find(db,Query(f"{group}.{peripheral}"))
	ret = f"REPORTING REGISTERS FOR GROUP {group} AND PERIPH {peripheral} ...\n"
	if unique :
		ret += "USING UNIQUE PARAMETER\n"
	done : T.Set[str] = set()
	for reg in sorted(r,key=lambda x : x.name):
		if fnmatch(reg.name,filter) and (not unique or reg.name not in done) :
			ret += f"\t{reg.name}\n"
			done.add(reg.name)
	return ret


if __name__ == "__main__" :
	import argparse

	# parser = argparse.ArgumentParser(description="A tool to search for information within SooL DB")
	# parser.add_argument("search_pattern",
	# 					type=str,
	# 					help="Pattern in form of GROUP.PERIPH.REGISTER.FIELD to look for.")
	#
	# args = parser.parse_args()

	db = get_db(".data/SooL.dat")
	t = find(db,"GPIO.GPIO")
	pass

