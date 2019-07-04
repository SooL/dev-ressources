import logging
import typing as T
import xml.etree.ElementTree as ET
import fnmatch
from copy import copy

logger = logging.getLogger()


class PDSCFile :
	def __init__(self,filepath : str):
		
		self.file = filepath
		self.root : ET.Element = self.cache_and_remove_ns(filepath)
		
		self.define_to_chip_mapping : T.Dict[str,T.List[str]] = dict()
		self.define_to_svd : T.Dict[str,str] = dict()
		
		self.process()
		
	def cache_and_remove_ns(self,filepath):
		"""
		Put the XML content into cache and remove the default namespace if relevant.
		"""
		logger.info("Removing namespace and caching XML file.")
		with open(filepath,"r") as init_file :
			cached = init_file.read()
			start = cached.find("<package")
			if start > -1 :
				stop = cached.find('>',start)
				cached = cached[:start] + "<package" + cached[stop :]
			else :
				logger.warning("No xmlns found")
		
		return ET.fromstring(cached)
	
	def process(self):
		
		for family in self.root.findall("devices/family/subFamily") :
			svd = family.find("debug")
			define = family.find("compile")
			
			
			if define is not None and "define" not in define.attrib.keys():
				define = None
			
			
			for chip in family.findall("device") :
				logger.debug(f'Checking {chip.attrib["Dname"]}')
				
				if svd is None :
					if chip.find("debug") is None :
						logger.warning(f'\tNo association for {chip.attrib["Dname"]:12s}')
						continue
					svd_name = chip.find("debug").attrib["svd"]
				else :
					svd_name = svd.attrib["svd"]
				
				if define is None :
					if chip.find("compile") is None :
						logger.warning(f'\tNo header declaration for {chip.attrib["Dname"]:12s}')
						continue
					define_name = chip.find("compile").attrib["define"]
				else :
					define_name = define.attrib["define"]
					
				chip_name = chip.attrib["Dname"]
				if define_name not in self.define_to_chip_mapping :
					self.define_to_chip_mapping[define_name] = list()
				self.define_to_chip_mapping[define_name].append(chip_name)
				
				if define_name in self.define_to_svd and svd_name != self.define_to_svd[define_name] :
					logger.error(f"\tMultiple SVD for {define_name}. "
								 f"Replacing {self.define_to_svd[define_name]} by {svd_name}.")
				self.define_to_svd[define_name] = svd_name
				
				logger.info(f'\tFound association {define_name:12s} -> {svd_name}')
