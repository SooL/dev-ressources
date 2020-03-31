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

from structure import ChipSet
import logging
import typing as T


def generate_sool_cmsis_config() :
    logger = logging.getLogger()
    out = ""
    with open("license_header.txt", "r") as lgpl:
        out += lgpl.read()
    out += '#ifndef SOOL_CMSIS_H\n'
    out += '#define SOOL_CMSIS_H\n'
    out += '\n'
    out += '#include "../../sool_chip_setup.h"\n'
    out += '#include "system_stm32.h"\n'
    out += '\n'
    out += '#ifdef __cplusplus\n'
    out += 'extern "C" {\n'
    out += '#endif\n'

    synthesis: T.Dict[T.Tuple[str, int], ChipSet] = dict()
    logger.info("Processing CMSIS configs...")
    for chip in ChipSet.reference_chipset:
        for cmsiskey, value in chip.header_handler.cmsis_conf.items():
            key = (cmsiskey, value)
            if key not in synthesis:
                synthesis[key] = ChipSet()
            synthesis[key].add(chip)

    reverse_synthesis: T.Dict[ChipSet, T.List[T.Tuple[str, int]]] = dict()
    for key in sorted(synthesis.keys(), key=lambda x: (x[0], x[1])):
        cs = synthesis[key]
        if cs not in reverse_synthesis:
            reverse_synthesis[cs] = list()
        reverse_synthesis[cs].append(key)

    for key in reverse_synthesis:
        need_define = key != ChipSet.reference_chipset

        out += f"#if {key.defined_list(4)}\n" if need_define else ""
        for cmsisrecord in reverse_synthesis[key]:
            out += f"\t#define {cmsisrecord[0]:20s} "
            if str(cmsisrecord[1]).isdigit() :
                out += f"0x{cmsisrecord[1]:04X}\n"
            else :
                out += f"{cmsisrecord[1]}\n"
        out += f"#endif\n" if need_define else ""

    out += "\n"
    out += "#ifdef __cplusplus\n"
    out += "}\n"
    out += "#endif\n"
    out += "\n"
    out += "#endif //__SOOL_CMSIS_H"

    logger.info("\tDone.")
    return out