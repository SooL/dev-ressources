from multiprocessing import Pool
import typing as T
from FileSetHandler.svd import SVDFile
from tools import global_parameters
import os
import logging
import xml.etree.ElementTree as ET
logger = logging.getLogger()


def svd_processor(handler : SVDFile, filter : T.List[str] = None):
	logger.debug(f"{handler.file_name} - Start Process")
	handler.process(filter)
	logger.debug(f"{handler.file_name} - Done")
	return handler


def svd_process_handler(svd_set : T.Dict[str,SVDFile], filter : T.List[str] = None):
	if global_parameters.jobs == 1 :
		logger.info("Processing SVD in the current thread.")
		ret = {i.path:svd_processor(i) for i in svd_set.values()}
	else:
		logger.info(f"Dispatching SVD analysis in a pool of {global_parameters.jobs} workers.")
		#handlers = map(svd_processor, [(x, filter) for x in svd_set.values()])
		with Pool(global_parameters.jobs) as pool :
			handlers = pool.starmap(svd_processor,[(x,filter) for x in sorted(svd_set.values(),reverse=True, key=lambda y : y.file_size)])
			pool.close()
			pool.join()
			ret = {i.path: i for i in handlers}
			logger.info("\tDone")
	del svd_set
	return ret