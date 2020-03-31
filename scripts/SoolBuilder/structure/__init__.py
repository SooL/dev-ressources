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

# Reminder : import variables and such before importing a module which may import it from here
from structure.utils import get_node_text, TabManager, default_tabmanager, fill_periph_hole
from structure.chipset import ChipSet, Chip
from structure.component import Component
from structure.field import Field
from structure.registervariant import RegisterVariant
from structure.register import Register
from structure.mappingelement import MappingElement
from structure.peripheralmapping import PeripheralMapping
from structure.peripheralinstance import PeripheralInstance
from structure.peripheraltemplate import PeripheralTemplate
from structure.peripheral import Peripheral
from structure.group import Group
