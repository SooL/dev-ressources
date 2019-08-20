from Jstructure.Peripheral import Peripheral
import typing as T
import logging

logger = logging.getLogger()


def TIM_create_cleaner(periph : Peripheral) :
	periph.group_name = "TIM"

	brief_tokens = periph.brief.split()

	if "advanced" in brief_tokens :
		periph.name = "TIM_ADVANCED"
	elif "basic" in brief_tokens :
		periph.name = "TIM_BASIC"
	elif "general" in brief_tokens :
		periph.name = "TIM_GENERAL"
	else :
		logger.error(f"TIM type detection failure for {periph.name} for chips {periph.chips:s} assigning generic")
		periph.name = "TIM_GENERIC"
	pass


def DEFAULT_create_cleaner(periph : Peripheral) :
	periph.name = periph.group_name


# For a given group, provide a proper cleaner function. None is the default one.
create_association_table : T.Dict[str,T.Callable] = {
	"TIM1"	: TIM_create_cleaner,
	"TIMs"	: TIM_create_cleaner,
	"TIM"	: TIM_create_cleaner,
	None	: DEFAULT_create_cleaner
}