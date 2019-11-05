import xml.etree.ElementTree as ET
import typing as T


#from structure import ChipSet


def get_node_text(root : ET.Element, node : str) -> str :
	return str() if root.find(node) is None else root.find(node).text

def fill_periph_hole(size: int, prefix: str = "", sep: str = "", suffix: str = "") -> str :
	s: int = 1
	pos: int = 0
	out = ""

	while size > 0 :
		if size & 1 :
			out += f"{prefix if pos == 0 else sep}__SOOL_PERIPH_PADDING_{2**pos}"
		pos += 1
		size >>= 1

	# while pos < size :
	# 	s = 1
	# 	while (size - pos) % s == 0 :
	# 		s *= 2
	# 	s /= 2
	# 	out += f"{prefix if pos == 0 else sep}__SOOL_PERIPH_PADDING_{int(s)}"
	# 	pos += s
	if pos > 0 :
		out += suffix
	return out

class TabManager :
	def __init__(self):
		self.level : int = 0
		self.char : str = "\t"
		self.multiple: int = 1

	def __iadd__(self, other):
		if isinstance(other, int) :
			if self.level + other < 0 :
				raise ValueError("Tab level should always be positive or equal to zero")
			else :
				self.level += other
		else :
			raise TypeError("Can only add integers")

	def __isub__(self, other):
		self.__iadd__(-other)

	def __add__(self, other) -> str:
		if isinstance(other, int) :
			if self.level + other < 0:
				raise ValueError("Tab level should always be positive or equal to zero")
			else :
				return (self.level + other)*self.multiple*self.char
		else:
			raise TypeError("Can only add integers")

	def __sub__(self, other):
		return self.__add__(-other)

	def __str__(self):
		return self.level*self.multiple*self.char

	def increment(self):
		self.__iadd__(1)

	def decrement(self):
		self.__isub__(1)

	# def default(self):
	# 	if TabManager.std is None :
	# 		TabManager.std = self


default_tabmanager = TabManager()


class DefinesHandler :
	def __init__(self):
		self.defines: T.List[str] = list()
		self.not_defines: T.List[str] = list()
		self.undefines: T.List[str] = list()

	def add(self, alias, defined_value: T.Union[str, None] =None, define_not: T.Union[bool, str] = True, undefine=True):
		"""

		:param alias: the name of the preprocessor constant
		:param defined_value: the value defined if one of the chips is selected
		:param define_not: <b>False</b> if nothing should be defined if none of the chips is selected; <br>
						<b>True</b> if the constant must be defined empty; <br/>
						An <b>str</b> value if the constant must have the specified value.
		:param undefine: whether or not the preprocessor constant should be undefined at the end of the file
		"""
		if defined_value is not None :
			self.defines.append(f"#define {alias} {defined_value}")
		else :
			self.defines.append(f"#define {alias}")

		if isinstance(define_not, str) :
			self.not_defines.append(f"#define {alias} {define_not}")
		elif define_not :
			self.not_defines.append(f"#define {alias}")

		if undefine :
			self.undefines.append(alias)

	def add_raw(self, defined: str = None, not_defined: str = None, undefine: str = None):
		if defined is not None :
			self.defines.append(defined)
		if not_defined is not None :
			self.not_defines.append(not_defined)
		if undefine is not None :
			self.undefines.append(undefine)

	def output_defines(self, chip_set: "ChipSet", use_else = True) :
		out: str = "#if\t"
		out += chip_set.defined_list() + "\n"

		for define in self.defines :
			out += define + "\n"

		if use_else and len(self.not_defines) > 0 :
			out += "#else"
			for not_define in self.not_defines :
				out += not_define + "\n"

		out += "#endif\n"

		return out

	def output_undef(self) :
		out: str = ""
		for undef in self.undefines :
			out += f"\n#undef {undef}"

		return out
