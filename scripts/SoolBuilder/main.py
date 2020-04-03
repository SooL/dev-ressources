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

import glob


import argparse
import shutil

from structure import *

from tools import svd_retriever as svd
from tools import global_parameters

import pickle
from FileSetHandler.pdsc import *
from FileSetHandler import PDSCHandler
from FileSetHandler.svd import SVDFile
from  cleaners import register_forbid_autonamefix
from generators.sool_chip_setup import generate_sool_chip_setup
from dispatchers import svd_process_handler

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

########################################################################################################################
#                                            GLOBAL VARIABLES INITIALIZATION                                           #
########################################################################################################################

# ________________________________________________________________________________________________________________ Paths

main_out = "out"
out_include = f"{main_out}/include"
out_sys = f"{main_out}/system/include"
out_rccf = f"{main_out}/rccf"
pdsc_path_model = ".data/fileset/*.pdsc"
pickle_data_path = ".data/SooL.dat"

generation_manifest_path = f"{main_out}/manifest.xml"

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

	from tools import SoolManifest

	from time import time
	import sqlite3 as sql

	from generators import generate_get_bit
	from generators import generate_get_reg
	from generators import generate_records
	from generators import generate_sool_irqn
	from generators import generate_sool_cmsis_config

	start_time = time()

	logger.info("Tool startup")
	parser = argparse.ArgumentParser(description="A tool to pre-build SooL")
	parser.add_argument("--update",
						nargs="+",
						dest="update_svd",
						default=list(),
						help="Add a family to the files to be updated.",
						choices=list(svd.defined_archives_keil.keys()) + ['all'])
	parser.add_argument("--upgrade", "-u",
						nargs="+",
						default=list(),
						dest="upgrade_svd",
						help="Add a family to the files to be upgraded.",
						choices=list(svd.defined_archives_keil.keys()) + ['all'])
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
	# parser.add_argument("--dump",
	# 					action="store_true",
	# 					help="Generate a SooL.dat file which might be used by other scripts")
	parser.add_argument("--reuse",
						action="store_true",
						help="Reuse an existing .data/SooL.dat file to skip the analysis step.")
	parser.add_argument("--force-version",
						action="store_true",
						help="Force packs versions as specified in .data/version.ini")

	args = parser.parse_args()

	global_parameters.read_args(args,svd.defined_archives_keil)

	skip_analysis = False
	output_groups: T.Dict[str, Group] = dict()

	manifest_handler = SoolManifest(generation_manifest_path)

	if global_parameters.reuse_db :
		try :
			logger.info("Trying to restore a previous database...")
			with open(pickle_data_path,"rb") as pickle_file :
				output_groups = pickle.load(pickle_file)
			skip_analysis = True
			logger.info("\tDone !")
		except Exception as e :
			output_groups = dict()
			skip_analysis = False
			logger.error(f"Error while trying to reuse a previous database : {e.__cause__}")

	if global_parameters.big_endian :
		logger.warning("The library will be generated for big endian.")

	if not global_parameters.physical_mapping :
		logger.warning("The library will be generated with non-physical capabilities.")

	if not skip_analysis :
		if not os.path.exists(svd.svd_path) :
			logger.info("First initialization")
			svd.init()

		if global_parameters.fileset_reinit :
			svd.init()

		if global_parameters.need_update :
			if global_parameters.use_local_packs :
				logger.info("Using local packs.")
			logger.warning("Refresh definition for following families :")
			not_retrieved = list()
			for chip in global_parameters.update_list :
				logger.warning("\t" + chip)

				enforced_ver = svd.get_current_version(chip)
				local_failed = False
				local_pack = None
				temp_folder = None
				force_update = chip in global_parameters.family_update_request or global_parameters.enforce_versions

				if global_parameters.use_local_packs :
					local_pack = svd.select_local_keil_pack(chip, enforced_ver if global_parameters.enforce_versions else "*")
					if not force_update and svd.version_cmp(enforced_ver) <= svd.version_cmp(svd.pack_version_string(local_pack)) :
						continue

					local_failed = local_pack is None

				if not global_parameters.use_local_packs or local_failed:
					current_version = svd.keil_get_version(chip) if not global_parameters.enforce_versions else enforced_ver
					if current_version is None and chip in svd.default_version_keil :
						current_version = svd.default_version_keil[chip]
						logger.error(f"Error in getting version number. using static version number {current_version}")
					if not force_update and svd.version_cmp(current_version) <= svd.version_cmp(enforced_ver) :
						continue
					local_pack = svd.retrieve_keil_pack(chip,current_version,global_parameters.store_packs,global_parameters.enforce_versions)
					if local_pack is not None :
						temp_folder = os.path.dirname(local_pack)

				if local_pack is not None :
					t = svd.handle_keil_pack(local_pack)
				else:
					not_retrieved.append(chip)
					continue
				if temp_folder is not None :
					shutil.rmtree(temp_folder)

			if len(not_retrieved) > 0 :
				logger.warning("Several chip families have not been retrieved :")
				for chip in sorted(not_retrieved) :
					logger.warning(f"\t{chip}")
			else:
				logger.info("All families retrieved")

		FileListing = sorted(glob.glob(svd.svd_path + "/*.svd"))

		periph_list : T.List[Peripheral] = list()
		pdsc_handlers: T.List[PDSCHandler] = list()
		group_dict : T.Dict[str, Group] = dict()
		svd_list : T.Dict[str,SVDFile] = dict()

		register_forbid_autonamefix.setup()

		logger.info("Reading .pdsc files to map STM number to svd...")
		for pdsc_file in glob.glob(pdsc_path_model):
			logger.info(f"Reading {pdsc_file}...")
			pdsc_handlers.append(PDSCHandler(pdsc_file))
			pdsc_handlers[-1].process()
			pdsc_handlers[-1].rebuild_extracted_associations("./.data")
			pdsc_handlers[-1].compute_cmsis_handlers()

		for pdsc_file in pdsc_handlers :
			pdsc_file.check_svd_define_association()
		define_done_set = set()
		i = 1
		logger.info("Build SVD list...")
		for pdsc in pdsc_handlers :
			j = 1
			logger.info(f"Read PDSC {pdsc.path}")
			for assoc in pdsc.associations :
				logger.debug(f"Handling PDSC {i:2d}/{len(pdsc_handlers)} - Assoc {j:3d}/{len(pdsc.associations)}.")
				j += 1
				if not assoc.is_full :
					logger.error("\tSkip not full association.")
					continue

				if os.path.exists(assoc.svd) :
					if assoc.computed_define in define_done_set :
						logger.error(f"\tSkipped due to define {assoc.computed_define} already read")
						if assoc.svd not in svd_list :
							logger.error(f"\t\tSVD File {assoc.svd} skipped !")
						continue
					define_done_set.add(assoc.computed_define)
					if assoc.svd not in svd_list :
						svd_list[assoc.svd] = SVDFile(assoc.svd,{assoc})
					else :
						svd_list[assoc.svd].chipset.add(assoc)
			i += 1
		used_svd = set()

		logger.info("SVD list done, begin processing")
		svd_list = svd_process_handler(svd_list,global_parameters.group_filter)

		for pdsc in pdsc_handlers :
			manifest_handler.add_pdsc_version(pdsc.family,pdsc.version_string)

		with open("reports/used_svd.txt","w") as report :
			data = ""
			for f in sorted(svd_list.keys()) :
				handler = svd_list[f]
				data += f"{os.path.basename(f):20s} - {handler.chipset}\n"
				used_svd.add(os.path.basename(f))
			existing_svd = {os.path.basename(x) for x in glob.glob(".data/svd/*.svd")}
			unused_svd = sorted(list(existing_svd - {os.path.basename(x) for x in svd_list.keys()}))

			data += f"\n{' UNUSED FILES ':=^80s}\n"
			for f in unused_svd :
				data += f"{f}\n"
			report.write(data)


		with open("reports/used_svd.txt","a") as report :
			data = ""
			delta_svd = sorted(list(used_svd - {os.path.basename(x.path) for x in svd_list.values()}))
			if len(delta_svd) > 0 :
				data += f"\n{' UNPROCESSED FILES ':=^80s}\n"
				for f in delta_svd :
					data += f"{f}\n"


		i = 1
		for name, svd in svd_list.items() :
			logger.info(f"Final merge {i:2d}/{len(svd_list)} of SVD {svd.file_name} ")
			for name, data in svd.groups.items() :
				if name not in output_groups :
					output_groups[name] = data
				else:
					output_groups[name].inter_svd_merge(data)
			i += 1
		del i

		for name, group in output_groups.items() :
			logger.info(f"Finalizing {name}")
			group.finalize()

		if global_parameters.dump_db:
			logger.info("Dumping data to .data/SooL.dat")
			with open(".data/SooL.dat", "wb") as dump_file:
				pickle.dump(output_groups, dump_file)

		# End of generation section. If reuse specified, the code will start here
	#sanity.report_sanity(output_groups)

	if args.refresh_output :
		if os.path.exists("out/") :
			shutil.rmtree("out")
		os.makedirs(out_include)
		os.makedirs(out_sys)

	logger.info("Printing output files...")
	for name, group in output_groups.items():
		if not global_parameters.got_group_filter or name in global_parameters.group_filter :
			with open(f"{out_include}/{name}_struct.h","w") as header :
				header.write(group.cpp_output())

			manifest_handler.add_generated_group(name)

	manifest_handler.add_chip(ChipSet.reference_chipset)
	logger.info("Printing manifest...")
	manifest_handler.construct_xml()
	manifest_handler.write_file()


	with open(f"{main_out}/sool_chip_setup.h", "w") as header:
		header.write(generate_sool_chip_setup())

	with open(f"{out_sys}/IRQn.h", "w") as irq_table :
		irq_table.write(generate_sool_irqn())
		pass

	with open(f"{out_sys}/cmsis_config.h", "w") as cmsis_configuration :
		cmsis_configuration.write(generate_sool_cmsis_config())
		pass


	if global_parameters.dump_sql :
		logger.info("Generating SQL database...")
		if os.path.exists("out/database.sqlite3"):
			os.remove("out/database.sqlite3")
		db = sql.connect("out/database.sqlite3")
		with open("sql/create_db.sql","r") as script :
			db.executescript(script.read())
		cursor = db.cursor()
		logger.info("\tDumping chipset...")
		ChipSet.reference_chipset.generate_sql(cursor)
		db.commit()
		for name,group in output_groups.items() :
			if global_parameters.got_group_filter and name not in global_parameters.group_filter :
				continue
			logger.info(f"\tDumping {name}...")
			group.generate_sql(cursor)
			db.commit()
		logger.info("Done")

	if global_parameters.dump_rccf :
		os.makedirs(out_rccf,exist_ok=True)
		for name,group in output_groups.items():
			if name == "RCC" or global_parameters.got_group_filter and name not in global_parameters.group_filter :
				continue
			for periph in group.peripherals :
				logger.info(f"RCCF generation for {periph.name}")
				with open(f"{out_rccf}/{periph.name}.h","w") as rccf :
					records = generate_records(periph,output_groups['RCC'].peripherals[0])
					rccf.write(generate_get_reg(records,periph))
					rccf.write(generate_get_bit(records,periph))



	end_time = time()
	print("End of process.")
	print(f"Elapsed time : {end_time - start_time:.2f}s")

