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
import xml.etree.ElementTree as ET
import os
import glob
import shutil
from fnmatch import fnmatch

from structure import Chip

logger = logging.getLogger()

class STFilesetHandler :
	def __init__(self, path):
		self.path : str = path
		self.root : ET.Element = self.cache_and_remove_ns(self.path)
		self.chips : T.Set[Chip] = set()

		"""
			Supposed for debug only
			Needed to check coherency between ST and Keil data.
		"""

		self.define_svd_assoc : T.Dict[str,str] = dict()

	@staticmethod
	def cache_and_remove_ns(filepath):
		"""
		Put the XML content into cache and remove the default namespace if relevant.
		"""
		# logger.info("Removing namespace and caching XML file.")
		with open(filepath, "r", encoding='utf-8') as init_file:
			cached = init_file.read()
			start = cached.find("<targetDefinitions")
			if start > -1:
				stop = cached.find('>', start)
				cached = cached[:start] + "<targetDefinitions" + cached[stop:]
			else:
				logger.warning("No xmlns found")

		return ET.fromstring(cached)

	def process(self):
		"""
				self.define : str = define
				self.header : str = header
				self.svd 	: str = svd
				self.processor: str = processor
				self.processor_define : str = pdefine
				self.sql_id : int = None
				self.header_handler : CMSISHeader = None
				self.cmsis_options : T.Dict[str,str] = cmsis_options
		"""

		for mcu in self.root.findall("mcu") :
			# chip_name = mcu.find("name").text
			chip_define = mcu.findall("CDefines/CDefine")[-1].text[2:]

			pdefine = None
			cpu_list = mcu.findall("cpus/cpu")
			for cpu in cpu_list:
				chip_coretype = cpu.find("cores/core/type").text
				if len(cpu_list) > 1 :
					pdefine = f"{chip_define}_C{chip_coretype[-2:].upper()}"
				chip_svd = cpu.find("svd/name").text
				self.define_svd_assoc[chip_define] = chip_svd
				self.chips.add(Chip(define=chip_define,svd=chip_svd,processor=chip_coretype,pdefine=pdefine))

	def merge(self,other : "STFilesetHandler"):
		self.chips.update(other.chips)

	def match_defines_svd(self,defines : T.List[str]):
		result : T.Dict[str,T.Set[str]] = dict()
		i = 0
		for pat in defines :
			i += 1
			logger.info(f"Checking pattern {i:3d}/{len(defines)}")
			init = pat
			pat = pat.replace("x","*")
			if pat[-1] != "*" :
				pat += "*"
			for loc in self.define_svd_assoc :
				if fnmatch(loc,pat) :
					if init not in result :
						result[init] = set()
					result[init].add(self.define_svd_assoc[loc])
			if init not in result :
				logger.warning(f"\tNo association found for {init}")
		return result

class FileSetLocator :
	def __init__(self,cubeide_root : str):
		self.root = cubeide_root
		self.svd_list : T.Dict[str,str] = dict()
		self.targets_list : T.List[str] = list()

		self.process()

	def process(self):
		self.svd_list.clear()
		self.targets_list.clear()

		patterns_targets = f"{self.root}/plugins/com.st.stm32cube.ide.m[cp]u.productdb_*/resources/board_def/stm32targets.xml"
		patterns_svd = f"{self.root}/plugins/com.st.stm32cube.ide.m[cp]u.productdb_debug_*/resources/cmsis/STMicroelectronics_CMSIS_SVD/*.svd"

		for target_list_file in glob.glob(patterns_targets) :
			self.targets_list.append(os.path.abspath(target_list_file))

		for svd_file in glob.glob(patterns_svd) :
			self.targets_list[os.path.basename(svd_file)] = os.path.abspath(svd_file)

	def retrieve_svd(self,dest):
		logger.info(f"Retrieving SVD files to {dest}")
		labels = sorted(self.svd_list.keys())
		for i in range(0,len(labels)) :
			logger.info(f"\tCopying SVD {i:03d}/{len(labels)} : {labels[i]}")
			shutil.copy(self.svd_list[labels[i]],dest)

	def retrieve_targets(self,dest):
		logger.info(f"Retrieving targets files to {dest}")
		for i in range(0, len(self.targets_list)):
			logger.info(f"\tCopying target {i:03d}/{len(self.targets_list)} : {self.targets_list[i]}")
			shutil.copy(self.targets_list[i],dest)