from structure import ChipSet


def generate_sool_chip_setup() :
	out: str = ""

	with open("license_header.txt","r") as license:
		out = license.read() + "\n\n"

	max_in_line = 3
	family_list = sorted(ChipSet.reference_chipset.families.keys())
	for family in family_list :
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

	out += f"#define __SOOL_NB_TOT "
	curr_line = 0
	for family in family_list :
			if curr_line == 0:
				out += "\\\n         "
			out += f"__SOOL_NB_{family} + "
			curr_line += 1
			if curr_line > max_in_line:
				curr_line = 0
	out = out[:out.rfind("+") - 1] + "\n"
	out += f"#if __SOOL_NB_TOT > 1 \n"
	out += f"\t#error Only one chip can be defined\n"
	out += f"#elif __SOOL_NB_TOT == 0\n"
	out += f"\t#error At least one chip have to be defined\n"
	out += "#endif"
	return out

