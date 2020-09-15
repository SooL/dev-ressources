# ******************************************************************************
#  Copyright (c) 2018-2020 FAUCHER Julien & FRANCE Loic.                       *
#                                                                              *
#  This file is part of SooL generator.                                        *
#                                                                              *
#  SooL generator is free software: you can redistribute it and/or modify      *
#  it under the terms of the GNU Lesser General Public License                 *
#  as published by the Free Software Foundation, either version 3              *
#  of the License, or (at your option) any later version.                      *
#                                                                              *
#  SooL core Library is distributed in the hope that it will be useful,        *
#  but WITHOUT ANY WARRANTY; without even the implied warranty of              *
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                *
#  GNU Lesser General Public License for more details.                         *
#                                                                              *
#  You should have received a copy of the GNU Lesser General Public License    *
#  along with SooL core Library. If not, see  <https://www.gnu.org/licenses/>. *
# ******************************************************************************

import re
import typing as T
import logging
from copy import copy

from structure import ChipSet

logger = logging.getLogger()

def PERIPH_VERSION_REGISTERS_cleaner(periph: "Peripheral") :
	from structure import Register, Field
	p_name = periph.name if periph.name is not None else periph.parent.name
	corr = [
		[None, None, ["VERR", "VER", "IP_VER"], f"{p_name} version register", [("MINREV", 0, 4), ("MAJREV", 4, 4)]],
		[None, None, ["IPIDR", "IPDR", "ID"], f"{p_name} identification register", [("ID", 0, 32)]],
		[None, None, ["SIDR", "SID"], f"{p_name} size identification register", [("SID", 0, 32)]],
	]
	for chip in periph.chips :
		if p_name in chip.header_handler.periph_table :
			header_periph = chip.header_handler.periph_table[p_name]
			for corr_reg in corr :
				name = None
				for candidate in corr_reg[2] :
					if candidate in header_periph :
						name = candidate
				if name is not None and name not in periph :
					if corr_reg[0] is None :
						corr_reg[0] = Register(chip, name, corr_reg[3])
						corr_reg[1] = header_periph[name].byte_offset
					else :
						corr_reg[0].chips.add(chip)
	for corr_reg in corr :
		if corr_reg[0] is not None :
			for f in corr_reg[4] :
				corr_reg[0].add_field(Field(corr_reg[0].chips, f[0], position=f[1], size=f[2]))
			periph.add_register(corr_reg[0])
			periph.place_component(corr_reg[0], corr_reg[1])



def ADC_periph_cleaner(periph: "Peripheral") :
	PERIPH_VERSION_REGISTERS_cleaner(periph)
	common: bool = False
	if "common" in periph.brief.lower() :
		common = True
	elif re.match(r"^ADC\d[\w_]*\d", periph.instances[0].name) :
		common = True
	else :
		for inst in periph.instances :
			if "common" in inst.name.lower() :
				common = True
				break
	if common :
		periph.name = "ADC_Common"
	else :
		periph.name = "ADC"

def CAN_periph_base_cleaner(periph: "Peripheral") :
	from structure import MappingElement
	for m in periph.mappings :
		if "F0R1" in m and "F27R1" in m and not "F26R1" in m :
			F0R1 = m["F0R1"]; F0R2 = m["F0R2"]
			F27R1 = m["F27R1"]; F27R2 = m["F27R2"]

			if F27R1.component is F0R1.component :
				m.remove_element(F27R1)
			else :
				periph.remove_register(F27R1.component)
			if F27R2.component is F0R2.component :
				m.remove_element(F27R2)
			elif F27R2.component is not F0R1.component :
				periph.remove_register(F27R2.component)

			step = F0R1.byte_size + F0R2.byte_size
			for i in range(0, 14) :
				if f"F{i}R1" not in m :
					FiR1 = MappingElement(F0R1.chips, name = f"F{i}R1", component = F0R1.component,
					                      address = F0R1.address + i * step)
					periph.add_placement(FiR1)
				if f"F{i}R2" not in m :
					FiR2 = MappingElement(F0R2.chips, name=f"F{i}R2", component=F0R2.component,
					                      address=F0R2.address + i * step)
					periph.add_placement(FiR2)

