from typing import List, Union

from structure.PeripheralInstance import PeripheralInstance
from structure.PeripheralSpecification import PeripheralSpecification
from structure.Register import Register
from structure.PeripheralMapping import PeripheralMapping
from structure.Component import Component
from tools.utils import ChipSeriesManager

TEMPLATE_PERIPH = """
class {periph}
{{
	//SOOL-{alias}-NESTED-TYPES
	
	public :
	{registers}
	
	{mappings}
	private:
	{periph}() = delete;
	//SOOL-{alias}-DECLARATION
}};
"""


class Peripheral(Component):
	def __init__(self, name: Union[str, None], chips: ChipSeriesManager):
		super().__init__(name, chips)
		self.registers: List[Union[Register, Peripheral]] = list()
		"""list of registers inside the peripheral. A register can be a sub-peripheral (like CAN's FIFOs)"""
		self.mappings: List[PeripheralMapping] = list()
		"""list of different mappings of registers"""
		self.specifications: List[PeripheralSpecification] = list()
		"""for divergent peripheral like timers, with different bitfields for the same register for two instances"""
		self.instances: List[PeripheralInstance] = list()
		"""list of the instances for this peripheral"""

	def alias(self):
		if isinstance(self.parent, Peripheral):
			return super().alias()
		else:
			return self.name

	def has_specializations(self)->bool:
		"""
		:return: True if the peripheral has specifications (that require the use of C++ templates)
		"""
		return len(self.specifications) > 0

	def define(self):
		return f"#define {self.alias()}"

	def declare(self):
		out = ""
		if self.defined:
			out += f"#ifdef {self.alias()}\n"

		str_registers = "\n".join(map(lambda r: r.declare(), self.registers))
		if len(self.mappings) == 1:
			str_mappings = self.mappings[0].declare()
		else:
			str_mappings = "\n".join(map(lambda r: r.declare(), self.registers))

		out += TEMPLATE_PERIPH.format(
			periph=self.name,
			alias=self.alias(),
			registers=str_registers,
			mappings=str_mappings)

		if self.defined:
			out += "#endif\n"

	def use(self, name: str):
			return ("#ifdef {1}_BASE_ADDR\n" +
			        "volatile class {0}* const {1} = reinterpret_cast<class {0}* const>({1}_BASE_ADDR);\n" +
			        "#endif").format(
						(self.name+"<>") if self.has_specializations() else self.name,
						name
			)
