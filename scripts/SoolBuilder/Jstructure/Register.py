
import xml.etree.ElementTree as ET
import logging
import typing as T
from Jstructure.utils import get_node_text
from Jstructure.Field import Field
from Jstructure import ChipSet
logger = logging.getLogger()



"""
<name>CR</name>
<displayName>CR</displayName>
<description>control register</description>
<addressOffset>0x0</addressOffset>
<size>0x20</size>
<access>read-write</access>
<resetValue>0x00000000</resetValue>
"""


class Register :
	def __init__(self,xml_base : ET.Element, chip: ChipSet, default_size : int = 32):
		"""
		Build a register representation based upon XML node.
		Also build all fields.
		:param xml_base: xml <register> node, extracted from SVD file
		"""

		self.xml_data = xml_base
		
		self.name = get_node_text(xml_base, "name").strip(None)
		
		disp_name = get_node_text(xml_base, "displayName").strip(None)
		if disp_name != self.name :
			logger.warning(f"Register name and display discrepancy : {self.name} displayed as {disp_name}")
		
		self.descr = get_node_text(xml_base,"description")
		self.offset = int(get_node_text(xml_base,"addressOffset"),0)
		
		read_size_value = get_node_text(xml_base,"size")
		if read_size_value == str() :
			self.size = default_size
		else :
			self.size = int(read_size_value,0)
			
		self.access = get_node_text(xml_base,"access")
		#self.rst = int(get_node_text(xml_base,"resetValue"),0) #Is a mask
		
		self.fields : T.List[Field] = list()
		
		self.chips : ChipSet = chip
		
		for xml_fields in xml_base.findall("fields/field") :
			self.fields.append(Field(xml_fields, self.chips))
	
	def __hash__(self) :
		return hash((self.name,self.size,tuple(self.fields)))
	
	def __repr__(self) :
		return self.name
	
	def __getitem__(self, item) :
		if isinstance(item,Field or isinstance(item,str)) :
			for field in self.fields :
				if item == field :
					return field
			return KeyError()
		elif isinstance(item,int) :
			return self.fields[item]
		else :
			raise TypeError()
		
	def __eq__(self, other) :
		if isinstance(other,Register) :
			if self.name != other.name or self.size != other.size:
				return False
			for field in other:
				if field not in self :
					return False
			return True
		elif isinstance(other,str):
			return self.name == other
		else:
			raise TypeError()
		
#	def __le__(self, other):
#		if isinstance(other,Register) :
#			return self.offset <= other.offset
#		raise TypeError()
	
	def rebuild_chip_list(self) :
		self.chips.clear()
		for field in self :
			self.chips.merge(field.chips)

	def mapping_equivalent_to(self,other : "Register") -> bool :
		"""
		Compare if two registers are structurally equivalents.
		:param other:
		:return:
		"""
		if self == other :
			for field in self.fields :
				if field not in other or field != other[field] :
					return False
		else :
			return False
		return True

	def compatible(self, other: "Register") -> bool :
		if self.name != other.name or self.size != other.size:
			return False
		for f_1 in self.fields :
			for f_2 in other.fields :
				if f_1.overlap(f_2) and f_1 != f_2 :
					return False
		return True
