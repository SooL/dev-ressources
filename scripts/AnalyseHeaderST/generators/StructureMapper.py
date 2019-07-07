import logging
import Jstructure as JS
import structure as S
from FileSetHandler.pdsc import PDSCFile as PDSC
import typing as T
from copy import copy

logger = logging.getLogger()


def build_chip_set(pdsc_list :T.List[PDSC] = list()) -> T.Dict[str,S.ChipSet.ChipSet]:
	"""
	This function will build a chip set dictionary based on each and every silicon made by ST.
	
	:param pdsc_list: The list of all PDSC (Keil) files which describes chips
	:return: An association between a SVD and the chips it describes
	"""
	logger.info("Build ChipSets")
	output = dict()
	for pdsc_handler in pdsc_list :
		for header_key in pdsc_handler.define_to_chip_mapping.keys() :
			new_chipset = S.ChipSet.ChipSet()
			for chip_name in pdsc_handler.define_to_chip_mapping[header_key] :
				new_chip = S.ChipSet.Chip(chip_name,
										  pdsc_handler.define_to_svd[header_key],
										  [header_key])
				new_chipset.add_chip(new_chip)
			output[pdsc_handler.define_to_svd[header_key]] = copy(new_chipset)
	logger.info("Done")
	return output
	
#def map_peripheral(xml_periph : JS.Peripheral.Peripheral) -> S.Peripheral.Peripheral:


def build_groups(svd_to_periphlist :T.Dict[str,T.List[JS.Peripheral.Peripheral]]) -> T.Dict[str,S.Group.Group] :
	grp_names : T.Set[str] = set()
	output : T.Dict[str,S.Group.Group] = dict()
	for svd in svd_to_periphlist.keys() :
		for per in svd_to_periphlist[svd] :
			grp = per.group
			if grp not in output :
				output[grp] = S.Group.Group(grp)
			#TODO WARNING : JS Peripheral inserted here !!!
			output[grp].add_peripheral(per)

	return output
	
def compute_peripherals_variances(svd_to_periphlist :T.Dict[str,T.List[JS.Peripheral.Peripheral]],
								  computed_groups : T.Dict[str,S.Group.Group] = None) -> T.Dict[str,S.Group.Group]:
	
	groups = computed_groups if computed_groups is not None else build_groups(svd_to_periphlist)
	logger.info("Compute groups...")
	for grp in sorted(groups.keys()) :
		models : T.List[JS.Peripheral.Peripheral] = list()
		logger.info(f"Computing {grp}...")
		for per in groups[grp].peripherals :
			for model in models :
				if per.mapping_equivalent_to(model) :
					per.variance_id = model.variance_id
			if per.variance_id is None :
				per.variance_id = str(len(models))
				models.append(per)
		logger.info(f"\tFound {len(models)} variants")
	
	return groups