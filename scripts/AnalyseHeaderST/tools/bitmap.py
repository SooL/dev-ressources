#!/usr/bin/python3
#-*-coding:utf-8 -*

import re
import header
from typing import *
from copy import deepcopy, copy
from .utils import ChipSeriesManager
verbosity = 1

class Mask :
	def __init__(self, o : int= 0, l : int = 0):
		self.offset = o
		self.length = l
	
	def __int__(self):
		ret = 0
		for i in range(0, self.length) :
			ret += 1
			ret <<= 1
		ret >>= 1
		ret <<= self.offset
		return ret
	
	def __str__(self):
		return "{:032b}".format(int(self))
		
	def __eq__(self,other) :
		if isinstance(self,other.__class__) :
			return (self.offset == other.offset
					and self.length == other.length)
	
	def __gt__(self,other) :
		if isinstance(self,other.__class__) :
			return self.offset > other.offset
	
	def __ge__(self,other) :
		if isinstance(self,other.__class__) :
			return self.offset >= other.offset
	
	def __iter__(self):
		return (i for i in range(self.offset, self.offset + self.length))
	
	def cross(self, other):
		return mask_cross(int(self), int(other))
	
	def set_length_from_value(self,val : int) :
		self.length = len("{:b}".format(val).strip("0"))
	
	def set_offset_from_value(self, val : int) :
		self.offset = 0
		while val & 1 != 1 and self.offset < 32 :
			self.offset += 1
			val >>= 1
		
	def set_from_value(self, val : int):
		self.set_length_from_value(val)
		self.set_offset_from_value(val)
		return self

class BitField(Mask) :
	def __init__(self, name : str = None, matching_msk : Mask = Mask(0,0), register : 'BitRegister' = None, chips :ChipSeriesManager = ChipSeriesManager()) :
		self.name : str = name
		self.reg : BitRegister = register
		self.associated_chip : ChipSeriesManager = copy(chips)

		Mask.__init__(self,matching_msk.offset,matching_msk.length)
		
	def __eq__(self,other) :
		if isinstance(self,other.__class__) :
			return (Mask.__eq__(self,other)
					and self.name == other.name
					and self.associated_chip == other.associated_chip
					and self.reg == other.reg)
	
	def __str__(self):
		return "{name:20s} {msk} {chips}".format(name=self.name,msk=str(Mask.__str__(self)), chips=" ".join(["{:13s}".format(str(c)) for c in self.associated_chip]))
	
	def clear(self):
		self.name: str = None
		self.reg: BitRegister = None
		self.associated_chip: ChipSeriesManager = ChipSeriesManager()
		
		Mask.__init__(self,0,0)
		#self.__init__()
		
	def got_same_def(self,other : 'BitField'):
		if isinstance(self,other.__class__) :
			return (Mask.__eq__(self,other)
					and self.name == other.name
					and self.reg == other.reg)
	
Peripheral = str

