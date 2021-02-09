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
import re
import os
from copy import copy
import logging

logger = logging.getLogger()


class CMSISRegister:
	def __init__(self):
		self.name : str 		= None
		self.array_size : int 	= 1
		self.element_size : int = 32
		self.comment : str = None
		self.type : str = None
		self.access_type= "IO"
		self.parent = None
		
		self.bit_offset = 0
		"""Register bit_offset, in bits"""

	@property
	def byte_offset(self):
		return int(self.bit_offset / 8)

	def apply_corrector(self, parent_corrector) :
		correctors = parent_corrector[self.name]
		for corrector in correctors :
			corrector(self)


class CMSISPeripheral:
	def __init__(self, parent: "CMSISHeader", name : str= None):
		self.registers : T.List[CMSISRegister] = list()
		self.parent = parent
		self.name : str = name

	@property
	def bit_size(self):
		return sum([x.array_size * x.element_size for x in self.registers])
	
	def compute_offset(self):
		i = 0
		for reg in self.registers :
			reg.bit_offset = i
			i += reg.array_size * reg.element_size

	def apply_corrector(self, root_corrector) :
		correctors = root_corrector[self.name]
		for corrector in correctors :
			for reg in self.registers :
				reg.apply_corrector(corrector)
			corrector(self)

	def __contains__(self, item:str):
		if isinstance(item, str) :
			for reg in self.registers :
				if reg.name == item :
					return True
			return False
		else :
			raise TypeError()

	def __getitem__(self, item: str):
		if isinstance(item, str) :
			for reg in self.registers :
				if reg.name == item :
					return reg
			raise KeyError()
		else :
			raise TypeError()



