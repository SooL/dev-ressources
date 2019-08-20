import logging
import typing as T
import xml.etree.ElementTree as ET
import fnmatch
from copy import copy

logger = logging.getLogger()


def get_node_text(root: ET.Element, node: str) -> str:
	return str() if root.find(node) is None else root.find(node).text


class MCUDescriptor:
	def __init__(self, name: str, svd_file: str, device: str):
		self.name = name

		self.svd_file = svd_file
		self.device = device
		self.memory_mapping: T.Dict[str, int] = dict()
		self.symbols: T.Dict[str, T.Union[str, None]] = dict()
		self.designator = str()

	def __hash__(self):
		return hash((self.name, self.svd_file))

	def __lt__(self, other):
		if isinstance(other, MCUDescriptor):
			return self.name < other.name

	def __eq__(self, other):
		if isinstance(other, MCUDescriptor):
			return self.name == other.name

	def __repr__(self):
		return f"{self.name} @ {list(self.symbols.keys())[0]}"

	def add_memory(self, name: str, addr):
		if isinstance(addr, str):
			self.memory_mapping[name] = int(addr, 0)
		elif isinstance(addr, int):
			self.memory_mapping[name] = int(addr)
		else:
			raise TypeError("Address must be str or int but " + str(type(addr)) + " provided")

	def add_symbol(self, symbol_name: str, symbol_value: T.Union[str, None]):
		if symbol_name in self.symbols:
			logger.warning(f"{symbol_name} is redefined from {self.symbols[symbol_name]} to {symbol_value}")
		self.symbols[symbol_name] = symbol_value

	def add_symbol_description(self, symbol_description: str):
		if "=" not in symbol_description:
			self.add_symbol(symbol_description, None)
		else:
			self.add_symbol(symbol_description[:symbol_description.find("=")].strip(None),
			                symbol_description[symbol_description.find("=") + 1:].strip(None))

	def select_designator(self, paterns: T.List[str], skip_sort=False) -> bool:
		loc_list = paterns if skip_sort else sorted(paterns)
		for p in sorted(loc_list):
			if fnmatch.fnmatch(self.name, p.replace("X", "?")):
				self.designator = p.replace("X", "x")
				logger.debug(f"{self.name} is designated by {self.designator}")
				return True
		logger.warning(f"{self.name} is not designated.")
		return False


class MCUGroup:
	def __init__(self, name: str):
		self.name = name
		self.children: T.Set[MCUDescriptor] = set()

	def add(self, child: MCUDescriptor):
		self.children.add(child)

	def __repr__(self):
		return f"{self.name}"

	def __iter__(self):
		return iter(list(self.children))


class TSPFile:
	def __init__(self, file_path: str):
		"""
		tsp.xml file handler generally found at :
		<Atollic Install Path>/ide/plugins/com.atollic.truestudio.tsp.stm32_1.0.0.20181203-0921/tsp.xml
		:param file_path: path to tsp.xml file
		"""
		self.tsp_path = file_path
		self.cached_content = None
		self.xmlroot: ET.Element = None
		# self.mcu_tree : T.List[MCUGroup] = list()
		self.mcu_custom_tree: T.List[MCUGroup] = list()

	def cache_and_remove_ns(self):
		"""
		Put the XML content into cache and remove the default namespace if relevant.
		"""
		logger.info("Removing namespace and caching TSP file.")
		with open(self.tsp_path, "r") as tsp_file:
			self.cached_content = tsp_file.read()
			start = self.cached_content.find("xmlns=")
			if start > -1:
				stop = self.cached_content.find('"', start)
				stop = self.cached_content.find('"', stop + 1) + 1

				self.cached_content = self.cached_content[:start] + self.cached_content[stop:]
			else:
				logger.warning("No xmlns found")

	def create_xml_root(self, clear_cache: bool = True):
		"""
		Create the XML Element corresponding to the XML root using either the
		cache or the file.
		:param clear_cache: Clear cache after root creation
		"""
		logger.info("Creating XML tree.")
		if self.cached_content is not None:
			logger.info("Creating XML tree from cached value.")
			self.xmlroot = ET.fromstring(self.cached_content)
			logger.info("Clear caching to save memory")
			if clear_cache:
				del self.cached_content
		else:
			logger.info("Creating XML tree from file.")
			self.xmlroot = ET.parse(self.tsp_path).getroot()

	"""
	def build_mcu_tree(self):
		self.mcu_tree.clear()
		for group in self.xmlroot.findall("MCUS/MCUSubGroup") :
			new_group = MCUGroup(group.attrib["name"])
			
			for mcu in group.findall("MCU") :
				sfr_data = mcu.find("SfrData")
				
				new_mcu = MCUDescriptor(mcu.attrib["name"],
										sfr_data.attrib["file"])
				
				for mem in mcu.findall("Memories/Memory"):
					new_mcu.add_memory(get_node_text(mem,"Type"),
									   get_node_text(mem,"Address"))
				for sym in mcu.findall("Symbols/Symbol"):
					new_mcu.add_symbol_description(sym.text)
					
				new_group.add(copy(new_mcu))
				
			self.mcu_tree.append(copy(new_group))
	"""

	def build_mcu_custom_tree(self):
		"""
		Rebuild the MCU custom tree
		the custom tree is a list of mcu group descriptors
		At the end, this structure will contain the list of all MCU groups, merged (?), and, for each MCU,
		its memory base addresses,	its default compilation symbols and the associated svd file.

		It might be used by tree[MCUGroup][MCUDescriptor].attributes
		:return:
		"""
		self.mcu_custom_tree.clear()
		svd_group: T.Dict[str, MCUGroup] = dict()
		for group in self.xmlroot.findall("MCUS/MCUSubGroup"):
			for mcu in group.findall("MCU"):
				if "STM32" not in mcu.attrib["name"].upper():
					continue
				sfr_data = mcu.find("SfrData")
				svd_file: str = sfr_data.attrib["file"]
				new_group = MCUGroup("{:x<11s}".format(svd_file[:-4].upper().replace("X", "x")))
				new_mcu = MCUDescriptor(mcu.attrib["name"],
				                        copy(svd_file),
				                        sfr_data.attrib["device"])

				for mem in mcu.findall("Memories/Memory"):
					new_mcu.add_memory(get_node_text(mem, "Type"),
					                   get_node_text(mem, "Address"))
				for sym in mcu.findall("Symbols/Symbol"):
					new_mcu.add_symbol_description(sym.text)

				if svd_file not in svd_group:
					new_group.add(copy(new_mcu))
					svd_group[copy(svd_file)] = copy(new_group)
				else:
					svd_group[svd_file].add(copy(new_mcu))

		for svd in svd_group:
			self.mcu_custom_tree.append(svd_group[svd])

	def compute_designators(self, designator_list: T.List[str]):
		tot = 0
		done = 0
		ref = sorted([d.upper() for d in designator_list])
		invalid_chip: T.List[MCUDescriptor] = list()

		for group in self.mcu_custom_tree:
			for mcu in group:
				if mcu.select_designator(ref, True):
					done += 1
				else:
					invalid_chip.append(mcu)

				tot += 1
		logger.info(f"[{(done)} / {tot}] ({done/tot*100:3.2f}%) chips are designated")

	def get_mcu_groups(self) -> T.List[ET.Element]:
		ret = list()
		for MCUGroups in self.xmlroot.findall("MCUS/MCUSubGroup"):
			ret.append(MCUGroups)
		return ret