class BitRegister :
	def __init__(self, name = None, size = 32, addr = 0, parent = None, chip : ChipSeriesManager = ChipSeriesManager()) :
		self.name = name
		self.full_size = size
		self.addr: int = addr
		self.parent: Peripheral = parent  # TODO Edit when peripheral object ready
		self.associated_chips: ChipSeriesManager = copy(chip)
		self.fields : List[BitField] = list()
		
	def __str__(self):
		return "{name:50s} {size:2} {addr:08x}".format(name=self.parent+"."+self.name,size=self.full_size,addr=self.addr)
	
	def __eq__(self, other : 'BitRegister'):
		if isinstance(self,other.__class__) :
			return (self.name == other.name
					and self.full_size == other.full_size
					and self.associated_chips == other.associated_chips
					and self.addr == other.addr
					and self.parent == other.parent
					and self.fields == other.fields)
	
	def __getitem__(self, item) -> BitField:
		if isinstance(item,int) :
			#Here looking on the position (not the offset)
			return self.fields[item]
		elif isinstance(item,str) :
			#Here looking on the name
			for i, val in enumerate(self.fields) :
				if val.name == item :
					return self.fields[i]
			raise KeyError("BitField " + item + " not found.")
		elif isinstance(item,BitField) :
				#return self.fields[self.fields.index(item)]
				for i in self :
					if i.got_same_def(item) :
						return i
				raise KeyError("BitField given not found.")
		else :
			raise TypeError("Invalid type " + str(type(item)) + " as index.")
	
	def __hash__(self):
		return hash((self.fields,self.name,self.full_size,self.addr,self.parent,self.associated_chips))
		
	def __len__(self):
		return len(self.fields)
	
	def __iter__(self):
		return (i for i in sorted(self.fields))
	
	def __contains__(self, item):
		if isinstance(item,str) :
			#Here looking on the name
			for i,val in enumerate(self.fields) :
				if val.name == item :
					return True
			return False
		elif isinstance(item,BitField) :
			return item in self.fields
		else :
			raise TypeError("Invalid type " + str(type(item)) + " as index.")
	
	def __gt__(self,other) :
		if isinstance(self,other.__class__) :
			return self.addr > other.addr
	
	def __ge__(self,other) :
		if isinstance(self,other.__class__) :
			return self.addr >= other.addr
	
	def get_eq_mask(self):
		out = 0
		for f in self :
			out += int(f)
		return out
	
	def contains_same_def(self,item : BitField):
		for i in self :
			if i.got_same_def(item) :
				return True
		return False
	
	def build_associated_chips(self):
		"""
		Will build self.associated_chips which represent the list of all chips for which the register is defined.
		"""
		self.associated_chips.clear()
		for field in self :
			self.associated_chips.merge(field.associated_chip)
			
		
	def merge(self,other : 'BitRegister'):
		"""
		Will add all BitField of "other" into the current BitRegister without checks for consistency.
		If the BitField already is present _with the same definition_, the chips it's referring to will be added to the
		current corresponding field so save work on simplification step.
		
		The call of this function should be followed by a synthetize call. (and even a recursive call)
		
		:param BitRegister other: the BitRegister to merge into the current one. Won't be modified.
		"""
		for i in other :
			if self.contains_same_def(i) :
				self[i].associated_chip.merge(copy(i.associated_chip))
			else :
				self.fields.append(i)
		
	def simplify(self) -> 'BitRegister':
		"""
		Will remove any overlapping field from this one and return it.
		:return: Overlapping fields in a BitRegister
		"""
		output = deepcopy(self)
		output.fields.clear()
		current_content = BitRegister()
		for f in sorted(self,key=lambda x : len(x.associated_chip.chip_list),reverse=True) :#Order by number of chips reversed.
			if f.cross(current_content.get_eq_mask()) :
				output.fields.append(deepcopy(f))
			else :
				current_content.fields.append(copy(f))
		self.fields = copy(current_content.fields)
		return output

	def is_valid(self) -> bool:
		"""
		Return true if there is no field overlapping each other in the BitRegister
		
		:return:
		"""
		compare = deepcopy(self)
		compare.fields.clear()
		
		for f in self :
			if not f.cross(compare.get_eq_mask()) :
				compare.fields.append(f)
			else :
				return False
		return True
	
	def fill(self):
		val = self.get_eq_mask()
		position = 0
		length = 0
		while position < self.full_size :
			if not (val & 1) :
				length += 1
			else :
				if length > 0 :
					self.fields.append(BitField(name="", matching_msk=Mask(position,length)))
				length = 0
			position += 1
			val >>= 1
		if length > 0 :
			self.fields.append(BitField(name="",matching_msk=Mask(position,length)))
			
	def cpp_output(self,indent_level : int = 0,prefix : str = str(), chip_reference : ChipSeriesManager = None) -> Tuple[Dict[str,List[Tuple[str,str,str]]],Tuple[str,int,str,ChipSeriesManager]] :
		"""
		This function will output the whole register to a structure suitable for SOOL C++ implementation
		
		:param chip_reference: Reference to simplify chips lists
		:param prefix: Prefix to add to names to create specifics aliases for each periph/reg
		:param indent_level: Specifies the base indentation level
		:return: The structure definition to add into a C++ header.
		"""
		work = copy(self)
		
		define_groups : Dict[str,List[Tuple[str,str,str]]] = dict()
		out_undef = ""
		computed_prefix = (prefix + "_" if len(prefix) else "")

		all_chips :ChipSeriesManager = None
		for f in work :
			if all_chips is None :
				all_chips = deepcopy(f.associated_chip)
			else :
				all_chips.merge(f.associated_chip)
				
		chip_reference.simplify(all_chips)
		
		for f in work :
			computed_name = computed_prefix + f.name
			if not all_chips == f.associated_chip :
				if computed_name not in BitRegister.used_aliases_defines :
					BitRegister.used_aliases_defines[computed_name] = 0
				BitRegister.used_aliases_defines[computed_name] += 1
				if BitRegister.used_aliases_defines[computed_name] > 1 :
					computed_name += "_" + str(BitRegister.used_aliases_defines[computed_name])
					
			if chip_reference is not None :
				chip_reference.simplify(f.associated_chip)
			if f.associated_chip == all_chips :
				continue
			key = f.associated_chip.output_ifdef_template()
			
			if key not in define_groups :
				define_groups[key] = list()
			#Build here the alias in define
			define_groups[key].append(("\t#define {0:20s} {1}\n".format(computed_name,f.name),
									   "\t#define {:20s}\n".format(computed_name,f.name),
									   "#undef {:20s}\n".format(computed_name,f.name)))
		if not all_chips.is_all_chips():
			key = all_chips.output_ifdef_template()
			if key not in define_groups:
				define_groups[key] = list()
			# Build here the alias in define
			#define_groups[key].append(("\t#define {0}\n".format(prefix), "", ""))
		
		work.fill()
		idt = "\t"*(indent_level-1)
		#out_struc = [	"struct " + work.name + "_TypeDef : public hll::Reg" + str(work.full_size) + "_t",
		#		"{",
		#		"\tusing hll:Reg" + str(work.full_size) + "_t::operator=;"]
		out_struc = list()
		for f in sorted(work,reverse=False) :
			computed_name = computed_prefix + f.name
			if not f.associated_chip == all_chips :
				if computed_name not in BitRegister.used_aliases_reg :
					BitRegister.used_aliases_reg[computed_name] = 0
				BitRegister.used_aliases_reg[computed_name] += 1
				if BitRegister.used_aliases_reg[computed_name] > 1 :
					computed_name += "_" + str(BitRegister.used_aliases_reg[computed_name])
			out_struc.append("\tuint{reg_size}_t {field_name:20s} :{field_size};".format(
				reg_size=work.full_size,
				field_name=f.name if (f.associated_chip == all_chips or len(f.name)==0) else (computed_name),
				field_size=f.length
				))
		#out_struc.append("} __attribute__(( __aligned__(" + str(int(work.full_size/8))+") ));\n")
		
		return (define_groups, (work.name,work.full_size,("\n"+idt ).join(out_struc), None if all_chips.is_all_chips() else all_chips))
	
	