class CMSISHeader:
	"""This object provides a handler for CMSIS headers.

	You might use read, process functions and then directly access processed data though direct access members.

	Examples
	=======
	The typical use example would be
	::
		h = CMSISHeader("path/to/cmsis_header.h")
		h.read()
		h.process_irq_table()
		h.process_memory_table()
		h.process_peripheral()
		h.clean()

		some_stuff(h.irq_table)
	"""
	def __init__(self,path : str ):
		self.content_cmsis_data : bool = False
		self.path = path
		
		self.irq_table 		: T.Dict[str,int] 			  = None
		"""Processed IRQ table, name to value mapping"""
		self.periph_table	: T.Dict[str,CMSISPeripheral] = None
		"""Processed peripheral table, name to CMSIS peripheral mapping."""
		self.include_table	: T.Dict[str, str] 			  = None
		"""Processed include table, chip define to valid file path"""
		self.memory_table	: T.Dict[str,int] 			  = None
		"""Processed memory table, memory define to integer memory address."""
		self.cmsis_conf		: T.Dict[str, int] 			  = None
		"""Processed CMSIS configuration section. Define to data"""


		self.raw_irq_table 	: str 			= None
		self.raw_includes	: str 			= None
		self.raw_peripheral : T.List[str] 	= None
		self.raw_memory 	: str 			= None
		self.raw_cmsis_conf : str			= None

	@property
	def file_name(self) -> str:
		idx = self.path.rindex('/')
		return self.path if idx == -1 else self.path[idx+1:]

	@property
	def is_structural(self) -> bool:
		"""
		:return: Return the fact that this CMSIS header contains a raw definition of the structure of peripherals.
		"""
		return self.raw_peripheral is not None or self.periph_table is not None
	
	@property
	def is_irq(self):
		"""
		:return: Return the fact that this CMSIS header contains a raw definition of the IRQ table.
		"""
		return self.raw_irq_table is not None or self.irq_table is not None
	
	@property
	def is_include_map(self):
		"""
		:return: Return the fact that this CMSIS header contains a raw Include list that points to other stuff.
		"""
		return self.raw_includes is not None or self.include_table is not None

	def read(self):
		"""
		This function will read the provided file and extract if possible the raw data sections.
		In order to use those values, an explicit call to processing functions must be done.

		.. seealso:: clean
		"""
		with open(self.path,"r",encoding="latin-1") as f :
			data = f.read()

		start = data.find("@addtogroup Configuration_section_for_CMSIS")
		# L5 inconsistency workaround :
		if start == -1 :
			start = data.find("@addtogroup Configuration_of_CMSIS")
		if start != -1 :
			end = data.find("@}",start)
			self.raw_cmsis_conf = data[start:end]

		end = data.rfind("IRQn_Type;")
		if end != -1 :
			start = data.rfind("enum",0,end)
			self.raw_irq_table = data[start:end]

		start = 0
		while True :
			start = data.find("typedef struct",start+1)
			if start == -1 :
				break
			if self.raw_peripheral is None :
				self.raw_peripheral = list()
			end = data.find("}", start)
			end = data.find("_TypeDef",end)
			self.raw_peripheral.append(data[start:end])
			
		start = data.find("@addtogroup Device_Included")
		if start != -1 :
			end = data.find("@}",start)
			self.raw_includes = data[start:end]
		
		start = data.find("@addtogroup Peripheral_memory_map")
		if start != -1 :
			end = data.find("@}", start)
			self.raw_memory = data[start:end]

	def extend_read(self):
		"""
		This function will read the provided file and extract if possible the raw data sections.
		In order to use those values, an explicit call to processing functions must be done.

		.. seealso:: clean
		"""
		with open(self.path,"r",encoding="latin-1") as f :
			data = f.read()

		start = data.find("#define __")
		stop = data.find("\n",data.rfind("#define __"))
		addendum = data[start:stop]
		self.raw_cmsis_conf += "\n" + addendum

	def clean(self):
		"""
		Remove all raw data to gain memory space and eventually ease data transfer.

		This function will *not* empty processed data structures.
		"""
		self.raw_irq_table 	= None
		self.raw_peripheral = None
		self.raw_includes 	= None
		self.raw_memory 	= None

	def process_include_table(self):
		"""
		This function process the include data in order to fill the include_table.

		If the raw data have not been processed already, this function will have no effect.
		"""
		if self.raw_includes is None :
			return
		
		self.include_table = dict()
		ifdef_rexp = re.compile(r"\#(?:el)?if\s+defined\s*\(\s*(?P<define>\w+)\)")
		include_rexp = re.compile(r"\#include\s+\"(?P<file>\w+\.h)\"")
		
		define = None
		filename= None
		for line in [x.strip(None) for x in self.raw_includes.split("\n")] :
			if define is None :
				result = ifdef_rexp.search(line)
				if result :
					define = result["define"].replace("X","x")
					#Reset the file name for each new define
					filename = None
				else:
					continue
			elif filename is None :
				result = include_rexp.search(line)
				if result :
					filename = result["file"]
					self.include_table[define] = f"{os.path.dirname(self.path)}/{filename}"
					define = None
	
	def process_memory_table(self):
		"""
		This function process the memory definition data in order to fill the memory_table.

		If the raw data have not been processed already, this function will have no effect.
		"""
		if self.raw_memory is None :
			return
		self.memory_table = dict()
		irq_mem = re.compile(r"\#define\s+(?P<name>\w+)\s+\(?(?P<type>\(\s*[^()]+\s*\)\s*)?\(?(?P<val>(?:[^ )\n]+\s*\+\s*)*[^ )\n]+)\)?")
		
		for line in [x.strip() for x in self.raw_memory.split("\n")]:
			if line == str():
				continue
			
			result = irq_mem.search(line)
			if result :
				data = result.groupdict()
				name = data["name"]
				value= data["val"]
				interpreted_values = list()
				val_fields = [x for x in value.split(None) if x != "+"]
				for f in val_fields :
					if f in self.memory_table :
						interpreted_values.append(self.memory_table[f])
					else :
						#Should be an integer
						try :
							interpreted_values.append(int(f.strip("L").strip("U"),0))
						except ValueError :
							logger.error(f"Failed to interpret memory field named {name} for file {os.path.basename(self.path)}.")
						
				self.memory_table[name] = sum(interpreted_values)
	
	def process_irq_table(self):
		"""
		This function process the IRQ table data in order to fill the irq_table.

		If the raw data have not been processed already, this function will have no effect.
		"""
		if self.raw_irq_table is None:
			return
		self.irq_table = dict()
		irq_rexp = re.compile(r"(?P<id>\S+)\s+=\s+(?P<val>-?\d+)\s*,?\s*(?P<comment>.+)?")


		for line in [x.strip() for x in self.raw_irq_table.split("\n")] :
			if line == str() :
				continue

			result = irq_rexp.search(line)
			if result :
				data = result.groupdict()
				self.irq_table[data["id"]] = int(data["val"])
			else :
				if not ( "enum" in line or "/*" in line or "{" in line or "}" in line or "MAX_IRQ_n" in line) :
					logger.warning(f"IRQ line match failure: {line}")

	def process_cmsis_conf(self):
		"""
		This function process the CMSIS section in order to retrieve all options.
		"""

		regex = re.compile(r"\#(?P<command>\w+)\s+(?P<name>(?:\w+))\s+(?P<val>(?:0x)?\d+)?")

		if self.raw_cmsis_conf is None or len(self.raw_cmsis_conf) == 0:
			logger.error(f"Analyze of an empty CMSIS conf for {os.path.basename(self.path)}")
			return
		if self.cmsis_conf is None :
			self.cmsis_conf = dict()

		for line in [x.strip() for x in self.raw_cmsis_conf.split("\n")]:
			if line == str():
				continue

			result = regex.search(line)
			if result:
				if result["command"] != "define" :
					logger.error(f"Found {result['command']} statement while parsing CMSIS conf in {os.path.basename(self.path)}")
					continue
				else :
					self.cmsis_conf[result["name"]] = int(result["val"],0) if result["val"] is not None else ""

	def process_peripheral_definition(self):
		"""
		This function process the peripheral definitions data in order to fill the peripheral_table.

		If the raw data have not been processed already, this function will have no effect.
		"""
		if self.raw_peripheral is None or len(self.raw_peripheral) == 0:
			return
		if self.periph_table is None :
			self.periph_table = dict()
		periph_rexp = re.compile(r"(?:__(?P<io>[IO]{1,2})\s+)?(?P<type>u?int(?P<int_size>\d+)_t|\w+)\s+(?P<name>\w*)(?:\[(?P<arr_size>\d+)\])?\s*;\s*(?:\*(?:!<)?(?P<com>.+)\*)?")
		
		for raw in self.raw_peripheral :
			new_peripheral = CMSISPeripheral(self)
			for line in [x.strip() for x in raw.split("\n")]:
				if line == str():
					continue

				result = periph_rexp.search(line)
				if result :
					new_register = CMSISRegister()
					data = result.groupdict()
					new_register.access_type = data["io"]
					new_register.name		 = data["name"]
					new_register.array_size	 = int(data["arr_size"]) if data["arr_size"] is not None else 1
					new_register.type		 = data["type"]
					new_register.comment	 = data["com"]
					new_register.parent = new_peripheral
					
					new_register.element_size = int(data["int_size"]) if data["int_size"] is not None else self.periph_table[data["type"].strip("_TypeDef")].bit_size
					new_peripheral.registers.append(new_register)
				elif line[0] == "}":
					new_peripheral.name = line[1:].strip(None)

			new_peripheral.compute_offset()
			self.periph_table[new_peripheral.name] = new_peripheral

	def process_structural(self):
		self.process_memory_table()
		self.process_irq_table()
		self.process_peripheral_definition()
		self.process_cmsis_conf()
		if len(self.cmsis_conf) == 0 :
			logger.warning(f"Extended read required for {self.file_name}")
			self.extend_read()
			self.process_cmsis_conf()

	def apply_corrector(self, root_corrector):
		for periph in self.periph_table.values() :
			periph.apply_corrector(root_corrector)
