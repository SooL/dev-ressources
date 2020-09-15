#!/usr/bin/python3
# -*-coding:utf-8 -*



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

import argparse
import logging
from tools import global_parameters


########################################################################################################################
#                                                 LOGGER SETTING                                                       #
########################################################################################################################
# Logger shall be initialized in global of main in order to be used in multi-thread stuff.
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

########################################################################################################################
#                                                         MAIN                                                         #
########################################################################################################################
	
if __name__ == "__main__" :

	from time import time
	from builder import SooLBuilder

	logger.info("Tool startup")
	parser = argparse.ArgumentParser(description="A tool to pre-build SooL")
	parser.add_argument("--update",
						nargs="+",
						dest="update_svd",
						default=list(),
						help="Add a family to the files to be updated.",
						choices=list(global_parameters.defined_keil_archive.keys()) + ['all'])
	parser.add_argument("--upgrade", "-u",
						nargs="+",
						default=list(),
						dest="upgrade_svd",
						help="Add a family to the files to be upgraded.",
						choices=list(global_parameters.defined_keil_archive) + ['all'])
	parser.add_argument("--use-local-packs",
						action="store_true",
						help="Try to use the local packs repository (.data/packs)")
	parser.add_argument("--store-packs",
						action="store_true",
						help="Store the downloaded .pack files in .data/packs instead of using a temporary location")
	parser.add_argument("--limit-groups",
						nargs="+",
						dest="group_filter",
						help="groups to regenerate",
						default=list())
	parser.add_argument("--limit-chips",
						nargs="+",
						dest="chips_filter",
						help="Chips to consider",
						default=list())
	parser.add_argument("--exclude-chips",
						nargs="+",
						dest="chips_exclude",
						help="Chips to exclude",
						default=list())
	parser.add_argument("--generate","-g",
						nargs="+",
						default=list(),
						choices=global_parameters.generate_options.keys(),
						help="Generation options. " +
						  "Available options are :\n\t" +
						  "\n\t".join([f"{n} : {x}" for n,x in global_parameters.generate_options.items()]))
	parser.add_argument("-k","--keep-generated",
						action="store_false",
						dest="refresh_output",
						help="Keeps all non-refreshed output files")
	parser.add_argument("--jobs","-j",
						help="Job ammount, be careful of RAM usage...",
						default=1,
						type=int)
	parser.add_argument("--reuse",
						action="store_true",
						help="Reuse an existing .data/SooL.dat file to skip the analysis step.")
	parser.add_argument("--force-version",
						action="store_true",
						help="Force packs versions as specified in .data/version.ini")
	parser.add_argument("--cubeide-path",
						type=str,
						default=None,
						help="Path to STM32CubeIDE installation")

	# Start of actual code
	args = parser.parse_args()
	global_parameters.read_args(args,global_parameters.defined_keil_archive)

	builder = SooLBuilder(global_parameters)
	start_time = time()
	builder.run()
	end_time = time()
	print("End of process.")
	print(f"Elapsed time : {end_time - start_time:.2f}s")
	quit(0)
