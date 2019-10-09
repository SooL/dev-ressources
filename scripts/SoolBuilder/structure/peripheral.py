import xml.etree.ElementTree as ET
import typing as T
import logging
from structure.register import Register
from structure.chipset import ChipSet
from structure.utils import get_node_text, default_tabmanager, DefinesHandler
from cleaners.field_name_cleaner import field_association_table
# Must not be imported (cyclic import issues)
# from structure.group import Group

from copy import copy, deepcopy
# from deprecated import deprecated
logger = logging.getLogger()


class Peripheral:
	def __init__(self, xml_base : ET.Element, chip : ChipSet = ChipSet()):
		"""
		Build a Peripheral representation based upon XML node.
		If relevant, build all registers.
		:param xml_base: xml <peripheral> node, extracted from SVD file
		"""
		self.xml_data: ET.Element = xml_base

		self.name: str = None
		brief: str = get_node_text(self.xml_data, "description")\
			.lower()\
			.replace("-", " ")\
			.replace("\n", " ")
		self.brief = " ".join(brief.split())

		self.group: "Group" = None
		self.registers: T.List[Register] = list()
		self.chips = ChipSet(chip)

		self.variance_id: str = None
		self.instances: T.List[PeripheralInstance] = list()
		self.mappings: T.List[PeripheralMapping] = list()

		self.fill_from_xml()

		# self.address = int(self.xml_data.find("baseAddress").text,0)

	def fill_from_xml(self):
		new_mappings = [PeripheralMapping(self, self.chips)]

		for xml_reg in self.xml_data.findall("registers/register"):
			new_register = Register(xml_reg, self.chips)
			self.registers.append(new_register)
			pos = int(get_node_text(xml_reg, "addressOffset"), 0)

			mapping = None
			for m in new_mappings :
				if pos in m.register_mapping : continue # this mapping has no room for this register
				mapping = m
				break
			if mapping is None :
				mapping = PeripheralMapping(self, self.chips)
				new_mappings.append(mapping)

			mapping.register_mapping[pos] = new_register
		self.mappings.extend(new_mappings)

########################################################################################################################
#                                                      OPERATORS                                                       #
########################################################################################################################

	def __repr__(self):
		return f"{str(self.name):20s} : {str(self.chips)}"

	def __eq__(self, other):
		if isinstance(other, Peripheral) :
			return (self.name == other.name and
					self.brief == other.brief and
					self.mapping_equivalent_to(other))

		elif isinstance(other, str) :
			return other == self.name
		else :
			raise TypeError()

	def __getitem__(self, item) -> Register:
		if isinstance(item, Register):
			for register in self.registers :
				if item == register :
					return register
			raise KeyError()
		elif isinstance(item,str) :
			for register in self.registers :
				if register.name == item :
					return register
			raise KeyError()
		elif isinstance(item,int) :
			return self.registers[item]
		else :
			raise TypeError()

	@property
	def computed_chips(self) -> ChipSet:
		"""
		Return chipset based upon content
		:return:
		"""
		out = ChipSet()
		for map in self.mappings :
			out.add(map.computed_chips)
		return out

	@property
	def have_been_edited(self):
		for reg in self.registers :
			if reg.have_been_edited :
				return True
		return False

	def clean_register_list(self):
		self.registers.clear()
		for mapping in self.mappings :
			for addr, reg in mapping.register_mapping.items() :
				if reg in self.registers :
					#logger.warning(f"Duplicate register {reg} in peripheral mapping")
					continue
				self.registers.append(reg)

	def cleanup(self):
		for m in self.mappings :
			m.cleanup()
		try:
			del self.xml_data
		except AttributeError:
			pass
########################################################################################################################
#                                                 INSTANCES MANAGEMENT                                                 #
########################################################################################################################

	def add_instance(self, instance : "PeripheralInstance"):
		self.chips.add(instance.chips)
		for inst in self.instances :
			if instance == inst :
				inst.chips.add(instance.chips)
				return
		instance.reference = self
		self.instances.append(instance)

	# Todo merge into add_instance, cf chips.
	def add_instances(self, instances):
		for inst in instances :
			self.add_instance(inst)


