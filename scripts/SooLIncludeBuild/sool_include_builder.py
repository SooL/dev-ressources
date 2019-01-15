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
from pathlib import *
from typing import *

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




def check_params(root : Path,dest : Path) :
	print("\n{:#^80s}".format(" PARAMETERS CHECK "))
	
	print("Root :",str(root.absolute()))
	if not root.is_dir() :
		raise FileNotFoundError("Root " + str(root) + " not found or not a directory.")
	
	print("Dest :",str(dest.absolute()))
	if not dest.is_dir() and dest.parent.is_dir() :
		print("\tCreating last level directory.")
		os.mkdir(dest)
	elif not dest.is_dir() and not dest.parent.is_dir() :
		raise FileNotFoundError("Destination " + str(dest) + " do not exist, nor its parent")
	
	print("Done")
	
def retrieve_valid_folders(root_dir : Path,ref_root : Path, valid_names : List[str] = ["include"], exclude : List[str] = list()) :
	
	ret = list()
	root = Path(os.path.abspath(root_dir)).absolute()
	print("Exploring ",str(root))

	
	for f in os.listdir(root) :
		file = Path(root/f)
		if file == ref_root :
			continue
		if file.name[0] == "." :
			continue
		if file.is_dir() and file.name in valid_names :
			ret.append(file)
		elif file.is_dir() and file.name not in exclude :
			for sub_f in retrieve_valid_folders(root/file,ref_root,valid_names,exclude) :
				ret.append(root/sub_f)
	
	return ret
	
def retrive_files(paths : List[Path]) -> Dict[Path,List[Path]]:
	ret = dict()
	
	for p in paths :
		print("Check", os.path.abspath(str(p)))
		if p not in ret :
			ret[p] = []
		
		for file in os.listdir(p) :
			if (p/Path(file)).match("*.h") :
				print("\tFound",file)
				ret[p].append(p/Path(file))
	
	return ret

def build_output_struct(new_root : Path,rel_paths : List[Path],build_hier =True) :
	
	print("Performing cleanup")
	shutil.rmtree(new_root,True)
	os.mkdir(new_root)
	
	if build_hier :
		for p in rel_paths :
			if str(p) != "." :
				print("Creating",str(p))
				os.makedirs(new_root/p.parent)
	
	
	
#runtime_args = None

if __name__ == "__main__" :
	
	#if len(sys.argv) < 2 and runtime_args is None:
	#	runtime_args = ["testcase/TEST_struct.h", "testcase/output"]
	args = parser.parse_args()
	
	root=Path(args.working_dir)
	out_dir = Path(args.output)
	
	check_params(root,out_dir)
	
	valid = ["include","inc"]
	forbid = ["dev","csl","cmake-build-debug"]
	
	get_path = retrieve_valid_folders(root,Path(os.path.abspath(out_dir)),valid,forbid)
	get_path.append(Path(os.path.abspath(root)))
	print("Found :")
	for p in get_path :
		
		print("\t",str(p))
		
	files_dict = retrive_files(get_path)
	
	build_output_struct(out_dir,[Path(os.path.relpath(p,root.absolute())) for p in get_path],args.hierarchy)
	
	for src_path in files_dict :
		for src_file in files_dict[src_path] :
			print("Writting",src_file.name)
			dist_path = Path(os.path.abspath(src_file))
			if args.hierarchy :
				local_path = out_dir/Path(os.path.relpath(src_path,root.absolute())).parent
			else:
				local_path = out_dir
				
			with open(local_path/src_file.name , "w") as file :
				dist_relpath = os.path.relpath(dist_path,local_path.absolute())
				
				file.write("#include \"{}\"".format(dist_relpath))
				
				
	
	exit(0)