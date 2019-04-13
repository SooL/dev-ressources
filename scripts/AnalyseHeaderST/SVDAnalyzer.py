
import xml.etree.ElementTree as ET
from typing import List, Dict

from numpy.distutils.misc_util import get_frame

from structure.Peripheral import Peripheral
from structure.Group import Group
import re


def get_node_text(root : ET.Element, node : str) -> str :
	return str() if root.find(node) is None else root.find(node).text


periph_name_mapping_dict: Dict[str, Dict[str, str]] = { # group -> (instance_name -> periph_name). Default : periph name is group name
	'ADC' : {
		'ADC' : 'ADC_Common',
		'ADC\d\d+' : 'ADC_Common',
	},
}


def node_to_Periph(group, instance_name, description, chips) -> Peripheral:

	# By default, the name of the peripheral is the name of the group
	periph_name: str = group.name

	# Make 1st step correction :
	if group.name in periph_name_mapping_dict.keys():
		for key in periph_name_mapping_dict[group.name]:
			if re.match(key, instance_name):
				periph_name = periph_name_mapping_dict[group.name][key]

	# TODO make other corrections (like specializations)

	# Create the peripheral
	periph = Peripheral(periph_name, chips)
	periph.set_brief(description)

	# Add the new peripheral to the group
	group.add_peripheral(periph)

def create_register

def analyze_svd(root_element: ET.Element) -> Dict[str, Group] :

	chip_name = get_node_text(root_element, "name")

	chips = chip_name  # TODO create chips object

	out: Dict[str, Group] = dict()

	# Iterate over all <peripheral> node
	for periph_node in root_element.findall("peripherals/peripheral"):
		instance_name = get_node_text(periph_node, 'name')

		# If the peripheral is not an instance, create it
		if "derivedForm" not in periph_node.attrib.keys():

			group_name = get_node_text(periph_node, "groupName")
			description = get_node_text(periph_node, "description")

			# Get the group in which the peripheral will be created. Create it if it doesn"t exist yet
			group = Group(group_name, chips) if (group_name not in out.keys()) else out[group_name]

			# Create the peripheral
			periph = node_to_Periph(group, instance_name, description, chips)

			for reg_node in periph_node.findall("registers/register"):
				reg_name = get_node_text(reg_node, "name")
				reg_disp = get_node_text(reg_node, "displayName")
				reg_descr = get_node_text(reg_node, "description")
				reg_offset = get_node_text(reg_node, "addressOffset")
				reg_size = get_node_text(reg_node, "size")
				reg_access = get_node_text(reg_node, "access")
				reg_rst = get_node_text(reg_node, "resetValue")

				for svd_field in reg_node.findall("fields/field"):
					field_name = get_node_text(svd_field, "name")
					field_descr = get_node_text(svd_field, "description")
					field_offset = get_node_text(svd_field, "bitOffset")
					field_width = get_node_text(svd_field, "bitWidth")

					print(instance_name, reg_name, field_name)


	return out
