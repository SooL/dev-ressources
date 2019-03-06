from typing import List, Dict, Tuple, Union

from structure.Peripheral import Component
from structure.Peripheral import Field
from tools.utils import ChipSeriesManager

REG_TEMPLATE_FULL = """
#ifdef {alias}
struct {reg.name}_TypeDef : public {reg.reg_type}
{{
	using {reg.reg_type}::operator=;

	union
	{{{content}
	}};
	//SOOL-{alias}-DECLARATION
}};
#endif
"""

REG_TEMPLATE_SIMPLE = """
#ifdef {alias}
struct {reg.name}_TypeDef : public {reg.reg_type}
{{
	using {reg.reg_type}::operator=;
	{content}

	//SOOL-{alias}-DECLARATION
}};
#endif
"""

REG_VARIANT_TEMPLATE = """
#ifdef {0}
struct
{{{1}
}};
#endif"""
REG_VARIANT_TEMPLATE_NO_IF = """
struct
{{{0}
}};"""

class RegisterVariant(Component):
	def __init__(self, number: int, chips: ChipSeriesManager):
		Component.__init__(self, str(number), chips)
		self.fields: List[Field] = list()

	def need_def(self):
		return Component.need_def(self) and self.name is not None and len(self.name) > 0

	def _define(self):
		return "#define {}".format(self.prefixed_name())

	def use(self):
		fields_out = ""
		prefix = self.prefixed_name()
		cursor = 0
		if self.name is None or len(self.name) == 0: #if this is the only variant, don't use structs, only content
			for field in sorted(self.fields, key=lambda f:f.pos):
				fields_out += "\n"+field.use()
			return fields_out
		else :
			for field in sorted(self.fields, key=lambda f:f.pos):
				fields_out += "\n\t"+field.use()
			if self.need_def():
				return REG_VARIANT_TEMPLATE.format(prefix, fields_out)
			else:
				return REG_VARIANT_TEMPLATE_NO_IF.format(fields_out)

	def define_output(self, dictionary: Dict[str, List[Tuple[str, str, str]]]):
		Component.define_output(self, dictionary)
		for field in self.fields:
			field.define_output(dictionary)

	def add_field(self, field: Field):
		field.set_parent(self)
		self.fields.append(field)

	def finalize(self, full_chips):
		for field in self.fields:
			self.chips.merge(field.chips)

		Component.finalize(self, full_chips)
		self.fields.sort(key=lambda f: f.pos)
		cursor = 0
		fillers: List[Field] = []
		reg_size = self.parent.size
		item_max_size = min(reg_size, 32)
		for field in self.fields:
			field.finalize(full_chips)

			if field.pos < cursor :
				raise Exception("Fields overlap in register {} at position {}".format(self.prefixed_name(), field.pos))
			elif field.pos > cursor:
				while field.pos - cursor > item_max_size:
					fillers.append(Field("", self.chips, cursor, item_max_size))
					cursor += item_max_size
				if field.pos > cursor:
					fillers.append(Field("", self.chips, cursor, field.pos - cursor))
			cursor = field.pos + field.size
		if cursor < reg_size:
			while reg_size - cursor > item_max_size:
				fillers.append(Field("", self.chips, cursor, item_max_size))
				cursor += item_max_size
			if reg_size > cursor:
				fillers.append(Field("", self.chips, cursor, reg_size - cursor))
		if len(fillers) > 0:
			for filler in fillers:
				self.add_field(filler)
				filler.finalize(full_chips)
			self.fields.sort(key=lambda f: f.pos)

	def __iter__(self):
		for field in self.fields:
			yield field

	def __getitem__(self, item: Union[str, int]):
		if type(item) == str:
			for field in self.fields:
				if field.name == item:
					return field
		elif type(item) == int:
			for field in self.fields:
				if field.pos == item:
					return field
		else:
			raise TypeError("argument of type {} is not of the right type.".format(type(item)))

