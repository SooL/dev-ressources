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
import os
import typing as T
import xml.etree.ElementTree as ET
from structure.chipset import ChipSet, Chip
from structure.group import Group
from structure.peripheral import Peripheral, PeripheralInstance
from copy import copy
logger = logging.getLogger()


def get_node_text(root : ET.Element, node : str) -> str :
	return str() if root.find(node) is None else root.find(node).text

class SVDFile :
	def __init__(self,path : str, chips: T.Set[Chip] = None):
		self.path = os.path.abspath(path)
		self.base_path = os.path.dirname(self.path)
		self.file_name = os.path.basename(self.path)
		self.file_size : int = os.path.getsize(self.path)
		
		# Systematically reparse to avoid huge memory overhead.
		# Performance cost negligible, therefore do not store in self.root.
		#root = ET.parse(path).getroot()
		
		# if chips is None :
		# 	chip : Chip = Chip(get_node_text(root, "name"),self.file_name)
		# 	self.chipset : ChipSet = ChipSet(chip)
		# else :
		self.chipset = ChipSet(chips)
			# for chip in chips :
			# 	self.chipset.add(Chip(chip,self.file_name))
		self.groups : T.Dict[str,Group] = dict()
		
	def __repr__(self):
		return f"{self.file_name}"
		
	def process(self,filter_grp_name : T.List[str] = None):
		logger.info(f"Processing SVD file {self.file_name}")
	
		periph_instances_dict : T.Dict[str,PeripheralInstance] = dict()
		root = ET.parse(self.path).getroot()
		
		if self.chipset.empty :
			self.chipset.add(Chip(get_node_text(root, "name"), self.file_name))
		
		for svd_periph in root.findall("peripherals/peripheral"):
			#periph : Peripheral = None
			group_name : str =  get_node_text(svd_periph, "groupName").upper()
			if "derivedFrom" not in svd_periph.attrib:  # new peripheral
				# return the group associated with the name, and creates it if necessary
				if filter_grp_name is not None and len(filter_grp_name) > 0 and group_name not in filter_grp_name :
					continue
		
				group = Group.get_group(self.groups, group_name)
		
				# create the peripheral, add it to the group
				periph = Peripheral.create_from_xml(self.chipset, svd_periph)
				group.add_peripheral(periph)
		
			else:  # peripheral already exists
				if svd_periph.attrib["derivedFrom"] in periph_instances_dict:
					periph = periph_instances_dict[svd_periph.attrib["derivedFrom"]].parent
				else:
					continue
		
			# create instance from its name, address and base peripheral
			inst_name = svd_periph.find("name").text
			inst_addr = int(svd_periph.find("baseAddress").text, 0)
			inst_brief = get_node_text(svd_periph,"description")
			instance = PeripheralInstance(periph.chips,inst_name,inst_brief,inst_addr)

			# add the instance to its peripheral, and to the instances list
			periph.add_instance(instance)
			periph_instances_dict[inst_name] = instance
		
		for grp_name in self.groups:
			grp = self.groups[grp_name]

			grp.edited = True
			while grp.has_been_edited :
				grp.validate_edit()
				grp.before_svd_compile()

			grp.edited = True
			while grp.has_been_edited :
				grp.validate_edit()
				grp.svd_compile()

			grp.edited = True
			while grp.has_been_edited :
				grp.validate_edit()
				grp.after_svd_compile()
		
	