########################################################################################################################
#                                                  PERIPHERAL MERGING                                                  #
########################################################################################################################

	def mapping_equivalent_to(self,other : "Peripheral") -> bool :
		"""
		Check if the mapping is equivalent between self and other.
		That is if both peripheral are equals and their contents recursively are too.
		:param other:
		"""
		for register in self :
			if register not in other or not other[register].mapping_equivalent_to(register) :
				return False
		return True

	def compatible(self, other: "Peripheral") -> bool :
		if self.mapping_equivalent_to(other) :
			return True
		for other_mapping in other.mappings :
			compatible = False
			for self_mapping in self.mappings :
				if other_mapping.compatible(self_mapping) :
					compatible = True
					break
			if not compatible :
				return False

		return True
	
	def merge_peripheral(self,other : "Peripheral"):
		"""
		Will merge another peripheral to this one. Adding instances and mapping.
		
		:param other: The peripheral to merge into this one.
		:return:
		"""
		equivalent_mapping = None
		equivalent_instance = None

		# Merge chips
		self.chips.add(other.chips)

		# Merge registers
		for reg in other:
			if reg.name in self:
				# TODO test for size (and error if size is different)
				local_register = self[reg.name]
				for field in reg:
					local_register.add_field(field)
			else:
				self.registers.append(reg)

		# If a mapping, equivalent to the one of the other peripheral, is found, we will use it
		# In this case, we only have to append the chip(s) of the other peripheral.
		if len(other.mappings) != 1:
			logger.warning("multiple mappings on new peripheral")

		for other_mapping in other.mappings:
			merge_done: bool = False
			for m in self.mappings:
				if m.merge_mapping(other_mapping):
					self.chips.add(other_mapping.chips)
					merge_done = True
					break
			
			if not merge_done :
				self.mappings.append(other_mapping)
				self.chips.add(other_mapping.chips)
				
		# Same principle with instances
		for other_instance in other.instances :
			equivalent_instance = None
			for instance in self.instances:
				if instance == other_instance:
					equivalent_instance = instance
					break

			# Same for instances
			if equivalent_instance is None:
				equivalent_instance = PeripheralInstance(self,
														 other_instance.name,
														 other_instance.address,
														 other.chips)
				self.instances.append(equivalent_instance)
				self.chips.add(other_instance.chips)
			else:
				equivalent_instance.chips.add(other.chips)
				self.chips.add(other_instance.chips)

	def self_merge(self):
		"""
		This function will try to merge all mappings of the current peripheral together in order to clean up and
		factorize.
		Mappings and registers will be merged as much as possible.
		"""
		mapping_index = 0
		for var in self.mappings:
			var.simplify_registers()

		# Merge mappings which each others, simplifying them on the fly.
		while mapping_index < len(self.mappings):
			mapping_offset = 1

			while mapping_index + mapping_offset < len(self.mappings):
				self.mappings[mapping_index].merge_reduce_mapping(self.mappings[mapping_index + mapping_offset])

				# If the two mappings had the same registers (name and address equals) the "other"
				# mapping might be empty and therefore have to be removed.
				if len(self.mappings[mapping_index + mapping_offset].register_mapping.keys()) == 0:
					self.mappings.pop(mapping_index + mapping_offset)
					continue
				else:
					mapping_offset += 1
			mapping_index += 1

	def perform_name_rework(self):
		"""
		Clean all name_edited flags and perform all name fixing tasks
		"""
		for reg in self.registers :
			reg.name_edited = False

			for variant in reg.variants :
				variant.name_edited = False
				for field in variant.fields :
					field.name_edited = False
					if reg.name in field_association_table :
						field_association_table[reg.name](field,reg)
	
	def finalize(self):
		self.instances = sorted(self.instances,key=lambda x : (x.name,len(x.chips.chips),x.address))
		for register in self :
			register.finalize()
		
		max_size = max([x.last_byte for x in self.mappings])
		
		for mapping in self.mappings :
			mapping.fill_to(max_size)

	def cpp_output_structure(self, defines_dict: T.Dict[ChipSet, DefinesHandler]):

		# default_tabmanager.increment()

		# Register definition section
		out =""
		out += (f"{default_tabmanager}class {self.name}\n"
				f"{default_tabmanager}{{\n")

		out += f"{default_tabmanager+1}//Registers definition\n\n"
		for reg in self.registers:
			out += reg.cpp_output()

		# Mappings definition section
		default_tabmanager.increment()
		out += f"\n\n{default_tabmanager}//Mappings needs conditions\n\n"
		if len(self.mappings) > 1 :
			out += (f"{default_tabmanager}union\n"
					f"{default_tabmanager}{{\n")
			default_tabmanager.increment()

		for mapping in self.mappings:
			if len(self.mappings) > 1:
				out += (f"{default_tabmanager}struct\n"
						f"{default_tabmanager}{{\n")
				default_tabmanager.increment()

			out += mapping.cpp_output() + "\n"

			if len(self.mappings) > 1:
				default_tabmanager.decrement()
				out += f"{default_tabmanager}}};\n\n"

		if len(self.mappings) > 1:
			default_tabmanager.decrement()
			out += f"{default_tabmanager}}};\n\n"

		default_tabmanager.decrement()
		out += f"{default_tabmanager}}};\n\n"
		
		return out

	def cpp_output_instances(self, defines_dict: T.Dict[ChipSet, DefinesHandler]):
		# Instances address declaration
		out = "\n"
		for instance in self.instances :
			out += instance.cpp_output_address()


		out += "\n"
		instance_done : T.Set[str] = set()
		for instance in self.instances :
			# The instance declaration is based upon the address macro. Therefore there is no need to output it more than once.
			if instance.name not in instance_done :
				out += instance.cpp_output_declaration()
				instance_done.add(instance.name)
		return out
		
