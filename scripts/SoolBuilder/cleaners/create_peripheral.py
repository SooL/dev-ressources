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
		reg_placements = list(reg_p.name for reg_p in sorted(periph.mappings[0].register_placements))
		if reg_placements == ["CR1", "CR2", "DIER", "SR", "EGR", "CNT", "PSC", "ARR"] :
			periph.name = "TIM_BASIC"
		elif len(reg_placements) >= 18 and \
				reg_placements[:6] == ["CR1", "CR2", "SMCR", "DIER", "SR", "EGR"] and \
			    "CCMR1" in reg_placements[6] and "CCMR2" in reg_placements[7] and \
			    reg_placements[8:18] == ["CCER", "CNT", "PSC", "ARR", "RCR", "CCR1", "CCR2", "CCR3", "CCR4", "BDTR"] :
			periph.name = "TIM_ADVANCED"
		else :
			TIM_GENERAL_decider(periph)
	placements = list()
	for m in periph.mappings :
		placements.extend(m.register_placements)

def HRTIM_periph_cleaner(periph: "Peripheral") :

	if len(periph.instances) == 1 :
		periph.name = periph.instances[0].name
	else :
		logger.error(f"HRTIM type detection failure for {periph.name} for chips {str(periph.chips)}. Assigning generic")
		periph.name = "HRTIM_GENERIC"
	pass

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

def ETHERNET_periph_cleaner(periph: "Peripheral") :

	if len(periph.instances) == 1 :
		periph.name = periph.instances[0].name
	else :
		logger.error(f"ETHERNET type detection failure for {periph.name} for chips {str(periph.chips)}. Assigning generic")
		periph.name = "ETHERNET_GENERIC"
	pass

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

def DEFAULT_create_cleaner(periph : "Peripheral") :
	
	periph.name = periph.group_name

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

# For a given group, provide a proper cleaner function. None is the default one.
create_association_table : T.Dict[str,T.Callable] = {
	"TIM"       : TIM_periph_cleaner,
	"HRTIM"     : HRTIM_periph_cleaner,
	"USB"       : USB_periph_cleaner,
	"ETHERNET"  : ETHERNET_periph_cleaner,
	"ADC"       : ADC_periph_cleaner,
	"I2C"       : I2C_periph_cleaner,
	"GPIO"		: GPIO_periph_cleaner,
	None        : DEFAULT_create_cleaner
}