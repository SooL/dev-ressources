import typing as T
import logging
from tools.svd_retriever import defined_archives_keil

logger = logging.getLogger()


class ParametersHandler :
	generate_options = {"no-phy" 	: "Generate to allow targetting a non-physical device (emulation).",
						"big-endian": "Swich to big endian memory organization.",
						"dump"		: "Dump the database into .data/SooL.dat."}

	def __init__(self):
		self.reuse_db			: bool = False
		self.dump_db			: bool = False
		self.physical_mapping	: bool = True
		self.big_endian			: bool = False
		self.store_packs 		: bool = False
		self.use_local_packs 	: bool = False
		self.update_requested 	: bool = False
		self.force_pack_version	: bool = False

		self.group_filter		: T.List[str] = list()
		self.family_update_request : T.List[str] = list()
		self.family_upgrade_request: T.List[str] = list()
		self.fileset_reinit		: bool = False

		self.enforce_versions	: bool = False
		
		self.jobs : int = 1


	@property
	def need_update(self):
		return self.update_requested and (len(self.family_update_request) or len(self.family_upgrade_request))

	@property
	def update_list(self):
		return sorted(list(set(self.family_upgrade_request + self.family_update_request)))

	def process_generate(self,options : T.List[str]):

		if len(options) == 0 : return
		for token in options :
			if token == "no-phy" :
				self.physical_mapping = False
			elif token == "big-endian" :
				self.big_endian = True
			elif token == "dump":
				self.dump_db = True
			else :
				logger.error(f"Unrecognized option provided to generate : {token} will be ignored.")

	def read_args(self,args):
		self.reuse_db 			= args.reuse

		self.process_generate(args.generate)
		# self.physical_mapping 	= not args.no_phy
		# self.big_endian			= args.big_endian

		self.enforce_versions	= args.force_version
		self.store_packs		= args.store_packs
		self.use_local_packs	= args.use_local_packs
		self.update_requested	= args.update_svd or args.upgrade_svd
		self.jobs				= args.jobs
		if args.group_filter is not None :
			self.group_filter = args.group_filter.split(",")
		if self.update_requested :
			if 'all' in args.update_svd :
				self.fileset_reinit = True
				self.family_update_request = list(defined_archives_keil.keys())
			elif 'all' in args.upgrade_svd :
				self.family_update_request.extend(args.update_svd)
				self.family_upgrade_request= list(defined_archives_keil.keys())
			else :
				self.family_update_request.extend(args.update_svd)
				self.family_upgrade_request.extend(args.upgrade_svd)

		
global_parameters = ParametersHandler()