BitRegister.used_aliases_defines : Dict[str,int] = dict()
BitRegister.used_aliases_reg : Dict[str,int] = dict()

class BitPeripheral :
	def __init__(self, name : str = str()):
		self.name : str = name
		self.registers : List[BitRegister] = list()
		self.associated_chips : ChipSeriesManager = ChipSeriesManager()
		
	def __getitem__(self,item) -> BitRegister :
		if isinstance(item,int) :
			#Here looking on the position (not the offset)
			return self.registers[item]
		elif isinstance(item,str) :
			#Here looking on the name
			for i,val in enumerate(self.registers) :
				
				if val.name == item :
					return self.registers[i]
			raise KeyError("BitField " + item + " not found.")
		elif isinstance(item,BitRegister) :
			return self.registers[self.registers.index(item)]
		else :
			raise TypeError("Invalid type " + str(type(item)) + " as index.")
	
	def __hash__(self) :
		return hash((self.name, self.registers))
	
	def __len__(self) :
		return len(self.registers)
	
	def __iter__(self) :
		return (i for i in sorted(self.registers))
	
	def __contains__(self,item) :
		if isinstance(item,str) :
			#Here looking on the name
			for i,val in enumerate(self.registers) :
				if val.name == item :
					return True
			return False
		elif isinstance(item,BitRegister) :
			return item in self.registers
		else :
			raise TypeError("Invalid type " + str(type(item)) + " as index.")

	def __str__(self):
		out = str()
		for r in self :
			out += r.name + " "
		return out[:-1]

	def merge(self, other : 'BitPeripheral') -> 'BitPeripheral':
		"""
		Add other's registers into this one
		
		:param 'BitPeripheral' other:
		"""
		for reg in other :
			if reg not in self :
				self.registers.append(deepcopy(reg))
		return self
	
	def build_associated_chips(self) :
		for register in self :
			register.build_associated_chips()
			self.associated_chips.merge(register.associated_chips)
		
		
	
