#
#  Copyright (c) 2018 FAUCHER Julien & FRANCE Loic
#  This file is part of SooL Toolkit.
#
#  SooL core Library is free software: you can redistribute it and/or modify
#  it under the terms of the GNU Lesser General Public License
#  as published by the Free Software Foundation, either version 3
#  of the License, or (at your option) any later version.
#
#  SooL core Library is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
#  GNU Lesser General Public License for more details.
#
#  You should have received a copy of the GNU Lesser General Public License
#  along with SooL core Library. If not, see <https://www.gnu.org/licenses/>.
#

import os
import shutil
import argparse
#from pathlib import *
from typing import *
from fnmatch import fnmatch


parser = argparse.ArgumentParser(description="Simple tool to build a virtual include tree")

parser.add_argument("working_dir",
					help="Root of the lib tree to read")
parser.add_argument("-o", "--output",
					default="include",
					type=str,
					required=False,
					help="Destination directory to write in.")
parser.add_argument("-H", "--hierarchy",
					action="store_true",
					required=False,
					help="Keep hierarchy")
parser.add_argument("-a","--accumulate",
					action="store_true",
					required=False,
					help="Do not performs cleanup")
parser.add_argument("-L","--absolute-paths",
					action="store_true",
					required=False,
					help="Use absolute paths instead of relatives")


def check_params(root : str,dest : str) :
	print("\n{:#^80s}".format(" PARAMETERS CHECK "))
	
	print("Root :",os.path.abspath(root))
	if not os.path.isdir(root):
		raise FileNotFoundError("Root " + str(root) + " not found or not a directory.")
	
	print("Dest :",os.path.abspath(dest))
	if not os.path.exists(dest):
		print("\tDestination directory.")
		os.makedirs(os.path.abspath(dest))
	elif not os.path.isdir(dest):
		raise FileExistsError(f"The path {dest} exists and is not a directory")



def retrieve_valid_folders(root_dir : str,ref_root : str, valid_names : List[str] = ["include"], exclude : List[str] = list()) :
	
	ret = list()
	root = os.path.abspath(root_dir)
	print("Exploring ",root)

	for f in os.listdir(root) :
		file = f"{root}/{f}"
		if file == ref_root :
			continue
		if os.path.basename(file)[0] == "." :
			continue
		if os.path.isdir(file) and os.path.basename(file) in valid_names :
			ret.append(file)
		elif os.path.isdir(file) and os.path.basename(file) not in exclude :
			for sub_f in retrieve_valid_folders(file,ref_root,valid_names,exclude) :
				ret.append(sub_f)
	
	return ret


def retrive_files(paths : List[str]) -> Dict[str,List[str]]:
	ret = dict()
	
	for p in paths :
		print("Check", os.path.abspath(str(p)))
		if p not in ret :
			ret[p] = []
		
		for file in os.listdir(p) :
			if fnmatch(file,"*.h"):
				print("\tFound",file)
				ret[p].append(file)
	
	return ret


def build_output_struct(new_root : str,rel_paths : List[str],build_hier =True,accumulate=True) :
	
	if not accumulate :
		print("Performing cleanup\n")
		shutil.rmtree(new_root,True)
	else:
		print("Accumulating old files\n")
		
	if not os.path.exists(new_root) :
		print("Creating",new_root)
		os.makedirs(new_root)
	
	if build_hier :
		for p in rel_paths :
			if str(p) != "." :
				if not os.path.exists(f"{new_root}/{os.path.dirname(p)}") :
					print("Creating",f"{new_root}/{os.path.dirname(p)}")
					os.makedirs(f"{new_root}/{os.path.dirname(p)}")
				else :
					print("Skipping",f"{new_root}/{p}")
	
	
	
#runtime_args = None

if __name__ == "__main__" :
	
	#if len(sys.argv) < 2 and runtime_args is None:
	#	runtime_args = ["testcase/TEST_struct.h", "testcase/output"]
	args = parser.parse_args()
	
	root=args.working_dir
	out_dir = args.output
	
	check_params(root,out_dir)
	
	valid = ["include","inc"]
	forbid = ["dev","csl","cmake-build-debug","__pycache__","dev-ressources"]

	print("\n{:#^80s}".format(" ROOT EXPLORATION "))
	get_path = retrieve_valid_folders(root,os.path.abspath(out_dir),valid,forbid)
	get_path.append(os.path.abspath(root))
	print("\nFound :")
	for p in get_path :
		print("\t",str(p))

	print("\n{:#^80s}".format(" FILE RETRIEVING "))
	files_dict = retrive_files(get_path)

	print("\n{:#^80s}".format(" REBUILDING STRUCTURE "))
	build_output_struct(out_dir,[os.path.relpath(p,os.path.abspath(root)) for p in get_path],args.hierarchy,args.accumulate)

	print("\n{:#^80s}".format(" WRITING FILES "))
	for src_path in files_dict :
		for src_file in files_dict[src_path] :
			print("Writting",f"{src_path}/{src_file}")
			dist_path = os.path.abspath(src_file)
			if args.hierarchy :
				local_path = f"{out_dir}/{os.path.dirname(os.path.relpath(src_path,os.path.abspath(root)))}"
			else:
				local_path = out_dir
				
			with open(f"{local_path}/{src_file}" , "w") as file :
				if args.absolute_paths :
					dist_relpath = os.path.abspath(dist_path)
				else :
					dist_relpath = os.path.relpath(dist_path,os.path.abspath(local_path))
				
				
				file.write("#include \"{}\"".format(dist_relpath))

	print("{:#^80s}".format(" DONE "))
	exit(0)
