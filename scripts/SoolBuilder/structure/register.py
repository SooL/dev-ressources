
import xml.etree.ElementTree as ET
import logging
import typing as T
from structure.utils import get_node_text
from structure.field import Field
from structure import ChipSet
from structure import default_tabmanager
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
	XML_Template : str = """<register><name>{name}</name>
<displayName>{name}</displayName>
<description>{descr}</description>
<addressOffset>{offset}</addressOffset>
<size>{size}</size>
<access>{access}</access>
<resetValue>{rst_val}</resetValue></register>
"""
	
	def __init__(self,xml_base : ET.Element, chip: ChipSet, default_size : int = 32, filler : bool = False):
		"""
		Build a register representation based upon XML node.
		extract the name, size and description from the xml node.
		Also stores the address offset, but it is not relevant when the register
		Also build all fields.
		:param xml_base: xml <register> node, extracted from SVD file
		"""

		self.xml_data = xml_base
		self._name = get_node_text(xml_base, "name").strip(None)

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

		self.chips : ChipSet = ChipSet(chip)
		self.name_edited = False;
		self.variants : T.List["RegisterVariant"] = list()
		self.variants.append(RegisterVariant(self, self.chips))
		
		self.filler = filler
		
		xml_fields = xml_base.findall("fields/field")
		if xml_fields is not None :
			for xml_field in xml_fields :
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
				del self._iter_field
				del self._iter_variant
				raise StopIteration

			return out
		else :
			del self._iter_field
			del self._iter_variant
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
		if other is self : return True
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

	@property
	def name(self) -> str:
		return self._name

	@name.setter
	def name(self,new_name) :
		if self._name != new_name :
			self.name_edited = True
			self._name = new_name

	@property
	def have_been_edited(self):
		if self.name_edited :
			return True
		for field in self :
			if field.name_edited :
				return True
		return False


	def cleanup(self):
		for v in self.variants :
			v.cleanup()
		try:
			del self.xml_data
		except AttributeError:
			pass

	@property
	def computed_chips(self) -> ChipSet:
		"""
		Return chipset based upon content
		:return:
		"""
		out = ChipSet()
		for var in self.variants :
			out.add(var.computed_chips)
		return out

########################################################################################################################
#                                                  FIELDS MANAGEMENT                                                   #
########################################################################################################################

	def add_field(self, field: Field):
		"""
		Add a field to the register through best effort filling.
		The variants will be filled up as much as possible before creating a new variant.

		:param field: Field to add
		:return: None
		"""
		for variant in self.variants :
			if field in variant or variant.has_room_for(field):
				variant.add_field(field)
				self.chips.add(field.chips)
				# if len(field.chips.chips - self.chips.chips) > 0 :
				# 	logger.warning(f"Chips descriptor discrepancy for field {field} within {self.name}")
				return

		new_variant = RegisterVariant(self, self.chips)
		new_variant.add_field(field)
		self.chips.add(field.chips)
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
		for field in self :
			if field not in other or field != other[field] :
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

	def merge_register(self,other : "Register"):
		for f in other :
			self.add_field(f)
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
	def self_merge(self):
		mapping_index = 0
		while mapping_index < len(self.variants):
			mapping_offset = 1

			while mapping_index + mapping_offset < len(self.variants):
				if self.variants[mapping_index] == self.variants[mapping_index + mapping_offset] :
					self.variants.pop(mapping_index + mapping_offset)
					continue
				else :
					mapping_offset += 1
			mapping_index += 1

	def finalize(self):
		"""
		Function grouping all final cleanup steps for registers.
		"""
		# This functions should not contains anything else aside simple functions calls, in order to keep it simple
		self.fill_memory()
		self.sort_fields()

	def sort_fields(self):
		"""
		Sort all fields in all variants, by offset.
		"""
		for var in self.variants:
			var.sort()

	def fill_memory(self):
		for var in self.variants:
			var.fill_memory()

	def cpp_output(self) :
		out = ""
		if self.filler :
			return ""
		default_tabmanager.increment()
		out += (f"{default_tabmanager}class {self.name}_t : Reg{self.size}_t\n"
				f"{default_tabmanager}{{\n")
		if len(self.variants) > 1 :
			default_tabmanager.increment()
			out += (f"{default_tabmanager}union\n"
					f"{default_tabmanager}{{\n")
			for var in self.variants :
				out += var.cpp_output() + "\n"
			out += f"{default_tabmanager}}};\n"
			default_tabmanager.decrement()
		else:
			out +=  self.variants[0].cpp_output(self.name)
		out += f"{default_tabmanager}}};\n"
		default_tabmanager.decrement()
		return out


########################################################################################################################
#                                                   REGISTER VARIANT                                                   #
########################################################################################################################

class RegisterVariant :

	def __init__(self, register: Register, chips: ChipSet):
		self.register = register
		self.fields: T.List[Field] = list()
		self._name = None
		self.name_edited = False
		self.chips = ChipSet(chips)

	def __repr__(self):
		return f"{self.register.name} : {str(self.fields)}"

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

	def __eq__(self, other):
		if isinstance(other,RegisterVariant) :
			for field in other.fields :
				if field not in self :
					return False
			return True

	def cleanup(self):
		for f in self.fields :
			f.cleanup()

	def has_room_for(self, field: Field):
		for f in self.fields :
			if f.overlap(field) :
				return False
		return True

	@property
	def computed_chips(self) -> ChipSet:
		"""
		Return chipset based upon content
		:return:
		"""
		out = ChipSet()
		for field in self.fields :
			out.add(field.chips)
		return out

	@property
	def memory_usage(self) -> T.Set[int] :
		output = set()
		for field in self.fields :
			output |= field.memory_usage()
		return output

	@property
	def name(self) -> str :
		return self._name

	@name.setter
	def name(self, new_name) -> str:
		if new_name != self._name :
			self.name_edited = True
			self._name = new_name

	def add_field(self, field: Field):
		"""
		Add the given field to the current variant. If the field already exist, it is merged.
		:param field: Field to add
		"""
		if field not in self :
			self.fields.append(field)
			self.name_edited = True
		else :
			self[field].chips.add(field.chips)
		self.chips.add(field.chips)

	def sort(self):
		self.fields = sorted(self.fields)

	def finalize(self):
		self.fill_memory()

	def add_filler(self, offset : int, length : int):
		if offset + length > self.register.size :
			raise ValueError("Adding filler outside register size")
		xml_equivalent = Field.XML_Template.format(name="",
												   description="Filler field",
												   offset=str(offset),
												   width=str(length))
		self.add_field(Field(ET.fromstring(xml_equivalent), self.computed_chips))

	def fill_memory(self):
		memory_holes = sorted(list(set(range(0,self.register.size)) - self.memory_usage))
		offset = None
		length = 0

		for hole in memory_holes :
			if offset is None :
				offset = hole
				length = 1
				continue
			if hole > offset + length :
				self.add_filler(offset,length)
				offset = hole
				length = 1
			else :
				length += 1

		# Required for last element.
		if offset is not None :
			self.add_filler(offset, length)

	def cpp_output(self, register_name : str = str()):
		default_tabmanager.increment()
		out = (f"{default_tabmanager}struct {register_name}\n"
			   f"{default_tabmanager}{{\n")
		for field in sorted(self.fields,key=lambda x : x.offset, reverse=False):
			out += field.cpp_output()
		out += f"{default_tabmanager}}};\n"
		default_tabmanager.decrement()

		return out




