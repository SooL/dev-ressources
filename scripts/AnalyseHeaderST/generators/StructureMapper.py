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


def build_groups(svd_to_periphlist :T.Dict[str,T.List[JS.Peripheral.Peripheral]]) -> T.Dict[str, S.Group.Group]:
	"""
	This function will create groups containing actual peripherals.
	:param svd_to_periphlist: a dict for which the values are a list of peripherals.
	The key should be a SVD path/file but this isn't really relevant.
	:return: Dict with the group name as key  and the group as value.
	"""
	output : T.Dict[str,S.Group.Group] = dict()
	models: T.Dict[str,T.List[JS.Peripheral.Peripheral]] = dict()
	refd_names : T.List[str] = list()
	logger.info("Begin Group analysis...")
	removed = 0
	
	for svd in svd_to_periphlist.keys() :
		logger.info(f"Processing {svd}")
		for per in svd_to_periphlist[svd] :
			grp = per.group
			#Group creation
			if grp not in output :
				output[grp] = S.Group.Group(grp)
				models[grp] = list()
			#TODO WARNING : JS Peripheral inserted here !!!
			#Compute peripheral variance.
			for model in models[grp] :
				if per.mapping_equivalent_to(model) :
					per.variance_id = model.variance_id
			if per.variance_id is None :
				per.variance_id = len(models[grp])
				models[grp].append(per)
			#Save name to keep all instance names
			id_seq = f"{per.name}.{per.variance_id}"
			if id_seq not in refd_names :
				refd_names.append(id_seq)
				output[grp].add_peripheral(per)
			else :
				#TODO Handle adding chips to registered periph.
				removed += 1
				pass
	
	for k in sorted(models.keys()) :
		logger.info(f"Group {k:20s} : {len(models[k]):3d} variants")
	logger.info(f"Total of {len(refd_names)} instances kept. {removed:d} Instances removed.")

	return output
	
	
def compute_peripherals_variances(svd_to_periphlist:T.Dict[str, T.List[JS.Peripheral.Peripheral]],
								computed_groups: T.Dict[str, S.Group.Group] = None) -> T.Dict[str, S.Group.Group]:
	"""
	This function will compute the variance_id of all peripherals lists provided through svd_to_periphlist
	(it will compute groups) or réusing (and updating) an already existing dict of groups.
	
	See also build_groups.
	
	:param svd_to_periphlist: a dict for which the values are a list of peripherals.
	The key should be a SVD path/file but this isn't really relevant.
	
	Can be filled with anything if computed_groups is provided.
	//TODO To be cleaned up.
	
	:param computed_groups: An already existing computed group <b>which will be updated</b>
	:return: The edited group.
	"""
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