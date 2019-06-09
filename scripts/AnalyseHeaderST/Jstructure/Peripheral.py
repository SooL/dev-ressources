import xml.etree.ElementTree as ET
import typing as T
from .Register import Register
from tools.utils import ChipSeriesManager

def get_node_text(root : ET.Element, node : str) -> str :
	return str() if root.find(node) is None else root.find(node).text


class Peripheral:
	def __init__(self, xml_base : ET.Element, chip : ChipSeriesManager = ChipSeriesManager()):
		"""
		Build a Peripheral representation based upon XML node.
		If relevant, build all registers.
		:param xml_base: xml <peripheral> node, extracted from SVD file
		"""
		self.name : str 		= None
		self.address : int 		= None
		self.brief : str 		= None
		self.derivation : str 	= None
		self.group : str 		= None
		self.registers : T.List = list()
		
		self.complete : bool = False
		self.xml_data : ET.Element = xml_base
		self.chips = chip
	
		if "derivedFrom" in self.xml_data.attrib:
			self.derivation = self.xml_data.attrib["derivedFrom"]
			self.complete = False
		else :
			self.complete = True
			self.brief = get_node_text(self.xml_data,"description")
			self.group = get_node_text(self.xml_data,"groupName")
			self.fill_from_xml()
		
		self.name = self.xml_data.find("name").text
		self.address = int(self.xml_data.find("baseAddress").text,0)
		
		
		
	def __repr__(self):
		return self.name
	
	def fill_from_xml(self):
		for xml_reg in self.xml_data.findall("registers/register"):
			self.registers.append(Register(xml_reg,self.chips))
			
	def __eq__(self, other):
		if isinstance(other,Peripheral) :
			return (self.name == other.name and
					self.address == other.address)
		elif isinstance(other,str):
			return other == self.name
		else:
			raise TypeError()
		
	def __le__(self, other):
		if isinstance(other,Peripheral):
			return self.address <= other.address
		else:
			raise TypeError()