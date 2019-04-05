from typing import Union, Dict, List, Tuple

from tools.utils import ChipSeriesManager


class Component:
	"""
	Base class for Peripherals, Instances, Specifications, Registers, Mappings, Fields, Variants
	"""

# ________________________________________________________________________________________________Constructor, accessors

	def __init__(self, name: Union[None, str], chips: ChipSeriesManager):
		"""
		Creates the Component with the specified name for the specified chips

		:param name: name of the component
		:param chips: chips for which the component is defined

			parent : the parent component, or None if it is a root component
			brief : a small description of the component that will be written inline with its declaration
		"""

		self.name: Union[str, None] = name
		"""Name of the component, or None if the component has no name"""
		self.chips: ChipSeriesManager = chips
		"""A ChipManager containing all chips for which the component is defined"""
		self.parent: Union[Component, None] = None
		"""The parent component, or None if it is a root component"""
		self.brief: Union[str, None] = None
		"""A small description of the component that will be written with its declaration"""
		self.defined = False
		"""Set to true if the 'define()' function gets called"""

	def set_parent(self, parent: "Component"):
		"""
		Sets the parent of the component.

		:param parent: parent of the Component
		:return: None
		"""
		self.parent = parent

	def set_brief(self, brief: str):
		"""
		Sets the description of the component.

		:param brief: description of the Component
		:return: None
		"""
		self.brief = brief

	def alias(self) -> str:
		"""
		return the alias name of the component. This i_s the name that will be used for preprocessor constants
		:return: the alias of the component
		"""
		parent_alias = "" if self.parent is None else self.parent.alias()
		if self.name is None:
			return parent_alias
		elif len(parent_alias) > 1:
			return parent_alias + '_' + self.name
		else:
			return self.name
# ________________________________________________________________________________________definition, declaration, usage

	def define(self)->Union[str, None]:
		"""
		Sets the 'defined' attribute to True, and return the '#define {}' string
		to define the component if necessary

		:return: the "#define {}" line necessary to define the component,
		        or None if the component must not be defined before usage
		"""
		self.defined = True
		return "#define " + self.alias()

	def no_define(self)->Union[str, None]:
		"""
		:return: the "#define {}" line necessary in the "#else" to define the absence of the component,
		        or None if the component's absence needs not to be specified.
		"""
		return None

	def undefine(self)->Union[str, None]:
		"""
		:return: the "#undef {}" line necessary to undefine the component,
		        or None if the component must not be undefined
		"""
		return None

	def need_define(self)->bool:
		"""
		:return: True if the component needs a "#define {}" line
		"""
		return (self.chips.is_all_chips()) if (self.parent is None) else (self.chips != self.parent.chips)

	def define_condition(self)->str:
		"""
		:return: the condition to
		"""
		return self.chips.output_condition()

	def add_to_define_dict(self, define_dict: Dict[str, List[Tuple[str, str]]], undef: str):
		"""
		adds the definition and the "no-definition" to the dictionary, with the definition condition as the key

		:param define_dict: the dictionary to fill
		:param undef: string that will be added at the end of the file to undefine all preprocessor constants,
		        to avoid pollution
		:return: None
		"""
		if self.need_define():
			key = self.define_condition()
			if define_dict[key] is None:
				define_dict[key] = list()
			define_dict[key].append((self.define(), self.no_define()))

			self_undef = self.undefine()
			if self_undef is not None:
				undef += self_undef

	def declare(self)->Union[str, None]:
		"""
		:return: the declaration of the component, or None if the component must not be declared prior usage
		"""
		return None

	def use(self, name: str)->Union[str, None]:
		"""
		:param name: name of the variable. None if no variable are declared here
		:return: the usage of the component (declares an instance of it),
		        or None if the component must not be declared
		"""
		return None

# _________________________________________________________________________________________________________________build

	def finalize(self):
		"""
		Check if everything is as expected, and make optimizations if possible
		:return:None
		"""
		self.chips.build_chip_family()
		ChipSeriesManager.get_full_chips().simplify(self.chips)

	def merge(self, other: "Component"):
		"""
		Adds the chips of the other component to this component's chips, only if thay are the same components
		(same type, name and parent component)

		Raise an error if the components are different in type, name or parent.

		Warns if the descriptions are different

		:param other: other component to copy the chips from
		:return: None
		"""
		if self != other:
			raise Exception(f"{type(self)} {self.alias()} cannot be merged with {type(other)} {other.alias()}")
		elif self.brief != other.brief:
			""  # TODO log : description are not the same

		self.chips.merge(other.chips)
# _____________________________________________________________________________________________________________operators

	def __eq__(self, other):
		"""
		:param other: other component
		:return: True if the other component is of the same type and has the same name.
				Doesn't care about parent, chips and brief
		"""
		return type(self) == type(other) and self.name == other.name

	def __str__(self):
		"""
		:return: the alias of the component
		"""
		return self.alias()
