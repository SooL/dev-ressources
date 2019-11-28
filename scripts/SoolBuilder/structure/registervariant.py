import typing as T
from copy import copy

from structure import TabManager
from structure import Field
from structure import ChipSet
from structure import Component

from tools import global_parameters

REG_VAR_DECLARATION : str = """{indent}struct
{indent}{{
{fields}{indent}}};
"""


class RegisterVariant(Component) :
	def __init__(self, chips: T.Optional[ChipSet] = None) :
		super().__init__(chips=chips)
		self.fields : T.List[Field] = list()

		from structure import PeripheralInstance
		self.linked_instances : T.Optional[T.List[PeripheralInstance]] = None

################################################################################
#                                  OPERATORS                                   #
################################################################################
	def __iter__(self):
		return iter(self.fields)

	def __contains__(self, item):
		if isinstance(item, str) :
			for f in self :
				if f.name == item :
					return True
			return False
		elif isinstance(item, Field) :
			for f in self :
				if f == item :
					return True
			return False

	def __getitem__(self, item):
		if isinstance(item, str) :
			for f in self :
				if f.name == item :
					return f
			raise KeyError()
		elif isinstance(item, Field) :
			for f in self :
				if f == item :
					return f
			raise KeyError()
		elif isinstance(item, int) :
			for f in self :
				if f.position == item :
					return f
			raise KeyError()
		else :
			raise KeyError()

	def __eq__(self, other):
		if not(isinstance(other, RegisterVariant)) : return False

		s_len = len(self.fields)
		o_len = len(other.fields)
		if s_len != o_len : return False

		if self.for_template != other.for_template :
			return False

		self.sort_fields()
		other.sort_fields()
		for i in range(0, s_len) :
			if self.fields[i] != other.fields[i] : return False

		return True

	@property
	def for_template(self):
		return self.linked_instances is not None and len(self.linked_instances) > 0

	@property
	def size(self) -> int:
		self.sort_fields()
		last_field = self.fields[-1]
		return last_field.position + last_field.size

################################################################################
#                              FIELDS MANAGEMENT                               #
################################################################################

	def before_svd_compile(self, parent_corrector) :
		super().before_svd_compile(parent_corrector)
		self.sort_fields()
		if self.linked_instances is None :
			self.linked_instances = copy(self.parent.parent.instances)

	def after_svd_compile(self):
		super().after_svd_compile()
		self.sort_fields()
		if self.linked_instances is not None :
			self.linked_instances.sort()
			if sorted(self.linked_instances) == sorted(self.parent.parent.instances) :
				self.linked_instances = None
				self.edited = True

	def has_room_for(self, field: Field) :
		for f in self.fields :
			if f.overlap(field) :
				return False
			elif f.name == field.name :
				return f == field
		return True

	def add_field(self, field: Field) :
		if field in self :
			self[field].inter_svd_merge(field)
		else :
			self.fields.append(field)
			field.set_parent(self)
			self.chips.add(field.chips)

	def remove_field(self, field: T.Union[str, Field]) :
		if isinstance(field, Field) :
			self.fields.remove(field)
		elif isinstance(field, str) :
			for f in self :
				if f.name == field :
					self.fields.remove(f)
			raise ValueError(f"{field} is not in {self}")
		else :
			raise TypeError(f"Cannot remove {field} from {self} : not a str or Field")


	def sort_fields(self, reverse = False):
		self.fields.sort(key=(lambda f: f.position), reverse=reverse)

	def inter_svd_merge(self, other: "RegisterVariant") :
		super().inter_svd_merge(other)
		if other.for_template != self.for_template :
			raise AssertionError("Non-template register variant cannot be merged with template register variant")
		if self.for_template :
			self.linked_instances.extend(other.linked_instances)
		for f in other :
			self.add_field(f)

	def intra_svd_merge(self, other: "RegisterVariant"):
		super().intra_svd_merge(other)
		if other.for_template != self.for_template :
			raise AssertionError("Non-template register variant cannot be merged with template register variant")
		if self.for_template :
			self.linked_instances.extend(other.linked_instances)
		for f in other :
			self.add_field(f)

	def fill_holes(self):
		"""
		Fills the holes in the bitfield by creating unnamed fields.
		Needs the fields to be sorted by position
		Called by the 'finalize' method.
		"""
		pos: int = 0
		fillers: T.List[Field] = list()
		self.sort_fields()
		for f in self :
			if f.position > pos :
				filler = Field(position = pos, size = f.position - pos)
				filler.set_parent(self)
				fillers.append(filler)
			pos = f.position + f.size
		if pos < self.parent.size :
			filler = Field(position=pos, size = self.parent.size - pos)
			filler.set_parent(self)
			fillers.append(filler)
		self.fields.extend(fillers)
		self.sort_fields()

	def finalize(self):
		self.fill_holes()
		if len(self.parent.variants) > 1 :
			self.name = str(self.parent.variants.index(self))
		super().finalize()

################################################################################
#                                DEFINE AND USE                                #
################################################################################

	def declare(self, indent: TabManager = TabManager()) -> T.Union[None,str] :
		self.sort_fields(reverse=global_parameters.big_endian)
		if len(self.parent.variants) == 1 :
			out = "".join([f.declare(indent) for f in self])
		else :
			indent.increment()
			content = "".join([f.declare(indent) for f in self])
			indent.decrement()
			out = REG_VAR_DECLARATION.format(indent= indent, fields= content)

		if self.needs_define :
			out = f"{indent}#ifdef {self.defined_name}\n{out}{indent}#endif\n"
		return out