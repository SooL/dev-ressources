import logging
import typing as T
import xml.etree.ElementTree as ET
import os

logger = logging.getLogger()


class FilesAssociations:
	def __init__(self,define = None,header = None ,svd = None ):
		self.define : str = define
		self.header : str = header
		self.svd 	: str = svd

	def __hash__(self):
		return hash((self.define,self.header,self.svd))

	def __eq__(self, other):
		if isinstance(other,FilesAssociations) :
			return self.define == other.define and self.header == other.header and self.svd == other.svd

	@property
	def is_full(self):
		return self.define is not None and self.header is not None and self.svd is not None

	def from_node(self,element : ET.Element):
		header_node = element.find("compile[@header]")
		define_node = element.find("compile[@define]")
		svd_node = element.find("debug[@svd]")

		if header_node is not None:
			self.header = header_node.attrib["header"]
		if define_node is not None:
			self.define = define_node.attrib["define"]
		if svd_node is not None:
			self.svd = svd_node.attrib["svd"]




class PDSCHandler:
	def __init__(self,path):
		self.path = path

		self.root : ET.Element = self.cache_and_remove_ns(self.path)

		self.associations : T.Set[FilesAssociations] = set()


	@staticmethod
	def cache_and_remove_ns(filepath):
		"""
		Put the XML content into cache and remove the default namespace if relevant.
		"""
		logger.info("Removing namespace and caching XML file.")
		with open(filepath, "r", encoding='utf-8') as init_file:
			cached = init_file.read()
			start = cached.find("<package")
			if start > -1:
				stop = cached.find('>', start)
				cached = cached[:start] + "<package" + cached[stop:]
			else:
				logger.warning("No xmlns found")

		return ET.fromstring(cached)

	def process(self):
		family : ET.Element
		for family in self.root.findall("devices/family/subFamily") :

			family_files = FilesAssociations()
			family_files.from_node(family)
			# If all required data is found, we just stop here.
			if family_files.is_full :
				self.associations.add(family_files)
				continue

			for device in family.findall("device") :
				device_files = family_files
				device_files.from_node(device)

				if not device_files.is_full :
					logger.error(f"Incomplete fileset for chip {device.attrib['Dname']}.")
				else:
					self.associations.add(device_files)


