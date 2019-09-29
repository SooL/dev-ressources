from structure import Group, Peripheral, Register, Field, ChipSet, Chip
import os, shutil
import typing as T
import logging

logger = logging.getLogger()


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
	
	with open("reports/sanity/multi_variant_chips.rpt","w") as report :
		rpt = sanity_multi_variant_chips(data)
		print(rpt)
		report.write(rpt)