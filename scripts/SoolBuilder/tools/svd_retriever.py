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
logger = logging.getLogger()
file_path = "./.data/svd"
fileset_path = "./.data/fileset"

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
#	"STM32MP1" : "Keil.STM32MP1xx_DFP.",
	"STM32G0"  : "Keil.STM32G0xx_DFP.",
	"STM32G4"  : "Keil.STM32G4xx_DFP.",
#	"STM32W1"  : "Keil.STM32W1xx_DFP.",
	"STM32WB"  : "Keil.STM32WBxx_DFP."
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


def download_and_handle_keil(archive : str, destination : str = file_path):
	
	base_url_check = "http://pack.keil.com/api/pack/check?pack="
	
	if archive.upper() in defined_archives_keil :
		archive = defined_archives_keil[archive.upper()]
	
	url_check = base_url_check + archive + "1.0.0.pack"
	check_ok = False
	
	logger.info(f"Getting version for {archive}")
	try :
		with urllib.request.urlopen(url_check) as response :
			t = json.loads(response.read().decode())
			check_ok = t["Success"]
			new_version = t["LatestVersion"]
			
			if not check_ok :
				logger.error(f"Unable to retrieve {archive}'s version value")
				return list()
			else :
				url = "https://keilpack.azureedge.net/pack/" + archive + new_version + ".pack"
			
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
				
				return [os.path.basename(f) for f in svd_files]
	
	except urllib.error.HTTPError as err :
		logger.error(f"HTTP Error {err.code} : {err.reason}")
		return list()