class BitExtractor :
	def __init__(self, associated_header : header, chip : ChipSeriesManager, correction_matrix : Dict[Tuple[str,str,str],Tuple[str,str,str]] = dict()):
		self.REGEX_Combined_Pos = re.compile(r"#define (\w+)_Pos\s+\(?([0-9]+)U?\)?")
		self.REGEX_Combined_Msk = re.compile(r"#define (\w+)_Msk\s+\((0x[A-Fa-f0-9]+)U?\s*<<\s*(\w+)_Pos\)?")
		self.REGEX_Combined_Direct = re.compile(r"#define (\w+)\s+\((0x[A-Fa-f0-9]+)U?\s*<<\s*(\w+)_Pos\)?")
		self.REGEX_SimpleMsk = re.compile(r"#define\s+(\w+)\s+\(?(?:\(uint(?:32|16|8)_t\))?\s*((?:0x[A-Fa-f0-9]+|[0-9]+))U?\s*\)?")
		self.REGEX_SimpleRef = re.compile(r"#define\s+(\w+)\s+\(?(\w+)\)?")


		
		self.REGEX_RegisterName = re.compile(r"(\w+)R([0-9]+)")
		
		self.header : header = associated_header
		self.extracted_fields : List[BitField] = list()
		self.extracted_structure : Dict[Peripheral, BitPeripheral] = dict()
		self.current_chips : ChipSeriesManager = copy(chip)
		self.correction_matrix = copy(correction_matrix)
		self.extract_mapping()
		self.process_mapping()
		self.extracted_fields.clear()

	def extract_mapping(self):
		"""
		This function will extract all data from file and build a list of fields.
		
		The fields are named directly after the defines values (eg : GPIO_ODR_ODR1) and will have to be post-processed
		to assume register, peripheral and actual name.
		
		All data are stored into self.extracted_fields.
		"""
		fast_index : Dict[str, BitField] = dict()
		data_lines = self.header.extractGroup("Peripheral_Registers_Bits_Definition").split("\n")
		current_bitfield : BitField = BitField()
		
		for line in data_lines :
			current_bitfield.associated_chip = self.current_chips
			
			match = self.REGEX_Combined_Pos.search(line)
			if match :
				current_bitfield.name = match.group(1)
				current_bitfield.offset = int(match.group(2),0)
				continue
			
			match = self.REGEX_Combined_Msk.search(line)
			if match :
				if match.group(3) not in current_bitfield.name and match.group(3) not in match.group(1) :
					raise Exception(
						str("Mismatch between Pos (" + match.group(3) + ") and expected (" + current_bitfield.name + ")"))
				if not isMaskContinuous(int(match.group(2),0)) :
					current_bitfield.clear()
					continue
				current_bitfield.set_length_from_value(int(match.group(2), 0))
				#self.extracted_fields.append(deepcopy(current_bitfield))
				self.extracted_fields.append(deepcopy(current_bitfield))
				fast_index[current_bitfield.name] = self.extracted_fields[-1]
				current_bitfield.clear()
				continue
			
			match = self.REGEX_Combined_Direct.search(line)
			if match :
				if current_bitfield.name is None : continue
				if match.group(3) not in current_bitfield.name and match.group(3) not in match.group(1) :
					raise Exception(
						str("Mismatch between Pos (" + match.group(3) + ") and expected (" + current_bitfield.name + ")"))
				if not isMaskContinuous(int(match.group(2),0)) :
					current_bitfield.clear()
					continue
				current_bitfield.set_length_from_value(int(match.group(2),0))
				#self.extracted_fields.append(deepcopy(current_bitfield))
				self.extracted_fields.append(deepcopy(current_bitfield))
				fast_index[current_bitfield.name] = self.extracted_fields[-1]
				current_bitfield.clear()
				continue
			
			match = self.REGEX_SimpleMsk.search(line)
			if match :
				if not isMaskContinuous(int(match.group(2),0)) :
					current_bitfield.clear()
					continue
				self.extracted_fields.append(BitField(match.group(1), Mask().set_from_value(int(match.group(2), 0)), None, copy(self.current_chips)))
				fast_index[match.group(1)] = self.extracted_fields[-1]
				continue
			
			match = self.REGEX_SimpleRef.search(line)
			if match :
				if match.group(2) == str(self.extracted_fields[-1].name + "_Msk") :
					#On vient d'ajouter ce point donc on skip.
					continue
					#new_field = deepcopy(self.extracted_fields[-1])
					#new_field.name = match.group(1)
					#fast_index[new_field.name] = new_field
					#self.extracted_fields.append(new_field)
				else :
					if match.group(2) in fast_index.keys() :
						#new_field = deepcopy(fast_index[match.group(2)])
						new_field = copy(fast_index[match.group(2)])
						new_field.name = match.group(1)
						self.extracted_fields.append(new_field)
						fast_index[new_field.name] = new_field
					else :
						if verbosity > 1 : print(
							"[Warning - KEYNFOND] : " + match.group(1) + " \tline " + match.group(0))
				continue
			
			if verbosity > 1 and "#define" in line :
				print("[Warning - SKIPLINE] : " + line)

	def process_mapping(self):
		"""
		This function actually process all bitfield names, build and populate the structure.
		
		"""
		#TODO Insert case examples
		self.extracted_structure.clear()
		for i, bitfield in enumerate(self.extracted_fields) :
			if int(bitfield) == 0 :
				if verbosity > 1 :
					print("[Warning - MSKVOID] : Bit mask (" + bitfield.name + ") void. Skipped")
				continue
			name_fields = bitfield.name.split("_")
			
			if len(name_fields) < 2 :
				print("[bitmap::process_mapping] ERROR : The field indexed " +  str(i) + " have an invalid name : " + bitfield.name + " (Not enough fields)")
				continue
				
			peripheral = name_fields[0]
			register = name_fields[1]
			
			#Remove all digit in the end of periph name (eg TIM1 -> TIM)
			peripheral = peripheral.rstrip("0123456789")
			
			field = register if len(name_fields) < 3 else name_fields[2]
			
			#Correct USB_OTG case
			if peripheral == "USB" and register == "OTG" :
				peripheral == "USB_OTG"
				register = name_fields[2]
				field = register if len(name_fields) < 4 else name_fields[3]
			
			#Correct case of PERIPHERAL_REGISTER_FIELD_1
			if len(name_fields) >= 4 :
				if name_fields[3].isdigit() :
					field += name_fields[3]
					
			#Correct case of PERIPHERAL_REGISTER_1
			if field.isdigit() :
				field = register + field
			
			if (peripheral,register,field) in self.correction_matrix :
				field = self.correction_matrix[(peripheral,register,field)][2]
			
			if (peripheral,register,None) in self.correction_matrix :
				register = self.correction_matrix[(peripheral,register,None)][1]
			
			if (peripheral,None,None) in self.correction_matrix :
				peripheral = self.correction_matrix[(peripheral,None,None)][0]
				
			if field is None or register is None or peripheral is None :
				continue
			
			#Remove "R" in ODR1 if OD+R = register name (ie if the field is unrelated to the register name, it will be left alone)
			match = self.REGEX_RegisterName.search(field)
			if match :
				#ODR1 => OD1
				#TODO Check if useful (probably not cause REGEX match only if R present)
				if not match.group(1) + "R" == register :
					field = match.group(1) + "R" + match.group(2)
				else :
					field = match.group(1) + match.group(2)
					
			self.extracted_fields[i].name = field


			if peripheral not in self.extracted_structure :
				self.extracted_structure[peripheral] = BitPeripheral(peripheral)
				
			if register not in self.extracted_structure[peripheral] :
				self.extracted_structure[peripheral].registers.append(BitRegister(register, parent=peripheral))
			
			#index = [r.name for r in self.extracted_structure[peripheral]].index(register)
			already_defined = False
			for name in [f.name for f in self.extracted_structure[peripheral][register]] :
				if name == self.extracted_fields[i].name :
					already_defined = True
					break
					
			if not already_defined:
				self.extracted_structure[peripheral][register].fields.append(self.extracted_fields[i])
			
			
			
			

