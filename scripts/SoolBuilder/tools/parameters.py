

class ParametersHandler :
	def __init__(self):
		self.reuse_db: bool = False
		self.dump_db: bool = False
		self.physical_mapping: bool = True
		self.big_endian: bool = False
		self.store_packs : bool = False
		self.use_local_packs : bool = False
	
	def read_args(self,args):
		self.reuse_db : bool = args.reuse
		self.dump_db : bool = args.dump
		self.physical_mapping : bool = not args.no_phy
		self.big_endian : bool = args.big_endian
		self.store_packs: bool = args.store_packs
		self.use_local_packs: bool = args.load_local_packs

		
global_parameters = ParametersHandler()