########################################################################################################################
#                                                 PERIPHERAL MAPPING                                                 #
########################################################################################################################


class PeripheralMapping:
	forbidden_fixs : T.Dict[str,T.List[str]] = dict()
	fixs_done: T.List[T.Tuple[str,str,str]] = list()
	@staticmethod
	def forbid_fix(source : str, other : str, bidir = False):
		if source not in PeripheralMapping.forbidden_fixs :
			PeripheralMapping.forbidden_fixs[source] = []
		PeripheralMapping.forbidden_fixs[source].append(other)
		
		if bidir :
			PeripheralMapping.forbid_fix(other,source,False)
	
	def __init__(self, reference: Peripheral, chips: ChipSet):
		self.reference = reference
		self.name: str = None # the name will be determined when the whole structure is built
		self.chips: ChipSet = ChipSet(chips)
		
		self.register_mapping: T.Dict[int, Register] = dict()
	
	def __repr__(self):
		return ", ".join([f"{pos:3d}: {self.register_mapping[pos]}" for pos in self.register_mapping.keys()]) + " : " \
			   + str(self.chips)
		
	def __eq__(self, other):
		if isinstance(other, PeripheralMapping):
			positions = self.register_mapping.keys()
			if len(set(positions).symmetric_difference(set(other.register_mapping.keys()))) != 0:
				return False
			for pos in positions :
				if self.register_mapping[pos] != other.register_mapping[pos]:
					return False
			return True
		elif isinstance(other, Peripheral):
			for mapping in other.mappings:
				if mapping == self:
					return True
		else:
			raise TypeError()
		return False

	def compatible(self, other: "PeripheralMapping"):
		for pos in other.register_mapping :
			if pos in self.register_mapping :
				if not other.register_mapping[pos].compatible(self.register_mapping[pos]) :
					return False
		return True

	@property
	def computed_chips(self) -> ChipSet:
		"""
		Return chipset based upon content
		:return:
		"""
		out = ChipSet()
		for key,reg in self.register_mapping.items() :
			out.add(reg.computed_chips)
		return out

	@property
	def memory_bit_space(self) -> T.Set[int]:
		out = set()
		for addr, reg in self.register_mapping.items() :
			out.update(range(addr*8,(addr*8) + reg.size))
		return out
	
	@property
	def memory_byte_space(self) -> T.Set[int]:
		out = set()
		for addr, reg in self.register_mapping.items() :
			out.update(range(addr,addr + int(reg.size/8)))
		return out

	@property
	def last_byte(self) -> int :
		return sorted(list(self.memory_byte_space))[-1]

	def subset(self,other : "PeripheralMapping") -> bool:
		"""
		Check if the current mapping is a subset of the given mapping
		:param other:
		"""
		for pos,reg in self.register_mapping.items() :
			if pos not in other.register_mapping :
				return False
			if reg != other.register_mapping[pos] :
				return False
		return True

	def superset(self, other: "PeripheralMapping") -> bool:
		return other.subset(self)

	def cleanup(self):
		for p,m in self.register_mapping.items():
			m.cleanup()

	def simplify_registers(self):
		for addr, reg in self.register_mapping.items() :
			reg.self_merge()

	def merge_mapping(self, other : "PeripheralMapping") -> bool:
		"""
		This function will merge the other mapping into the current one if
		the other one can fit within the current one. That is either :
		
		 - Same register name at same position
		 - Hole in the current register to be filled by other.
		
		This function will not edit anything unless the merge is possible.
		
		:param other: mapping to merge to the current one.
		:return: True if merged ok, false otherwise
		"""
		for addr,reg  in other.register_mapping.items() :
			if addr in self.register_mapping:
				local_reg = self.register_mapping[addr]
				if reg.name != local_reg.name :
					if reg.mapping_equivalent_to(local_reg) :
						local_name = local_reg.name
						other_name = reg.name
						
						if local_name in PeripheralMapping.forbidden_fixs :
							if reg.name in PeripheralMapping.forbidden_fixs[local_name] :
								return False
						
						PeripheralMapping.fixs_done.append((self.reference.name,local_name,other_name))
						new_name = local_name if len(local_name) <= len(other_name) else other_name
						logger.warning(f"Fixing register name : same mapping for various names in "
									   f"{self.reference.name:10s}. Local : {local_name:15s} - Other : {other_name:15s}")
						local_reg.name = new_name
						reg.name = new_name
					else :
						return False
		
		for a, reg in other.register_mapping.items() :
			if a in self.register_mapping :
				self.register_mapping[a].merge_register(reg)
			else :
				self.register_mapping[a] = reg
		self.chips.add(other.chips)
		
		return True

	def merge_reduce_mapping(self, other: "PeripheralMapping"):
		"""
		This function will merge parts of the other mapping into the current one, exploiting register variants.
		To be merged, two register have to got the same name and address.

		The merged registers will be removed from the other mapping.

		:param other: mapping to merge to the current one.
		"""
		deleted_addr: T.List[int] = list()
		for a, reg in other.register_mapping.items():
			if a in self.register_mapping:
				if reg.name == self.register_mapping[a].name:
					self.register_mapping[a].merge_register(reg)
					self.chips.add(reg.chips)
					deleted_addr.append(a)
			else:
				self.register_mapping[a] = reg
				self.chips.add(reg.chips)
				deleted_addr.append(a)

		for addr in deleted_addr :
			other.register_mapping.pop(addr)

	def cpp_output(self):
		out = ""
		default_tabmanager.increment()
		for addr in sorted(self.register_mapping.keys()) :
			reg = self.register_mapping[addr]
			if reg.filler :
				out += f"{default_tabmanager}{' ':20s}\t{f'{reg.name};':25s} // @{addr:4d} - {addr + int(reg.size/8)-1:4d}\n"
			else :
				out += f"{default_tabmanager}{f'{reg.name}_t':20s}\t{f'{reg.name};':25s} // @{addr:4d} - {addr + int(reg.size/8)-1:4d}\n"

		default_tabmanager.decrement()
		return out
	
	def fill_to(self, address : int):
		"""
		Will fill the current mapping with empty registers up to the given address (included) in bytes.
		:param address:
		"""
		holes = sorted(list(set(range(0,address+1)) - self.memory_byte_space))
		if len(holes) == 0 :
			return
		
		hole_size = 1
		hole_start = holes[0]
		
		for hole in holes[1:] :
			if hole == hole_start + hole_size :
				hole_size += 1
			else :
				self.add_filler(hole_start,hole_size)
				hole_start = hole
				hole_size = 1

		# If we wish to remove all filling at the end of the peripheral, just comment the following line.
		self.add_filler(hole_start, hole_size)
		
		
		
	def add_filler(self,offset : int, size : int):
		computed_sizes :T.List[int] = list()
		i = 0
		while size != 0 :
			if size & 1 :
				computed_sizes.append(2**i)
			size >>= 1
			i += 1
		computed_sizes.sort(reverse=True)
		
		position = offset
		"""< name > {name} < / name >
		< displayName > {name} < / displayName >
		< description > {descr} < / description >
		< addressOffset > {offset} < / addressOffset >
		< size > {size} < / size >
		< access > {access} < / access >
		< resetValue > {rst_val} < / resetValue >
		"""
		for s in computed_sizes :
			XML = Register.XML_Template.format(name=f"__SOOL_FILLER_{s}",
											   descr=" ",
											   offset=position,
											   size=s,
											   access="reserved",
											   rst_val=0)
			self.register_mapping[position] = Register(ET.fromstring(XML), self.computed_chips,filler=True)
			position += s
	
		
