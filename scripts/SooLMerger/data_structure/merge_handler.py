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

import logging
import typing as T

from .fileset import GroupFileSet
from .tags import SooLTag
logger = logging.getLogger()

class MergeHandler:
	def __init__(self, fileset : GroupFileSet):
		self.files : GroupFileSet = fileset

		self.struct_tags    : T.Dict[str,SooLTag] = dict()
		self.definition_tags: T.Dict[str,SooLTag] = dict()
		self.merged_tags    : T.Dict[str,SooLTag] = dict()

		if not self.files.struct_exists and not self.files.merged_exists :
			logger.error(f"No struct file nor merged file found for basename {self.files.base_name}")
			raise FileNotFoundError(f"No struct file nor merged file found for basename {self.files.base_name}")

	def read_split_tags(self):
		if self.files.struct_exists :
			self.__read_struct_tags()
		if self.files.definition_exists :
			self.__read_definition_tags()

	def read_merged_tags(self):
		if self.files.merged_exists :
			self.__read_merged_tags()

	def __read_merged_tags(self):
		self.__read_file_tags(self.files.merged_file,self.merged_tags)

	def __read_struct_tags(self):
		self.__read_file_tags(self.files.struct_file,self.struct_tags)

	def __read_definition_tags(self):
		self.__read_file_tags(self.files.definition_file,self.definition_tags)


	def __read_file_tags(self, filepath: str, tag_dict : T.Dict[str,SooLTag]):
		with open(filepath, "r") as f:
			line_number = -1
			for line in f:
				line_number += 1
				line_data = line.strip()
				if line_data.startswith("//SOOL-"):
					new_tag = SooLTag.from_tag(line_data)

					if new_tag.flagtag not in tag_dict:
						if new_tag.is_stop_boundarie:
							raise RuntimeError("End of tag found before start")
						elif new_tag.is_start_boundarie:
							new_tag.start = line_number
							for c in line :
								if c.isspace():
									new_tag.indent += c
								else :
									break
						else:
							new_tag.set_flagtag_position(line_number)
							for c in line :
								if c.isspace():
									new_tag.indent += c
								else :
									break

						tag_dict[new_tag.flagtag] = new_tag
					else:
						stored_tag = tag_dict[new_tag.flagtag]
						if stored_tag.is_start_boundarie:
							if not new_tag.is_stop_boundarie:
								raise RuntimeError("Not stopping boundarie found while starting boundarie exists")
							stored_tag.is_stop_boundarie = True
							stored_tag.stop = line_number
						else:
							raise RuntimeError(f"Duplicated flag {new_tag.flagtag} found")

	def split_to_merge(self):
		logger.info(f"Merging split data to destination for {self.files.base_name}")
		data_struct = self.files.struct_data.split("\n")
		data_definition = self.files.definition_data.split("\n")
		offset = 0
		for name, tag in self.struct_tags.items() :
			if tag.is_start_boundarie or tag.is_stop_boundarie :
				raise RuntimeError("Found boundaries in struct file")

			pos = tag.start + offset

			if name in self.definition_tags or tag.exclude_boundaries :
				data_struct.pop(pos)
				offset = offset - 1

			if name in self.definition_tags :
				logger.info(f"Replacing tag {name}")
				for line in reversed(data_definition[self.definition_tags[name].start:self.definition_tags[name].stop]):
					data_struct.insert(pos,tag.indent + line)
					offset += 1

		logger.info("Writing result")
		self.files.merged_data = "\n".join(data_struct)

	def merge_to_definition(self):
		logger.info(f"Extracting merged data to definition for {self.files.base_name}")
		data_definition = self.files.definition_data.split("\n")
		data_merged = self.files.merged_data.split("\n")
		to_append : T.List[str] = list()
		offset = 0

		for name, tag in self.merged_tags.items() :
			if tag.is_start_boundarie != tag.is_stop_boundarie :
				raise RuntimeError("Found incomplete boundaries in merged file")
			if not (tag.is_start_boundarie and tag.is_stop_boundarie) :
				continue

			if not name in self.definition_tags :

				to_append.extend([x.replace(tag.indent,'') for x in data_merged[tag.start:tag.stop]])
				continue

			logger.info(f"Replacing tag {name}")
			pos = self.definition_tags[name].start + offset

			for i in range(self.definition_tags[name].start,self.definition_tags[name].stop) :
				data_definition.pop(pos)
				offset = offset -1

			for line in reversed(data_merged[tag.start:tag.stop]):
				data_definition.insert(pos,self.definition_tags[name].indent + line.replace(tag.indent,''))
				offset += 1


		logger.info("Writing result")
		self.files.definition_data = "\n".join(data_definition + to_append)

	def merge_to_struct(self):
		logger.info(f"Extracting merged data to structure for {self.files.base_name}")
		struct_lines: T.List[str] = self.files.merged_data.split("\n")
		offset = 0

		for name, tag in self.merged_tags.items() :
			if tag.is_start_boundarie != tag.is_stop_boundarie :
				raise RuntimeError("Found incomplete boundaries in merged file")
			if not (tag.is_start_boundarie and tag.is_stop_boundarie) :
				continue
			pos = tag.start + offset
			for i in range(tag.start,tag.stop) :
				struct_lines.pop(pos)
				offset = offset -1
			struct_lines.insert(pos,tag.flagtag)
			offset = offset +1

		logger.info("Writing result")
		self.files.struct_data = "\n".join(struct_lines)