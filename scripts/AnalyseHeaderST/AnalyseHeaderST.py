#!/usr/bin/python3
# -*-coding:utf-8 -*

"""
Documentation, License etc.

@package AnalyseHeaderST
"""

import logging
import glob

import argparse
import os

from structure import Peripheral
from tools import svd_retriever as svd
from tools.utils import ChipSeriesManager
import typing as T

import xml.etree.ElementTree as ET

########################################################################################################################
#                                                    LOGGER SETTING                                                    #
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

logger.info("Tool startup")

########################################################################################################################
#                                            GLOBAL VARIABLES INITIALIZATION                                           #
########################################################################################################################


# _________________________________________________________________________________________________________________Paths

OutputDirectory = "out/"


def get_node_text(root: ET.Element, node: str) -> str:
	return str() if root.find(node) is None else root.find(node).text


Periph_Correction = {
	'ADC': lambda local_dict, inst_name, desc:
	'ADC_Common' if ('_' in inst_name or inst_name == 'ADC') else "ADC"  # return ADC or ADC_Common
}


def get_peripheral(local_dict, chips, instance_name, group_name, periph_descr):
	"""
	This function is called when the parser reaches a <peripheral> tag with no 'derivedFrom' attribute.
	It creates the peripheral needed for the instance (but not the instance itself).
	Handles the related peripherals thanks to the 'Periph_Correction' dictionary defined above.
	:param local_dict: dictionary containing already defined peripherals
	:param chips: list of chips for which the peripheral must be defined
	:param instance_name: name of the peripheral instance. Only used for corrections
	:param group_name: <group_name> node text value
	:param periph_descr: Peripheral description
	:return:
	"""
	periph_name: str = None

	# If the group includes special peripherals (related to or inside other peripherals)

	special_case = None if (group_name not in Periph_Correction.keys()) else Periph_Correction[group_name]
	if special_case is not None:
		periph_name = special_case(local_dict, instance_name, periph_descr)
	else:
		periph_name = group_name

	if periph_name is None:
		return None

	if local_dict[periph_name] is None:
		periph = Peripheral(periph_name, chips)
		periph.set_brief(periph_descr)
		local_dict[periph_name] = periph
	else:
		if periph_descr != local_dict[periph_name]:
			""  # log

	return local_dict[periph_name]


def analyze_svd(svd_file: str):
	"""
	This function will read a svd file and extract all informations
	:param svd_file: Path to SVD file
	"""
	root = ET.parse(svd_file).getroot()

	local_dict = dict()

	# TODO retrieve chips list from atollic's "tsp.xml" file
	chips = None
	chip_name = get_node_text(root, "name")

	for svd_periph in root.findall("peripherals/peripheral"):

		periph_baseaddr = get_node_text(svd_periph, "baseAddress")

		print(periph_baseaddr)

		if "derivedForm" in svd_periph.attrib.keys():
			# Some specific stuff here :D
			continue

		periph_name = get_node_text(svd_periph, "name")
		print(periph_name)
		periph_descr = get_node_text(svd_periph, "description")
		periph_grpname = get_node_text(svd_periph, "groupName")
		periph = get_peripheral(local_dict, chips, periph_name, periph_grpname, periph_descr)

		if periph is None:
			continue

		for svd_register in svd_periph.findall("registers/register"):
			reg_name = get_node_text(svd_register, "name")
			reg_disp = get_node_text(svd_register, "displayName")
			reg_descr = get_node_text(svd_register, "description")
			reg_offset = get_node_text(svd_register, "addressOffset")
			reg_size = get_node_text(svd_register, "size")
			# ---------- ignored values
			reg_access = get_node_text(svd_register, "access")
			reg_rst = get_node_text(svd_register, "resetValue")
			# ----------
			for svd_field in svd_register.findall("fields/field"):
				field_name = get_node_text(svd_field, "name")
				field_descr = get_node_text(svd_field, "description")
				field_offset = get_node_text(svd_field, "bitOffset")
				field_width = get_node_text(svd_field, "bitWidth")

				print(periph_name, reg_name, field_name)


# ______________________________________________________________________________________________________Template strings


# _____________________________________________________________________________________________________Correction_matrix


if __name__ == "__main__":
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

	if not os.path.exists(svd.file_path):
		logger.info("First initialization")
		svd.init()

	if args.update_all:
		svd.init()
		args.update_svd = svd.defined_archives.keys()

	if args.update_svd is not None and len(args.update_svd):
		logger.warning("Refresh definition for following families :")
		for chip in args.update_svd:
			logger.warning("\t" + chip)
		for chip in args.update_svd:
			svd.download_and_handle(chip)

	FileListing = glob.glob(svd.file_path + "/*.svd")

	full = ChipSeriesManager()
	full.from_file_path(FileListing)

	ChipSeriesManager.set_full_chips(full)

	for file in FileListing:
		analyze_svd(file)

	csm: T.Set[str] = full  # .select("STM32F07")
	# csm.remove_chips(csm.select("F1"),"remove")
	with open(OutputDirectory + "chips.h", "w") as file:
		with open('license_header.txt', 'r') as license:
			file.write(license.read() + full.output_series_definition())