class Register(Component):
	def __init__(self, name: str, chips: ChipSeriesManager, reg_type: str, size: int):
		Component.__init__(self, name, chips)
		self.reg_type: str = reg_type
		self.variants: List[RegisterVariant] = list()
		self.size = size
		self.divergent = False

	def prefixed_name(self, direct=False):
		if not direct :
			return Component.prefixed_name(self)
		else:
			from structure.Peripheral import PeriphDivergence
			if isinstance(self.parent, PeriphDivergence):
				return self.parent.parent.prefixed_name() + "_" + self.name
			else:
				return Component.prefixed_name(self)

	def _define(self):
		from structure.Peripheral import PeriphDivergence
		if not isinstance(self.parent, PeriphDivergence):
			return "#define {}".format(self.prefixed_name(True))

	def use(self):
		if self.divergent:
			return "typename plugin::{0.name}_TypeDef".format(self)
		return ("uint{0.size}_t".format(self))\
			if len(self.variants) == 0 else\
			("{0.name}_TypeDef".format(self))

	def declare(self, force=False):
		content = ""
		if len(self.variants) == 0 and not force:
			return ""
		else :
			for var in self.variants:
				content += var.use().replace("\n", "\n\t" if len(self.variants) == 0 else "\n\t\t")
			return (REG_TEMPLATE_FULL if len(self.variants) > 1 else REG_TEMPLATE_SIMPLE).format(
				reg = self,
				alias = self.prefixed_name(True),
				content = content)

	def need_def(self):
		return True
	def define_key(self):
		if self.parent.parent is None and self.parent.chips == self.chips:
			return "{ifdef}\n"
		else :
			return Component.define_key(self)

	def define_output(self, dictionary: Dict[str,List[Tuple[str, str, str]]]):
		Component.define_output(self, dictionary)
		for var in self.variants :
			var.define_output(dictionary)

	def add_field(self, field: Field):
		#self.chips.merge(field.chips)

		ok = len(self.variants) > 0
		for var in self.variants :
			ok = True
			for f in sorted(var.fields, key=lambda f:f.pos) :
				if f.name == field.name :
					if f.pos == field.pos and f.size == field.size :
						f.chips.merge(field.chips)
						return
					else :
						ok = False # Same name as existing field, but not same mask.
						break      # Need other variant, even if there is room in this one
				if ((f.pos <= field.pos) and (f.pos + f.size > field.pos)) or \
						((field.pos < f.pos) and (field.pos + field.size) > f.pos):
					ok = False #current variant is already occupied at the field position
			if ok :
				var.add_field(field)
				break
		if not ok :
			var = RegisterVariant(len(self.variants), field.chips)
			var.set_parent(self)
			self.variants.append(var)
			var.add_field(field)

	def finalize(self, full_chips):
		self.variants.sort(key=lambda v: v.name)
		if len(self.variants) == 1:
			self.variants[0].name = None
		for var in self.variants:
			var.finalize(full_chips)

		if self.chips.is_empty(): # register created manually. Add all chips from variants
			for var in self.variants:
				self.chips.merge(var.chips)
		else:
			"" #TODO check if variant chips are all in register chips

		Component.finalize(self, full_chips)



	def __eq__(self, other):
		return isinstance(other, Register)\
		       and other.name == self.name
				#and other.reg_type == self.reg_type

	def merge(self, other: "Register"):
		self.chips.merge(other.chips) #useless when fields will be added
		if other.size > self.size:
			self.size = other.size
		for var in other.variants :
			for f in var.fields :
				self.add_field(Field(f.name, f.chips, f.pos, f.size))

	def __iter__(self):
		for var in self.variants:
			yield var

	def split_array(self, names, item_size):
		self.size = len(names)*item_size
		if self.size > 64: #cannot be considered to be an integer, only an array (and a bitfield)
			self.reg_type = "BigArrayReg_t<uint{}_t, 0, {}, {}>".format(item_size, int(item_size/8), len(names))
		else: #can still be considered to be an integer itself
			self.reg_type = "ArrayRegBase_t<uint{}_t, uint{}_t>".format(self.size, item_size)
		mappings = self.parent.getMappings(self)
		for m in mappings :
			if m.array_size != len(names):
				raise Exception("the register " + self.prefixed_name()
				                + " cannot be split in several registers because the array size ({})"
				                  " is different for different mappings : current mapping length : {}"\
				                .format(len(names), m.array_size))
			m.array_size = 1
			pos = m.pos
			for name in names:
				if name is not None:
					self.parent.add_register(Register(name, m.chips, "Reg{}_t".format(item_size), item_size), pos)
				pos = pos + item_size
