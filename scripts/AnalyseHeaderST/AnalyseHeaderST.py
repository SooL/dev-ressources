#!/usr/bin/python3
# -*-coding:utf-8 -*

'''
Documentation, License etc.

@package AnalyseHeaderST
'''

import glob
from pathlib import *
import time

from header import *
from tools.display import *
from tools.utils import *
# from tools import bitmap
# from tools.typedef import *
# from tools import memory_mapping
# import gen_bitmap

# from gen_periphmap import *
import pickle
from IRQ_CFG import *

########################################################################################################################
#                                            GLOBAL VARIABLES INITIALIZATION                                           #
########################################################################################################################


# _________________________________________________________________________________________________________________ Paths

FileLocation = "../CMSIS header files/"
OutputDirectory = "out/"

db_path_base = Path(".db")
db_header = db_path_base / "headers.pkl"
db_peripheral_typedef = db_path_base / "periph_typedef.pkl"

FileListing = glob.glob(FileLocation + "stm32?????*.h")

# ______________________________________________________________________________________________________ Template strings

full = ChipSeriesManager()
full.from_file_path(FileListing)

csm: Set[str] = full  # .select("STM32F07")
# csm.remove_chips(csm.select("F1"),"remove")

# _____________________________________________________________________________________________________ Correction_matrix

"""
correction_matrix : Dict[Tuple[str,str,str],Tuple[str,str,str]] = dict()
typedef_correction_matrix : Dict[str,str] = dict()
typedef_post_correction_matrix : Dict[Tuple[str,str],Callable[[TypedefRegister],None]] = dict()

correction_matrix[("GPIO","OSPEEDER",None)] = ("GPIO","OSPEEDR",None)

#To debug L4(+) Legacy legacies on I/ODR.
for i in range(0,16) :
	correction_matrix[("GPIO","OTYPER","ODR" + str(i))] = ("GPIO","OTYPER",None)
	correction_matrix[("GPIO","OTYPER","IDR" + str(i))] = ("GPIO","OTYPER",None)

correction_matrix[("FW",None,None)] = ("FIREWALL",None,None)
correction_matrix[("COMP1_2",None,None)] = ("COMP",None,None)

for i in range(1,50) :
	correction_matrix[("CAN","F" + str(i) + "R1",None)] = ("CAN",None,None)
	correction_matrix[("CAN","F" + str(i) + "R2",None)] = ("CAN",None,None)


correction_matrix[("CAN","F0R1",None)] = ("CAN","FR1",None)
correction_matrix[("CAN","F0R2",None)] = ("CAN","FR2",None)

typedef_correction_matrix["AFR1"] = "AFRL"
typedef_correction_matrix["AFR2"] = "AFRH"

def f_test(x : TypedefRegister) :
	x.name = "AFR"
	x.length_multiple = 1
	x.length_unit = 8
	x.true_array = False


typedef_post_correction_matrix[("GPIO","AFR[2]")] = f_test



associated_periphs : Dict[str, List[str]] = dict()
associated_periphs["CAN"] = list()
associated_periphs["CAN"].append("TTCAN")
associated_periphs["COMP"] = list()
associated_periphs["COMP"].append("COMPOPT")

"""

# ________________________________________________________________________________________________________________ Others

load_state: Dict[str, bool] = {"init_bit": False, "init_typedef": False, "final_bit": False}
load_ok = False

# bitmap.verbosity = 1

peripheral_listing: Dict[str, Peripheral] = dict()
header_listing: List[Header] = list()


########################################################################################################################
#                                                  DATABASE FUNCTIONS                                                  #
########################################################################################################################

def load_db(path, fail_value=None):
	"""

	:param path: path (generated with pathLib.Path) to the desired database.
	:param fail_value: value to use if the loading fails, because the file does not exist or the reading is impossible.
			Default value is None.
	:return: the database if loaded, or the default value.
	"""
	result = fail_value
	if path.is_file():
		print("Found database file at " + str(path) + ".\n\tRecovering...")
		with open(path, "rb") as db:
			try:
				result = pickle.load(db)
				print("\tDatabase recovered")
			except Exception as e:
				print("\nError reading database. See error below.")
				print(repr(e))
				print("\n")
	return result


