

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

from .utils import *

full: ChipSeriesManager = None

def log_init(all_chips: ChipSeriesManager):
	global full
	full = all_chips

class Message :
	def __init__(self,code,message,csm : ChipSeriesManager()):
		self.code = copy(code)
		self.message = copy(message)
		self.chips : ChipSeriesManager = ChipSeriesManager(csm.chip_list)
		self.occurrence = 1
		
	def __hash__(self):
		return hash((self.code,self.message))
	
	def __gt__(self, other):
		if isinstance(other, Message) :
			if self.code != other.code :
				return self.code > other.code
			
			else : return self.message > other.message
	
	def __eq__(self, other):
		return  (self.code == other.code
				and self.message == other.message)
	
	def __str__(self):
		full.simplify(self.chips)
		return "{0.occurrence:4d} {0.code:30s} {0.message:50s} {1}".format(self, str(self.chips))

	def key(self):
		return self.code + self.message

log_dict : Dict[str,Message] = dict()

def log(code : str,msg : str,chips : ChipSeriesManager = ChipSeriesManager()) :
	global log_dict
	message = Message(code,msg,chips)
	if message.key() in log_dict :
		log_dict[message.key()].chips.merge(message.chips)
		log_dict[message.key()].occurrence += 1
	else :
		log_dict[message.key()] = copy(message)

def output_log() :
	global log_dict
	out = ""
	for key in sorted(log_dict.keys(),key=(lambda x : log_dict[x])) :
		out += str(log_dict[key]) + "\n"
	return out
	