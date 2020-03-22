import typing as T
import sqlite3 as sql

from copy import copy

from . import TabManager
from . import Field
from . import ChipSet
from . import Component

from tools import global_parameters
import logging

logger = logging.getLogger()

REG_VAR_DECLARATION : str = """{indent}struct
{indent}{{
{fields}{indent}}};
"""


class RegisterVariant(Component) :
	def __init__(self, chips: T.Optional[ChipSet] = None,
	             linked_instances : T.Optional[T.List["PeripheralInstance"]] = None) :
		super().__init__(chips=chips)
		self.fields : T.List[Field] = list()

		from structure import PeripheralInstance
		self.linked_instances : T.Optional[T.List[PeripheralInstance]] = linked_instances

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

	def __copy__(self) :
		result = RegisterVariant(chips=self.chips)
		for field in self :
			result.add_field(copy(field))
		return result

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

	def after_svd_compile(self, parent_corrector):
		from structure import Peripheral
		super().after_svd_compile(parent_corrector)
		self.sort_fields()
		if self.linked_instances is not None :
			self.linked_instances.sort()
			periph = self.parent.parent
			if isinstance(periph.parent, Peripheral) :
				periph = periph.parent
			if sorted(self.linked_instances) == sorted(periph.instances) :
				self.linked_instances = None
				self.edited = True

	def force_remove_template(self):
		if self.linked_instances is not None :
			self.edited = True
			self.linked_instances = None

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
		self.chips = ChipSet()
		for field in self :
			self.chips.add(field.chips)


	def sort_fields(self, reverse = False):
		self.fields.sort(key=(lambda f: f.position), reverse=reverse)

	def inter_svd_merge(self, other: "RegisterVariant") :
		super().inter_svd_merge(other)
		if other.for_template != self.for_template :
			raise AssertionError("Non-template register variant cannot be merged with template register variant")
		if self.for_template :
			for inst in other.linked_instances :
				if inst not in self.linked_instances :
					self.linked_instances.append(inst)
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

	def for_instance(self, instance) -> bool :
		if self.for_template :
			return instance in self.linked_instances
		else :
			return not self.chips.chips.isdisjoint(instance.chips.chips)

	def generate_sql(self,cursor : sql.Cursor, parent_id:int):

		all_data = []

		for f in self.fields :
			if f.name is None :
				continue
			for c in self.chips:
				if c.sql_id is None :
					c.update_sql_id(cursor)
					logger.error(f"Chip SQL coherency failure on {c.name} : id = {c.sql_id}")
				data = {"rid":parent_id,"n":f.name,"s":f.size,"p":f.position,"cid":c.sql_id}
				all_data.append(data)
			cursor.execute("INSERT INTO fields(name,size,position) VALUES (:n,:s,:p)",data)
			f_id = cursor.lastrowid

			data = [{"fid":f_id,"cname":c.name} for c in f.chips]

			cursor.executemany("""
			WITH _temp_ AS (
				SELECT id as cid FROM chips
					WHERE name = :cname
			)
			INSERT INTO chip_field (chip_id,field_id)
			SELECT cid,:fid FROM _temp_
			""",data)


		cursor.executemany("""
		WITH _temp_ AS (
			SELECT id AS fid FROM fields 
				WHERE
					name == :n AND
					size == :s AND
					position  == :p 
		)
		INSERT INTO field_reg_placement (field_id, reg_placement_id, chip_id) 
		SELECT fid,:rid,:cid FROM _temp_
		""",all_data)



