#!/usr/bin/python3
# -*-coding:utf-8 -*
import header
from .utils import *
from copy import *
import re

from typing import *

def get_generic_size(id, instance=None):
	if id == "uint32_t":	return 4
	if id == "int32_t" : 	return 4
	if id == "uint16_t":	return 2
	if id == "int16_t" : 	return 2
	if id == "uint8_t" : 	return 1
	if id == "int8_t"  :  	return 1

	if instance is not None:
		return instance.get_size(id)

	return None


class TypedefExtractor :
	def __init__(self, associated_header : header, chip : ChipSeriesManager, correction_matrix : Dict[str,str] = None) :
		self.REGEX_Typedef = re.compile(r"typedef struct\n\{([^}]+)\}\s*(.*)_TypeDef;")
	#	self.REGEX_Register = re.compile(r"(?:\s*__\w+\s+(?:const\s+)?)?([^_ ]\w+)\s+(.+);")
		self.REGEX_Register = re.compile(r"(?:__IO)?\s*(?:u?int(\d+)_t|(\w+))\s*(\D\w*)(?:\[(\d+)\])?\s*;.*")
		self.REGEX_Array = re.compile(r".+\[([0-9]+)\]")
		self.content : Dict[str,TypedefPeripheral] = dict()
		self.chip = chip
		self.extract_data(associated_header.extractGroup("Peripheral_registers_structures"),correction_matrix)
		
	def extract_data(self, data, correction : Dict[str,str] = dict()) :

		match = self.REGEX_Typedef.findall(data)
		for td in match:
			working_peripheral : TypedefPeripheral = TypedefPeripheral(td[1],self.chip)
			working_datas : List[str] = td[0].split("\n")
			
			for register_declaration in working_datas :
				match = self.REGEX_Register.search(register_declaration)
				if match :
					working_register = TypedefRegister()
					(std_size,nonstd_type,name,array_size) = match.groups()
					if nonstd_type is not None :
						if "TypeDef" in nonstd_type :
							nonstd_type = nonstd_type[:nonstd_type.rfind("_")]
					if std_size is not None :
						working_register.length_unit = int(int(std_size)/8)
					elif nonstd_type in self.content :
						working_register.length_unit = self.content[nonstd_type].size()
					if array_size is not None :
						working_register.length_multiple = int(array_size)
					if "RESERVED" not in name :
						working_register.name = name
						
					if working_register.name in correction :
						if correction[working_register.name] is None :
							continue
						else :
							working_register.name = correction[working_register.name]
							
					if "RESERVED" not in name and array_size is not None :
						print("WARN","Found array :",name)
						working_register.name += "[{:s}]".format(array_size)
						working_register.true_array = True
						working_register.address = working_peripheral.next_address()
						working_peripheral.append(copy(working_register))
						
						working_register.true_array = False
						working_register.length_multiple = 1
						for i in range(1,int(array_size)+1) :
							working_register.name = "{:s}{:d}".format(name,i)
							if working_register.name in correction :
								if correction[working_register.name] is None :
									continue
								else :
									working_register.name = correction[working_register.name]
							working_peripheral.append(copy(working_register),keep_adress=True)
							working_register.address += working_register.length_unit
					else :
						working_peripheral.append(copy(working_register))
			
			self.content[td[1]] = deepcopy(working_peripheral)
			
		
