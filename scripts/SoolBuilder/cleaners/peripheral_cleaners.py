import re
import typing as T
import logging

logger = logging.getLogger()

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

def HRTIM_periph_cleaner(periph: "Peripheral") :

	if len(periph.instances) == 1 :
		periph.name = periph.instances[0].name
	else :
		logger.error(f"HRTIM type detection failure for {periph.instances} for chips {str(periph.chips)}. Assigning generic")
		periph.name = "HRTIM_GENERIC"
	pass

def USART_periph_cleaner(periph: "Peripheral") :
	if periph.name is not None :
		return

	if "low power" in periph.brief :
		periph.name = "LPUART"
	else :
		brief_tokens = periph.brief.split()
		if "synchronous" in brief_tokens :
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


def TZC_periph_cleaner(periph : "Peripheral") :
	if periph.brief.upper() == "GTZC_TZIC" :
		logger.error("Fix GTZC")
		periph.name = "TZIC"
	elif periph.brief.upper() == "GTZC_TZSC" :
		logger.error("Fix GTZC")
		periph.name = "TZSC"

def ETHERNET_periph_cleaner(periph: "Peripheral") :
	if len(periph.instances) == 1 :
		periph.name = periph.instances[0].name
	else :
		logger.error(f"ETHERNET type detection failure for {periph.name} for chips {str(periph.chips)}. Assigning generic")
		periph.name = "ETHERNET_GENERIC"
	pass

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

def FDCAN_periph_cleaner(periph: "Peripheral") :
	if re.match(r"^fdcan\d?", periph.brief) :
		periph.name = "FDCAN"
	elif periph.instances[0].name.startswith("CAN_CCU") :
		periph.name = "CAN_CCU"

def ADC_periph_cleaner(periph: "Peripheral") :
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

def I2C_periph_cleaner(periph: "Peripheral") :

	if "TIMINGR" in periph and "TIMEOUTR" in periph and "PECR" in periph:
		periph.name = "FMPI2C"

def GPIO_periph_cleaner(periph) :
	if "CRL" in periph :
		periph.name = "GPIO_OLD"
	elif "PCTRACECR" in periph :
		periph.name = "GPIO_DBG"
	else :
		periph.name = "GPIO"

def SERIAL_CONTROL_periph_cleaner(periph) :
	if len(periph.instances[0].name) > 3 and periph.instances[0].name[3] == "_" : #SCx_XXX
		periph.name = "SC_" + periph.instances[0].name[4:]
	# TODO split SC1 and SC2 peripherals into 2 peripherals so that the parts of SC1 and SC2 can be merged together
	#else :
	#	periph.name = "SC"