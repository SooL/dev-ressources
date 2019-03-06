
from tools.utils import *

def extract_IRQ_CFG(full, header_listing):
	step1_cfg: Dict[Tuple[str, int], ChipSeriesManager] = dict()
	step2_cfg: Dict[ChipSeriesManager, Dict[str, int]] = dict()
	step1_irq: Dict[Tuple[str, int], ChipSeriesManager] = dict()
	step2_irq: Dict[ChipSeriesManager, Dict[str, int]] = dict()
	for header in header_listing:
		dico_cfg = header.extract_CMSIS_configuration()
		for name in dico_cfg.keys():
			if (name, dico_cfg[name]) not in step1_cfg.keys():
				step1_cfg[(name, dico_cfg[name])] = ChipSeriesManager(header.chips.chip_list)
			else:
				step1_cfg[(name, dico_cfg[name])].merge(header.chips)
		dico_irq = header.extract_irq_values()
		if dico_irq is None:
			print("Error in " + list(header.chips.chip_list)[0])
		else :
			for name in dico_irq.keys():
				if (name, dico_irq[name]) not in step1_irq.keys():
					step1_irq[(name, dico_irq[name])] = ChipSeriesManager(header.chips.chip_list)
				else:
					step1_irq[(name, dico_irq[name])].merge(header.chips)

	for cfg in step1_cfg.keys():
		(name, value) = cfg
		if step1_cfg[cfg] not in step2_cfg.keys():
			step2_cfg[step1_cfg[cfg]] = dict()
		step2_cfg[step1_cfg[cfg]][name] = value
	for irq in step1_irq.keys():
		(name, value) = irq
		if step1_irq[irq] not in step2_irq.keys():
			step2_irq[step1_irq[irq]] = dict()
		step2_irq[step1_irq[irq]][name] = value

	with open("out/IRQ_NVIC.h", "w") as file:
		file.write("""
#ifndef SOOL_IRQ_H
#define SOOL_IRQ_H

#include "../../sool_chip_setup.h"
#include "system_stm32.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
		""")
		file_out = ""
		for chips in step2_irq.keys():
			copy = ChipSeriesManager(chips.chip_list)
			full.simplify(copy)
			key = copy.output_ifdef_template()
			out = ""
			for name in step2_irq[chips].keys():
				out += "\n\t{0:15} = {1},".format(name, step2_irq[chips][name])
			file_out += key.format(ifdef=out,
				ifndef=""
				).replace("#else\n\n#endif", "#endif")
		file_out = file_out[:-9] + file_out[-8:]
		file_out += "\n} IRQn_Type;\n"
		file.write(file_out)

		for chips in step2_cfg.keys():
			copy = ChipSeriesManager(chips.chip_list)
			full.simplify(copy)
			key = copy.output_ifdef_template()
			out = ""
			for name in step2_cfg[chips].keys():
				if name[-4:] == "_REV":
					out += "#define {0:23} 0x{1}U\n".format(name, step2_cfg[chips][name])
				else:
					out += "#define {0:25} {1}\n".format(name, step2_cfg[chips][name])
			file.write(key.format(ifdef=out,
				ifndef=""
				).replace("\n#else\n\n#endif", "#endif"))
		file.write("""
#ifdef __cplusplus
}
#endif

#endif //SOOL_IRQ_H""")