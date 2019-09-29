#!/usr/bin/python3
# -*-coding:utf-8 -*

import re
from structure.peripheral import *
from tools.msglog import *

REGEX_HRTIM_BDTxUPR = re.compile("BDT[A-Z]UPR")
class Header :
	def __init__(self,path: str,chips: ChipSeriesManager = ChipSeriesManager()) :
		self.filePath = path
		self.chips = ChipSeriesManager(chips.chip_list)
		with open(self.filePath,'r') as data :
			self.fileContentRaw = data.read()
			self.fileContentLines = self.fileContentRaw.split('\n')
			
			self.REGEX_Typedef = re.compile(r"typedef struct\n\{([^}]+)\}\s*(.*)_?TypeDef;")
			#	self.REGEX_Register = re.compile(r"(?:\s*__\w+\s+(?:const\s+)?)?([^_ ]\w+)\s+(.+);")
			self.REGEX_Register = re.compile(r"(?:__IO)?\s*(?:u?int(?P<std_size>\d+)_t|(?P<nonstd_type>\w+))\s*(?P<name>\D\w*)(?:\[(?P<array_value>(?:0x)?[0-9A-Fa-f]+)\])?\s*;.*")
			self.REGEX_Array = re.compile(r".+\[([0-9]+)\]")
			
			self.REGEX_Bitfield_Combined = re.compile(r"#define (?P<name>\w+)_(?P<type>Pos|Msk)\s+\(?(?:(?P<msk>0x[A-Fa-f0-9]+)|(?P<pos>\d+))U?(?:\s*<<\s*(?P<ref_pos>\w+)_Pos)?\)?")
			self.REGEX_Bitfield_Direct = re.compile(r"#define\s+(?P<name>\w+)\s+\(?(?:\(uint(?:32|16|8)_t\))?\s*(?:(?:(?P<literal>0x[A-Fa-f0-9]+|[0-9]+))U?|(?P<ref_name>[A-Z]+(?:_[A-Za-z0-9]+)*))\s*\)?")
			
			""" REGEX tests
			#define ADC_ISR_ADRDY_Pos         (0U)
			#define ADC_ISR_ADRDY_Msk         (0x1U << ADC_ISR_ADRDY_Pos)                  /*!< 0x00000001 */
			#define ADC_ISR_ADRDY             ADC_ISR_ADRDY_Msk                            /*!< ADC ready flag */

			#define CRC_IDR_IDR              ((uint8_t)0xFFU)
			"""

			self.REGEX_Address = re.compile(r"#define\s+(?P<name>\w+)\s+\(?(?P<base>[a-zA-Z]\w+)?(?:\(?uint32_t\)?|\s*\+\s*)?(?P<addr>0[xX][0-9a-f-A-F]+)?U?L?\)?")
			""" REGEX Tests
			#define SRAM_BASE             ((uint32_t)0x20000000U)              /*!< SRAM base address in the alias region */
			#define PERIPH_BASE           ((uint32_t)0x40000000U)              /*!< Peripheral base address in the alias region */

			#define APBPERIPH_BASE        PERIPH_BASE
			#define AHBPERIPH_BASE        (PERIPH_BASE + 0x00020000)
			#define FLASH_BASE            0x08000000U
			#define FLASH_BASE            (0x08000000U)
			"""
			self.REGEX_Peripheral_declaration = re.compile(r"#define\s+(?P<name>\w+)\s+\(?\((?P<periph>\w+[a-zA-Z0-9])_?TypeDef\s*\*\)\s*(?P<ref>\w+)\)?")
			""" REGEX Tests
			#define MDMA_Channel15      ((MDMA_Channel_TypeDef *)MDMA_Channel15_BASE)
			#define USB1_OTG_HS         ((USB_OTG_GlobalTypeDef *) USB1_OTG_HS_PERIPH_BASE)
			#define ETH                 ((ETH_TypeDef *)ETH_BASE)
			#define MDMA                ((MDMA_TypeDef *)MDMA_BASE)
			"""

			self.REGEX_IRQ_enum_content = re.compile(r"typedef\s+enum\s*\n{([^}]+)} IRQn_Type;")
			self.REGEX_IRQ_extraction = re.compile(r"(?P<name>\w+_IRQn)\s*=\s*(?P<value>(-?\d+))")
			self.REGEX_CMSIS_param = re.compile(r"#define\s+(?P<name>__\w+)\s+(?P<value>(?:0[xX])?[0-9A-Fa-f]+)")
			self.correction_matrix = None
			self.correction_postprocess = None
	
	def findGroup(self,group: str) :
		data = self.fileContentRaw
		start = data.find("@addtogroup " + group)
		
	
	def extractGroup(self,group: str) -> str :
		data = self.fileContentRaw
		start = data.find("@addtogroup " + group)
		temp = 0
		# Erreur
		if start == -1 :
			start = data.find("@brief " + group)
			# Erreur
			if start == -1 : return None
			temp = data.find("*/",start) + 2
		else:
			temp = data.find("@{",start) + 2

		end = data.find("@}",start) + 2
		while end != -1 :
			temp = data.find("@{",temp,end)
			if temp != -1 :
				temp += 2
				end = data.find("@}",end)
				if end != -1 : end += 2
			else :
				break
		
		return data[start :end - 2]
	def extract_irq_values(self) -> Dict[str,int]:
		"""
		This function will output the values defined in the IRQn enumeration.
		"""

		data = self.extractGroup("Peripheral_interrupt_number_definition")
		if data is None :
			log("E_MISSIRQGRP","Missing IRQ enum group",self.chips)
			data = self.fileContentRaw
		match = self.REGEX_IRQ_enum_content.search(data)

		output : Dict[str,int] = dict()
		if match :
			data = match[1]
		else :
			log("E_MISSIRQDATA","Missing IRQ data",self.chips)
			return None
		for line in data.split("\n") :
			match = self.REGEX_IRQ_extraction.search(line)
			if not match :
				continue
			infos = match.groupdict()

			output[infos["name"]] = int(infos["value"])
		return output

	def extract_CMSIS_configuration(self) -> Dict[str,int] :
		"""
		This function extract when possible the CMSIS configuration of the core.
		"""

		data = self.extractGroup("Configuration_section_for_CMSIS")
		output = dict()
		if data is None :
			log("E_MISSCMSIS","Missing CMSIS configuration group",self.chips)
			return None
		for line in data.split("\n") :
			match = self.REGEX_CMSIS_param.search(line)
			if not match :
				continue
			infos = match.groupdict()
			output[infos["name"]] = int(infos["value"],0)
		return output

	def extract_memory_mapping(self) -> Dict[str,Tuple[int,str]]:
		"""
		This function will output the raw memory mapping Name -> (Addr, Original type)
		"""
		data = self.extractGroup("Peripheral_memory_map").split("\n")
		base_addr = dict()

		for line in data :
			match = self.REGEX_Address.search(line)
			if match :
				addr = 0
				base_info = match.groupdict()
				if base_info["name"] in base_addr :
					log("W_BASE_DBL","Base address {0} already registered".format(base_info["name"]),self.chips)
					continue
				if base_info["base"] is not None :
					if base_info["base"] not in base_addr :
						log("E_MISSING_BASE","Use of non declared " + base_info["base"], self.chips)
						continue
					addr = base_addr[base_info["base"]]
				addr += int(base_info["addr"],0) if base_info["addr"] is not None else 0
				base_addr[base_info["name"]] = addr


		data = self.extractGroup("Peripheral_declaration").split("\n")
		periph_infos = dict()

		for line in data :
			match = self.REGEX_Peripheral_declaration.search(line)
			if match :
				infos = match.groupdict()
				if infos["name"] in periph_infos :
					log("W_PERIPH_DBL","Peripheral {0} already registered".format(infos["name"]),self.chips)
					continue
				if infos["ref"] not in base_addr :
					log("E_MISSING_REF","Peripheral {0} address non referenced ({1})".format(infos["name"],infos["ref"]),self.chips)
					continue
				periph_infos[infos["name"]] = (base_addr[infos["ref"]],infos["periph"])

		return periph_infos



	def exploit_typedef(self,periph_dict: Dict[str,Peripheral]) -> None :
		"""
		This function will exploit all available information within the header typedefs
		to build the structure involving Peripherals and Registers.


		:param periph_dict: The peripherals to work on. [name,Periph] to help search.
		"""
		data = self.extractGroup("Peripheral_registers_structures")
		match = self.REGEX_Typedef.findall(data)
		
		for td in match :
			periph_name = td[1]
			if periph_name[-1] == "_" :
				periph_name = periph_name[:-1]

			elif periph_name[:8] == "USB_OTG_":
				periph_name = periph_name[:4] + periph_name[8:]

			working_data = td[0]
			
			if periph_name not in periph_dict :
				periph_dict[periph_name] = Peripheral(periph_name,ChipSeriesManager(self.chips.chip_list))
				working_peripheral = periph_dict[periph_name]
			else :
				working_peripheral = periph_dict[periph_name]
				working_peripheral.chips.merge(self.chips)
			
			current_pos: int = 0
			for line in working_data.split("\n") :
				match = self.REGEX_Register.search(line)
				if match is None :
					continue
				register_properties: Dict[str,str] = match.groupdict()
				
				map_name = register_properties["name"]
				if "RESERVED" in map_name.upper() :
					reg_size = int(register_properties["std_size"])
					array_size = 0
					if register_properties["array_value"] is None:
						array_size = 1
					else:
						array_size = int(register_properties["array_value"], 0)
					current_pos += reg_size * array_size
					continue
				reg_name = map_name
				################################################## change register name if necessary
				if working_peripheral.name == "CAN_FilterRegister":
					if map_name[:-1] == "FR":
						reg_name = "FR"

				elif working_peripheral.name == "DFSDM_Channel":
					if map_name == "CHWDATAR":
						map_name = reg_name = "CHWDATR"

				elif working_peripheral.name == "ETH" :
					if map_name in ["MACA0HR","MACA1HR","MACA2HR","MACA3HR"] : reg_name = "MACAHR"
					elif map_name in ["MACA0LR","MACA1LR","MACA2LR","MACA3LR"] : reg_name = "MACALR"
					elif map_name in ["MACL3L4C0R","MACL3L4C1R"] : reg_name = "MACL3L4CR"
					elif map_name in ["MACL4A0R","MACL4A1R"] : reg_name = "MACL4AR"
					elif map_name == "MACL3A0R0R" : map_name = reg_name = "MACL3A00R"
					elif map_name == "MACL3A1R0R" : map_name = reg_name = "MACL3A10R"
					elif map_name == "MACL3A2R0R" : map_name = reg_name = "MACL3A20R"
					elif map_name == "MACL3A3R0R" : map_name = reg_name = "MACL3A30R"
					elif map_name == "MACL3A0R1R" : map_name = reg_name = "MACL3A01R"
					elif map_name == "MACL3A1R1R" : map_name = reg_name = "MACL3A11R"
					elif map_name == "MACL3A2R1R" : map_name = reg_name = "MACL3A21R"
					elif map_name == "MACL3A3R1R" : map_name = reg_name = "MACL3A31R"

				elif working_peripheral.name == "FLASH" :
					parts = map_name.split("_")
					if len(parts) > 1 and parts[0] in ["BOOT","OPTSR","PRAR","SCAR"] and parts[1][:3] in ["CUR","PRG"] :
						reg_name = map_name.split("_")[0]
					elif map_name[:-1] in ["CCR","CRCCR","ECC_FA"] :
						reg_name = map_name[:-1]
					elif map_name[:-1] in ["CRCEADD","CRCSADD"] :
						reg_name = map_name[:-1] + "R"
					elif map_name[:5] == "WPSN_":
						reg_name = "WPSN"

				elif working_peripheral.name[:3] == "FMC" or working_peripheral.name[:4] == "FSMC":
					if map_name[:-1] in ["PATT", "PMEM", "PCR", "SR", "ECCR"]:
						reg_name = map_name[:-1]

				elif working_peripheral.name == "HRTIM_Common":
					if REGEX_HRTIM_BDTxUPR.match(map_name):
						reg_name = "BDTUPR"

				elif working_peripheral.name == "HRTIM_Timerx":
					if "x" in map_name:
						index = map_name.index('x')
						map_name = reg_name = map_name[:index]+map_name[(index+1):]

				elif working_peripheral.name in ["SDIO", "SDMMC"] :
					if map_name in ["RESP1", "RESP2", "RESP3", "RESP4"]:
						reg_name = "RESP"

				elif working_peripheral.name[:7] == "USB_OTG":
					working_peripheral.name[4:] = working_peripheral.name[7:]
				##################################################
				reg_size = 0
				reg = None
				if register_properties["array_value"] is None :
					array_size = 1
				else :
					array_size = int(register_properties["array_value"],0)
				
				if register_properties["std_size"] is not None :
					reg_type = "Reg{}_t".format(register_properties["std_size"])
					reg_size = int(register_properties["std_size"])
					reg = Register(reg_name,self.chips,reg_type,reg_size)
				elif register_properties["nonstd_type"] is not None :
					reg_type = register_properties["nonstd_type"]
					reg_type = reg_type[:reg_type.rfind("TypeDef")]
					if reg_type[-1] == "_" :
						reg_type = reg_type[:-1]
					reg_size = periph_dict[reg_type].compute_size()
					reg = periph_dict[reg_type]

				working_peripheral.add_register(reg,current_pos,self.chips,map_name,array_size)
				current_pos += array_size * reg_size
	
	def exploit_defines(self,periph_dict: Dict[str,Peripheral]) -> None :
		data_lines = self.extractGroup("Peripheral_Registers_Bits_Definition").split("\n")
		out = ""
		current_pos = -1
		current_name = None
		extracted_data = None
		extracted_type = None
		skip_next = False
		skip_bloc = False
		for line in data_lines :
			if "legacy defines" in line :
				skip_bloc = True
				continue
			if "legacy" in line and not "#define" in line :
				skip_next = True
				continue
			if "legacy" in line and "#define" in line :
				log("W_DEFINE_LEGACY","Legacy in " + line,self.chips)
				
			if skip_next or skip_bloc :
				print("Legacy skipping " + line)
				skip_next = False
				if skip_bloc and ( "#define" not in line or line.strip(None) == str()):
					skip_bloc = False
				continue
			
			
		
			# 1. match the right regexp
			match = self.REGEX_Bitfield_Combined.search(line)
			if match :
				extracted_data = match.groupdict()
				extracted_type = extracted_data["type"]
			else :
				match = self.REGEX_Bitfield_Direct.search(line)
				if match :
					extracted_data = match.groupdict()
					extracted_type = "direct"
			if not match :
				continue
			
			# 2. process the name of the field
			extracted_name = extracted_data["name"]
			if extracted_name is None :
				raise ValueError("Invalid None name")
			
			extracted_name = extracted_name.split("_")
			if len(extracted_name) < 3 :
				if extracted_type == "Pos" :
					if int(extracted_data["pos"]) != 0 :
						# out += "Fail on :" + "_".join(extracted_name) + "_Pos\n"
						log("W_FAIL_LEN","len < 3: " + "_".join(extracted_name),self.chips)
				if extracted_type == "Msk" :
					if len("{:b}".format(int(extracted_data["msk"],0)).strip("0")) != 32 :
						# out += "Fail on :" + "_".join(extracted_name) + "_Msk\n"
						log("W_FAIL_LEN","len < 3: " + "_".join(extracted_name),self.chips)
			
			processed_info = systematic_bitfield_fix(extracted_name,self.chips)
			
			if processed_info is None :
				continue
			ok,offset = user_bitfield_fix(self.correction_matrix,processed_info)
			if not ok :
				continue
			
			
			proc_periph = processed_info[0]
			periph_origin = proc_periph

			if proc_periph not in periph_dict.keys() :
				while proc_periph[-1].isdigit() :
					proc_periph = proc_periph[:-1]
				#processed_info[0] = proc_periph
				
			if proc_periph not in periph_dict.keys() :
				log("E_UNKNOWN_PERIPH",periph_origin,self.chips)
				continue
			
			# 3. create field
			"""
			If we are handling a position (first in the file) we may extract as much
			information as possible (name, position) and start to build a field.
			At the next line read, we should encounter a mask, and finish the job.

			To be able to handle that, we save the field in construction and the
			original captured name.
			"""
			if extracted_type == "Pos" :
				if current_pos >= 0 :
					log("E_OVERRIDE","field {} overrides field {}".format("_".join(extracted_name),current_name),
						self.chips)
				current_pos = int(extracted_data["pos"]) + offset
				if current_pos < 0:
					raise Exception("field at negative position : {} @{}".format("_".join(extracted_name), current_pos))
				current_name = "_".join(extracted_name)
			# specific position correction TODO move to specific function
			
			elif extracted_type == "Msk" :
				extracted_msk = extracted_data["msk"]
				extracted_ref = extracted_data["ref_pos"]
				if current_name != extracted_ref :
					""  # log("E_MISMATCH","mismatch mask with referenced constant {}, {}".format(extracted_ref, current_name), self.chips)
				
				bit_mask = "{:b}".format(int(extracted_msk,0)).strip("0")
				current_size = len(bit_mask)
				if current_size != len(bit_mask.replace("0","")) :
					log("E_HOLE_MSK","{} = {}".format(current_name,"{:b}".format(int(extracted_msk,0))),
						self.chips)
				else :
					# special size fix for SYSCFG.EXTICR.EXTIx
					if processed_info[0] == "SYSCFG" and processed_info[1] == "EXTICR" and current_size == 3:
						current_size = 4
					# periph_dict[proc_periph].create_field(proc_reg, proc_field, current_pos, current_size, self.chips)
					if not periph_dict[proc_periph].parse_define(processed_info,current_pos,current_size,
																 self.chips) :
						log("E_UNKNOWN_REG","_".join(processed_info) + " ({} @ {})".format(current_size, current_pos),self.chips)
				current_pos = -1
				current_name = None
			
			elif extracted_type == "direct" :
				extracted_literal = extracted_data["literal"]
				extracted_ref = extracted_data["ref_name"]
				
				if extracted_ref is not None :
					extracted_ref = extracted_ref.split("_")
					ref_processed_info = systematic_bitfield_fix(extracted_ref,self.chips)

					if ref_processed_info is None:
						continue
					ok,offset = user_bitfield_fix(self.correction_matrix,ref_processed_info)
					if not ok :
						continue
					field_ref = periph_dict[proc_periph].find_field(ref_processed_info, self.chips)

					if field_ref is not None:
						#not optimal : search again for the name
						periph_dict[proc_periph].parse_define(processed_info,field_ref.pos,field_ref.size,
																 self.chips)
				else :
					# Case of direct assignation
					
					val = int(extracted_literal,0)
					position = 0
					while val & 1 != 1 and position < 32 :
						position += 1
						val >>= 1
					if position == 32 :
						position = 0
					position += offset
					bit_mask = "{:b}".format(int(extracted_literal,0)).strip("0")
					size = len(bit_mask)
					if size != len(bit_mask.replace("0","1")) :
						log("E_HOLE_MSK","{} = {}".format(current_name,"{:b}".format(int(extracted_literal,0))),
							self.chips)
						continue
					if processed_info[0] == "SYSCFG" and processed_info[1] == "EXTICR" and size == 3:
						size = 4
					# periph_dict[proc_periph].create_field(proc_reg, proc_field, position, len(bit_mask), self.chips)
					if not periph_dict[proc_periph].parse_define(copy(processed_info),position,size,
																 self.chips) :
						log("E_UNKNOWN_REG","_".join(processed_info),self.chips)
			
			else :
				# Doesn't match any regex.
				continue
		
		print(out)


