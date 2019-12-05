#!/usr/bin/python3
# -*-coding:utf-8 -*

import logging
import os, fnmatch
import shutil
import urllib.request
import urllib.error
import tempfile
import zipfile
import typing as T
import json
import configparser
import glob

logger = logging.getLogger()
file_path = "./.data/svd"
fileset_path = "./.data/fileset"
packs_path = "./.data/packs"
config_file = "./.data/versions.ini"

defined_archives_st = {
	"STM32F0"  : "stm32f0_svd.zip",
	"STM32F1"  : "stm32f1_svd.zip",
	"STM32F2"  : "stm32f2_svd.zip",
	"STM32F3"  : "stm32f3_svd.zip",
	"STM32F4"  : "stm32f4_svd.zip",
	"STM32F7"  : "stm32f7_svd.zip",
	"STM32H7"  : "stm32h7_svd.zip",
	"STM32L0"  : "stm32l0_svd.zip",
	"STM32L1"  : "stm32l1_svd.zip",
	"STM32L4"  : "stm32l4_svd.zip",
	"STM32L4+" : "stm32l4plus_svd.zip",
	"STM32MP1" : "stm32mp1_svd.zip",
	#"STM32G0"  : "stm32g0_svd.zip",
	"STM32G4"  : "stm32g4_svd.zip"
}

defined_archives_keil = {
	"STM32F0"  : "Keil.STM32F0xx_DFP.",
	"STM32F1"  : "Keil.STM32F1xx_DFP.",
	"STM32F2"  : "Keil.STM32F2xx_DFP.",
	"STM32F3"  : "Keil.STM32F3xx_DFP.",
	"STM32F4"  : "Keil.STM32F4xx_DFP.",
	"STM32F7"  : "Keil.STM32F7xx_DFP.",
	"STM32H7"  : "Keil.STM32H7xx_DFP.",
	"STM32L0"  : "Keil.STM32L0xx_DFP.",
	"STM32L1"  : "Keil.STM32L1xx_DFP.",
	"STM32L4"  : "Keil.STM32L4xx_DFP.",
	"STM32MP1" : "Keil.STM32MP1xx_DFP.",
	"STM32G0"  : "Keil.STM32G0xx_DFP.",
	"STM32G4"  : "Keil.STM32G4xx_DFP.",
	"STM32W1"  : "Keil.STM32W1xx_DFP.",
	"STM32WB"  : "Keil.STM32WBxx_DFP."
}

default_version_keil = {
	 "STM32MP1" 	: "1.1.0",
	 "STM32F4"	: "2.14.0",
	 "STM32H7" 	: "2.3.1",
}

def init():
	"""
	This function will re-init the data folder for svd storage.
	:return:
	"""
	logger.info("Re-init data folder")
	if os.path.exists(file_path) :
		logger.warning("Delete" + os.path.realpath(file_path))
		shutil.rmtree(file_path)
	os.makedirs(file_path)
	
	if os.path.exists(fileset_path) :
		logger.warning("Delete" + os.path.realpath(fileset_path))
		shutil.rmtree(fileset_path)
	os.makedirs(fileset_path)

	if not os.path.exists(packs_path) :
		os.makedirs(fileset_path)

