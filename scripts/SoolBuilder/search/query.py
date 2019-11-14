import typing as T
from fnmatch import fnmatch


class Query :
	def __init__(self, pattern : str = ""):
		self.group : str = None
		self.peripheral : str = None
		self.register : str = None
		self.field : str = None

		self.read_pattern(pattern)
		self.match_on_none = False

	def read_pattern(self,pattern : str,separator = "."):
		registered_tokens : T.List[T.Optional[str]] = [None for x in range(0,4)]
		index = 0
		for token in pattern.split(separator) :
			registered_tokens[index] = token
			index += 1

		self.group = registered_tokens[0]
		self.peripheral = registered_tokens[1]
		self.register = registered_tokens[2]
		self.field = registered_tokens[3]

	def match(self,other : T.Union[str, T.Tuple[str], "Query"], partial = False) -> bool :
		"""
		This function will test if other match self pattern in a unix way (as provided by fnmatch)
		:param partial:
		:param other:
		:return:
		"""
		self.match_on_none = False
		if isinstance(other,str) :
			return self.match(Query(other),partial)
		elif isinstance(other,tuple) :
			return self.match(Query(".".join([str(x) for x in other])),partial)
		elif isinstance(other,Query) :
			for attribute in ["group","peripheral","register","field"] :
				s_attr = self.__getattribute__(attribute)
				o_attr = other.__getattribute__(attribute)

				if s_attr is None :
					self.match_on_none = True
					return True
				elif o_attr is None :
					#print(f"Other None value return {partial}")
					return partial
				elif not fnmatch(o_attr,s_attr) :
					#print(f"Value mismatch on {attribute} : {s_attr} vs {o_attr}")
					return False
			return True
		else :
			raise TypeError()