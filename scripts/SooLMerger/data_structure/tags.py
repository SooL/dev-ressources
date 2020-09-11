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

import typing as T

class InvalidTagFormatError(RuntimeError):
	def __init__(self,message):
		super().__init__(message)


class SooLTag:
	exclude_boundaries = False

	def __init__(self,peripheral: str, name : str, is_start = False, is_stop = False ):
		self.peripheral = peripheral
		self.name : str = name
		self.__start: int = -1
		self.__stop : int = -1
		self.is_start_boundarie : bool = is_start
		self.is_stop_boundarie  : bool = is_stop
		self.indent : str = ""
	@classmethod
	def from_tag(cls,tag : str):
		tag.strip().upper()
		fields = tag.strip().upper().split("-")
		if not fields[0] == "//SOOL" :
			raise InvalidTagFormatError(f"Tag {tag} doesn't start with //SOOL")
		if fields[-1] not in ["BEGIN","END"] :
			return cls(fields[1],"-".join(fields[2:]))
		else :
			return cls(fields[1], "-".join(fields[2:-1]), is_start=fields[-1]=="BEGIN", is_stop=fields[-1] == "END")

	@property
	def flagtag(self) -> str:
		return f"//SOOL-{self.peripheral}-{self.name}"

	@property
	def starttag(self) -> str:
		return f"//SOOL-{self.peripheral}-{self.name}-BEGIN"

	@property
	def stoptag(self) -> str:
		return f"//SOOL-{self.peripheral}-{self.name}-END"

	@property
	def start(self) -> int:
		return self.__start
	@start.setter
	def start(self,v):
		self.__start = v + (1 if self.exclude_boundaries else 0)

	@property
	def stop(self) -> int:
		return self.__stop

	@stop.setter
	def stop(self,v):
		self.__stop = v + (1 if not self.exclude_boundaries else 0)

	def set_flagtag_position(self,pos : int):
		self.__start = pos
		self.__stop = pos