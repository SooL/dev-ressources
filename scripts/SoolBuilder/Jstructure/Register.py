
import xml.etree.ElementTree as ET
import logging
import typing as T
from Jstructure.utils import get_node_text
from Jstructure.Field import Field
from Jstructure import ChipSet
from deprecated import deprecated
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
		extract the name, size and description from the xml node.
		Also stores the address offset, but it is not relevant when the register
		Also build all fields.
		:param xml_base: xml <register> node, extracted from SVD file
		"""

		self.xml_data = xml_base
		
		self.name = get_node_text(xml_base, "name").strip(None)

		# check if displayName is different from name
		disp_name = get_node_text(xml_base, "displayName").strip(None)
		if disp_name != self.name :
			logger.warning(f"Register name and display discrepancy : {self.name} displayed as {disp_name}")
		
		self.descr = get_node_text(xml_base,"description")
		self.extracted_offset = int(get_node_text(xml_base, "addressOffset"), 0)
		
		read_size_value = get_node_text(xml_base,"size")
		if read_size_value == str() :
			self.size = default_size
		else :
			self.size = int(read_size_value,0)
			
		self.access = get_node_text(xml_base,"access")
		#self.rst = int(get_node_text(xml_base,"resetValue"),0) #Is a mask

		
		self.chips : ChipSet = chip

		self.variants : T.List["RegisterVariant"] = list()
		self.variants.append(RegisterVariant(self, self.chips))
		
		for xml_field in xml_base.findall("fields/field") :
			self.add_field(Field(xml_field, self.chips))

########################################################################################################################
#                                                      OPERATORS                                                       #
########################################################################################################################

	def __hash__(self) :
		"""
		builds an hash based on the name and size of the register, and the hashes of all the variants
		:return: the calculated hash
		"""
		return hash((self.name,self.size,tuple(self.variants)))
	
	def __repr__(self) :
		"""
		the string representation of the register is its name
		:return: the register name
		"""
		return self.name
	
	def __getitem__(self, item) :
		"""
		return the field corresponding o the specified value.
		if the specified value is a string, the returned value id the first field with the specified name.
		If it is a field, the returned value is the field of this register which is equal to the specified field
		(identical name, offset and size).
		:param item: the name of the required field, or an equivalent field
		:return: the required field, or KeyError if it doesn't exist, or TypeError
				if the parameter is neither a string or a field.
		"""
		if isinstance(item,Field) or isinstance(item,str) :
			for variant in self.variants :
				for field in variant.fields :
					if field == item :
						return field
			return KeyError()
		else :
			raise TypeError()

	def __iter__(self):
		"""
		Will iterate through all fields in all variants of the register.
		:return:
		"""
		self._iter_variant = 0
		self._iter_field = 0
		return self

	def __next__(self):
		"""
		Will iterate through all fields in all variants of the register.
		:return: the next field in the list
		"""
		out = None
		if self._iter_variant < len(self.variants) :
			if self._iter_field < len(self.variants[self._iter_variant].fields) :
				out = self.variants[self._iter_variant].fields[self._iter_field]
				self._iter_field += 1
			elif self._iter_variant < len(self.variants) -1 :
				self._iter_variant += 1
				self._iter_field = 0
				out = self.variants[self._iter_variant].fields[self._iter_field]
			else :
				raise StopIteration

			return out
		else :
			raise StopIteration

	def __eq__(self, other) :
		"""
		If the parameter is a register, this function returns True if all the fields are common to both registers.
		If the parameter is a string, this function returns True if the name of the register is the same
		as the specified one.
		:param other: register of string to test
		:return: True if the register is equal to the specified one (or the name is the specified one),
				False if different, or TypeError is the type of the parameter is wrong
		"""
		if isinstance(other,Register) :
			if self.name != other.name or self.size != other.size:
				return False
			for field in other:
				if field not in self :
					return False
			for field in self:
				if field not in other :
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

########################################################################################################################
#                                                  FIELDS MANAGEMENT                                                   #
########################################################################################################################

	def add_field(self, field: Field):
		for variant in self.variants :
			if field in variant or variant.has_room_for(field):
				variant.add_field(field)
				return

		new_variant = RegisterVariant(self, self.chips)
		new_variant.add_field(field)

		self.variants.append(new_variant)

########################################################################################################################
#                                                   REGISTER MERGING                                                   #
########################################################################################################################

	def mapping_equivalent_to(self,other : "Register") -> bool :
		"""
		Compare if two registers are structurally equivalents.
		:param other:
		:return:
		"""
		if self == other :
			for field in self :
				if field not in other or field != other[field] :
					return False
		else :
			return False
		return True

	def compatible(self, other: "Register") -> bool :
		"""
		Checks if the given register is compatible with the current one.
		Two register are said compatibles if all fields of the current register are present or could fit within the
		other one

		This function is not symmetrical. It'll try to fit all **current** register fields within the given other
		register and not the other way around;

		:param other: The register that we are using as reference.
		:return: True if the current register cant fit within the other one.
		"""
		if self.name != other.name or self.size != other.size:
			return False
		for f_1 in self :
			for f_2 in other :
				if f_1.overlap(f_2) and f_1 != f_2 :
					return False
		return True

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
		if other in self:
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

	@deprecated(reason="self.fields do not exists anymore. Use add_field instead")
	def merge_field(self,other : Field) -> bool:
		"""
		This function will merge if possible the given field within the current register.
		:param other: Field to merge
		:return: True if the field was merged, false otherwise
		"""
		# Todo Re-do if required

		# if self.can_integrate(other):
		# 	local_field = list(self.get_fields_by_memory(other.memory_usage()))
		# 	if len(local_field) > 0:
		# 		local_field[0].chips.add(other.chips)
		# 	else:
		# 		self.fields.append(other)
		# 		self.fields.sort(key=lambda x: x.offset)
		# 	return True
		# else :
		# 	return False

	@deprecated(reason="By definition, we always can merge by adding variant. Use add_field.")
	def can_fully_merge(self, other: "Register") -> bool:
		"""
		This function determine if a given register can be fully merged into the current one
		:param other:
		:return: True if the full merge is possible
		"""
		# Todo Redo if required.
		pass

		# for f in other.fields :
		# 	if not self.can_integrate(f):
		# 		return False
		# return True

	def merge_as_possible(self, other: "Register") -> T.List[Field]:
		"""
		This function will merge as much fields as possible and return the non-merged fields.
		:param other:
		:return:
		"""
		out = list()
		for f in other:
			if not self.merge_field(f):
				out.append(f)
		return out

########################################################################################################################
#                                                 MEMORY USAGE STATUS                                                  #
########################################################################################################################

	def get_memory_usage(self) -> T.Set[int]:
		"""
		This function will return a set of used memory zone. If the set is {0,1,4}
		it means that bits 0,1 and 4 are used. All others are unused.
		:return:
		"""
		out = set()
		for field in self :
			out |= field.memory_usage()
		return out

	def get_fields_by_memory(self, mem: T.Set[int]) -> T.Set[Field]:
		out = set()
		for f in self:
			if mem.intersection(f.memory_usage()) != set():
				out.add(f)
		return out

########################################################################################################################
#                                                     FINALISATION                                                     #
########################################################################################################################
	@deprecated
	def rebuild_chip_list(self) :
		pass
		# TODO To be re-done if required

		# self.chips.clear()
		# for field in self :
		# 	self.chips.merge(field.chips)

	def finalize(self):
		"""
		Function grouping all final cleanup steps for registers.
		"""
		# This functions should not contains anything else aside simple functions calls, in order to keep it simple

		self.sort_fields()

	def sort_fields(self):
		"""
		Sort all fields in all variants, by offset.
		"""
		for var in self.variants:
			var.sort()


########################################################################################################################
#                                                   REGISTER VARIANT                                                   #
########################################################################################################################

class RegisterVariant :

	def __init__(self, register: Register, chips: ChipSet):
		self.register = register
		self.fields: T.List[Field] = list()
		self.name = None
		self.chips = chips

	def __contains__(self, item) :
		if isinstance(item, Field) :
			if item in self.fields :
				return True
		return False

	def __getitem__(self, item):
		if isinstance(item, Field) or isinstance(item, str):
			for field in self.fields :
				if field == item :
					return field

	def __hash__(self) :
		return hash(tuple(self.fields))

	def has_room_for(self, field: Field):
		for f in self.fields :
			if f.overlap(field) :
				return False
		return True

	def add_field(self, field: Field):
		"""
		Add the given field to the current variant. If the field already exist, it is merged.
		:param field: Field to add
		"""
		if field not in self :
			self.fields.append(field)
		else :
			self[field].chips.add(field.chips)
		self.chips.add(field.chips)

	def sort(self):
		self.fields = sorted(self.fields)



