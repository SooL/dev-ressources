import logging
import typing as T
import xml.etree.ElementTree as ET
#from Jstructure.utils import encoding

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
		root : ET.Element = self.cache_and_remove_ns(filepath)
		
		self.define_to_chip_mapping : T.Dict[str, T.List[str]] = dict()
		self.define_to_svd : T.Dict[str, str] = dict()
		
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
		
		for family in root.findall("devices/family/subFamily") :
			# For each recognized "meaningful" family
			# Debug and compile tag can be found at subFamily... or might not !
			svd = family.find("debug[@svd]")
			define = family.find("compile")
			
			# Compile tag might not contain the define attrib at subFamily level.
			# In this case, skip it.
			if define is not None and "define" not in define.attrib.keys():
				define = None
			
			for chip in family.findall("device") :
				logger.debug(f'Checking {chip.attrib["Dname"]}')
				
				# If the debug tag wasn't previously found, that's because it is within the chip
				# Or because it is not even here.
				if svd is None :
					# If nowhere to be found, skip the whole definition
					if chip.find("debug") is None :
						logger.warning(f'\tNo association for {chip.attrib["Dname"]:12s}')
						continue
					# Else, take the definition from the device.
					svd_name = chip.find("debug").attrib["svd"]
				else :
					svd_name = svd.attrib["svd"]
				
				# If the chip define wasn't found, we will try to have it from the chip
				if define is None :
					# If nowhere to be found, skip the whole definition
					if chip.find("compile") is None :
						logger.warning(f'\tNo header declaration for {chip.attrib["Dname"]:12s}')
						continue
					define_name = chip.find("compile").attrib["define"]
				else :
					define_name = define.attrib["define"]
					
				chip_name = chip.attrib["Dname"]
				
				# Compute the mapping
				# First : add the chip to the list of defines. Therefore define -> list[chip]
				if define_name not in self.define_to_chip_mapping :
					self.define_to_chip_mapping[define_name] = list()
				self.define_to_chip_mapping[define_name].append(chip_name)
				
				# Second : map SVD to define name.
				if define_name in self.define_to_svd and svd_name != self.define_to_svd[define_name] :
					logger.error(f"\tMultiple SVD for {define_name}. "
								 f"Replacing {self.define_to_svd[define_name]} by {svd_name}.")
				self.define_to_svd[define_name] = svd_name
				
				logger.info(f'\tFound association {define_name:12s} -> {svd_name}')