def write_db(path, content):
	"""

	:param path: path (generated with pathLib.Path) to the desired database.
	:param content: data to be copied to the database.
	:return: True if the dumping was a success, False otherwise.
	"""
	result = False
	print("Dump Database at " + str(path) + " ...")
	with open(path, "wb") as db:
		try:
			pickle.dump(content, db, pickle.HIGHEST_PROTOCOL)
			print("\tDone")
			result = True
		except Exception as e:
			print("\nError writing to database. See error below")
			print(repr(e))
			print("\n")
	return result


########################################################################################################################
#                                                    STEP FUNCTIONS                                                    #
########################################################################################################################

# ______________________________________________________________________________ Initial Database generation & processing

def load_databases():
	pass


def build_headers_files():
	global FileListing
	global csm

	global header_listing
	start = time.perf_counter()
	print("#" * 80, "\n{:#^80}\n".format(" INITIAL READING ") + "#" * 80, "\n")

	for f in sorted(FileListing):

		chip_id = f[f.find("stm32"):len(f) - 2].upper()
		chip_id = chip_id.replace("X","x")
		if chip_id not in csm:
			print("SKIPPING CHIP " + f)
			continue

		print("Reading " + lenAdj(chip_id, 12) + ": " + f)

		header_listing.append(Header(f, ChipSeriesManager({chip_id})))

	print("\nElapsed in", time.perf_counter() - start)


def process_header_to_typedef():
	global header_listing
	global peripheral_listing
	global csm
	start = time.perf_counter()
	print("#" * 80, "\n{:#^80}\n".format(" TYPEDEF BUILDING ") + "#" * 80, "\n")

	for header in header_listing:
		chip_id = header.filePath[header.filePath.find("stm32"):len(header.filePath) - 2].upper()

		print("Typedef analysis of", chip_id)
		header.exploit_typedef(peripheral_listing)

	print("\nElapsed in", time.perf_counter() - start)


def process_header_to_defines():
	global header_listing
	global peripheral_listing
	global csm
	start = time.perf_counter()
	print("#" * 80, "\n{:#^80}\n".format(" DEFINE BUILDING ") + "#" * 80, "\n")

	for header in header_listing:
		chip_id = header.filePath[header.filePath.find("stm32"):len(header.filePath) - 2].upper()

		print("Defines analysis of", chip_id)
		header.exploit_defines(peripheral_listing)

	print("\nElapsed in", time.perf_counter() - start)


