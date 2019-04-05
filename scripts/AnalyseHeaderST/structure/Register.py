from typing import Union, Dict, Tuple

from structure.Field import Field
from structure.RegisterVariant import RegisterVariant
from structure.Component import Component
from tools.utils import ChipSeriesManager, List


REG_TEMPLATE = """
#ifdef {alias}
struct {reg.name}_TypeDef : public {reg.reg_type}
{{
	using {reg.reg_type}::operator=;
	{content}

	//SOOL-{alias}-DECLARATION
}};
#endif
"""


class Register(Component):
	"""
	The Register component. Its parent is the Peripheral, and it contains Register Variants.
	"""

	def __init__(self, name: str, chips: ChipSeriesManager, reg_type: str, size=32):
		super().__init__(name, chips)
		self.reg_type: str = reg_type
		"""base type of the register"""
		self.variants: List[RegisterVariant] = list()
		"""list of variants for this register"""
		self.size: int = size
		"""size (in bits) of this register"""
		self.divergent: bool = False
		"""True if this register has different bitfields depending on the instance.
		 In this case this register only holds common fields"""
		self.defined = True  # all registers are defined

# _______________________________________________________________________________________________________________defines
	def need_define(self):
		return True

	def define_condition(self)->str:
		if super().need_define():
			return self.chips.output_condition()
		else:
			return ""  # define without condition if the chips are the same as th ones for the peripheral

	def define(self):
		from AnalyseHeaderST.structure.PeripheralSpecification import PeripheralSpecification
		if isinstance(self.parent, PeripheralSpecification):
			return None
		else:
			return f"#define {self.alias()}"

	def add_to_define_dict(self, define_dict: Dict[str, List[Tuple[str, str]]], undef: str):
		super().add_to_define_dict(define_dict, undef)
		for var in self.variants:
			var.add_to_define_dict(define_dict, undef)
# _________________________________________________________________________________________________________________build

	def add_field(self, field: Field):
		for var in self.variants:
			if var.has_room(field):
				var.add_field(field)

	def finalize(self):
		if len(self.variants) == 1:
			self.variants[0].set_only_variant()
		else:
			i = 0
			for var in self.variants:
				var.set_variant_id(i)
				var.finalize()
				i += 1

	def declare(self):
		content = "\n".join(map(lambda var: var.declare(), self.variants))
		if len(self.variants) > 1:
			content = "union\n{\n\t" + content.replace('\n', '\n\t') + "\n}"
		return REG_TEMPLATE.format(
				reg=self,
				alias=self.alias(),
				content=content)

	def use(self, name: str)->str:
		if self.divergent:
			return f"typename plugin::{self.name}_TypeDef {name}"
		return f"uint{self.size}_t {name}" if len(self.variants) == 0 else f"{self.name}_TypeDef {name}"