def CRC_periph_cleaner(periph: "Peripheral") :
	from structure import Register, Field, MappingElement
	PERIPH_VERSION_REGISTERS_cleaner(periph)
	if "POL" in periph :
		return
	svd_name = list(periph.chips.chips)[0].svd
	svd_name = svd_name[svd_name.rindex('STM32'):svd_name.rindex('.svd')]
	if svd_name in ["STM32F0x1", "STM32F0x2", "STM32F0x8"] :
		pol_reg = Register(periph.chips, "POL")
		pol_reg.add_field(Field(periph.chips, "POL", position=0, size=32))
		periph.add_register(pol_reg)
		periph.place_component(pol_reg, 0x14)

def DAC_periph_cleaner(periph: "Peripheral") :
	PERIPH_VERSION_REGISTERS_cleaner(periph)
	if "DOR2" in periph :
		return
	if "DOR1" not in periph :
		return
	chips = ChipSet()
	for chip in periph.chips.chips :
		if "DAC" not in chip.header_handler.periph_table :
			""# TODO delete peripheral
		elif "DOR2" in chip.header_handler.periph_table["DAC"] :
			chips.add(chip)

	if not chips.empty :
		DHR12R2, DHR12L2, DHR8R2, DOR2 = copy(periph["DHR12R1"]), copy(periph["DHR12L1"]),\
		                                 copy(periph["DHR8R1"]), copy(periph["DOR1"])
		DHR12R2.name, DHR12L2.name, DHR8R2.name, DOR2.name = "DHR12R2", "DHR12L2", "DHR8R2", "DOR2"
		DHR8RD = copy(DHR8R2)
		DHR12RD = copy(DHR12R2)
		DHR12LD = copy(DHR12L2)

		for reg in (DHR8RD, DHR12RD, DHR12LD) :
			reg.name = reg.name[:-1] + 'D'
			for var in reg :
				if "DACC1DHRB" in var : var.remove_field("DACC1DHRB")
				if len(var.fields) > 1 : raise AssertionError(f"1 field expected in DAC.{reg}. 2 found: {var.fields}")
				DACC2DHR = copy(var.fields[0])
				if DACC2DHR.size <= 8 : DACC2DHR.position += 8
				else : DACC2DHR.position += 16
				DACC2DHR.brief = DACC2DHR.brief.replace('channel1', 'channel2')
				DACC2DHR.name = DACC2DHR.name.replace('1', '2')
				var.add_field(DACC2DHR)
			periph.add_register(reg)

		for reg in (DHR12R2, DHR12L2, DHR8R2, DOR2) :
			reg.name = reg.name[:-1] + '2'
			reg.brief = reg.brief.replace('channel1', 'channel2')
			for var in reg :
				for f in var :
					f.name = f.name.replace('1', '2')
					f.brief = f.brief.replace('channel1', 'channel2')
			periph.add_register(reg)

		for reg in (DHR12R2, DHR12L2, DHR8R2, DOR2, DHR8RD, DHR12RD, DHR12LD) :
			reg.chips = ChipSet(chips)
			for var in reg :
				var.chips = ChipSet(chips)
				for f in var :
					f.chips = ChipSet(chips)

		pos_0 : int = -1
		for m in periph.mappings :
			if "DHR12R1" in m :
				if pos_0 != -1 : raise AssertionError("Multiple mappings for incomplete DAC. expected only 1")
				pos_0 = m["DHR12R1"].address
		if pos_0 == -1 :
			raise AssertionError("no DHR12R1 in DAC mappings")
		periph.place_component(DHR12R2, pos_0 + 12)
		periph.place_component(DHR12L2, pos_0 + 16)
		periph.place_component(DHR8R2, pos_0 + 20)
		periph.place_component(DHR12RD, pos_0 + 24)
		periph.place_component(DHR12LD, pos_0 + 28)
		periph.place_component(DHR8RD, pos_0 + 32)
		periph.place_component(DOR2, pos_0 + 40)

def DMA_periph_cleaner(periph: "Peripheral") :
	from structure import Register, Field
	if "CSELR" in periph :
		return
	chips = ChipSet()
	pos = -1
	for chip in periph.chips.chips :
		if "DMA" not in chip.header_handler.periph_table :
			""# TODO delete peripheral
		elif "CSELR" in chip.header_handler.periph_table["DMA"] :
			chips.add(chip)
			pos = chip.periph_table["DMA"]["CSELR"].byte_offset

	if not chips.empty :
		CSELR = Register(chips=chips, name="CSELR", brief="DMA channel selection register", size=32)
		for i in range(1, 8) :
			if f"CCR{i}" in periph :
				CSELR.add_field(Field(chips=chips, name=f"C{i}S", brief=f"DMA channel {i} selection",
				                      position=(i-1)*4, size=4))
		periph.add_register(CSELR)
		periph.place_component(CSELR, address=pos, name="CSELR", chips=chips)

