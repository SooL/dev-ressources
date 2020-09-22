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

import inspect
import xml.etree.ElementTree as ET
import typing as T
import random
import logging
import os
logger = logging.getLogger()


class Entry:

	@classmethod
	def from_xml(cls, xml : ET.Element):
		ret = cls(xml.text)
		ret.file = xml.attrib["file"]
		ret.line = int(xml.attrib["line"])
		ret.count= int(xml.attrib["count"])
		ret.waived=xml.attrib["waived"] == "True"

		return ret

	def __init__(self, message, category = None, unique = False):
		self.msg = message
		self.category = category

		self.file = None
		self.line = None

		self.count= 1
		self.waived = False

	def __hash__(self):
		return hash((self.msg,self.category,self.file,self.line))

	@property
	def identifier(self) -> int :
		return hash(self)

	@property
	def xml(self) -> ET.Element:
		elt = ET.Element("entry",file=self.file,line=str(self.line),count=str(self.count),waived=str(self.waived))
		elt.text = self.msg
		return elt


class Reporter:
	def __init__(self):
		self.records : T.Dict[str,T.List[Entry]] = dict()
		self.waived : T.Set[int] = set()

	def log(self,category,message,unique = False, addstack = 1):
		entry = Entry(message,category,unique)
		stack = inspect.stack()[addstack] # The caller
		entry.file = os.path.basename(stack.filename)
		entry.line = stack.lineno
		if entry.identifier in self.waived :
			return None
		if category not in self.records :
			self.records[category] = list()
			self.records[category].append(entry)
			return entry
		if unique :
			self.records[category].append(entry)
		else :
			try :
				i = self.records[category].index(entry)
			except ValueError :
				self.records[category].append(entry)
			else :
				self.records[category][i].count += 1

		return entry

	def process_waived(self):
		for cat in self.records :
			for entry in self.records[cat] :
				if entry.waived :
					self.waived.add(entry.identifier)

	@property
	def xml(self):
		root = ET.Element("report")
		for cat in self.records :
			cat_root : ET.Element = ET.SubElement(root,"category",name=cat)
			for entry in self.records[cat]:
				cat_root.append(entry.xml)
		return root

	def read_xml(self, path : str):
		root = ET.parse(path).getroot()
		for cat in root.findall("category") :
			category = cat.attrib["name"]
			if category not in self.records :
				self.records[category] = list()
			for elt in cat.findall("entry") :
				self.records[category].append(Entry.from_xml(elt))
		self.process_waived()

	def info(self, category, message, unique=False):
		if self.log(category, message, unique,addstack=2) is not None :
			logger.info(message)

	def warning(self, category, message, unique=False, ):
		if self.log(category, message, unique,addstack=2) is not None:
			logger.warning(message)

	def error(self, category, message, unique=False):
		if self.log(category, message, unique,addstack=2) is not None:
			logger.error(message)

main_reporter = Reporter()