def make_typedef_corrections():
	global peripheral_listing

	peripheral_listing["GPIO"]["AFR"].split_array(["AFRL", "AFRH"], 32)
	peripheral_listing["DSI"]["FIR"].split_array(["FIR0", "FIR1"], 32)
	peripheral_listing["DSI"]["IER"].split_array(["IER0", "IER1"], 32)
	peripheral_listing["DSI"]["ISR"].split_array(["ISR0", "ISR1"], 32)
	peripheral_listing["AFIO"]["EXTICR"].split_array([None, None, None, None], 32)
	peripheral_listing["DSI"]["TCCR"].split_array([None, None, None, None, None, None], 32)
	peripheral_listing["DSI"]["WPCR"].split_array([None, None, None, None, None], 32)

	peripheral_listing["SYSCFG"]["EXTICR"].split_array([None, None, None, None], 32)
	empty_32_array = [None]*32
	peripheral_listing["SYSCFG"]["IT_LINE_SR"].split_array(empty_32_array, 32)

	LUT_mappings = peripheral_listing["GFXMMU"].getMappings("LUT")
	LUT_mappings[0].reg.size = 64
	LUT_mappings[0].reg.reg_type = "Reg64_t"
	LUTL: Register = Register("LUTL", LUT_mappings[0].reg.chips,"Reg32_t", 32)
	LUTH: Register = Register("LUTH", LUT_mappings[0].reg.chips,"Reg32_t", 32)
	for m in LUT_mappings:
		m.array_size = int(m.array_size/2)
		peripheral_listing["GFXMMU"].add_register(LUTL, m.pos, m.chips, None, m.array_size, 0, 8)
		peripheral_listing["GFXMMU"].add_register(LUTH, m.pos, m.chips, None, m.array_size, 4, 8)

	BTCR_mappings = peripheral_listing["FMC_Bank1"].getMappings("BTCR")
	BTCR_mappings[0].reg.size = 64
	BTCR_mappings[0].reg.reg_type = "Reg64_t"
	BCR: Register = Register("BCR", BTCR_mappings[0].reg.chips, "Reg32_t", 32)
	BTR: Register = Register("BTR", BTCR_mappings[0].reg.chips, "Reg32_t", 32)
	BCR1: Register = Register("BCR1", BTCR_mappings[0].reg.chips, "Reg32_t", 32)
	for m in BTCR_mappings:
		m.array_size = int(m.array_size/2)
		peripheral_listing["FMC_Bank1"].add_register(BCR, m.pos, m.chips, None, m.array_size, 0, 8)
		peripheral_listing["FMC_Bank1"].add_register(BTR, m.pos, m.chips, None, m.array_size, 4, 8)
		peripheral_listing["FMC_Bank1"].add_register(BCR1, m.pos, m.chips)

	BWTR_mappings = peripheral_listing["FMC_Bank1E"].getMappings("BWTR")
	for m in BWTR_mappings:
		m.array_size = 4

	BTCR_mappings = peripheral_listing["FSMC_Bank1"].getMappings("BTCR")
	BTCR_mappings[0].reg.size = 64
	BTCR_mappings[0].reg.reg_type = "Reg64_t"
	BCR: Register = Register("BCR", BTCR_mappings[0].reg.chips, "Reg32_t", 32)
	BTR: Register = Register("BTR", BTCR_mappings[0].reg.chips, "Reg32_t", 32)
	BCR1: Register = Register("BCR1", BTCR_mappings[0].reg.chips, "Reg32_t", 32)
	for m in BTCR_mappings:
		m.array_size = int(m.array_size/2)
		peripheral_listing["FSMC_Bank1"].add_register(BCR, m.pos, m.chips, None, m.array_size, 0, 8)
		peripheral_listing["FSMC_Bank1"].add_register(BTR, m.pos, m.chips, None, m.array_size, 4, 8)
		peripheral_listing["FSMC_Bank1"].add_register(BCR1, m.pos, m.chips)

	BWTR_mappings = peripheral_listing["FSMC_Bank1E"].getMappings("BWTR")
	for m in BWTR_mappings:
		m.array_size = 4

	peripheral_listing["SPDIFRX"].add_register(Register("VERR", ChipSeriesManager(), "Reg32_t", 32), 0x03F4*8)
	peripheral_listing["SPDIFRX"].add_register(Register("IDR", ChipSeriesManager(), "Reg32_t", 32), 0x03F8*8)
	peripheral_listing["SPDIFRX"].add_register(Register("SIDR", ChipSeriesManager(), "Reg32_t", 32), 0x03FC*8)

	DR: Register = peripheral_listing["SPDIFRX"]["DR"]
	DR0 = Register("DR0", ChipSeriesManager(), DR.reg_type, DR.size)
	DR1 = Register("DR1", ChipSeriesManager(), DR.reg_type, DR.size)
	DR2 = Register("DR2", ChipSeriesManager(), DR.reg_type, DR.size)
	for m in peripheral_listing["SPDIFRX"].getMappings("DR"):
		peripheral_listing["SPDIFRX"].add_register(DR0, m.pos)
		peripheral_listing["SPDIFRX"].add_register(DR1, m.pos)
		peripheral_listing["SPDIFRX"].add_register(DR2, m.pos)

	peripheral_listing["DMA"].add_link(peripheral_listing["DMA_Request"])
	peripheral_listing["DMA"].add_link(peripheral_listing["DMA_Stream"])
	peripheral_listing["DMA"].add_link(peripheral_listing["DMA_Channel"])
	peripheral_listing["BDMA"].add_link(peripheral_listing["BDMA_Channel"])
	peripheral_listing["MDMA"].add_link(peripheral_listing["MDMA_Channel"])

	peripheral_listing["DMAMUX"] = Peripheral("DMAMUX", ChipSeriesManager())
	peripheral_listing["DMAMUX"].add_link(peripheral_listing["DMAMUX_Channel"])
	peripheral_listing["DMAMUX"].add_link(peripheral_listing["DMAMUX_ChannelStatus"])
	peripheral_listing["DMAMUX"].add_link(peripheral_listing["DMAMUX_RequestGen"])
	peripheral_listing["DMAMUX"].add_link(peripheral_listing["DMAMUX_RequestGenStatus"])

	peripheral_listing["ADC"].add_link(peripheral_listing["ADC_Common"])

	peripheral_listing["COMP"].add_link(peripheral_listing["COMPOPT"])

	peripheral_listing["DFSDM"] = Peripheral("DFSDM", ChipSeriesManager())
	peripheral_listing["DFSDM"].add_link(peripheral_listing["DFSDM_Channel"])
	peripheral_listing["DFSDM"].add_link(peripheral_listing["DFSDM_Filter"])

	peripheral_listing["EXTI"].add_link(peripheral_listing["EXTI_Core"])

	peripheral_listing["FDCAN"] = Peripheral("FDCAN", ChipSeriesManager())
	peripheral_listing["FDCAN"].add_link(peripheral_listing["FDCAN_ClockCalibrationUnit"])
	peripheral_listing["FDCAN"].add_link(peripheral_listing["FDCAN_Global"])
	peripheral_listing["FDCAN"].add_link(peripheral_listing["TTCAN"])

	peripheral_listing["FMC"] = Peripheral("FMC", ChipSeriesManager())
	peripheral_listing["FMC"].add_link(peripheral_listing["FMC_Bank1"])
	peripheral_listing["FMC"].add_link(peripheral_listing["FMC_Bank1E"])
	peripheral_listing["FMC"].add_link(peripheral_listing["FMC_Bank2"])
	peripheral_listing["FMC"].add_link(peripheral_listing["FMC_Bank2_3"])
	peripheral_listing["FMC"].add_link(peripheral_listing["FMC_Bank3"])
	peripheral_listing["FMC"].add_link(peripheral_listing["FMC_Bank4"])
	peripheral_listing["FMC"].add_link(peripheral_listing["FMC_Bank5_6"])
	for p in peripheral_listing["FMC"].linked_peripherals:
		mappings = p.getMappings("PATT")
		mappings.extend(p.getMappings("PMEM"))
		mappings.extend(p.getMappings("PCR"))
		mappings.extend(p.getMappings("SR"))
		mappings.extend(p.getMappings("ECCR"))
		for m in mappings:
			reg = m.reg
			if reg in p.registers:
				p.registers.remove(reg)
			reg.parent = None
			peripheral_listing["FMC"].add_register(reg, -1)
			m.reg = peripheral_listing["FMC"][reg.name]

	peripheral_listing["FSMC"] = Peripheral("FSMC", ChipSeriesManager())
	peripheral_listing["FSMC"].add_link(peripheral_listing["FSMC_Bank1"])
	peripheral_listing["FSMC"].add_link(peripheral_listing["FSMC_Bank1E"])
	peripheral_listing["FSMC"].add_link(peripheral_listing["FSMC_Bank2_3"])
	peripheral_listing["FSMC"].add_link(peripheral_listing["FSMC_Bank4"])
	for p in peripheral_listing["FSMC"].linked_peripherals:
		mappings = p.getMappings("PATT")
		mappings.extend(p.getMappings("PMEM"))
		mappings.extend(p.getMappings("PCR"))
		mappings.extend(p.getMappings("SR"))
		mappings.extend(p.getMappings("ECCR"))
		for m in mappings:
			reg = m.reg
			if reg in p.registers:
				p.registers.remove(reg)
			reg.parent = None
			peripheral_listing["FSMC"].add_register(reg, -1)
			m.reg = peripheral_listing["FSMC"][reg.name]
			m.reg.parent = peripheral_listing["FSMC"] #workaround to prevent specific error

	peripheral_listing["HASH"].add_link(peripheral_listing["HASH_DIGEST"])

	peripheral_listing["HRTIM"] = Peripheral("HRTIM", ChipSeriesManager())
	peripheral_listing["HRTIM"].add_link(peripheral_listing["HRTIM_Common"])
	peripheral_listing["HRTIM"].add_link(peripheral_listing["HRTIM_Master"])
	peripheral_listing["HRTIM"].add_link(peripheral_listing["HRTIM_Timerx"])

	peripheral_listing["LTDC"].add_link(peripheral_listing["LTDC_Layer"])

	peripheral_listing["OPAMP"].add_link(peripheral_listing["OPAMP_Common"])

	peripheral_listing["SAI"].add_link(peripheral_listing["SAI_Block"])

	peripheral_listing["USB"].add_link(peripheral_listing["USB_Device"])
	peripheral_listing["USB"].add_link(peripheral_listing["USB_Global"])
	peripheral_listing["USB"].add_link(peripheral_listing["USB_Host"])
	peripheral_listing["USB"].add_link(peripheral_listing["USB_HostChannel"])
	peripheral_listing["USB"].add_link(peripheral_listing["USB_INEndpoint"])
	peripheral_listing["USB"].add_link(peripheral_listing["USB_OUTEndpoint"])