REGEX_RegisterName = re.compile(r"(\w+)R([0-9]+)")
REGEX_ADCx = re.compile("ADC([0-9]+)?")
REGEX_DMAx = re.compile("DMA[0-9]")
REGEX_CHx = re.compile("CH[0-9]")
REGEX_TIMEx = re.compile("TIME([0-9]+)?")
REGEX_TRIGx = re.compile("TRIG([0-9]+)?")
REGEX_TOCNTx = re.compile("TOCNT([0-9]+)?")
REGEX_xBeat = re.compile("([0-9]+)?Beat")
REGEX_GenericRegisterName = re.compile(r"(?P<name>[A-Za-z0-9]+[A-Za-z](?:_[A-Za-z0-9]+[A-Za-z])*)_?R?(?P<num>[0-9]+)R?$")


def systematic_bitfield_fix(field_name: List[str],chip: ChipSeriesManager) -> Union[None,List[str]] :
	"""
	This function will fix raw bitfields names based on systematics rules
	:param chip:
	:param field_name: Field name, split by '_'
	:return: An array containing [Periph,Register,Field] names or None if field deleted
	"""
	length = len(field_name)
	if length < 3 :
		return None  # warning message already fired by calling function
	
	if field_name[length - 1] in ["_Pos","_Msk"] :
		log("W_Msk/Pos","_".join(field_name))
		# TODO voir si besoin de régler ça dans la fonction appelante
		return None
	
	periph = field_name[0]
	
	if periph == "USB" and field_name[1] == "OTG" :
		if field_name[2] in ["CHNUM","BCNT","DPID","PKTSTS","EPNUM","FRMNUM"] :
			field_name[1] = "GRXSTSR"  # replace "OTG" by "GRXSTSR"
		elif field_name[2] in ["NPTXFSA","NPTXFD"] :
			field_name[1] = "HNPTXFSIZ"
		elif field_name[2] in ["TX0FSA","TX0FD"] :
			field_name[1] = "DIEPTXF0"
		else :
			field_name[1:] = field_name[2:]
	
	elif length > 3 and field_name[1] == field_name[2] :  # _______________ADC_CALFACT_CALFACT_D -> ADC_CALFACT_D
		if field_name[3].isdigit() :
			field_name[2] = (field_name[2][:-1] if field_name[2][-1:] == "R" else field_name[2]) + field_name[3]
			field_name.pop(3)
		else :
			field_name[2] = field_name[3]
			if len(field_name) > 3 :
				field_name[3 :] = field_name[4 :]
			else :
				field_name = field_name[:3]
			length = length - 1
	
	# Fix ODR_1 -> OD1, ODR1 -> OD1
	match = REGEX_GenericRegisterName.match(field_name[2])
	if match :
		extracted_data = match.groupdict()
		eq_field_name = extracted_data["name"]
		if eq_field_name == field_name[1] and eq_field_name[-1] == "R" :
			eq_field_name = eq_field_name[:-1]
			eq_field_name += extracted_data["num"]
			field_name[2] = eq_field_name
	
	if field_name[1][:-1] == 'R' and field_name[2].index(field_name[1]) == 0 and field_name[2][
																				 len(field_name[1]) :].isdigit() :
		log("W_R","_".join(field_name[:2]) + "_" + field_name[2][:len(field_name[1])] + "[x]",chip)
		field_name[2] = field_name[1][:-1] + field_name[2][len(field_name[1]) :]
	# ODR1 => OD1
	
	return field_name


