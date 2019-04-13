import xml.etree.ElementTree as ET
import typing as T

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
	def __init__(self,xml_base : ET.Element):
		"""
		Build a field representation based upon XML node.
		:param xml_base: xml <field> node, extracted from SVD file
		"""
		
		self.name 	= get_node_text(xml_base,"name")
		self.descr 	= get_node_text(xml_base,"description")
		self.offset = int(get_node_text(xml_base,"bitOffset"),0)

		self.width 	= int(get_node_text(xml_base,"bitWidth"),0)
		
		self.xml_data = xml_base
		
	def __repr__(self):
		return self.name