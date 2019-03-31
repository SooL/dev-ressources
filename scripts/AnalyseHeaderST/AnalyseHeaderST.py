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


def analyze_svd(svd : str) :
	"""
	This function will read a svd file and extract all informations
	:param svd: Path to SVD file
	"""
	root = ET.parse(svd).getroot()
	
	chip_name = root.find("name").text
	
	for svd_periph in root.findall("peripherals/peripheral"):
		
		periph_baseaddr = svd_periph.find("baseAddress").text
		
		if "derivedForm" in svd_periph.attrib.keys():
			#Some specific stuff here :D
			continue
		periph_name  	= svd_periph.find("name").text
		periph_descr	= svd_periph.find("description").text
		periph_grpname	= svd_periph.find("groupName").text
		
		
		for svd_register in svd_periph.findall("registers/register"):
			reg_name 	= svd_register.find("name").text
			reg_disp	= svd_register.find("displayName").text
			reg_descr 	= svd_register.find("description").text
			reg_offset 	= svd_register.find("addressOffset").text
			reg_size 	= svd_register.find("size").text
			reg_access 	= svd_register.find("access").text
			reg_rst 	= svd_register.find("resetValue").text
			
			for svd_field in svd_register.findall("fields/field"):
				field_name	= svd_field.find("name").text
				field_descr = svd_field.find("description").text
				field_offset = svd_field.find("bitOffset").text
				field_width = svd_field.find("bitWidth").text

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
			
			