from structure import Group, PeripheralMapping, Register, Field, ChipSet, Chip
import os, shutil
import typing as T
import logging

logger = logging.getLogger()


def sanity_report_fixed_register_names():
	out = ""
	previous = None
	for fix in sorted(PeripheralMapping.fixs_done) :
		if fix == previous :
			continue
		if previous is None or previous[0] != fix[0] :
			out += f"\n# Peripheral : {fix[0]}\n"
			
		previous = fix
		out += f'# PeripheralMapping.forbid_fix("{fix[1]}", "{fix[2]}")\n'
	return out

def sanity_multi_variant_chips(data : T.Dict[str,Group]):
	"""
	This function will check that there is (no) mappings in conflict for a given chip
	:param data:
	:return:
	"""
	out = ""
	for name in sorted(data.keys()):
		g = data[name]
		logger.info(f"Sanity check 'multi_variant_chips' on {name}")
		for p in g.peripherals :
			checked_chips : T.Dict[Chip,int] = dict()
			for mapping in p.mappings :
				for chip in list(mapping.computed_chips.chips) :
					if chip not in checked_chips:
						checked_chips[chip] = 0
					else:
						checked_chips[chip] += 1
			
			out += f"Peripheral {name}:{p.name} multiple variant per-chip report :\n"
			for chip in sorted(checked_chips.keys(),key=lambda x : checked_chips[x],reverse=True):
				if checked_chips[chip] > 1 :
					out += f"\t{checked_chips[chip]:<3} variants for the chip {str(chip):15s}\n"
					memory : T.Set[int] = set()
					
					# for mapping in p.mappings :
					# 	for pos, register in mapping.register_mapping.items() :
					# 		if register.chips.match(chip) :
					# 			for var in register.variants :
					# 				if var.chips.match(chip) :
					# 					for field in var.fields :
					# 						if field.chips.match(chip) :
					#
					# 							start = pos * 32 + field.offset
					# 							used_addr = range(start,start + field.width)
					# 							for addr in used_addr :
					# 								if addr in memory :
					# 									out += f"\t{checked_chips[chip]:<3} variants for the chip {str(chip):15s} @ {mapping.name}:{register.name:10s}:{field.name} (0x{addr:8X})\n"
					# 							memory.update(used_addr)
					
	return out


def report_sanity(data : T.Dict[str,Group]):
	shutil.rmtree("reports/sanity",True)
	os.makedirs("reports/sanity")
	
	logger.info("Writing sanity reports...")
	
	with open("reports/sanity/register_name_fixes_done.rpt", "w") as report:
		report.write(sanity_report_fixed_register_names())
		
	with open("reports/sanity/multi_variant_chips.rpt","w") as report :
		rpt = sanity_multi_variant_chips(data)
		report.write(rpt)