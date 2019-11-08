import re
import typing as T
import logging

logger = logging.getLogger()

tim_log: str = ""

def TIM_log():
	return tim_log

def TIM_periph_cleaner(periph : "Peripheral") :
	global tim_log

	brief_tokens = periph.brief.split()

	if periph.brief[-5:] == "timer" :
		periph.brief += 's'

	periph_name = ""
	if "advanced" in brief_tokens :
		periph_name = "TIM_ADVANCED"
	elif "basic" in brief_tokens :
		periph_name = "TIM_BASIC"
	elif "general" in brief_tokens :
		periph_name = "TIM_GENERAL"

		tim_log += f"{periph.chips} :" \
		           f" {repr(list(inst.name for inst in periph.instances))} :" \
		           f" {repr(list(reg.name for reg in periph.registers))}"

		# TODO split timers depending on numbers or registers presence
		periph_name += "_" + periph.instances[0].name[3:]

	else :
		logger.error(f"TIM type detection failure for {periph.name} for chips {str(periph.chips)}. Assigning generic")
		periph_name = "TIM_GENERIC"
		periph_name += "_" + periph.instances[0].name[3:]

	periph.name = periph_name

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