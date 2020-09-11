# ******************************************************************************
#  Copyright (c) 2018-2020 FAUCHER Julien & FRANCE Loic.                       *
#                                                                              *
#  This file is part of SooL generator.                                        *
#                                                                              *
#  SooL generator is free software: you can redistribute it and/or modify      *
#  it under the terms of the GNU Lesser General Public License                 *
#  as published by the Free Software Foundation, either version 3              *
#  of the License, or (at your option) any later version.                      *
#                                                                              *
#  SooL core Library is distributed in the hope that it will be useful,        *
#  but WITHOUT ANY WARRANTY; without even the implied warranty of              *
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                *
#  GNU Lesser General Public License for more details.                         *
#                                                                              *
#  You should have received a copy of the GNU Lesser General Public License    *
#  along with SooL core Library. If not, see  <https://www.gnu.org/licenses/>. *
# ******************************************************************************

import os
import logging

logger = logging.getLogger()


class GroupFileSet:
	default_split_folder : str = "."
	default_merged_folder : str = "."

	def __init__(self,base_name : str,split_folder : str = None, merged_folder : str = None):
		self.base_name = base_name.replace(".h","").replace("_definition","").replace("_struct","")
		self.split_folder = split_folder if split_folder is not None else GroupFileSet.default_split_folder
		self.merged_folder = merged_folder if merged_folder is not None else GroupFileSet.default_merged_folder

		self.init_folders()

	def __eq__(self, other : "GroupFileSet"):
		return  self.base_name == other.base_name and \
				self.split_folder == other.split_folder and \
				self.merged_folder == other.merged_folder

	@classmethod
	def from_path(cls, path) -> "GroupFileSet":
		file_name = os.path.basename(path)
		if file_name.endswith("_struct.h") or file_name.endswith("_definition.h") :
			return cls(file_name[:file_name.rfind("_")])
		elif file_name.endswith(".h") :
			return cls(file_name[:-2])
		else :
			raise RuntimeError("Invalid file name")


	def init_folders(self):
		self.split_folder = os.path.abspath(self.split_folder)
		self.merged_folder = os.path.abspath(self.merged_folder)

		if not os.path.exists(self.split_folder) :
			logger.error(f"Splited sources path {self.split_folder} does not exists")
			raise FileNotFoundError("Splited sources path does not exists")

		if not os.path.exists(self.merged_folder) :
			logger.error(f"Merged sources path {self.merged_folder} does not exists")
			raise FileNotFoundError("Merged sources path does not exists")

	@property
	def definition_file(self) -> str:
		return f"{self.split_folder}/{self.base_name}_definition.h"

	@property
	def struct_file(self) -> str:
		return f"{self.split_folder}/{self.base_name}_struct.h"

	@property
	def merged_file(self) -> str:
		return f"{self.merged_folder}/{self.base_name}.h"

	@property
	def definition_exists(self) -> bool:
		return os.path.exists(self.definition_file) and os.path.isfile(self.definition_file)

	@property
	def struct_exists(self) -> bool:
		return os.path.exists(self.struct_file) and os.path.isfile(self.struct_file)

	@property
	def merged_exists(self) -> bool:
		return os.path.exists(self.merged_file) and os.path.isfile(self.merged_file)

	@property
	def definition_data(self) -> str :
		data = ""
		if self.definition_exists :
			with open(self.definition_file,"r") as f:
				data = f.read()
		return data

	@definition_data.setter
	def definition_data(self,data : str):
		with open(self.definition_file,"w") as f:
			f.write(data)

	@property
	def struct_data(self) -> str :
		data = ""
		if self.struct_exists :
			with open(self.struct_file,"r") as f:
				data = f.read()
		return data

	@struct_data.setter
	def struct_data(self,data : str):
		with open(self.struct_file,"w") as f:
			f.write(data)


	@property
	def merged_data(self) -> str :
		data = ""
		if self.merged_exists :
			with open(self.merged_file,"r") as f:
				data = f.read()
		return data

	@merged_data.setter
	def merged_data(self,data : str):
		with open(self.merged_file,"w") as f:
			f.write(data)