def download_and_handle_st(archive : str, destination : str = file_path) -> T.List[str]:
	"""
	This function will download the archive corresponding to archive, extract all .svd files
	and put them whithin the destination folder.
	
	:param archive: Archive designator. Either alias as defined in defined_archives_st or directly a .zip file
	:param destination: Destination folder
	:return: List of all .svd files
	"""
	
	base_url = "https://www.st.com/resource/en/svd"
	
	if archive.upper() in defined_archives_st :
		archive = defined_archives_st[archive.upper()]
	url = base_url + "/" + archive

	#Create a temporary directory, download the .zip, extract it and retrieve files
	with tempfile.TemporaryDirectory(prefix=f"SVD_RETR_ST_{archive}_") as temp_dir :
		with open(temp_dir + "/archive.zip","wb") as temp_archive :
			logger.info("Trying to download " + url + " ...")
			logger.debug("Temp path is " + temp_archive.name)
			with urllib.request.urlopen(url) as response :
				shutil.copyfileobj(response,temp_archive)
				logger.info("Download complete !")

		logger.info("Unzipping archive...")
		with zipfile.ZipFile(temp_archive.name) as zip_handler :
			zip_handler.extractall(temp_dir)
		logger.info("Done !")

		#Look for SVD files in the file tree
		svd_files = []
		for root,dirs,files in os.walk(temp_dir) :
			for name in files :
				if fnmatch.fnmatch(name,"*.svd") :
					svd_files.append(os.path.join(root,name))
		logger.info("Found " + str(len(svd_files)) + " SVD file(s)")

		for file in svd_files :
			logger.info("\tRetrieving " + os.path.basename(file))
			shutil.copy(file,destination)

		return [os.path.basename(f) for f in svd_files]
	
	
def version_cmp(v:str):
	try :
		return tuple([int(x) for x in v.split(".")])
	except:
		return (0,0,0)
	
def file_to_family(f:str):
	for family, archive in defined_archives_keil.items() :
		if fnmatch.fnmatch(f,f"*{archive}*") :
			return family
	return None

def keil_get_version(family : str) -> T.Union[None,str]:
	"""
	Retrieve the lateset version string for the pack associated to the provided family from Keil.
	:param family:
	:return: Version string if success, None otherwise.
	"""
	base_url_check = "http://pack.keil.com/api/pack/check?pack="
	archive = defined_archives_keil[family.upper()]

	url_check = base_url_check + archive + "1.0.0.pack"
	check_ok = False

	try:
		with urllib.request.urlopen(url_check) as response:
			t = json.loads(response.read().decode())
			check_ok = t["Success"]
			new_version = t["LatestVersion"]

			if not check_ok:
				logger.error(f"\tUnable to retrieve {archive}'s version value")

	except urllib.error.HTTPError as err:
		logger.error(f"HTTP Error {err.code} : {err.reason}")

	return new_version if check_ok else None

def select_local_keil_pack(family : str,version : str = "*") -> T.Union[str,None]:
	"""
	Select the higher version available of the family pack in the local repository.
	If no version match, it will try to find any version for the given family.
	If still none available, return None

	:param family: STM32 family to look for.
	:param version: Wanted version strin, format is x.y.z and the use of wildcards is available.
	:return: The path of the most recent compatible path trying to match the family or None.
	"""
	valid_packs = glob.glob(f"{packs_path}/{defined_archives_keil[family.upper()]}.{version}.pack")
	selected = None
	max_version = (0,0,0)
	if len(valid_packs) == 0:
		valid_packs = glob.glob(f"{packs_path}/{defined_archives_keil[family.upper()]}.*.pack")
		if len(valid_packs) == 0 :
			return None

	for pack in valid_packs :
		pack_version = tuple(map(int,pack.rsplit(".",4)[-4:-1]))
		if selected is None :
			max_version = pack_version
			selected = pack
			continue

		if pack_version > max_version :
			selected = pack
	return selected

