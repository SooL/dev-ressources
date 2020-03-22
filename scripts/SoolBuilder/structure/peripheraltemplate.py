import typing as T
from structure import Component, ChipSet, RegisterVariant, PeripheralInstance, TabManager, Register
from structure.utils import DefinesHandler


class PeripheralTemplate(Component) :

	def __init__(self,
	             name: T.Union[None, str] = None,
				 parent: "Component" = None) :
		super().__init__(name=name, parent=parent)

		self.registerVariants : T.List[RegisterVariant] = list()
		self.instances : T.List[PeripheralInstance] = list()

	def compatible_with(self, instance: PeripheralInstance) -> bool :
		variants = list()

		# tests if variants are overlapping (chips in common for different variants in same register)
		inst_variants = instance.template_reg_variants
		for var in self.registerVariants :
			if var.for_template and var not in inst_variants :
				for inst_var in inst_variants :
					if inst_var.for_template :
						if var.parent is inst_var.parent and var is not inst_var : # same register, different variants
							if not var.chips.chips.isdisjoint(inst_var.chips.chips) :
								return False
		return True

	def add_instance(self, instance: PeripheralInstance) :

		new_variants = instance.template_reg_variants

		for var in new_variants :
			if var not in self.registerVariants :
				self.registerVariants.append(var)
				self.chips.add(var.chips)

		self.instances.append(instance)

	def finalize(self):
		if len(self.instances) == 0 :
			self.chips = self.parent.chips
			self.brief = "default template for " + self.parent.name
		else :
			names : T.Set[str] = set()
			for inst in self.instances :
				names.add(inst.name)
			self.brief = "fields used by " + ", ".join(names)
		super().finalize()

	def define_for_instance(self, defines, instance, define_not: bool = False) :
		if self.chips not in defines :
			defines[self.chips] = DefinesHandler()
		defines[self.chips].add(
			alias=f"{instance.name}_tmpl",
			defined_value=self.name,
			define_not=define_not,
			undefine=True)

	def declare(self, indent: TabManager = TabManager()) -> T.Union[None,str] :

		out = f"{indent}struct {self.name} /// {self.brief} \n{indent}{{\n"
		indent.increment()

		registers: T.List[Register] = list(filter(lambda register : register.has_template, self.parent.registers))

		for reg in registers :
			out += reg.declare(indent, self.instances)

		indent.decrement()
		out += f"{indent}}};\n"
		if self.needs_define :
			out = f"{indent}#ifdef {self.defined_name}\n{out}{indent}#endif\n"
		return out






