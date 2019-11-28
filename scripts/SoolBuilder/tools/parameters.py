

class ParametersHandler :
	def __init__(self):
		self.reuse_db: bool = False
		self.dump_db: bool = False
		self.physical_mapping: bool = True
		self.big_endian: bool = False
	
	def read_args(self,args):
		self.reuse_db : bool = args.reuse
		self.dump_db : bool = args.dump
		self.physical_mapping : bool = not args.no_phy
		self.big_endian : bool = args.big_endian
		
global_parameters = ParametersHandler()
