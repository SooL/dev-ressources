import xml.etree.ElementTree as ET
import typing as T

from Jstructure import *
def get_node_text(root : ET.Element, node : str) -> str :
	return str() if root.find(node) is None else root.find(node).text


"""
<field>
<name>EN1</name>
<description>DAC channel1 enable</description>
<bitOffset>0</bitOffset>
<bitWidth>1</bitWidth>
</field>
"""


class Field:
	def __init__(self,xml_base : ET.Element, chip : ChipSet = None):
		"""
		Build a field representation based upon XML node.
		:param xml_base: xml <field> node, extracted from SVD file
		"""
		
		self.name 	= get_node_text(xml_base,"name")
		self.descr 	= get_node_text(xml_base,"description")
		self.offset = int(get_node_text(xml_base,"bitOffset"),0)

		self.width 	= int(get_node_text(xml_base,"bitWidth"),0)
		
		self.xml_data = xml_base
		
		self.chips: ChipSet = chip
		
	def __repr__(self):
		return self.name
	
	def __eq__(self, other):
		if isinstance(other,Field) :
			return (self.name == other.name and
					self.offset == other.offset and
					self.width == other.width)
		elif isinstance(other,str) :
			return other == self.name
		raise TypeError()
		
	def __hash__(self):
		return hash((self.name,self.offset,self.width,self.width))
	
	def __le__(self, other):
		if isinstance(other,Field) :
			return self.offset <= other.offset
		raise TypeError()

	def overlap(self, other: "Field"):
		if other.offset > self.offset :
			return (self.offset + self.width) > other.offset
		else :
			return (other.offset + other.width) > self.offset