class TypedefRegister :
	def __init__(self, name : str = None, unit_length : int = 4, unit_multiple : int = 1, address : int = 0,chip : ChipSeriesManager = ChipSeriesManager(),true_array : bool = False):
		"""
		This class provides a register in the typedef reading context.
		:param name: Nom du registre
		:param unit_length: Lenght of one unit of size (in byte)
		:param unit_multiple: Number of units which compose the register. The actual size take by the register is unit_length
		"""
		
		self.name = copy(name)
		self.length_unit = copy(unit_length)
		self.length_multiple = copy(unit_multiple)
		self.address = copy(address)
		self.chip = copy(chip)
		self.true_array = copy(true_array)
	
	def __gt__(self, other : 'TypedefRegister'):
		if isinstance(self,other.__class__) :
			return self.address > other.address
	
	def __ge__(self, other : 'TypedefRegister'):
		if isinstance(self,other.__class__) :
			return self.address >= other.address
	
	def __eq__(self, other : 'TypedefRegister'):
		if isinstance(self,other.__class__) :
			return (self.name == other.name
					and self.address == other.address
					and self.full_size() == other.full_size())
			
			
	
	def __str__(self):
		return "{0:20s} on {1:2d} byte @ 0x{2:08x}".format(self.name,self.full_size(),self.address)
	
	def full_size(self) -> int :
		"""
		:return: Full register size in bytes
		"""
		return self.length_unit * self.length_multiple
	
	def cpp_output(self):
		if self.name is None :
			return ("uint{0}_t" + " " *35 + ":{1}"
											";   //0x{2:08X}").format(self.length_unit*8,self.full_size()*8,self.address)
		else :
			if self.true_array :
				return "{:50s} //0x{:08X}".format("uint{0}_t {1};".format(self.length_unit,self.name),self.address)
			else :
				return "{:50s} //0x{:08X}".format("{0}_TypeDef {0}{1};".format(self.name, ("[" + str(self.length_multiple) + "]") if self.length_multiple > 1 else ""),self.address)
		
		
	def got_same_def(self,item : 'TypedefRegister'):
		return self.name == item.name and self.full_size() == item.full_size() and self.address == item.address
	
	def get_mem_mapping(self) -> Set[int]:
		return set(range(self.address,self.address + self.full_size()))
		
		