# REGEX_CAN_TIxR = re.compile("TI[0-9]+R")
# REGEX_CAN_TDTxR = re.compile("TDT[0-9]+R")
# REGEX_CAN_TDLxR = re.compile("TDL[0-9]+R")
# REGEX_CAN_TDHxR = re.compile("TDH[0-9]+R")
# REGEX_CAN_RIxR = re.compile("RI[0-9]+R")
# REGEX_CAN_RDTxR = re.compile("RDT[0-9]+R")
# REGEX_CAN_RDLxR = re.compile("RDL[0-9]+R")
# REGEX_CAN_RDHxR = re.compile("RDH[0-9]+R")
#
# REGEX_CAN_FxR2 = re.compile("F[0-9]+R2")
REGEX_EXTICRx           = re.compile("EXTICR[0-9]")
REGEX_CAN_FnRx          = re.compile("F[0-9]+R(?P<num>[0-9]+)")
REGEX_ETH_MACL3AxR      = re.compile("MACL3A[0-3]R")
REGEX_RCC_PLLxMULLx     = re.compile("PLL[0-9]*MULL?[0-9]+")
REGEX_FLASH_WRPx        = re.compile("WRP[0-9]")
REGEX_SYSCFG_ITLINEx    = re.compile("ITLINE[0-9]+")