# class bit_map :
# 	def __init__(self,associatedHeader : header) :
# 		self.associatedHeader = associatedHeader
# 		self.data = associatedHeader.extractGroup("Peripheral_Registers_Bits_Definition")
# 		self.dataLines = self.data.split("\n")
#
# 		self.REGEX_Combined_Pos = re.compile(r"#define (\w+)_Pos\s+\(?([0-9]+)U?\)?")
# 		self.REGEX_Combined_Msk = re.compile(r"#define (\w+)_Msk\s+\((0x[A-Fa-f0-9]+)U?\s*<<\s*(\w+)_Pos\)?")
# 		self.REGEX_SimpleRef = re.compile(r"#define\s+(\w+)\s+\(?(\w+)\)?")
# 		self.REGEX_SimpleMsk = re.compile(r"#define\s+(\w+)\s+\(?(?:\(uint(?:32|16|8)_t\))?\s*((?:0x[A-Fa-f0-9]+|[0-9]+))U?\s*\)?")
# 		self.REGEX_Combined_Direct = re.compile(r"#define (\w+)\s+\((0x[A-Fa-f0-9]+)U?\s*<<\s*(\w+)_Pos\)?")
#
# 		self.REGEX_RegisterName = re.compile(r"(\w+)R([0-9]+)")
# 		self.rawAssociation :Dict[str,int]= dict()
# 		self.extractedPeripheralStructure = dict()
# 		#extractedPeripheralStructure[periph][register][field] = mask
#
#
# 		self.registerNameCorrection = dict() 	#registerNameCorrection[(Periph,RegisterName)] = NewRegisterName
# 		self.fieldNameCorrection = dict()		#fieldNameCorrection[(Periph,Register,Field)] = NewFieldName
#
# 	def buildRawMap(self)  :
# 		currPos = 0
# 		currMsk = 0
# 		currPosName = None
# 		currMskName = None
#
# 		for line in self.dataLines :
# 			match = self.REGEX_Combined_Pos.search(line)
# 			if match :
# 				currPosName = match.group(1)
# 				currPos = int(match.group(2),0)
# 				continue
#
# 			match = self.REGEX_Combined_Msk.search(line)
# 			if match :
# 				currMskName = match.group(1)
# 				if match.group(3) != currPosName :
# 					raise Exception(str("Mismatch between Pos (" + match.group(3) + ") and expected (" + currPosName + ")"))
# 				currMsk = int(match.group(2),0) << currPos
# 				continue
#
# 			match = self.REGEX_Combined_Direct.search(line)
# 			if match :
# 				if match.group(3) != currPosName :
# 					raise Exception(str("Mismatch between Pos (" + match.group(3) + ") and expected (" + currPosName + ")"))
# 				currMsk = int(match.group(2),0) << currPos
# 				self.rawAssociation[match.group(1)] = currMsk
# 				continue
#
# 			match = self.REGEX_SimpleMsk.search(line)
# 			if match :
# 				self.rawAssociation[match.group(1)] = int(match.group(2),0)
# 				continue
#
# 			match = self.REGEX_SimpleRef.search(line)
# 			if match :
# 				if match.group(2) == str(currMskName + "_Msk") :
# 					self.rawAssociation[match.group(1)] = currMsk
# 				else :
# 					if match.group(1) in self.rawAssociation.keys() :
# 						self.rawAssociation[match.group(1)] = self.rawAssociation[match.group(2)]
# 					else :
# 						if verbosity > 1 : print("[Warning - KEYNFOND] : " + match.group(1) + " \tline " + match.group(0))
# 				continue
#
# 			if verbosity > 1  and "#define" in line :
# 				print("[Warning - SKIPLINE] : " + line)
#
#
# 		return self.rawAssociation
#
# 	def extractPeripheralStructure(self) :
# 		if self.rawAssociation == dict() :
# 			self.buildRawMap()
#
# 		for bitDef in self.rawAssociation.keys() :
# 			if self.rawAssociation[bitDef] == 0 :
# 				if verbosity > 1 :
# 					print("[Warning - MSKVOID] : Bit mask (" + bitDef + ") void. Skipped")
# 				continue
# 			if not isMaskContinuous(self.rawAssociation[bitDef]) :
# 				if verbosity > 1 :
# 					print("[Warning - MSKCTNT] : Bit mask (" + bitDef + ") not continuous ("+ display.toBin(self.rawAssociation[bitDef],32) +"). Skipped")
# 				continue
# 			p = bitDef.split("_")
# 			periph = p[0]
#
# 			#Remove any digit in the end of a periph name (TIMx)
#
#
# 			register = p[1]
#
#
# 			if periph == "USB" and register == "OTG" :
# 				periph == "USB_OTG"
# 				register = p[2]
# 				field = register if len(p) < 4 else p[3]
#
# 			if (periph,register) in self.registerNameCorrection.keys() :
# 				if self.registerNameCorrection[(periph,register)] == "" : continue
# 				register = self.registerNameCorrection[(periph,register)]
#
# 			field = register if len(p) < 3 else p[2]
#
# 			if len(p) >= 4 :
# 				if p[3].isdigit() :
# 					field += p[3]
# 			if field.isdigit() :
# 				field = register + field
#
# 			if (periph,register,field) in self.fieldNameCorrection.keys() :
# 				if self.fieldNameCorrection[(periph,register,field)] == "" : continue
# 				field = self.fieldNameCorrection[(periph,register,field)]
#
# 			match = self.REGEX_RegisterName.search(field)
#
# 			if match :
# 				if not match.group(1) + "R" == register :
# 					field = match.group(1) + "R" + match.group(2)
# 				else :
# 					field = match.group(1) + match.group(2)
#
#
# 			if periph not in self.extractedPeripheralStructure.keys() :
# 				self.extractedPeripheralStructure[periph] = dict()
#
# 			if register not in self.extractedPeripheralStructure[periph].keys() :
# 				self.extractedPeripheralStructure[periph][register] = dict()
#
#
#
# 			if field not in self.extractedPeripheralStructure[periph][register].keys() :
#
# 				if not isContainedInField(self.rawAssociation[bitDef],self.extractedPeripheralStructure[periph][register]) :
# 					overlap = isFieldOverlapping(self.rawAssociation[bitDef],self.extractedPeripheralStructure[periph][register])
# 					for f in overlap[0] :
# 						self.extractedPeripheralStructure[periph][register].pop(f)
# 					if verbosity > 1  and len(overlap[1]) :
# 						print("[Warning - BTOVRLAP] : " + bitDef + " overlap with bits " + str(overlap[1]))
# 					self.extractedPeripheralStructure[periph][register][field] = self.rawAssociation[bitDef]
#
#
# 		return self.extractedPeripheralStructure
#
# 	def setRegisterCorrectionTable(self,reg_corr : dict()) :
# 		"""
# 		Set a register name correction table BEFORE processing through extractPeripheralStructure
#
# 		:param reg_corr: The table to use
# 		:type reg_corr: dict() reg_corr[(Periph,RegisterName)] = NewName
#
# 		:return: None
# 		"""
# 		self.registerNameCorrection = reg_corr
#
# 	def setFieldCorrectionTable(self,field_corr : dict()) :
# 		"""
# 		Set a field name correction table BEFORE processing through extractPeripheralStructure
#
# 		:param field_corr: The table to use
# 		:type field_corr: dict() field_corr[(Periph,Register,Field)] = NewFieldName
#
# 		:return: None
# 		"""
# 		self.fieldNameCorrection = field_corr
#
# 	def correctRegisterName(self,peripheral : str(), original : str(), correct : str()) :
# 		if peripheral in self.extractedPeripheralStructure.keys() :
# 			if original in self.extractedPeripheralStructure[peripheral].keys() :
# 				if correct != str() :
# 					self.extractedPeripheralStructure[peripheral][correct] = dict(self.extractedPeripheralStructure[peripheral][original])
# 				self.extractedPeripheralStructure[peripheral].pop(original)
#
# 	def correctFieldName(self,path : tuple(), original : str(), correct : str()) :
# 		peripheral = path[0]
# 		register = path[1]
# 		if peripheral in self.extractedPeripheralStructure.keys() :
# 			if register in self.extractedPeripheralStructure[peripheral].keys() :
# 				if original in self.extractedPeripheralStructure[peripheral][register].keys() :
# 					if correct != str() :
# 						self.extractedPeripheralStructure[peripheral][register][correct] = self.extractedPeripheralStructure[peripheral][register][original]
# 					self.extractedPeripheralStructure[peripheral][register].pop(original)
#
# 	"""def correct(self, original = (None, None), correct = (None,None)) :
#
# 		original_peripheral = original[0]
# 		original_register = original[1]
# 		correct_peripheral = correct[0]
# 		correct_register = correct[1]
#
# 		if correct_peripheral == None : correct_peripheral = original_peripheral
#
# 		if original_peripheral != None and original_peripheral in self.extractedPeripheralStructure.keys() :
# 			if correct_peripheral != original_peripheral and original_peripheral != None :
# 				self.extractedPeripheralStructure[correct_peripheral] = self.extractedPeripheralStructure[correct_peripheral]
# 				self.extractedPeripheralStructure.pop(correct_peripheral)
#
#
#
# 			if correct_register != original_register and correct_register != None and original_register in self.extractedPeripheralStructure[correct_peripheral].keys():
# 				self.extractedPeripheralStructure[correct_peripheral][correct_register] = self.extractedPeripheralStructure[original_peripheral][original_register]
# 				self.extractedPeripheralStructure[original_peripheral].pop(correct_register)"""

