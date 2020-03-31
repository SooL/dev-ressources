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
import shutil
import tempfile
import zipfile
import typing as T
from FileSetHandler import PDSCFile

logger = logging.getLogger()

class KeilPack:
	data_root : str = ".data"
	pdsc_path : str = f"{data_root}/fileset"
	cmsis_path: str = f"{data_root}/cmsis"
	svd_path  : str = f"{data_root}/svd"

	defined_archives = {
		"STM32F0": "Keil.STM32F0xx_DFP.",
		"STM32F1": "Keil.STM32F1xx_DFP.",
		"STM32F2": "Keil.STM32F2xx_DFP.",
		"STM32F3": "Keil.STM32F3xx_DFP.",
		"STM32F4": "Keil.STM32F4xx_DFP.",
		"STM32F7": "Keil.STM32F7xx_DFP.",
		"STM32H7": "Keil.STM32H7xx_DFP.",
		"STM32L0": "Keil.STM32L0xx_DFP.",
		"STM32L1": "Keil.STM32L1xx_DFP.",
		"STM32L4": "Keil.STM32L4xx_DFP.",
		"STM32L5": "Keil.STM32L5xx_DFP.",
		"STM32MP1": "Keil.STM32MP1xx_DFP.",
		"STM32G0": "Keil.STM32G0xx_DFP.",
		"STM32G4": "Keil.STM32G4xx_DFP.",
		"STM32W1": "Keil.STM32W1xx_DFP.",
		"STM32WB": "Keil.STM32WBxx_DFP."
	}

	default_version = {
		"STM32MP1" : "1.1.0",
		"STM32F4"	: "2.14.0",
		"STM32H7" 	: "2.3.1",
	}

	def __init__(self, path : str):
		self.pack_path = path
		self.pack_file = os.path.basename(self.pack_path)
		self.pack_name = self.pack_file[:self.pack_file.rfind(".")]
		self.extracted_path = None

		self.pdsc = None

	def extract(self,path = None) -> T.Optional[str]:
		if path is None :
			path = os.path.dirname(self.pack_path) + "/temp_extract"
			shutil.rmtree(path,True)
			os.mkdir(path)

		shutil.copy(self.pack_path, f"{path}/{self.pack_name}.zip")

		with zipfile.ZipFile(f"{path}/{self.pack_name}.zip") as zip_handler:
			zip_handler.extractall(path)
			self.extracted_path = path

		if os.path.exists(f"{path}/{self.pack_name}.pdsc") :
			return f"{path}/{self.pack_name}.pdsc"
		else:
			logger.error(f"PDSC File {path}/{self.pack_name}.pdsc not found.")
			return None



