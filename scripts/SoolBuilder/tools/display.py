#!/usr/bin/python3
#-*-coding:utf-8 -*

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

def display(obj, order = True) :
	out = ""
	if type(obj) == type(list()) :
		if order :
			for e in sorted(obj) :
				out += e + "\n"
		else :
			for e in obj :
				out += e + "\n"
	
	if type(obj) == type(dict()) :
		if order :
			for k in sorted(obj.keys()) :
				if type(obj[k]) == type (list()) :
					for v in sorted(obj[k]) :
						out += k + " \t=" + v + "\n"
				else :
					out += str(k) + " \t= " + str(obj[k]) + "\n"
					
	print(out)

def toBin(val : int,  lenght = int(0)) :
	out = ""
	tempValue = val
	while tempValue > 0 :
		out += "1" if tempValue & 1 else "0"
		tempValue >>= 1
		
	while lenght > len(out) :
		out += "0"
	
	if lenght <= 0 : lenght = len(out)
	return out[::-1][0:lenght]

def lenAdj(txt,fullLen : int,fill = ' ') :
	txt = str(txt)
	if len(txt) > fullLen :
		raise RuntimeError("Length of " + txt + " (" + str(len(txt)) +") superior to fullLen (" + str(fullLen) + ")")

	txt += fill * (fullLen - len(txt))
	return txt