########################################################################################################################
#                                                 PERIPHERAL INSTANCE                                                  #
########################################################################################################################

class PeripheralInstance :
	def __init__(self, reference : Peripheral, name : str, address : int, chips: ChipSet):
		self.reference : Peripheral = reference
		self.name = name
		self.address = address
		self.chips = ChipSet(chips)
	
	def __repr__(self):
		return f"{self.name:20s} @ 0x{self.address:08X} {self.chips}"
	
	def __eq__(self, other):
		if isinstance(other, PeripheralInstance) :
			return self.name == other.name and self.address == other.address
		elif isinstance(other, Peripheral) :
			for instance in other.instances :
				if instance == self :
					return True
		else :
			raise TypeError()
		return False

	def computed_chips(self) -> ChipSet:
		"""
		Return chipset based upon content
		:return:
		"""
		return self.chips

	@property
	def addr_name(self):
		return f"{self.name}_BASE_ADDR"

	def cpp_output_address(self):
		out = "#if " + self.chips.defined_list(5,self.reference.group.computed_chips) + "\n"
		out += f"{default_tabmanager}#define {self.addr_name} ((uint32_t)0x{self.address:8X})\n"
		out += "#endif\n\n"
		return out

	def cpp_output_declaration(self):
		return (f"{default_tabmanager}volatile class {self.reference.name} * const {self.name} = " 
				f"reinterpret_cast<class {self.reference.name}* const>({self.addr_name});\n")
