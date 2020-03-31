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
from fnmatch import fnmatch


# noinspection PyUnresolvedReferences
def GPIO_field_cleaner(field : "Field", ):
	reg = field.parent.parent
	if reg.name == "OSPEEDR"    : field.name = f"OSPEED{int(field.position / field.size)}"
	elif reg.name == "MODER"    : field.name = f"MODE{  int(field.position / field.size)}"
	elif reg.name == "IDR"      : field.name = f"ID{    int(field.position / field.size)}"
	elif reg.name == "ODR"      : field.name = f"OD{    int(field.position / field.size)}"
	elif reg.name == "PUPDR"    : field.name = f"PUPD{  int(field.position / field.size)}"
	elif reg.name == "AFRH"     : field.name = f"AFSEL{ int((field.position +32) / field.size)}"
	elif reg.name == "AFRL"     : field.name = f"AFSEL{ int(field.position / field.size)}"

	if field.brief is not None :
		field.brief = field.brief\
			.replace(" (y = 0..15)", "")\
			.replace(" (y = 0..7)", "")\
			.replace(" (y = 8..15)", "")\
			.replace("These bits are ", "")
