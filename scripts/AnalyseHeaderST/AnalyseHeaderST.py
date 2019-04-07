#!/usr/bin/python3
# -*-coding:utf-8 -*

'''
Documentation, License etc.

@package AnalyseHeaderST
'''


import logging
########################################################################################################################
#                                                 LOGGER SETTING                                                       #
########################################################################################################################

logger = logging.getLogger()
logger.setLevel(logging.DEBUG)

formatter = logging.Formatter("{module:s}::{funcName:s}::{lineno:4<d} - {levelname:5s} : {message}",style="{")

#Log to file handler
log_file_handler = logging.FileHandler("run.log","w");
log_file_handler.setLevel(logging.DEBUG)
log_file_handler.setFormatter(formatter)
logger.addHandler(log_file_handler)

#Log to console handler
stream_handler = logging.StreamHandler()
stream_handler.setLevel(logging.DEBUG)
logger.addHandler(stream_handler)

logger.info("Tool startup")


import glob
import time


import argparse
import os

from tools import svd_retriever as svd
from tools.utils import ChipSeriesManager
import typing as T


########################################################################################################################
#                                            GLOBAL VARIABLES INITIALIZATION                                           #
########################################################################################################################



# _________________________________________________________________________________________________________________ Paths

OutputDirectory = "out/"

import xml.etree.ElementTree as ET

def get_node_text(root : ET.Element, node : str) -> str :
	return str() if root.find(node) is None else root.find(node).text

def analyze_svd(svd : str) :
	"""
	This function will read a svd file and extract all informations
	:param svd: Path to SVD file
	"""
	root = ET.parse(svd).getroot()
	output = dict()
	chip_name = get_node_text(root,"name")
	
	for svd_periph in root.findall("peripherals/peripheral"):
		
		periph_baseaddr = get_node_text(svd_periph,"baseAddress")
		
		if "derivedForm" in svd_periph.attrib.keys():
			#Some specific stuff here :D
			pass
		periph_name  	= get_node_text(svd_periph,"name")
		output[int(periph_baseaddr,0)] = periph_name
		continue
		periph_descr	= get_node_text(svd_periph,"description")
		periph_grpname	= get_node_text(svd_periph,"groupName")
		
		for svd_register in svd_periph.findall("registers/register"):
			reg_name 	= get_node_text(svd_register,"name")
			reg_disp	= get_node_text(svd_register,"displayName")
			reg_descr 	= get_node_text(svd_register,"description")
			reg_offset 	= get_node_text(svd_register,"addressOffset")
			reg_size 	= get_node_text(svd_register,"size")
			reg_access 	= get_node_text(svd_register,"access")
			reg_rst 	= get_node_text(svd_register,"resetValue")
			
			for svd_field in svd_register.findall("fields/field"):
				field_name	= get_node_text(svd_field,"name")
				field_descr = get_node_text(svd_field,"description")
				field_offset = get_node_text(svd_field,"bitOffset")
				field_width = get_node_text(svd_field,"bitWidth")
				
				print(periph_name,reg_name,field_name)
	
	return output
				
def comparison_table(svd1: str, svd2 : str,outfile = None) :
	
	
	
	ref1 = analyze_svd(svd1)
	ref2 = analyze_svd(svd2)
	
	addr_list = sorted(list(set(ref1.keys()) | set(ref2.keys())))
	line_model = "0x{addr:08x} {per1:15s} | {per2:15s}\n"
	
	out =""
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
# ______________________________________________________________________________________________________Template strings



# _____________________________________________________________________________________________________Correction_matrix


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
						choices=svd.defined_archives.keys())
	
	args = parser.parse_args()
	
	if not os.path.exists(svd.file_path) :
		logger.info("First initialization")
		svd.init()
	
	if args.update_all :
		svd.init()
		args.update_svd = svd.defined_archives.keys()
	
	if args.update_svd is not None and len(args.update_svd) :
		logger.warning("Refresh definition for following families :")
		for chip in args.update_svd :
			logger.warning("\t" + chip)
		for chip in args.update_svd :
			svd.download_and_handle(chip)
	
	FileListing = glob.glob(svd.file_path + "/*.svd")
	
	full = ChipSeriesManager()
	full.from_file_path(FileListing)
	
	csm: T.Set[str] = full  # .select("STM32F07")
	# csm.remove_chips(csm.select("F1"),"remove")
	with open(OutputDirectory + "chips.h","w") as file :
		with open('license_header.txt','r') as license :
			file.write(license.read() + full.output_series_definition())
			
			