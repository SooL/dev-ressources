import os
import pickle
import typing as T
from structure import *


def get_db(path : str) -> T.Dict[str,Group] :
	with open(path,"rb") as db :
		return pickle.load(db)



if __name__ == "__main__" :
	import argparse

	parser = argparse.ArgumentParser(description="A tool to search for information within SooL DB")
	parser.add_argument("search_pattern",
						type=str,
						help="Pattern in form of GROUP.PERIPH.REGISTER.FIELD to look for.")

	args = parser.parse_args()