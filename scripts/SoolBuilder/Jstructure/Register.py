
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

	def get_memory_usage(self) -> T.Set[int]:
		"""
		This function will return a set of used memory zone. If the set is {0,1,4}
		it means that bits 0,1 and 4 are used. All others are unused.
		:return:
		"""
		out = set()
		for field in self.fields :
			out |= field.memory_usage()
		return out

	def get_fields_by_memory(self,mem : T.Set[int]) -> T.Set[Field]:
		out = set()
		for f in self.fields :
			if mem.intersection(f.memory_usage()) != set() :
				out.add(f)

	def can_integrate(self,other: Field) -> bool:
		"""
		Determine if the given field can be merged into the current register.
		The merge can be done if :
		  - the field is already in here
		  - the memory location is unused
		  - the field already here have the same name, position and width

		:param other: Field that you try to merge
		:return: Is able to be merged.
		"""
		if other in self.fields:
			return True

		other_mem = other.memory_usage()
		local_mem = self.get_memory_usage()

		# If the memory location is free to use
		if other_mem - local_mem == other_mem :
			return True

		mapped_fields = self.get_fields_by_memory(other_mem)
		# Possibility to add something to map 1 n-wide field to n 1-wide fields
		if len(mapped_fields) > 1:
			return False
		# Check on position, size and name
		return list(mapped_fields)[0] == other

	def merge_field(self,other : Field) -> bool:
		"""
		This function will merge if possible the given field within the current register.
		:param other: Field to merge
		:return: True if the field was merged, false otherwise
		"""
		if self.can_integrate(other):
			local_field = list(self.get_fields_by_memory(other.memory_usage()))
			if len(local_field) > 0:
				local_field[0].chips.add(other.chips)
			else:
				self.fields.append(other)
				self.fields.sort(key=lambda x: x.offset)
			return True
		else :
			return False

	def can_fully_merge(self, other: "Register") -> bool:
		"""
		This function determine if a given register can be fully merged into the current one
		:param other:
		:return: True if the full merge is possible
		"""
		for f in other.fields :
			if not self.can_integrate(f):
				return False
		return True

	def merge_as_possible(self, other: "Register") -> T.List[Field]:
		"""
		This function will merge as much fields as possible and return the non-merged fields.
		:param other:
		:return:
		"""
		out = list()
		for f in other.fields:
			if not self.merge_field(f):
				out.append(f)
		return out