def make_final_corrections():
	# merge BSRR, (BSRRL,BSRRH) fields (to merge their chips)
	BSRR: Register = peripheral_listing["GPIO"]["BSRR"];
	BSRRL: Register = peripheral_listing["GPIO"]["BSRRL"];
	BSRRH: Register = peripheral_listing["GPIO"]["BSRRH"];
	BSRR.reg_type = "ArrayRegBase_t<uint32_t, uint16_t>";
	for var in BSRRL:
		for f in var:
			BSRR.add_field(Field(f.name, f.chips, f.pos, f.size))
	for var in BSRRH:
		for f in var:
			BSRR.add_field(Field(f.name, f.chips, f.pos + 16, f.size))
	for var in BSRR:
		for f in var:
			if f.pos < 16:
				BSRRL.add_field(Field(f.name, f.chips, f.pos, f.size))
			else:
				BSRRH.add_field(Field(f.name, f.chips, f.pos - 16, f.size))

	# add AFRL and AFRH fields to AFR register
	# The opposite direction (AFR -> AFRL & AFRH) is not necessary
	# as all fields are defined in AFRL and AFRG, AFR is empty
	AFR: Register = peripheral_listing["GPIO"]["AFR"]
	AFRL: Register = peripheral_listing["GPIO"]["AFRL"]
	AFRH: Register = peripheral_listing["GPIO"]["AFRH"]
	for var in AFRL:
		for f in var:
			AFR.add_field(Field(f.name, f.chips, f.pos, f.size))
	for var in AFRH:
		for f in var:
			AFR.add_field(Field(f.name, f.chips, f.pos + 32, f.size))

	LUT: Register = peripheral_listing["GFXMMU"]["LUT"]
	LUTL: Register = peripheral_listing["GFXMMU"]["LUTL"]
	LUTH: Register = peripheral_listing["GFXMMU"]["LUTH"]
	for var in LUTL:
		for f in var:
			LUT.add_field(Field(f.name, f.chips, f.pos, f.size))
	for var in LUTH:
		for f in var:
			LUT.add_field(Field(f.name, f.chips, f.pos+32, f.size))

	BTCR: Register = peripheral_listing["FMC_Bank1"]["BTCR"]
	BCR: Register = peripheral_listing["FMC_Bank1"]["BCR"]
	BTR: Register = peripheral_listing["FMC_Bank1"]["BTR"]
	for var in BCR:
		for f in var:
			BTCR.add_field(Field(f.name, f.chips, f.pos+32, f.size))
	for var in BTR:
		for f in var:
			BTCR.add_field(Field(f.name, f.chips, f.pos, f.size))

	BTCR: Register = peripheral_listing["FSMC_Bank1"]["BTCR"]
	BCR: Register = peripheral_listing["FSMC_Bank1"]["BCR"]
	BTR: Register = peripheral_listing["FSMC_Bank1"]["BTR"]
	for var in BCR:
		for f in var:
			BTCR.add_field(Field(f.name, f.chips, f.pos+32, f.size))
	for var in BTR:
		for f in var:
			BTCR.add_field(Field(f.name, f.chips, f.pos, f.size))

	peripheral_listing["RCC"]["CFGR3"].add_field(Field("ADCSW", ChipSeriesManager({"STM32F0"}), 8,1))

	USART_CR1: Register = peripheral_listing["USART"]["CR1"]
	for var in USART_CR1:
		for f in var :
			if f.name == "M":
				peripheral_listing["USART"].create_field("CR1", "M0", f.pos, f.size, f.chips)

	DR: register = peripheral_listing["SPDIFRX"]["DR"]
	DR0: register = peripheral_listing["SPDIFRX"]["DR0"]
	DR1: register = peripheral_listing["SPDIFRX"]["DR1"]
	DR2: register = peripheral_listing["SPDIFRX"]["DR2"]
	for var in DR0:
		for f in var: DR.add_field(Field("DR0_"+f.name, f.chips, f.pos, f.size))
	for var in DR1:
		for f in var: DR.add_field(Field("DR1_"+f.name, f.chips, f.pos, f.size))
	for var in DR2:
		for f in var: DR.add_field(Field("DR2_"+f.name, f.chips, f.pos, f.size))


