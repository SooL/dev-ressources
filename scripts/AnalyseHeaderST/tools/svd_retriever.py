#!/usr/bin/python3
# -*-coding:utf-8 -*

import logging
import os, fnmatch
import shutil
import urllib.request
import tempfile
import zipfile
import typing as T

logger = logging.getLogger()
base_url = "https://www.st.com/resource/en/svd"
file_path = "./.data/"

defined_archives = {
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


def init():
	"""
	This function will re-init the data folder for svd storage.
	:return:
	"""
	logger.info("Re-init data folder")
	if os.path.exists(file_path) :
		logger.warning("Delete" + os.path.realpath(file_path))
		shutil.rmtree(file_path)
	os.mkdir(file_path)


def download_and_handle(archive : str, destination : str = file_path) -> T.List[str]:
	"""
	This function will download the archive corresponding to archive, extract all .svd files
	and put them whithin the destination folder.
	
	:param archive: Archive designator. Either alias as defined in defined_archives or directly a .zip file
	:param destination: Destination folder
	:return: List of all .svd files
	"""
	if archive.upper() in defined_archives :
		archive = defined_archives[archive.upper()]
	url = base_url + "/" + archive

	#Create a temporary directory, download the .zip, extract it and retrieve files
	with tempfile.TemporaryDirectory(prefix="SVD_RETR_") as temp_dir :
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
			shutil.move(file,destination)

		return [os.path.basename(f) for f in svd_files]






