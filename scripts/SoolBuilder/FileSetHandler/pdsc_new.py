import logging
import typing as T
import xml.etree.ElementTree as ET
import os, shutil


logger = logging.getLogger()


class FilesAssociations:
	def __init__(self,define = None,header = None ,svd = None, processor = None ):
		self.define : str = define
		self.header : str = header
		self.svd 	: str = svd
		self.processor: str = processor

	def __hash__(self):
		return hash((self.define,self.header,self.svd,self.processor))

	def __eq__(self, other):
		if isinstance(other,FilesAssociations) :
			return self.define == other.define and self.header == other.header and self.svd == other.svd and \
				   self.processor == other.processor

	def __str__(self):
		return f'{self.define}{"" if self.processor is None else "_" + self.processor:<5s} : H = {self.header} S = {self.svd}'

	@property
	def is_full(self):
		return self.define is not None and self.header is not None and self.svd is not None

	def from_node(self,element : ET.Element):
		headers = element.findall("compile[@header]")
		defines = element.findall("compile[@define]")
		svds = element.findall("debug[@svd]")

		for header_node in headers:
			if self.processor is None or ("Pname" in header_node.attrib and header_node.attrib["Pname"] == self.processor) :
				self.header = header_node.attrib["header"]
		for define_node in defines :
			if self.processor is None or ("Pname" in define_node.attrib and define_node.attrib["Pname"] == self.processor):
				self.define = define_node.attrib["define"]
		for svd_node in svds:
			if self.processor is None or ("Pname" in svd_node.attrib and svd_node.attrib["Pname"] == self.processor):
				self.svd = svd_node.attrib["svd"]
	@property
	def computed_define(self):
		return f'{self.define}{"_" + self.processor if self.processor is not None else ""}'




class PDSCHandler:
	def __init__(self,path, analyze = True):
		self.path = path

		self.root : ET.Element = self.cache_and_remove_ns(self.path) if analyze else None

		self.associations : T.Set[FilesAssociations] = set()
		self.dest_paths : T.Dict[str,str] = {"svd" : "svd",
											 "header" : "cmsis",
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
				current_assoc = FilesAssociations()
				# Can store Dcore if required
				if "Pname" in processor.attrib and processor.attrib["Pname"] :
					current_assoc.processor = processor.attrib["Pname"]

				current_assoc.from_node(family)
				# If all required data is found, we just stop here.
				if current_assoc.is_full :
					self.associations.add(current_assoc)
					continue

				for device in family.findall("device") :
					current_assoc.from_node(device)

					if not current_assoc.is_full :
						logger.error(f"Incomplete fileset for chip {device.attrib['Dname']}.")
					else:
						self.associations.add(current_assoc)

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
		base_path = os.path.dirname(self.path) + "/"
		for key in destination_paths :
			destination_paths[key] = f"{root_destination}/{destination_paths[key]}"
			if not os.path.exists(destination_paths[key]) :
				os.makedirs(destination_paths[key])

		ret = PDSCHandler(destination_paths["pdsc"] + "/" + os.path.basename(self.path), analyze=False)

		shutil.copy(self.path,destination_paths["pdsc"])
		for assoc in self.associations :
			if not assoc.is_full :
				logger.warning(f"Ignored not full association for define {assoc.computed_define}")
				continue
			ret.associations.add(FilesAssociations(svd=assoc.svd,
												   header=assoc.header,
												   define=assoc.computed_define))
			shutil.copy(base_path + assoc.svd,destination_paths["svd"])
			shutil.copy(base_path + assoc.header, destination_paths["header"])
		logger.info(f"Files from {os.path.basename(self.path)} extracted to {root_destination}.")
		ret.rebuild_extracted_associations(root_destination)
		return ret
