# ******************************************************************************
#  Copyright (c) 2018-2020 FAUCHER Julien & FRANCE Loic.                       *
#                                                                              *
#  This file is part of SooL generator.                                        *
#                                                                              *
#  SooL generator is free software: you can redistribute it and/or modify      *
#  it under the terms of the GNU Lesser General Public License                 *
#  as published by the Free Software Foundation, either version 3              *
#  of the License, or (at your option) any later version.                      *
#                                                                              *
#  SooL core Library is distributed in the hope that it will be useful,        *
#  but WITHOUT ANY WARRANTY; without even the implied warranty of              *
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                *
#  GNU Lesser General Public License for more details.                         *
#                                                                              *
#  You should have received a copy of the GNU Lesser General Public License    *
#  along with SooL core Library. If not, see  <https://www.gnu.org/licenses/>. *
# ******************************************************************************

import logging
import os
import shutil
import tempfile
import zipfile
import typing as T
import urllib.request
import urllib.error
import json

from ..tools import global_parameters

logger = logging.getLogger()


class VersionUnavailableError(RuntimeError):
	def __init__(self,msg):
		super().__init__(msg)
		logger.error(msg)


class OnlineVersionUnavailableError(VersionUnavailableError):
	def __init__(self,msg):
		super().__init__(msg)


class DefaultVersionUnavailableError(VersionUnavailableError):
	def __init__(self,msg):
		super().__init__(msg)


class DownloadFailedError(RuntimeError):
	def __init__(self,msg):
		super().__init__(msg)
		logger.error(msg)


class UnextractedPDSCError(RuntimeError):
	def __init__(self,msg):
		super().__init__(msg)
		logger.error(msg)

class KeilUnpackingError(RuntimeError):
	def __init__(self,msg):
		super().__init__(msg)
		logger.error(msg)


class InvalidKeilPackError(RuntimeError):
	def __init__(self,msg):
		super().__init__(msg)
		logger.error(msg)


class KeilPack:
	@classmethod
	def from_path(cls, src : str):
		if not os.path.isfile(src) :
			raise InvalidKeilPackError(f"Pack archive {src} does not exists or is not a file")
		filename = os.path.basename(src)
		path = os.path.dirname(os.path.abspath(src))
		fields = filename.split(".")

		family = None
		for f, archive in global_parameters.defined_keil_archive.items() :
			if filename.startswith(archive) :
				family = f
				break

		if family is None :
			raise InvalidKeilPackError(f"{filename} is not a registered valid archive name.")

		ret = cls(family)
		ret.version = ".".join(fields[-4:-1])
		ret.location = path
		return ret

	def __init__(self, family : str):
		self.family = family.upper()
		self.archive_basename = global_parameters.defined_keil_archive[self.family]
		self.version 		: str = "0.0.0"
		self.location 		: str = None
		self.extracted_path : str = None
		self.__pdsc_path 	: str = None

	def get_online_version(self):
		base_url_check = "http://pack.keil.com/api/pack/check?pack="


		url_check = base_url_check + self.archive_basename + "1.0.0.pack"

		try:
			with urllib.request.urlopen(url_check) as response:
				t = json.loads(response.read().decode())
				check_ok = t["Success"]
				new_version = t["LatestVersion"]

				if not check_ok:
					raise OnlineVersionUnavailableError(f"\tUnable to retrieve {self.archive_basename}'s version value")

		except urllib.error.HTTPError as err:
			raise OnlineVersionUnavailableError(f"Unable to retrieve {self.archive_basename}'s version : HTTP Error {err.code} : {err.reason}")

		self.version = new_version

	def get_default_version(self):
		if self.family not in global_parameters.default_archives_version :
			raise DefaultVersionUnavailableError(f"Default version not available for family {self.family}")
		self.family = global_parameters.default_archives_version

	def setup_version(self):
		try :
			self.get_online_version()
		except OnlineVersionUnavailableError :
			self.get_default_version()

	@property
	def pack_filename(self) -> str:
		return f"{self.archive_basename}{self.version}.pack"

	@property
	def full_path(self) -> str:
		return f"{self.location}/{self.pack_filename}"

	def download_to(self, path = None):
		url = "https://keilpack.azureedge.net/pack/" + self.pack_filename

		destination = path if path is not None else tempfile.mkdtemp(prefix=f"SVD_RETR_Keil_{self.archive_basename[:-1]}_")
		with open(destination + f"/{self.pack_filename}", "wb") as temp_archive:
			logger.info("Trying to download " + url + " ...")
			logger.debug("Temp path is " + temp_archive.name)

			try:
				with urllib.request.urlopen(url) as response:
					shutil.copyfileobj(response, temp_archive)
					logger.info("Download complete !")
			except urllib.error.HTTPError as err:
				raise DownloadFailedError(f"\tIssue when downloading {self.archive_basename} : HTTP {err.code} : {err.reason}")

		self.location = os.path.abspath(destination)

	def extract_to(self, destination = None) -> T.Optional[str]:
		if destination is None :
			destination = os.path.dirname(global_parameters.pack_path) + "/temp_extract"
			shutil.rmtree(destination, True)
			os.mkdir(destination)

		shutil.copy(self.full_path, f"{destination}/{global_parameters.pack_name}.zip")
		logger.info("Unzipping archive...")
		with zipfile.ZipFile(f"{destination}/{global_parameters.pack_name}.zip") as zip_handler:
			zip_handler.extractall(destination)
			self.extracted_path = destination

		if os.path.exists(f"{destination}/{global_parameters.pack_name}.pdsc") :
			self.__pdsc_path = os.path.abspath(f"{destination}/{global_parameters.pack_name}.pdsc")
		else:
			raise KeilUnpackingError(f"PDSC File {destination}/{global_parameters.pack_name}.pdsc not found.")


	@property
	def pdsc_path(self) -> str:
		if self.__pdsc_path is None :
			raise UnextractedPDSCError("Trying to access to a PDSC file which have not been extracted")
		return self.__pdsc_path



