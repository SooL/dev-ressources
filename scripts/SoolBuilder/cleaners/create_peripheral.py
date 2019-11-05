import typing as T
import logging

logger = logging.getLogger()

tim_log: str = ""

def TIM_log():
	return tim_log

def TIM_create_cleaner(periph : "Peripheral") :
	global tim_log

	brief_tokens = periph.brief.split()

	if periph.brief[-5:] == "timer" :
		periph.brief += 's'

	if "advanced" in brief_tokens :
		periph.name = "TIM_ADVANCED"
	elif "basic" in brief_tokens :
		periph.name = "TIM_BASIC"
	elif "general" in brief_tokens :
		periph.name = "TIM_GENERAL"

		tim_log += f"{periph.chips} :" \
		           f" {repr(list(inst.name for inst in periph.instances))} :" \
		           f" {repr(list(reg.name for reg in periph.registers))}"

		# TODO split timers depending on numbers or registers presence
		periph.name += "_" + periph.instances[0].name[3:]

	else :
		logger.error(f"TIM type detection failure for {periph.name} for chips {str(periph.chips)}. Assigning generic")
		periph.name = "TIM_GENERIC"
		periph.name += "_" + periph.instances[0].name[3:]
	pass

def HRTIM_create_cleaner(periph: "Peripheral") :

	if len(periph.instances) == 1 :
		periph.name = periph.instances[0].name
	else :
		logger.error(f"HRTIM type detection failure for {periph.name} for chips {str(periph.chips)}. Assigning generic")
		periph.name = "HRTIM_GENERIC"
	pass

def USB_create_cleaner(periph: "Peripheral") :

	if len(periph.instances) == 1 :
		periph.name = periph.instances[0].name
	else :
		logger.error(f"USB type detection failure for {periph.name} for chips {str(periph.chips)}. Assigning generic")
		periph.name = "USB_GENERIC"
	pass

def ETHERNET_create_cleaner(periph: "Peripheral") :

	if len(periph.instances) == 1 :
		periph.name = periph.instances[0].name
	else :
		logger.error(f"ETHERNET type detection failure for {periph.name} for chips {str(periph.chips)}. Assigning generic")
		periph.name = "ETHERNET_GENERIC"
	pass

def ADC_create_cleaner(periph: "Peripheral") :

	if "common" in periph.brief.lower() :
		periph.name = "ADC_Common"
	else :
		periph.name = "ADC"

def DEFAULT_create_cleaner(periph : "Peripheral") :
	
	periph.name = periph.group_name

def I2C_create_cleaner(periph: "Peripheral") :

	if "TIMINGR" in periph and "TIMEOUTR" in periph and "PECR" in periph:
		periph.name = "FMPI2C"

def GPIO_create_cleaner(periph) :
	periph.name = "GPIO"
# For a given group, provide a proper cleaner function. None is the default one.
create_association_table : T.Dict[str,T.Callable] = {
	"TIM"       : TIM_create_cleaner,
	"HRTIM"     : HRTIM_create_cleaner,
	"USB"       : USB_create_cleaner,
	"ETHERNET"  : ETHERNET_create_cleaner,
	"ADC"       : ADC_create_cleaner,
	"I2C"       : I2C_create_cleaner,
	"GPIO"		: GPIO_create_cleaner,
	None        : DEFAULT_create_cleaner
}