def retrieve_keil_pack(family : str,
					   version : str = None,
					   locally_save : bool = False,
					   fallback = False) -> T.Union[None,str]:
	"""
	Try to download a given Keil .pack file.

	:param family: STM32 Family for which the pack should be retrieved.
	:param version: If provided, attempts to download this exact version of the pack. Try to get the latest version otherwise.
	:param locally_save: If set, save the downloaded pack into .data/packs/[name].pack
	:param fallback: If set, use the latest available local version if the desired one fails for any reason.
	:return: A path to the temporary directory on success. Should be manually deleted later. None otherwise.
	"""
	enforce_version = version is not None
	archive = defined_archives_keil[family.upper()]

	if not enforce_version:
		logger.info(f"Getting version for {archive}")
		new_version = keil_get_version(family)
	else:
		logger.warning(f"\tEnforced version : {version}")
		new_version = version

	check_ok = new_version is not None
	if not check_ok :
		return None

	pack_filename = archive + new_version + ".pack"
	url = "https://keilpack.azureedge.net/pack/" + pack_filename

	temp_dir = tempfile.mkdtemp(prefix=f"SVD_RETR_Keil_{archive[:-1]}_")

	fallback_triggered = False
	with open(temp_dir + "/archive.zip","wb") as temp_archive :
		logger.info("Trying to download " + url + " ...")
		logger.debug("Temp path is " + temp_archive.name)

		try :
			with urllib.request.urlopen(url) as response :
				shutil.copyfileobj(response,temp_archive)
				logger.info("Download complete !")
		except urllib.error.HTTPError as err :
			logger.error(f"\tIssue when downloading {pack_filename} : HTTP {err.code} : {err.reason}")
			if fallback :
				local_pack = select_local_keil_pack(family)
				if local_pack is None :
					return None

				logger.info(f"Fallback triggered, using local pack {local_pack}")
				shutil.copy(local_pack,temp_archive.name)
				fallback_triggered = True

		if locally_save and not fallback_triggered:
			if not os.path.exists(f"{packs_path}/{pack_filename}") :
				logger.info(f"Copy {temp_archive.name} to local repository")
				shutil.copy(temp_dir + "/archive.zip",f"{packs_path}/{pack_filename}")
			else:
				logger.info(f"{pack_filename} already in local repository.")

	return temp_dir

def handle_keil_pack(path) :

	version_handler = configparser.ConfigParser()
	version_handler.read(config_file)
	family = file_to_family(path)
	temp_dir = os.path.dirname(path)
	file_name= os.path.basename(path)
	archive	 = str(file_name.rsplit(".",4)[0]) + "."
	version_string = ".".join(file_name.rsplit(".",4)[-4:-1])
	destination = file_path

	logger.info("Unzipping archive...")
	with zipfile.ZipFile(path) as zip_handler:
		zip_handler.extractall(temp_dir)
	logger.info("Done !")

	# Look for SVD files in the file tree
	svd_files = []
	for root, dirs, files in os.walk(temp_dir):
		for name in files:
			if fnmatch.fnmatch(name, "*.svd"):
				svd_files.append(os.path.join(root, name))
	logger.info("Found " + str(len(svd_files)) + " SVD file(s)")

	for file in svd_files:
		logger.info("\tRetrieving " + os.path.basename(file))
		shutil.copy(file, destination)

	logger.info(f"Looking for {temp_dir}/{archive}pdsc")
	if os.path.exists(temp_dir + "/" + archive + "pdsc"):
		logger.info("\tFileset found !")
		shutil.copy(temp_dir + "/" + archive + "pdsc", fileset_path)
	else:
		logger.warning("Fileset not found")

	version_handler["PackagesVersion"][family] = version_string
	version_handler["GENERAL"][
		"VersionHash"] = f'{hash(tuple([version_handler["PackagesVersion"][x] for x in sorted(version_handler[f"PackagesVersion"])])):X}'

	version_handler.write(open(config_file, "w"))
	return [os.path.basename(f) for f in svd_files]


