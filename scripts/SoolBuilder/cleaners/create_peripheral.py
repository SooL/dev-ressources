import typing as T
import logging

logger = logging.getLogger()


def TIM_create_cleaner(periph : "Peripheral") :

	brief_tokens = periph.brief.split()

	if periph.brief[-5:] == "timer" :
		periph.brief += 's'

	if "advanced" in brief_tokens :
		periph.name = "TIM_ADVANCED"
	elif "basic" in brief_tokens :
		periph.name = "TIM_BASIC"
	elif "general" in brief_tokens :
		periph.name = "TIM_GENERAL"

	else :
		logger.error(f"TIM type detection failure for {periph.name} for chips {str(periph.chips)}. Assigning generic")
		periph.name = "TIM_GENERIC"
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

def ADC_create_cleaner(periph: "Periph") :

	if "common" in periph.brief.lower() :
		periph.name = "ADC_Common"
	else :
		periph.name = "ADC"

def DEFAULT_create_cleaner(periph : "Peripheral") :
	
	periph.name = periph.group_name


# For a given group, provide a proper cleaner function. None is the default one.
create_association_table : T.Dict[str,T.Callable] = {
	"TIM"       : TIM_create_cleaner,
	"HRTIM"     : HRTIM_create_cleaner,
	"USB"       : USB_create_cleaner,
	"ETHERNET"  : ETHERNET_create_cleaner,
	"ADC"       : ADC_create_cleaner,
	None        : DEFAULT_create_cleaner
}