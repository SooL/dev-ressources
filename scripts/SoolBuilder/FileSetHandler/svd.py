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

# root = ET.parse(svd_file).getroot()
# chip_name = get_node_text(root, "name")
# local_chipset = ChipSet({Chip(chip_name, svd_file)})
# logger.info(f"Working on {svd_file}")
# periph_instances_dict: T.Dict[str, PeripheralInstance] = dict()
#
# for svd_periph in root.findall("peripherals/peripheral"):
# 	periph = None
#
# 	if "derivedFrom" not in svd_periph.attrib:  # new peripheral
# 		# return the group associated with the name, and creates it if necessary
# 		if get_node_text(svd_periph, "groupName").upper() != "GPIO":
# 			continue
#
# 		group = Group.get_group(group_dict, get_node_text(svd_periph, "groupName"))
#
# 		# create the peripheral, add it to the group
# 		periph = Peripheral(svd_periph, copy(local_chipset))
# 		group.add_peripheral(periph)
#
# 	else:  # peripheral already exists
# 		if svd_periph.attrib["derivedFrom"] in periph_instances_dict:
# 			periph = periph_instances_dict[svd_periph.attrib["derivedFrom"]].reference
# 		else:
# 			continue
#
# 	# create instance from its name, address and base peripheral
# 	inst_name = svd_periph.find("name").text
# 	inst_addr = int(svd_periph.find("baseAddress").text, 0)
# 	instance = PeripheralInstance(periph, inst_name, inst_addr, periph.chips)
#
# 	# add the instance to its peripheral, and to the instances list
# 	periph.add_instance(instance)
# 	periph_instances_dict[inst_name] = instance
#
# for grp_name in group_dict:
# 	group_dict[grp_name].merge_svd_peripherals()


class SVDFile :
	def __init__(self,path : str, chips: T.Set[str] = None):
		path = os.path.abspath(path)
		self.base_path = os.path.dirname(path)
		self.file_name = os.path.basename(path)
		
		self.root = ET.parse(path).getroot()
		
		if chips is None :
			chip : Chip = Chip(get_node_text(self.root, "name"),self.file_name)
			self.chipset : ChipSet = ChipSet(chip)
		else :
			self.chipset = ChipSet([Chip(x,self.file_name) for x in chips])
			# for chip in chips :
			# 	self.chipset.add(Chip(chip,self.file_name))

				
		self.groups : T.Dict[str,Group] = dict()
		
	def __repr__(self):
		return f"{self.file_name}"
		
	def process(self,filter_grp_name : T.List[str] = None):
		logger.info(f"Processing SVD file {self.file_name}")
	
		periph_instances_dict : T.Dict[str,PeripheralInstance] = dict()
		
		for svd_periph in self.root.findall("peripherals/peripheral"):
			#periph : Peripheral = None
			group_name : str =  get_node_text(svd_periph, "groupName").upper()
			if "derivedFrom" not in svd_periph.attrib:  # new peripheral
				# return the group associated with the name, and creates it if necessary
				if filter_grp_name is not None and group_name not in filter_grp_name :
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

			instance = PeripheralInstance(periph.chips,inst_name,"Dummy Brief",inst_addr)

			# add the instance to its peripheral, and to the instances list
			periph.add_instance(instance)
			periph_instances_dict[inst_name] = instance
		
		for grp_name in self.groups:
			self.groups[grp_name].merge_svd_peripherals()
			
	def cleanup(self):
		for n, g in self.groups.items() :
			g.cleanup()
		del self.root
		
	