# TODO Add documentation
def download_and_handle_keil(archive_arg : str, destination : str = file_path, versions_path : str = config_file, force = False):
	version_handler = configparser.ConfigParser()
	version_handler.read(versions_path)
	
	if "GENERAL" not in version_handler:
		version_handler["GENERAL"] = {"EnforceVersion":"0"}
		version_handler["PackagesVersion"] = {}

	enforce_version : bool = version_handler["GENERAL"].getboolean("EnforceVersion",False)
	base_url_check = "http://pack.keil.com/api/pack/check?pack="
	local_version = (0,0,0)
	if archive_arg in version_handler["PackagesVersion"] :
		local_version = version_cmp(version_handler["PackagesVersion"][archive_arg])
		logger.info(f"Found local version {version_cmp(version_handler['PackagesVersion'][archive_arg])}")
	else:
		logger.info(f"Creating record for {archive_arg}")
		version_handler["PackagesVersion"][archive_arg] = "0.0.0"
		
	if archive_arg.upper() in defined_archives_keil :
		archive = defined_archives_keil[archive_arg.upper()]
	
	url_check = base_url_check + archive + "1.0.0.pack"
	check_ok = False
	
	if not enforce_version :
		logger.info(f"Getting version for {archive}")
		try :
			with urllib.request.urlopen(url_check) as response :
				t = json.loads(response.read().decode())
				check_ok = t["Success"]
				new_version = t["LatestVersion"]
				
				version_handler["GENERAL"]["VersionHash"] = str(hash(tuple([version_handler["PackagesVersion"][x] for x in version_handler[f"PackagesVersion"]])))
				if not check_ok :
					logger.error(f"\tUnable to retrieve {archive}'s version value")
					
		except urllib.error.HTTPError as err:
			logger.error(f"HTTP Error {err.code} : {err.reason}")
	else:
		logger.warning(f"\tEnforced version due to {versions_path}")
	
	if not check_ok and local_version != (0,0,0) :
		new_version = ".".join([str(x) for x in local_version])
		logger.warning(f"\tUsing previous version {new_version}")
		check_ok = True
	
	if not check_ok and archive_arg.upper() in default_version_keil :
		new_version = default_version_keil[archive_arg]
		logger.warning(f"\tUsing provided fallback version {new_version}")
		check_ok = True
	
	if not check_ok :
		version_handler.write(open(versions_path, "w"))
		return list()
			
	url = "https://keilpack.azureedge.net/pack/" + archive + new_version + ".pack"
	
	if not force and local_version >= version_cmp(new_version) :
		logger.info(f"\tLocal version {'.'.join([str(x) for x in local_version])} is higher or equal to distant {new_version}.")
		version_handler.write(open(versions_path, "w"))
		return list()
	
	with tempfile.TemporaryDirectory(prefix=f"SVD_RETR_Keil_{archive[:-1]}_") as temp_dir :
		with open(temp_dir + "/archive.zip","wb") as temp_archive :
			logger.info("Trying to download " + url + " ...")
			logger.debug("Temp path is " + temp_archive.name)
			with urllib.request.urlopen(url) as response :
				shutil.copyfileobj(response,temp_archive)
				logger.info("Download complete !")
		
		logger.info("Unzipping archive...")
		with zipfile.ZipFile(temp_archive.name) as zip_handler :
			zip_handler.extractall(temp_dir)
		logger.info("Done !")
		
		#Look for SVD files in the file tree
		svd_files = []
		for root,dirs,files in os.walk(temp_dir) :
			for name in files :
				if fnmatch.fnmatch(name,"*.svd") :
					svd_files.append(os.path.join(root,name))
		logger.info("Found " + str(len(svd_files)) + " SVD file(s)")
		
		for file in svd_files :
			logger.info("\tRetrieving " + os.path.basename(file))
			shutil.copy(file,destination)
			
		logger.info(f"Looking for {temp_dir}/{archive}pdsc")
		if os.path.exists(temp_dir + "/"+archive + "pdsc") :
			logger.info("\tFileset found !")
			shutil.copy(temp_dir + "/"+archive + "pdsc",fileset_path)
		else :
			logger.warning("Fileset not found")

		version_handler["PackagesVersion"][archive_arg] = new_version
		version_handler["GENERAL"]["VersionHash"] = f'{hash(tuple([version_handler["PackagesVersion"][x] for x in sorted(version_handler[f"PackagesVersion"])])):X}'
		
		version_handler.write(open(versions_path,"w"))
		return [os.path.basename(f) for f in svd_files]



