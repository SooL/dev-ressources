from structure import ChipSet
import logging
import typing as T

def generate_sool_irqn() :
    logger = logging.getLogger()
    out = ""
    with open("license_header.txt", "r") as lgpl:
        out += lgpl.read()
    out += '#ifndef SOOL_IRQ_H\n'
    out += '#define SOOL_IRQ_H\n'
    out += '\n'
    out += '#include "../../sool_chip_setup.h"\n'
    out += '#include "system_stm32.h"\n'
    out += '\n'
    out += '#ifdef __cplusplus\n'
    out += 'extern "C" {\n'
    out += '#endif\n'
    out += '\n'
    out += 'typedef enum\n'
    out += '{\n'

    synthesis: T.Dict[T.Tuple[str, int], ChipSet] = dict()
    logger.info("Processing IRQn...")
    for chip in ChipSet.reference_chipset:
        for irqname, value in chip.header_handler.irq_table.items():
            key = (irqname, value)
            if key not in synthesis:
                synthesis[key] = ChipSet()
            synthesis[key].add(chip)

    reverse_synthesis: T.Dict[ChipSet, T.List[T.Tuple[str, int]]] = dict()
    for key in sorted(synthesis.keys(), key=lambda x: (x[1], x[0])):
        cs = synthesis[key]
        if cs not in reverse_synthesis:
            reverse_synthesis[cs] = list()
        reverse_synthesis[cs].append(key)

    for key in reverse_synthesis:
        need_define = key != ChipSet.reference_chipset

        out = f"#if {key.defined_list(4)}\n" if need_define else ""
        for irq in reverse_synthesis[key]:
            out += f"\t{irq[0]} = {irq[1]},\n"
        out += f"#endif\n" if need_define else ""

    out += "} IRQn_Type;\n"
    out += "\n"
    out += "#ifdef __cplusplus\n"
    out += "}\n"
    out += "#endif\n"
    out += "\n"
    out += "#endif //__SOOL_IRQN_H"

    logger.info("\tDone.")
    return out