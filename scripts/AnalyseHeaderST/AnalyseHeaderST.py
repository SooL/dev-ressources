#!/usr/bin/python3
# -*-coding:utf-8 -*

"""
/**
 * Copyright (c) 2018-2019 FAUCHER Julien & FRANCE Loic
 * This file is part of SooL core library generator .
 *
 *  SooL core library generator is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License
 *  as published by the Free Software Foundation, either version 3
 *  of the License, or (at your option) any later version.
 *
 *  SooL core mibrary generator is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with SooL core Library generator. If not, see <https://www.gnu.org/licenses/>.
 */

@package AnalyseHeaderST
"""


import logging
import glob
import time


import argparse
import os
from Jstructure.Peripheral import PeripheralInstance
from Jstructure import *


from tools import svd_retriever as svd
from tools.utils import ChipSeriesManager
from FileSetHandler.tsp import *
import typing as T
import xml.etree.ElementTree as ET

from FileSetHandler.pdsc import *
from generators import StructureMapper

########################################################################################################################
#                                                 LOGGER SETTING                                                       #
########################################################################################################################

logger = logging.getLogger()
logger.setLevel(logging.DEBUG)

formatter = logging.Formatter("{module:s}::{funcName:s}::{lineno:4<d} - {levelname:5s} : {message}", style="{")

# Log to file handler
log_file_handler = logging.FileHandler("run.log", "w")
log_file_handler.setLevel(logging.DEBUG)
log_file_handler.setFormatter(formatter)
logger.addHandler(log_file_handler)

# Log to console handler
stream_handler = logging.StreamHandler()
stream_handler.setLevel(logging.DEBUG)
logger.addHandler(stream_handler)

log_file_handler = logging.FileHandler("run.issues.log", "w")
log_file_handler.setLevel(logging.WARNING)
log_file_handler.setFormatter(formatter)
logger.addHandler(log_file_handler)

logger.info("Tool startup")


########################################################################################################################
#                                            GLOBAL VARIABLES INITIALIZATION                                           #
########################################################################################################################

# ________________________________________________________________________________________________________________ Paths

OutputDirectory = "out/"
pdsc_path_model = ".data/fileset/*.pdsc"


def get_node_text(root : ET.Element, node : str) -> str :
	return str() if root.find(node) is None else root.find(node).text

########################################################################################################################
#                                                         MAIN                                                         #
########################################################################################################################


if __name__ == "__main__" :
	parser = argparse.ArgumentParser(description="A tool to pre-build SooL")
	parser.add_argument("--update-all",
						action="store_true",
						dest="update_all",
						help="Trigger a full update of svd files")
	parser.add_argument("--update", "-u",
						action="append",
						dest="update_svd",
						help="Add a family to the files to be updated.",
						choices=svd.defined_archives_st.keys())

	args = parser.parse_args()

	if not os.path.exists(svd.file_path) :
		logger.info("First initialization")
		svd.init()

	if args.update_all :
		svd.init()
		args.update_svd = svd.defined_archives_keil.keys()

	if args.update_svd is not None and len(args.update_svd) :
		logger.warning("Refresh definition for following families :")
		for chip in args.update_svd :
			logger.warning("\t" + chip)
		for chip in args.update_svd :
			svd.download_and_handle_keil(chip)

	FileListing = glob.glob(svd.file_path + "/*.svd")

	full = ChipSeriesManager()
	full.from_file_path(FileListing)

	csm: T.Set[str] = full  # .select("STM32F07")
	# csm.remove_chips(csm.select("F1"),"remove")

	periph_list : T.List[Peripheral] = list()
	full_list : T.Dict[str,T.List[Peripheral]] = dict()

	mapping_stm2svd: T.List[PDSCFile] = list()
	
	logger.info("Reading .pdsc files to map STM number to svd...")
	for pdsc_file in glob.glob(pdsc_path_model) :
		logger.info(f"\tReading {pdsc_file}...")
		
		mapping_stm2svd.append(PDSCFile(pdsc_file))
		
	group_list : T.Dict[str,Group] = dict()
	
	for svd_file in FileListing :
		# svd_file = FileListing[0]
		
		root = ET.parse(svd_file).getroot()
		chip_name = get_node_text(root, "name")
		logger.info(f"Working on {svd_file}")
		periph_instances_dict : T.Dict[str, PeripheralInstance] = dict()
		
		for svd_periph in root.findall("peripherals/peripheral") :
			periph = None
			if "derivedFrom" not in svd_periph.attrib :  # new peripheral

				# if peripheral group doesn't exist yet, create it
				group_name = get_node_text(svd_periph, "groupName")
				if group_name not in group_list :
					group_list[group_name] = Group(group_name)

				# create the peripheral, add it to the group
				periph = Peripheral(svd_periph, ChipSet({chip_name}))
				group_list[group_name].add_peripheral(periph)

				# add the new peripheral to the list. TODO see if list is necessary (group list already exists)
				periph_list.append(periph)
			else :  # peripheral already exists
				periph = periph_instances_dict[svd_periph.attrib["derivedFrom"]].reference

			# create instance from its name, address and base peripheral
			inst_name = svd_periph.find("name").text
			inst_addr = int(svd_periph.find("baseAddress").text, 0)
			instance = PeripheralInstance(periph, inst_name, inst_addr, ChipSet({chip_name}))

			# add the instance to its peripheral, and to the instances list
			periph.add_instance(instance)
			periph_instances_dict[inst_name] = instance
		
		#resolve_peripheral_derivation(periph_list)
		
		full_list[svd_file] = copy(periph_list)
		periph_list.clear()
		
	# Here, you have full_list with a dict : File -> list of peripherals
	
	cs = StructureMapper.build_chip_set(mapping_stm2svd)
	
	# Brutal merging. The first peripheral of each group will be used as reference.
	# All other peripherals will be kept for debug purpose. To be cleaned up afterward.
	# Maybe using a while loop with pop to remove all handled periphs ?
	logger.info("Merging peripherals...")
	for group in group_list :
		# if group != "GPIO" :
		#	continue
		logger.info(f"\tWorking on group {group}")
		ref = group_list[group].peripherals[0]
		for periph in group_list[group].peripherals[1:] :
			ref.merge_peripheral(periph)
			
	
	#grps = StructureMapper.build_groups(full_list)
	#grps_varied = StructureMapper.compute_peripherals_variances(full_list,grps)
	with open(OutputDirectory + "chips.h", "w") as file :
		with open('license_header.txt', 'r') as license_header :
			file.write(license_header.read() + full.output_series_definition())

