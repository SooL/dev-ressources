from structure import ChipSet

def generate_sool_chip_setup() :
	out : str = ""
	max_in_line = 3
	for family in ChipSet.reference_chipset.families :
		out += f"//{'#':#^78s}\n"
		out += f"//#{family:^76s}#\n"
		out += f"//{'#':#^78s}\n\n"

		chip_list = list(sorted(ChipSet.reference_chipset.families[family],key=lambda x : str(x)))
		for chip in chip_list :
			out += f"//#define {chip}\n"
		out += "\n"
		out += f"#define __SOOL_NB_{family}"
		curr_line = 0

		for chip in chip_list :
			if curr_line == 0 :
				out += "\\\n         "
			out += f"defined({chip.name:13s}) + "
			curr_line += 1
			if curr_line > max_in_line :
				curr_line = 0

		out = out[:out.rfind("+")-1] + "\n"

		out += (f"#if __SOOL_NB_{family} > 1\n"
				f"    #error Only one chip can be defined\n"
				f"#elif __SOOL_NB_{family} == 1\n"
				f"    #define {family}\n"
				f"#endif\n")

	return out