def isFieldOverlapping(mask : int, register : dict()) :
	"""
	Check if a mask overlap within a register
	
	to test : [0110]
	overlap to : [0100] or [1100]
	partial overlap with [1100] but not with [0100]
	
	:param mask: The mask to evaluate
	:param register: The register to evaluate the mask against
	:type mask: integer
	:type register: dict() register[name] = mask
	
	:return: Return a tuple (overlap,partial_overlap) which contain a list of overlapping fields and a specification of partially overlapping fields.
	:rtype: ([overlap_list],[partial_overlap_list])
	"""
	ret = []
	partial = []
	for f in register.keys() :
		if (mask ^ register[f]) & register[f] < register[f] :
			ret.append(f)
			if (mask ^ register[f]) & mask :
				partial.append(f)
			
	return (ret,partial)

def isContainedInField(mask : int, register : dict()) :
	"""
	Check if a mask is fully contained in a register
	
	:param mask: The mask to evaluate
	:param register: The register to evaluate the mask against
	:type mask: integer
	:type register: dict() register[name] = mask
	"""
	fullReg = 0
	for f in register.keys() :
		fullReg |= register[f]
		
	return not (mask ^ fullReg) & mask
	
def getMaskCarac(mask : int) :
	pos = 0
	lenght = 0
	
	while not mask & 1 :
		pos += 1
		mask >>= 1
	
	while mask & 1 :
		lenght += 1
		mask >>= 1
	
	return (pos,lenght)

def isMaskContinuous(mask : int) :
	ret = True
	state = 0
	while mask != 0 :
		if state == 0 and mask & 1 :
			state = 1
		elif state == 1 and not mask & 1 :
			if mask != 0 : return False
		mask >>= 1
	return ret

def mask_cross(mask1 : int, mask2 : int) :
	"""
	Return true if the two masks overlap each others
	:param mask1:
	:param mask2:
	:return:
	"""
	return (mask1 ^ mask2) & mask1 != mask1