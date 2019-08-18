#!/usr/bin/python3
# -*-coding:utf-8 -*

"""
Documentation, License etc.

@package AnalyseHeaderST
"""


import logging
import glob
import time


import argparse
import os
from Jstructure.Peripheral import resolve_peripheral_derivation, PeripheralInstance
from Jstructure import *
from Jstructure.Field import Field
from Jstructure.Register import Register

#from structure import Peripheral, Group
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
#tsp_path = "C:/Program Files (x86)/Atollic/TrueSTUDIO for STM32 9.3.0/ide/plugins/com.atollic.truestudio.tsp.stm32_1.0.0.20190212-0734/tsp.xml"
tsp_path = "/opt/Atollic_TrueSTUDIO_for_STM32_x86_64_9.2.0/ide/plugins/com.atollic.truestudio.tsp.stm32_1.0.0.20181203-0921/tsp.xml"
#cmsis_headers_dir = "C:/Users/RichardFrance/Documents/SOOL/sool-main/dev-ressources/scripts/CMSIS header files/stm32*.h"
cmsis_headers_dir = "/home/julien/Projets/sool-main/dev-ressources/scripts/CMSIS header files/stm32*.h"
pdsc_path_model = ".data/fileset/*.pdsc"
# _______________________________________________________________________________________________Peripheral dictionaries

#groups: T.Dict[Group] = dict()


########################################################################################################################
#                                               FILE ANALYZERS FUNCTIONS                                               #
########################################################################################################################


def compute_tsp(path=tsp_path):
	file_list = glob.glob(cmsis_headers_dir)
	file_list = [t[t.replace("\\", "/").rfind("/") + 1:-2] for t in file_list]
	print("files number : " + str(len(file_list)))
	for f in file_list:
		print("file : " + f)

	f = TSPFile(path)
	f.cache_and_remove_ns()
	f.create_xml_root()

	f.build_mcu_custom_tree()
	f.compute_designators(file_list)
	
	peripheral_list : T.Dict[str, T.List[Peripheral]] = dict()
	svd_list = list()
	i = 1
	for group in f.mcu_custom_tree :
		for desc in group :
			if desc.svd_file in svd_list :
				continue
			else :
				logger.info(f"Working on {desc.svd_file}")
				svd_list.append(desc.svd_file)
			svd_path = tsp_path[:tsp_path.rfind("/")] + "/tsp/sfr/" + desc.svd_file
			
			peripheral_list[desc.svd_file] = build_peripheral_list(svd_path)
			
	return peripheral_list
			
			


def get_node_text(root : ET.Element, node : str) -> str :
	return str() if root.find(node) is None else root.find(node).text

"""def create_Peripheral(node):
	group_name = get_node_text(node, "groupName")
	if group_name in
"""

def build_peripheral_list(svd_file):
	root = ET.parse(svd_file).getroot()
	out = list()
	
	for svd_periph in root.findall("peripherals/peripheral") :
		out.append(Peripheral(svd_periph))
		
	return out



def analyze_svd(svd_file : str) :
	"""
	This function will read a svd file and extract all informations
	:param svd_file: Path to SVD file
	"""
	root = ET.parse(svd_file).getroot()
	output = dict()
	chip_name = get_node_text(root, "name")

	for svd_periph in root.findall("peripherals/peripheral"):


		
		periph_baseaddr = get_node_text(svd_periph, "baseAddress")

		if "derivedForm" in svd_periph.attrib.keys():
			# TODO create instance
			pass
		periph_name  	= get_node_text(svd_periph, "name")
		output[int(periph_baseaddr, 0)] = periph_name
		continue

		periph_descr	= get_node_text(svd_periph, "description")
		periph_grpname	= get_node_text(svd_periph, "groupName")

		for svd_register in svd_periph.findall("registers/register"):
			reg_name 	= get_node_text(svd_register, "name")
			reg_disp	= get_node_text(svd_register, "displayName")
			reg_descr 	= get_node_text(svd_register, "description")
			reg_offset 	= get_node_text(svd_register, "addressOffset")
			reg_size 	= get_node_text(svd_register, "size")
			reg_access 	= get_node_text(svd_register, "access")
			reg_rst 	= get_node_text(svd_register, "resetValue")

			for svd_field in svd_register.findall("fields/field"):
				field_name = get_node_text(svd_field, "name")
				field_descr = get_node_text(svd_field, "description")
				field_offset = get_node_text(svd_field, "bitOffset")
				field_width = get_node_text(svd_field, "bitWidth")

				print(periph_name,reg_name,field_name)

	return output


def comparison_table(svd1: str, svd2 : str, outfile=None) :

	ref1 = analyze_svd(svd1)
	ref2 = analyze_svd(svd2)

	addr_list = sorted(list(set(ref1.keys()) | set(ref2.keys())))
	line_model = "0x{addr:08x} {per1:15s} | {per2:15s}\n"

	out = ""
	out += "Comparing PERIPHERAL MAPPING\n\t" + svd1 + "\n\t" + svd2 + "\n"
	for addr in addr_list :
		out += line_model.format(addr=addr,
								 per1="---------------" if addr not in ref1 else ref1[addr],
								 per2="---------------" if addr not in ref2 else ref2[addr])

	if outfile is None :
		print(out)
	else :
		with open(outfile,"w") as f :
			f.write(out)


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

	#compute_tsp()

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
		#svd_file = FileListing[0]
		
		root = ET.parse(svd_file).getroot()
		output = dict()
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
				periph = periph_instances_dict[svd_periph.attrib["derivedFrom"]].reference.reference

			# create instance from its name, address and base peripheral
			inst_name = svd_periph.find("name").text
			inst_addr = int(svd_periph.find("baseAddress").text, 0)
			instance = PeripheralInstance(periph.mappings[0], inst_name, inst_addr, ChipSet({chip_name}))

			# add the instance to its peripheral, and to the instances list
			periph.add_instance(instance)
			periph_instances_dict[inst_name] = instance
		
		#resolve_peripheral_derivation(periph_list)
		
		full_list[svd_file] = copy(periph_list)
		periph_list.clear()
		
	#Here, you have full_list with a dict : File -> list of peripherals
	
	cs = StructureMapper.build_chip_set(mapping_stm2svd)
	
	#Brutal merging. The first peripheral of each group will be used as reference.
	#All other peripherals will be kept for debug purpose. To be cleaned up afterward.
	#Maybe using a while loop with pop to remove all handled periphs ?
	logger.info("Merging peripherals...")
	for group in group_list :
		logger.info(f"\tWorking on group {group}")
		ref = group_list[group].peripherals[0]
		for periph in group_list[group].peripherals[1:] :
			ref.merge_peripheral(periph)
			
	
	#grps = StructureMapper.build_groups(full_list)
	#grps_varied = StructureMapper.compute_peripherals_variances(full_list,grps)
	with open(OutputDirectory + "chips.h", "w") as file :
		with open('license_header.txt', 'r') as license_header :
			file.write(license_header.read() + full.output_series_definition())

