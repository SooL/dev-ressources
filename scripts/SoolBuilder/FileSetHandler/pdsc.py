import logging
import typing as T
import xml.etree.ElementTree as ET
import os
from structure import ChipSet
#from structure.utils import encoding

logger = logging.getLogger()


class PDSCFile :
	def __init__(self,filepath : str):
		"""
		This class will handle a PDSC file from Keil and extract the mapping between chips names, defines
		and svd files
		
		Nothing have to be done. Only access the result through
		 - self.define_to_svd
		 - self.define_to_chip_mapping
		
		:param filepath: Path to the .pdsc file
		"""
		
		self.file = filepath
		self.define_to_svd: T.Dict[str, str] = dict()
		self.svd_to_define: T.Dict[str,T.Set[str]] = dict()
		self.define_to_cmsis : T.Dict[str,str] = dict()

		if filepath is not None:
			root : ET.Element = self.cache_and_remove_ns(filepath)
			self.process(root)
			del root
		
	def cache_and_remove_ns(self, filepath):
		"""
		Put the XML content into cache and remove the default namespace if relevant.
		"""
		logger.info("Removing namespace and caching XML file.")
		with open(filepath, "r", encoding='utf-8') as init_file :
			cached = init_file.read()
			start = cached.find("<package")
			if start > -1 :
				stop = cached.find('>', start)
				cached = cached[:start] + "<package" + cached[stop :]
			else :
				logger.warning("No xmlns found")
		
		return ET.fromstring(cached)

	def process(self, root: ET.Element):

		for family in root.findall("devices/family/subFamily"):
			# For each recognized "meaningful" family
			# Debug and compile tag can be found at subFamily... or might not !
			logger.info(f"Analyzing family {family.attrib['DsubFamily']}...")
			svd = family.findall("debug[@svd]")
			define = family.findall("compile[@define]")
			# SVD -> Define
			define_svd_map : T.Dict[str,str] = dict()

			if len(svd) > 0 and len(define) > 0:
				#For multicore CPU
				if len(svd) > 1 and len(define) > 1:
					svd_spec : ET.Element
					for svd_spec in svd :
						PnameSVD = svd_spec.attrib["Pname"]
						PnameDef = ""

						for define_spec in define :
							PnameDef = define_spec.attrib["Pname"]
							if PnameDef == PnameSVD :
								define_name = f"{define_spec.attrib['define']}_{PnameDef}"
								svd_name = os.path.basename(svd_spec.attrib['svd'])

								define_svd_map[define_name] = svd_name
								logger.info(f"Multi-processor found : {svd_name} mapped to {define_name}")
								break

					if len(svd) != len(define_svd_map) :
						logger.error(f"Multiprocessor mismatch in chip {family.attrib['DsubFamily']}")
				else:
					define_svd_map[define[0].attrib['define']] =  os.path.basename(svd[0].attrib['svd'])

			for chip in family.findall("device") :
				logger.debug(f'\tChecking {chip.attrib["Dname"]}')
				debug_infos : T.List[ET.Element] = chip.findall("debug[@svd]")
				compile_infos: T.List[ET.Element]= chip.findall("compile[@define]")
				svd_name : str = None
				define_name	: str = None

				if len(define_svd_map) == 0 and len(debug_infos) == 0:
					if len(svd) == 1 :
						svd_name = os.path.basename(svd[0].attrib['svd'])
					else :
						logger.warning(f'\t\tNo SVD association for {chip.attrib["Dname"]:12s}')
						continue
				elif len(debug_infos) > 1 :
					raise NotImplementedError()

				if len(debug_infos) > 0 :
					svd_name = os.path.basename(debug_infos[0].attrib['svd'])

				if len(define_svd_map) == 0 and len(compile_infos) == 0:
					if len(define) == 1 :
						define_name = define[0]
					else:
						logger.warning(f'\t\tNo Header association for {chip.attrib["Dname"]:12s}')
						continue
				elif len(debug_infos) > 1 :
					raise NotImplementedError()

				if len(compile_infos) > 0 :
					define_name = compile_infos[0].attrib['define']

				if svd_name is not None and define is not None :
					define_svd_map[define_name] = svd_name
					ChipSet.reference_chips_name_list.add(define_name)

			for define_name, svd_name in define_svd_map.items():

				if define_name in self.define_to_svd and svd_name != self.define_to_svd[define_name]:
					logger.error(f"\t\tMultiple SVD for {define_name}. "
								 f"Replacing {self.define_to_svd[define_name]} by {svd_name}.")
				self.define_to_svd[define_name] = svd_name

				if define_name is not None:
					if svd_name in self.svd_to_define:
						self.svd_to_define[svd_name].add(define_name)
					else:
						self.svd_to_define[svd_name] = {define_name}

				logger.info(f'\t\tFound association {define_name:12s} -> {svd_name}')
		