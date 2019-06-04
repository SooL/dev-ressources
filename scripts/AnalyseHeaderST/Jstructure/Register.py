from .Field import Field
import xml.etree.ElementTree as ET
import logging
import typing as T


logger = logging.getLogger()

def get_node_text(root : ET.Element, node : str) -> str :
	return str() if root.find(node) is None else root.find(node).text


"""
<name>CR</name>
<displayName>CR</displayName>
<description>control register</description>
<addressOffset>0x0</addressOffset>
<size>0x20</size>
<access>read-write</access>
<resetValue>0x00000000</resetValue>
"""


class Register:
	def __init__(self,xml_base : ET.Element):
		"""
		Build a register representation based upon XML node.
		Also build all fields.
		:param xml_base: xml <register> node, extracted from SVD file
		"""

		self.xml_data = xml_base
		
		self.name = get_node_text(xml_base, "name").strip(None)
		
		dispName = get_node_text(xml_base, "displayName").strip(None)

		if dispName != self.name :
			logger.warning(f"Register name and display discrepancy : {self.name} displayed as {dispName}")
		
		self.descr = get_node_text(xml_base,"description")
		self.offset = int(get_node_text(xml_base,"addressOffset"),0)
		self.size = int(get_node_text(xml_base,"size"),0)
		self.access = get_node_text(xml_base,"access")
		#self.rst = int(get_node_text(xml_base,"resetValue"),0) #Is a mask
		
		self.fields : T.List[Field] = list()
		
		for xml_fields in xml_base.findall("fields/field") :
			self.fields.append(Field(xml_fields))
			
	def __repr__(self) :
		return self.name