def user_bitfield_fix(matrix: Dict[Tuple[str,str,str],Union[Tuple[str,str,str],None]],
					  field_datas: List[str]) -> Tuple[bool,int] :
	"""
	This function will fix pre-processed bitfields based on a given dict.
	This matrix is a dict of the form (Periph,Register,Field) -> (Periph,Register,Field)
	If None is provided somewhere in input, it will act as a wildcard
	If None is provided somewhere in the output it will DELETE the field.

	:param matrix: Correcting matrix
	:param field_datas: List representing [Periph,Register,Field], will hold the changes.
	:return: True if field is kept
	"""
	offset = 0
	
	if field_datas[0] == "SDMMC" and field_datas[1] == "IDMA" :
		field_datas[1] += "CTRL"
	
	elif field_datas[0] == "OB" :
		if field_datas[1] in ["WRP1","WRP3"] :
			offset = -16
	
	elif field_datas[0] == "FW" :
		field_datas[0] = "FIREWALL"
	
	elif field_datas[0] == "DMA" :
		if field_datas[1][:2] == "Sx" :
			field_datas[0] = "DMA_Stream"
			if field_datas[1] == "SxNDT" :
				field_datas[1] = "NDTR"  #TODO possible mauvaise interprtation, rajouter "Stream" entre "DMA" et "NDTR", et le prendre en compte dans parse_define
			else :
				field_datas[1] = field_datas[1][2:]
		elif field_datas[1][:-1] in ["CMAR","CNDTR","CPAR"] :
			field_datas[1] = field_datas[1][:-1]
	
	elif field_datas[0] == "CAN" :
		match = REGEX_CAN_FnRx.match(field_datas[1])
		if match :
			field_datas[1] = "FR"
		else :
			match = REGEX_GenericRegisterName.match(field_datas[1])
			if match :
				reg_extracted_fields = match.groupdict()
				if reg_extracted_fields["name"] in ["TI","TDT","TDL","TDH","RI","RDT","RDL","RDH"] :
					# REG<num>R -> REGR
					field_datas[1] = reg_extracted_fields["name"] + "R"
				elif reg_extracted_fields["name"] in ["FFA"] :
					# FFAn => FFAnR
					field_datas[1] = reg_extracted_fields["name"] + reg_extracted_fields["num"] + "R"
	
	elif field_datas[0] == "AFIO" :
		if REGEX_EXTICRx.match(field_datas[1]) :
			offset = (int(field_datas[1][len("EXTICR") :]) - 1) * 32
			field_datas[1] = "EXTICR"

	elif field_datas[0] == "SYSCFG" :
		if REGEX_EXTICRx.match(field_datas[1]) :
			offset = (int(field_datas[1][len("EXTICR"):]) - 1) * 32
			field_datas[1] = "EXTICR"
		elif REGEX_SYSCFG_ITLINEx.match(field_datas[1]) :
			offset = int(field_datas[1][6:]) * 32
			field_datas[1] = "IT_LINE_SR"

	elif field_datas[0] == "CAN":
		if field_datas[1][:-1] == "FR":
			field_datas[1] = "FR"

	elif field_datas[0] == "COMP" :
		if field_datas[1] == "CFGRx" : field_datas[1] = "CFGR"
	
	elif field_datas[0] == "DCMI" :
		if field_datas[1] in ["CWSIZE","CWSTRT","MIS","RIS"] :
			field_datas[1] = field_datas[1] + "R"

	elif field_datas[0] == "DMAMUX":
		if field_datas[1] == "CxCR":
			field_datas[0] = "DMAMUX_Channel"
			field_datas[1] = "CCR"
		elif field_datas[1] == "RGxCR":
			field_datas[0] = "DMAMUX_RequestGen"
			field_datas[1] = "RGCR"
	
	elif field_datas[0] == "DSI" :
		if field_datas[1][:-1] == "TCCR" :
			offset = int(field_datas[1][-1]) * 32
			field_datas[1] = "TCCR"
			if len(field_datas) > 3 and len(field_datas[3]) > len("TOCNT") :  #sub-field with index not separated by '_'
				return False,0
		elif field_datas[1][:-1] == "WPCR" :
			offset = int(field_datas[1][-1]) * 32
			field_datas[1] = "WPCR"
	
	elif field_datas[0] == "ETH" :
		if field_datas[1] in ["MACAHR","MACA0HR","MACA1HR","MACA2HR","MACA3HR"] :
			field_datas[1] = "MACAHR"
			if field_datas[2] in ["MACA","MACAH","MACA0H","MACA1H","MACA2H","MACA3H"] :
				field_datas[2] = "MACAH"
		elif field_datas[1] in ["MACA0LR","MACA1LR","MACA2LR","MACA3LR"] :
			field_datas[1] = "MACALR"
			if field_datas[2] in ["MACA","MACAL","MACA0L","MACA1L","MACA2L","MACA3L"] :
				field_datas[2] = "MACAL"
		elif REGEX_ETH_MACL3AxR.match(field_datas[1]) :
			return False,0
		elif field_datas[1] == "MACRWUPFR" :
			field_datas[1] = "MACRWKPFR"
	
	elif field_datas[0] == "FLASH" :
		if field_datas[1] in ["CRCEADD","CRCSADD"] :
			field_datas[1] = field_datas[1] + "R"
		elif field_datas[1] in ["DATA0", "DATA1", "RDP", "USER"] or (REGEX_FLASH_WRPx.match(field_datas[1]) and len(field_datas[1]) < 6):
			field_datas[0] = "OB"
			if field_datas[1][:4] == "DATA":
				field_datas[1] = "Data"+field_datas[1][-1]
				if field_datas[1][-1] == "1":
					offset = -16
			elif field_datas[1][:-1] == "WRP" and int(field_datas[1][-1]) % 2 ==1:
				offset = -16


	elif field_datas[0] in ["FMC", "FSMC"] :
		if field_datas[1][:3] in ["BCR", "BTR"]:
			if field_datas[1] != "BCR1":
				field_datas[1] = field_datas[1][:3]
		elif field_datas[1][:4] == "BWTR":
			if field_datas[1][-1] == "x":
				field_datas[1] = "BWTR"
			else:
				return False,0
		elif field_datas[1][:4] in ["PATT", "PMEM", "ECCR"]:
			field_datas[1] = field_datas[1][:4]
			if field_datas[2][-1] == "x" or field_datas[2][-1].isdigit():
				field_datas[2] = field_datas[2][:-1]
		elif field_datas[1][:3] in ["PCR"]:
			field_datas[1] = field_datas[1][:3]
			if field_datas[2][-1] == "x" or field_datas[2][-1].isdigit():
				field_datas[2] = field_datas[2][:-1]
		elif field_datas[1][:2] in ["SR"]:
			field_datas[1] = field_datas[1][:2]
			if field_datas[2][-1] == "x" or field_datas[2][-1].isdigit():
				field_datas[2] = field_datas[2][:-1]
		elif field_datas[1][:-1] in ["SDTR", "SDCR"]:
			field_datas[1] = field_datas[1][:-1]


	elif field_datas[0] == "GFXMMU" :
		if field_datas[1] in ["LUTxL", "LUTxH"]:
			field_datas[1] = field_datas[1][:-2] + field_datas[1][-1]

	elif field_datas[0] == "GPIO" :
		if field_datas[1] == "OSPEEDER" :
			field_datas[1] = "OSPEEDR"
		if field_datas[1] == "OTYPER" and field_datas[2][:2] in ["ODR","IDR"]:
			return False, 0

	elif field_datas[0] == "HRTIM" :
		if field_datas[1] in ["PER", "REP"]:
			field_datas[1] += "R"

	elif field_datas[0] == "LTDC":
		if field_datas[1][:2] == "Lx":
			field_datas[0] = "LTDC_Layer"
			field_datas[1] = field_datas[1][2:]

	elif field_datas[0] == "RCC":
		if field_datas[1][:4] == "CFGR":
			if field_datas[2][-4:] == "MULL":
				field_datas[2] = field_datas[2][:-4] + "MUL"
			elif REGEX_RCC_PLLxMULLx.match(field_datas[2]):
				return False,0
			elif len(field_datas[2]) > 6 and field_datas[2][:6] == "PLLDIV" and field_datas[2][6:].isdigit():
				return False,0
	elif field_datas[0] == "SAI":
		if field_datas[1][0] == "x":
			field_datas[0] = "SAI_Block"
			field_datas[1] = field_datas[1][1:]

	elif field_datas[0] in ["SDIO", "SDMMC"]:
		if field_datas[1] in ["RESP1", "RESP2", "RESP3", "RESP4"]:
			field_datas[1] = "RESP"
			if field_datas[2][:-1] == "CARDSTATUS":
				field_datas[2] = "CARDSTATUS"
		elif field_datas[1] == "RESP0":
			field_datas[1] = "RESPCMD"

	elif field_datas[0] == "USB":
		""#if field_datas[1][:-1] == "COUNT":
		#	field_datas[1] = "COUNT"
	elif field_datas[0] == "SPDIFRX" and field_datas[1][:3] == "DR1" and field_datas[2][:4] == "DRNL":
		field_datas[1] = "DR2"
	
	return True,offset