def finalize():
	global peripheral_listing
	global csm
	start = time.perf_counter()
	print("#" * 80, "\n{:#^80}\n".format(" FINALIZATION ") + "#" * 80, "\n")

	for periph in peripheral_listing:
		print("Finalizing", periph)
		peripheral_listing[periph].finalize(full)

	print("\nElapsed in", time.perf_counter() - start)

def get_instances_mappings():
	global full
	start = time.perf_counter()
	print("#" * 80, "\n{:#^80}\n".format(" EXTRACT MEMORY MAPPING ") + "#" * 80, "\n")
	global_dict: Dict[str,List[(ChipSeriesManager,Tuple[int,str])]] = dict()
	for header in header_listing:
		header_dict = header.extract_memory_mapping()
		chip_id = header.filePath[header.filePath.find("stm32"):len(header.filePath) - 2].upper()
		print(chip_id + " : " + str(len(header_dict.keys())) + " memory mappings.")
		for name in header_dict.keys():
			if name not in global_dict:
				global_dict[name] = list()
			ok = False
			for chips, (addr,typedef) in global_dict[name]:
				if addr == header_dict[name][0] and typedef == header_dict[name][1]:
					chips.merge(header.chips)
					ok = True
			if not ok:
				global_dict[name].append((ChipSeriesManager(header.chips.chip_list), (header_dict[name][0], header_dict[name][1])))

	for name in global_dict.keys():
		for chips, (addr,typedef) in global_dict[name]:
			chips.build_chip_family()
			full.simplify(chips)

	print("\nElapsed in", time.perf_counter() - start)
	return global_dict


