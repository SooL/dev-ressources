# ******************************************************************************
#  Copyright (c) 2018-2020 FAUCHER Julien & FRANCE Loic.                       *
#                                                                              *
#  This file is part of SooL generator.                                        *
#                                                                              *
#  SooL generator is free software: you can redistribute it and/or modify      *
#  it under the terms of the GNU Lesser General Public License                 *
#  as published by the Free Software Foundation, either version 3              *
#  of the License, or (at your option) any later version.                      *
#                                                                              *
#  SooL core Library is distributed in the hope that it will be useful,        *
#  but WITHOUT ANY WARRANTY; without even the implied warranty of              *
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                *
#  GNU Lesser General Public License for more details.                         *
#                                                                              *
#  You should have received a copy of the GNU Lesser General Public License    *
#  along with SooL core Library. If not, see  <https://www.gnu.org/licenses/>. *
# ******************************************************************************

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
		ret = {i.path:svd_processor(i,filter) for i in svd_set.values()}
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