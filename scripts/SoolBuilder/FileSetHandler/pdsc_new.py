import logging
import typing as T
import xml.etree.ElementTree as ET
import os, shutil
from copy import copy
import glob

from cleaners.corrector import cmsis_root_corrector
from structure import Chip
from cmsis_analysis import CMSISHeader
from fnmatch import fnmatch
logger = logging.getLogger()


class PDSCHandler:
	def __init__(self,path, analyze = True):
		self.path = path

		self.root : ET.Element = self.cache_and_remove_ns(self.path) if analyze else None

		self.associations : T.Set[Chip] = set()

		self.file_name : str = os.path.basename(self.path)
		self.family = self.file_name[5:self.file_name.rfind("_")]

		self.dest_paths : T.Dict[str,str] = {"svd" : "svd",
											 "header" : f"cmsis/{self.family}",
											 "pdsc" : "fileset"}

	@staticmethod
	def cache_and_remove_ns(filepath):
		"""
		Put the XML content into cache and remove the default namespace if relevant.
		"""
		#logger.info("Removing namespace and caching XML file.")
		with open(filepath, "r", encoding='utf-8') as init_file:
			cached = init_file.read()
			start = cached.find("<package")
			if start > -1:
				stop = cached.find('>', start)
				cached = cached[:start] + "<package" + cached[stop:]
			else:
				logger.warning("No xmlns found")

		return ET.fromstring(cached)

	@property
	def svd_names(self) -> T.List[str]:
		return sorted([os.path.basename(x.svd) for x in self.associations])

	@property
	def svd_to_define(self) -> T.Dict[str,str]:
		return dict([(os.path.basename(x.svd),x.computed_define) for x in self.associations])

	def process(self):
		proc_list : T.List[ET.Element] = self.root.findall("devices/family/processor")
		family : ET.Element
		proc_ok = len(proc_list) > 0
		for family in self.root.findall("devices/family/subFamily") :
			if not proc_ok:
				proc_list = family.findall("processor")

			for processor in proc_list :
				current_assoc = Chip()
				# Can store Dcore if required
				if "Pname" in processor.attrib and processor.attrib["Pname"] :
					current_assoc.processor = processor.attrib["Pname"]

				current_assoc.from_node(family)

				for device in family.findall("device") :
					current_assoc.from_node(device)

					if not current_assoc.is_full :
						logger.error(f"Incomplete fileset for chip {device.attrib['Dname']}.")
					else:
						current_assoc.legalize()
						if current_assoc.fix(device.attrib["Dname"]) :
							# if not "STM32F1" in current_assoc.define and not fnmatch(device.attrib["Dname"],current_assoc.define.replace("x","?") + "*") :
							# 	logger.warning(f"\tChip/Define mismatch {device.attrib['Dname']} got {current_assoc.define}")
							self.associations.add(copy(current_assoc))

	def rebuild_extracted_associations(self,root_destination : str):
		destination_paths = self.dest_paths
		base_path = os.path.dirname(self.path) + "/"
		for key in destination_paths:
			destination_paths[key] = f"{root_destination}/{destination_paths[key]}"

		for assoc in self.associations :
			assoc.header = f'{destination_paths["header"]}/{os.path.basename(assoc.header)}'
			assoc.svd = f'{destination_paths["svd"]}/{os.path.basename(assoc.svd)}'

	def extract_to(self,root_destination :  str) -> "PDSCHandler":

		destination_paths = self.dest_paths
		shutil.rmtree(destination_paths["header"],True)
		base_path = os.path.dirname(self.path) + "/"
		for key in destination_paths :
			destination_paths[key] = f"{root_destination}/{destination_paths[key]}"
			if not os.path.exists(destination_paths[key]) :
				os.makedirs(destination_paths[key])

		ret = PDSCHandler(destination_paths["pdsc"] + "/" + os.path.basename(self.path), analyze=False)

		shutil.copy(self.path,destination_paths["pdsc"])

		header_src_done : T.Set[str] = set()

		for assoc in self.associations :
			if not assoc.is_full :
				logger.warning(f"Ignored not full association for define {assoc.computed_define}")
				continue
			ret.associations.add(Chip(svd=assoc.svd,
										header=assoc.header,
										define=assoc.define,
									  	processor=assoc.processor,
									  pdefine=assoc.processor_define))
			shutil.copy(base_path + assoc.svd,destination_paths["svd"])

			header_src =  base_path + assoc.header
			if header_src not in header_src_done :
				header_src_done.add(header_src)
				for file in glob.glob(f"{os.path.dirname(base_path + assoc.header)}/*.h"):
					logger.info(f"\tBatch retrieving header file {self.family}/{os.path.basename(file)}")
					shutil.copy(file, destination_paths["header"])
		logger.info(f"Files from {os.path.basename(self.path)} extracted to {root_destination}.")
		ret.rebuild_extracted_associations(root_destination)
		return ret

	def compute_cmsis_handlers(self):
		cmsis_handlers : T.Dict[str,CMSISHeader] = dict()

		for assoc in self.associations :
			if assoc.header not in cmsis_handlers :
				cmsis_handlers[assoc.header] = CMSISHeader(assoc.header)
				new_handler = cmsis_handlers[assoc.header]
				new_handler.read()
				new_handler.process_include_table()
				if not new_handler.is_include_map :
					new_handler.process_structural()
				new_handler.clean()

			curr_handler = cmsis_handlers[assoc.header]
			if curr_handler.is_include_map :
				if curr_handler.include_table[assoc.define] not in cmsis_handlers :
					cmsis_handlers[curr_handler.include_table[assoc.define]] = CMSISHeader(curr_handler.include_table[assoc.define])
					curr_handler = cmsis_handlers[curr_handler.include_table[assoc.define]]
					curr_handler.read()
					curr_handler.process_structural()
					curr_handler.apply_corrector(cmsis_root_corrector)
					curr_handler.clean()
				else :
					curr_handler = cmsis_handlers[curr_handler.include_table[assoc.define]]
			#Now the right handler is selected.
			assoc.header = curr_handler.path
			assoc.header_handler = curr_handler
			if not assoc.header_handler.is_structural :
				raise AssertionError(f"Chip header handler should be structural ! ({assoc.computed_define}")
