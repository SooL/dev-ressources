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


import argparse
import os
import shutil
from structure import *


from tools import svd_retriever as svd
from tools import sanity
import typing as T
import xml.etree.ElementTree as ET

from FileSetHandler.pdsc import *
from FileSetHandler.svd import SVDFile
from cleaners.create_peripheral import create_association_table, TIM_log
from  cleaners import register_forbid_autonamefix
from generators.sool_chip_setup import generate_sool_chip_setup

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


def report_debilus(group_list : T.Dict[str,Group]) :
	out =""
	for group in group_list :
		out += f"Group : {group}\n"
		for p in group_list[group].peripherals :
			out += f"\tPeripheral : {p.name}\n"
			chips_sum : T.Dict[str,T.List[int]] = dict()
			
			for m in p.mappings :
				for c in m.chips.chips :
					if c not in chips_sum :
						chips_sum[c] = [p.mappings.index(m)]
					else :
						chips_sum[c].append(p.mappings.index(m))
			i = 1
			for chip_name, lst in chips_sum.items() :
				if len(lst) > 1 :
					out += f"\t\tIssue : Chip {chip_name} is found {len(lst)} times. Indexes : {str(lst)}\n"
	
	return out
	
	
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
						choices=svd.defined_archives_keil.keys())
	parser.add_argument("--limit-groups",
						dest="group_filter",
						help="groups to regenerate",
						default=None)
	parser.add_argument("-k","--keep-generated",
						action="store_false",
						dest="refresh_output",
						help="Keeps all non-refreshed output files")

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

	FileListing = sorted(glob.glob(svd.file_path + "/*.svd"))

	periph_list : T.List[Peripheral] = list()
	mapping_stm2svd: T.List[PDSCFile] = list()
	group_dict : T.Dict[str, Group] = dict()
	svd_list : T.List[SVDFile] = list()

	register_forbid_autonamefix.setup()

	logger.info("Reading .pdsc files to map STM number to svd...")
	for pdsc_file in glob.glob(pdsc_path_model):
		logger.info(f"\tReading {pdsc_file}...")
		mapping_stm2svd.append(PDSCFile(pdsc_file))

	for svd_file in FileListing:
		handler = None
		for pdsc in mapping_stm2svd :
			if os.path.basename(svd_file) in pdsc.svd_to_define :
				handler = SVDFile(svd_file,pdsc.svd_to_define[os.path.basename(svd_file)])
				break
		if handler is None :
			logger.warning(f"No define found for svd file {svd_file}")
			continue
			# To add a default define based upon SVD name, uncomment
			# handler = SVDFile(svd_file)
			
		handler.process(args.group_filter.split(",") if args.group_filter is not None else None)
		#handler.cleanup()
		svd_list.append(handler)

	TIM_log() # DEGUB
	
	output_groups : T.Dict[str,Group] = dict()
	
	i = 1
	for svd in svd_list :
		logger.info(f"Final merge {i:2d}/{len(svd_list)} of SVD {svd.file_name} ")
		for name, data in svd.groups.items() :
			if name not in output_groups :
				output_groups[name] = data
			else:
				output_groups[name].merge_group(data)
		i += 1
	del i


	logger.info("Iterative merging...")
	for name, group in output_groups.items() :
		if group.have_been_edited :
			for periph in group.peripherals :
				while periph.have_been_edited :
					logger.info(f"Re-merging {periph.name}")
					periph.self_merge()
					#periph.clean_register_list()
					periph.perform_name_rework()

	for name, group in output_groups.items() :
		logger.info(f"Finalizing {name}")
		group.finalize()

	#sanity.report_sanity(output_groups)
	
	if args.refresh_output :
		if os.path.exists("out/") :
			shutil.rmtree("out")
		os.mkdir("out")

	for name, group in output_groups.items():
		with open(f"out/{name}.h","w") as header :
			header.write(group.cpp_output())

	with open(f"out/sool_chip_setup.h", "w") as header:
		header.write(generate_sool_chip_setup())

	print("End of process.")