def DBGMCU_periph_cleaner(periph: "Peripheral") :
	corr = [
		["^APB[1L]_?FZR?$", ["APB1FZR", "APB1FZ"]],
		["^APB[2H]_?FZR?$", ["APB2FZR", "APB2FZ"]],
		["^APB1(L_FZ|_FZR1)?$", ["APB1FZR1"]],
		["^APB1(H_FZ|_FZR2)?$", ["APB1FZR2"]],
		["^C2AP_B1FZR1$", ["C2APB1FZR1"]]
	]
	for chip in periph.chips :
		header_DBGMCU = chip.header_handler.periph_table["DBGMCU"]
		for reg_corr in corr :
			regs = list(filter(lambda reg : re.match(reg_corr[0], reg.name), periph.registers))
			if len(regs) > 0 :
				reg_name = None
				for name in reg_corr[1] :
					if name in header_DBGMCU :
						reg_name = name
						break
				if reg_name is None :
					raise AssertionError(f"no {reg_corr[1][0]} register in header {chip.header_handler.file_name}")
				for reg in regs :
					reg.name = reg_name

def DSI_periph_cleaner(periph: "Peripheral") :
	for i in periph.instances :
		if i.name == "DSIHOST" :
			i.name = "DSI"

def ETHERNET_periph_cleaner(periph: "Peripheral") :
	if len(periph.instances) == 1 :
		periph.name = periph.instances[0].name
	else :
		logger.error(f"ETHERNET type detection failure for {periph.name} for chips {str(periph.chips)}. Assigning generic")
		periph.name = "ETHERNET_GENERIC"
	pass

def FDCAN_periph_cleaner(periph: "Peripheral") :
	if re.match(r"^fdcan\d?", periph.brief) :
		periph.name = "FDCAN"
	elif periph.instances[0].name.startswith("CAN_CCU") :
		periph.name = "CAN_CCU"

def FLASH_periph_cleaner(periph: "Peripheral") :
	from structure import Register, Field
	corr = [
		#reg1, reg2, name1     , name2     , [[f_name, f_brief, f_offset, f_size]], relative_offset
		[None, None, "PCROP1SR", "PCROP2SR", [["STRT", "PCROP area start offset", 0, 16]], 0x20],
		[None, None, "PCROP1ER", "PCROP2ER", [["END", "PCROP area start offset", 0, 16]], 0x20],
		[None, None, "WRP1AR", "WRP2AR", [
			["STRT", "WRP area start offset", 0, 8],
			["END", "WRP area end offset", 16, 8],
		], 0x20],
		[None, None, "WRP1BR", "WRP2BR", [
			["STRT", "WRP area start offset", 0, 8],
			["END", "WRP area end offset", 16, 8],
		], 0x20],
		[None, None, "SEC1R", "SEC2R", [["SEC_SIZE2", None, 0, 8]], 0x04],
	]

	for chip in periph.chips.chips :
		header_FLASH = chip.header_handler.periph_table["FLASH"]
		for reg in corr :
			if reg[3] in header_FLASH and reg[3] not in periph :
				if reg[1] is None :
					reg[0] = periph[reg[2]]
					reg[1] = Register(ChipSet(chip), reg[3], reg[0].brief.replace("1", "2"))
					for field in reg[4] :
						reg[1].add_field(Field(reg[1].chips, field[0], field[1], field[2], field[3]))
					periph.add_register(reg[1])
				else :
					reg[1].chips += chip
		# TODO same for PCROP2ER, WRP2AR, WRP2BR, SEC2R. Refer to dm00355726 (G4 RM) for differences between X1R & X2R
		for m in periph.mappings :
			for elmt in m :
				for reg in corr :
					if elmt.component is reg[0] and reg[1] is not None :
						periph.place_component(reg[1], elmt.address + 0x20, reg[3], elmt.chips & reg[1].chips)
						break


def GPIO_periph_cleaner(periph) :
	if "CRL" in periph :
		periph.name = "GPIO_OLD"
	elif "PCTRACECR" in periph :
		periph.name = "GPIO_DBG"
	else :
		periph.name = "GPIO"

def HRTIM_periph_cleaner(periph: "Peripheral") :

	if len(periph.instances) == 1 :
		periph.name = periph.instances[0].name
	else :
		logger.error(f"HRTIM type detection failure for {periph.instances} for chips {str(periph.chips)}. Assigning generic")
		periph.name = "HRTIM_GENERIC"
	pass