class features :
	def __init__(self,associatedHeader: Header) :
		self.associatedHeader = associatedHeader
		self.data = associatedHeader.extractGroup("Exported_macro")
		self.dataLines = self.data.split("\n")
		self.instanceList = list()
		self.featureList = list()
		self.REGEX_INSTANCES = re.compile(r"\(\(_*INSTANCE_*\)\s*==\s*(\w+)\)")
		self.REGEX_FEATURE = re.compile(r"#define IS_(.+)_INSTANCE\(_*INSTANCE_*\)")
		self.REGEX_TIMER_CHANNEL = re.compile(r"#define IS_TIM_(.+)_INSTANCE\(_*INSTANCE_*,\s*CHANNEL\)")
		self.REGEX_CHANNEL = re.compile(r"\(\(_*CHANNEL_*\)\s*==\s*TIM_(\w+)\)")
		self.linkedFeatures = dict()
		self.linkedInstances = dict()
		self.timerChannels = dict()
	
	def listInstances(self) :
		capturedInstances = self.REGEX_INSTANCES.findall(self.data)
		for instance in capturedInstances :
			if instance not in self.instanceList :
				self.instanceList.append(instance)
		return self.instanceList
	
	def listFeatures(self) :
		capturedFeatures = self.REGEX_FEATURE.findall(self.data)
		for feature in capturedFeatures :
			if feature not in self.featureList :
				self.featureList.append(feature)
		return self.featureList
	
	def buildFeatureList(self) :
		if self.featureList == list() :
			self.listFeatures()
		for f in self.featureList :
			self.linkedFeatures[f] = list()
		
		currentFeature = ""
		match = ""
		for line in self.dataLines :
			match = self.REGEX_FEATURE.match(line)
			if match :
				currentFeature = match.group(1)
			match = self.REGEX_INSTANCES.search(line)
			if match :
				if match.group(1) not in self.linkedFeatures[currentFeature] :
					self.linkedFeatures[currentFeature].append(match.group(1))
		
		return self.linkedFeatures

	def buildInstanceList(self) :
		if self.instanceList == list() :
			self.listInstances()
		for i in self.instanceList :
			self.linkedInstances[i] = list()
		
		currentFeature = ""
		match = ""
		for line in self.dataLines :
			match = self.REGEX_FEATURE.match(line)
			if match :
				currentFeature = match.group(1)
			match = self.REGEX_INSTANCES.search(line)
			if match :
				if currentFeature not in self.linkedInstances[match.group(1)] :
					self.linkedInstances[match.group(1)].append(currentFeature)
		
		return self.linkedInstances
	
	def buildTimerChannels(self) :
		if self.instanceList == list() :
			self.listFeatures()
		for i in self.instanceList :
			if "TIM" in i :
				self.timerChannels[i] = dict()
		currentFeature = None
		currentTimer = None
		for line in self.dataLines :
			match = self.REGEX_TIMER_CHANNEL.search(line)
			if match :
				currentFeature = match.group(1)
			else :
				if self.REGEX_FEATURE.search(line) :
					currentFeature = None
			if currentFeature is None :
				continue
			
			match = self.REGEX_INSTANCES.search(line)
			if match :
				if "TIM" in match.group(1) :
					currentTimer = match.group(1)
					if currentFeature not in self.timerChannels[currentTimer].keys() :
						self.timerChannels[currentTimer][currentFeature] = list()
			
			match = self.REGEX_CHANNEL.search(line)
			if match :
				self.timerChannels[currentTimer][currentFeature].append(match.group(1))
		
		return self.timerChannels