class TypedefPeripheral :
	def __init__(self, name : str = None,chip : ChipSeriesManager = ChipSeriesManager()):
		"""
		
		:param name:
		"""
		self.name=copy(name)
		self.content : List[TypedefRegister] = list()
		self.chip = copy(chip)
	
	def __iter__(self) -> Iterable[TypedefRegister]:
		return (i for i in sorted(self.content))

	def __getitem__(self, item) -> TypedefRegister:
		if isinstance(item,str.__class__) :
			for i in self.content :
				if i.name == item :
					return i
			raise KeyError("Item not found for key " + str(item))
		elif isinstance(item,TypedefRegister) :
			for i in self.content :
				if i == item :
					return i
			raise KeyError("Item not found for key " + str(item.name))
		raise TypeError("Invalide type " + str(type(item)))
	
	def __contains__(self, item) -> bool:
		if isinstance(item,str.__class__) :
			for i in self.content :
				if item == i.name :
					return True
		elif isinstance(item,TypedefRegister) :
			return self.contains_same_def(item)
		return False
	
	def __len__(self) -> int:
			return len(self.content)
	
	def contains_same_def(self,item : TypedefRegister) -> bool:
		for i in self :
			if i.got_same_def(item) :
				return True
		return False
	
	def next_address(self, fast=True):
		if not len(self) :
			return 0
		if not fast :
			ret = 0
			for r in self :
				ret = max(ret,r.address + r.full_size())
			return ret
		return self.content[-1].address + self.content[-1].full_size()
	
	def append(self,item : TypedefRegister, keep_adress : bool = False, keep_chip = False) :
		if not keep_adress :
			item.address = self.next_address()
		if not keep_chip :
			item.chip = deepcopy(self.chip)
		self.content.append(copy(item))
	
	def size(self):
		return self.next_address()
	
	def merge(self,other : 'TypedefPeripheral') :
		for register in other :
			if self.contains_same_def(register) :
				self[register].chip.merge(register.chip)
			else :
				self.append(register,True,True)
	
	def get_mem_mapping(self) -> Set[int]:
		output : Set[int] = set()
		for reg in self :
			output |= set(reg.get_mem_mapping())
		return output
		
	def is_crossing(self,item : TypedefRegister) -> bool:
		return len(self.get_mem_mapping().intersection(item.get_mem_mapping())) > 0
		
	def is_valid(self):
		work_mem_map = set()
		for reg in self :
			if len(work_mem_map.intersection(reg.get_mem_mapping())) > 0 :
				return False
			work_mem_map |= reg.get_mem_mapping()
		return True
		
	
	def simplify(self):
		output = deepcopy(self)
		output.content.clear()
		current_content = TypedefPeripheral()
		
		for r in sorted(self,key=lambda x : len(x.chip.chip_list),reverse=True) :
			if r.name is None :
				continue
			if current_content.is_crossing(r) :
				output.append(deepcopy(r),True,True)
			else :
				current_content.append(r,True,True)
		self.content = current_content.content
		return output
		
	def fill(self,end : int):
		"""
		Fill peripheral with empty register up to the address end -1 so
		self.next_address() return end
		:param end: Next address after filling
		"""
		
		if type(self.next_address(self.is_valid())) is not int :
			raise TypeError("Wrong address return type")
		if type(end) is not int :
			raise TypeError("Wrong end type " + str(end))
		to_fill = sorted(list(set(range(0,max(self.next_address(self.is_valid()),end))) - (self.get_mem_mapping())))
		if len(to_fill) == 0:
			return
		
		start : int = to_fill[0]
		last : int = to_fill[0]
		
		to_fill.append(to_fill[-1] + 2)
		for i in to_fill[1:] :
			if i-last > 1 :
				#Filling required
				gap_size = last - start + 1
				if gap_size % 2 :
					self.append(TypedefRegister(unit_length=1,address=start,chip=copy(self.chip)),True)
					#Add 8bit fill
					gap_size -=1
					start += 1
				if gap_size % 4 :
					self.append(TypedefRegister(unit_length=2,address=start,chip=copy(self.chip)),True)
					#Add 16 bit fill
					gap_size -=2
					start += 2
				if gap_size > 0 :
					self.append(TypedefRegister(unit_length=4,unit_multiple=int(gap_size/4),address=start,chip=copy(self.chip)),True)
				start = i
			last = i
	
	def sort(self):
		self.content = sorted(self.content)


	#alias_template   = "{periph}_MAP{map!s}_{reg.name}{suffixe}"
	alias_template = "{periph}_MAP{map!s}_{reg}{suffixe}"
	blank_template   = "\tuint{size_unit}_t\t:{full_size};\t// 0x{addr:04x} - 0x{end:04x} "
	field_template   = "\t{alias};\t// 0x{addr:04x} - 0x{end:04x} "
	define_template  = "\t#define {alias:25}\t{reg.name}_TypeDef\t{reg.name}\n"
	define_empty_template = "\t#define {alias:25}\tuint{size_unit}_t\t:{size}\n"
	
	define_template_true_array = "\t#define {alias:25}\t{name}_TypeDef\t{reg.name}\n"
	
	undef_template   = "#undef {alias}\n"
	
	def cpp_output(self, mapId, define_groups: Dict[str, List[Tuple[str, str, str]]]):
		output = "\nstruct\n{\n"
		names = []
		
		for reg in self :
			
			if reg.name is None :
				output += TypedefPeripheral.blank_template.format(size_unit = reg.length_unit*8, full_size = reg.full_size()*8,
				                                                  addr = reg.address, end = reg.address + reg.full_size())
			else :
				striped_name = reg.name.replace("[","_").replace("]","_")
				alias = TypedefPeripheral.alias_template.format(periph= self.name, map=mapId, reg=striped_name,
				                                                suffixe= "_{0}".format(names.count(striped_name)) if striped_name in names else "")
				output += TypedefPeripheral.field_template.format(alias = alias, addr = reg.address,
				                                                  end = reg.address + reg.full_size())
				key = reg.chip.output_ifdef_template()
				if key not in define_groups :
					define_groups[key] = list()

				if reg.true_array :
					define_groups[key].append((
						TypedefPeripheral.define_template_true_array.format(alias=alias,name=reg.name[:reg.name.find("[")],reg=reg),
						TypedefPeripheral.define_empty_template.format(alias=alias,size_unit=reg.length_unit * 8,
																	   size=reg.full_size() * 8),
						TypedefPeripheral.undef_template.format(alias=alias)
					))
				else :
					define_groups[key].append((
							TypedefPeripheral.define_template.format(alias=alias, reg = reg),
							TypedefPeripheral.define_empty_template.format(alias=alias, size_unit=reg.length_unit*8, size=reg.full_size()*8),
							TypedefPeripheral.undef_template.format(alias=alias)
						))

				names.append(striped_name)
			output += str(reg.chip) + "\n"
		output += "} __attribute__((__packed__));"

		return output