def I2C_periph_cleaner(periph: "Peripheral") :

	if "TIMINGR" in periph and "TIMEOUTR" in periph and "PECR" in periph:
		periph.name = "FMPI2C"
	elif periph.name is None :
		periph.name = "I2C"

def SERIAL_CONTROL_periph_cleaner(periph) :
	if len(periph.instances[0].name) > 3 and periph.instances[0].name[3] == "_" : #SCx_XXX
		periph.name = "SC_" + periph.instances[0].name[4:]
	# TODO split SC1 and SC2 peripherals into 2 peripherals so that the parts of SC1 and SC2 can be merged together
	#else :
	#	periph.name = "SC"

def TIM_GENERAL_decider(periph) :
	if "CCMR2_Input" in periph :
		periph.name = "TIM_GENERAL_1"
	elif "BDTR" in periph :
		if "CCR2" in periph :
			periph.name = "TIM_GENERAL_2"
		else :
			periph.name = "TIM_GENERAL_3"
	elif "CCR2" in periph :
		if "CR2" in periph :
			periph.name = "TIM_GENERAL_4"
		else :
			periph.name = "TIM_GENERAL_5"
	else :
		periph.name = "TIM_GENERAL_6"

def TIM_periph_cleaner(periph : "Peripheral") :
	global tim_log

	if not periph.instances[0].name.startswith("TIM") :
		return
	brief_tokens = periph.brief.split()

	if periph.brief[-5:] == "timer" :
		periph.brief += 's'

	if "advanced" in brief_tokens :
		periph.name = "TIM_ADVANCED"
	elif "basic" in brief_tokens :
		periph.name = "TIM_BASIC"
	elif "general" in brief_tokens :
		TIM_GENERAL_decider(periph)

	else :
		elements = list(elmt.name for elmt in sorted(periph.mappings[0].elements))
		if elements == ["CR1", "CR2", "DIER", "SR", "EGR", "CNT", "PSC", "ARR"] :
			periph.name = "TIM_BASIC"
		elif len(elements) >= 18 and \
				elements[:6] == ["CR1", "CR2", "SMCR", "DIER", "SR", "EGR"] and \
			    "CCMR1" in elements[6] and "CCMR2" in elements[7] and \
			    elements[8:18] == ["CCER", "CNT", "PSC", "ARR", "RCR", "CCR1", "CCR2", "CCR3", "CCR4", "BDTR"] :
			periph.name = "TIM_ADVANCED"
		else :
			TIM_GENERAL_decider(periph)
	placements = list()
	for m in periph.mappings :
		placements.extend(m.elements)

def TZC_periph_cleaner(periph : "Peripheral") :
	if periph.brief.upper() == "GTZC_TZIC" :
		logger.error("Fix GTZC")
		periph.name = "TZIC"
	elif periph.brief.upper() == "GTZC_TZSC" :
		logger.error("Fix GTZC")
		periph.name = "TZSC"

def USART_periph_cleaner(periph: "Peripheral") :
	if periph.name is not None :
		return

	brief_tokens = periph.brief.lower().split()
	if "power" in brief_tokens :
		periph.name = "LPUART"
	elif "synchronous" in brief_tokens :
		periph.name = "USART"
	elif "asynchronous" in brief_tokens :
		periph.name = "UART"
	else :
		logger.error(f"USART type detection failure for {periph.instances} for chips {str(periph.chips)}. Assigning generic")
		periph.name = "USART_GENERIC"

def USB_periph_cleaner(periph: "Peripheral") :

	periph_name = "USB"
	if "_HS" in periph.instances[0].name :
		periph_name += "_HS"
	elif "_FS" in periph.instances[0].name :
		periph_name += "_FS"
	if "_GLOBAL" in periph.instances[0].name :
		periph_name += "_GLOBAL"
	elif "_HOST" in periph.instances[0].name :
		periph_name += "_HOST"
	elif "_DEVICE" in periph.instances[0].name :
		periph_name += "_DEVICE"
	elif "_PWRCLK" in periph.instances[0].name :
		periph_name += "_PWRCLK"
	if len(periph_name) > 3 :
		periph.name = periph_name

	elif len(periph.instances) == 1 :
		periph.name = periph.instances[0].name

	else :
		logger.error(f"USB type detection failure for {periph.name} for chips {str(periph.chips)}. Assigning generic")
		periph.name = "USB_GENERIC"
	pass