def get_var(periph: str,reg: str,field: str) :
	full_chips: ChipSeriesManager = ChipSeriesManager()
	for variant in peripheral_listing[periph][reg].variants :
		print("Found variant",[f.name for f in variant])
		if field in [f.name for f in variant] :
			full_chips.merge(variant[field].chips)
	
	full_chips.build_chip_family()
	full.simplify(full_chips)
	print("\n".join(str(full_chips).split()))

if __name__ == "__main__":
	log_init(full)

	build_headers_files()

	process_header_to_typedef()
	make_typedef_corrections()
	process_header_to_defines()
	make_final_corrections()

	finalize()
	print("END\n" + "#" * 80);

	global_dict = get_instances_mappings()
	if len(global_dict.keys()) == 0:
		print("ERROR : no memory mapping found")
	with open("mem_map.txt", "w") as file:
		for name in global_dict.keys():
			print(name)
			for chips, (addr,typedef) in global_dict[name]:
				if typedef in peripheral_listing:
					peripheral_listing[typedef].add_instance(name, chips, addr)
				else:
					file.write(chips.output_ifdef_template().format(
							ifdef="#define {:20} (reinterpret_cast<{}*>(0x{:08X}))".format(name, typedef, addr),
							ifndef=""
							).replace("#else\n\n#endif", "#endif"))

	for periph in peripheral_listing :
		if not peripheral_listing[periph].main :
			continue
		print("Output ",periph)
		peripheral_listing[periph].file_output()

	extract_IRQ_CFG(full, header_listing)

	print(output_log())
	with open("run.log","w") as file :
		file.write(output_log())
	
