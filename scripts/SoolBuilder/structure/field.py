import xml.etree.ElementTree as ET
import typing as T
import logging
from structure import ChipSet, default_tabmanager

logger = logging.getLogger()


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
	XML_Template : str = 	"""
							<field>
							<name>{name}</name>
							<description>{description}</description>
							<bitOffset>{offset}</bitOffset>
							<bitWidth>{width}</bitWidth>
							</field>
							"""
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
	
	def __lt__(self, other):
		if isinstance(other,Field) :
			return self.offset < other.offset
		raise TypeError()

	def cleanup(self):
		try :
			del self.xml_data
		except AttributeError :
			pass
		
	def overlap(self, other: "Field"):
		"""
		This function test if two fields are overlapping.

		:param other: The field to test again
		:return: True if there is an overlapping.
		"""
		if other.offset > self.offset :
			return (self.offset + self.width) > other.offset
		else :
			return (other.offset + other.width) > self.offset

	def memory_usage(self):
		return set(range(self.offset,self.offset+self.width))

	def cpp_output(self) -> str:
		default_tabmanager.increment()
		out =  f"{default_tabmanager}{str(self.name if self.name is not None else ''):15s} :{self.width:>3d};\n"
		default_tabmanager.decrement()
		return out
