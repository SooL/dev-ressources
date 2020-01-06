from multiprocessing import Process, Queue
import typing as T
from FileSetHandler.svd import SVDFile
from tools import global_parameters
import os
import logging
logger = logging.getLogger()


class SVDProcess(Process):
	def __init__(self,queue : Queue, handler : T.List[SVDFile] = list(), filter : T.List[str] = None, name = None):
		Process.__init__(self, name=name)
		self.handlers : T.List[SVDFile] = handler
		self.filter : T.List[str] = filter
		self.fb_queue : Queue = queue
		
	def run(self) -> None:
		for handler in self.handlers :
			logger.debug(f"{self.name} - Process {handler.file_name}")
			handler.process(self.filter)
			del handler.root
			self.fb_queue.put(handler)
		logger.debug(f"{self.name} - Done")
		self.fb_queue.put(None)
			
			
class SVDDispatcher:
	def __init__(self,handler_list : T.List[SVDFile], njobs : int = None):
		self.svd_list : T.List[SVDFile] = handler_list
		self.njobs = njobs
		self.filter = None
		self.process_list : T.List[SVDProcess] = list()
		self.fb_queue : Queue = Queue()
		
	def dispatch(self):
		if self.njobs is None :
			jobs = 1
		else :
			jobs = self.njobs
		
		if self.filter is None :
			filter = global_parameters.group_filter
		else :
			filter = self.filter
		
		sizes_list : T.List[int] = list()
		
		logger.debug(f"Dispatching SVD processes across {jobs} threads...")
		
		for i in range(0,jobs) :
			self.process_list.append(SVDProcess(self.fb_queue,handler=list(),filter=filter,name=f"SVDProcessWorker-{i}"))
			sizes_list.append(0)
		
		for handler in self.svd_list :
			size = os.path.getsize(handler.path)
			smallest = sizes_list.index(min(sizes_list))
			self.process_list[smallest].handlers.append(handler)
			sizes_list[smallest] += size
		
		for i in range(0,jobs) :
			logger.debug(f"\tQueue {i:2d}/{jobs:d} : length {len(self.process_list[i].handlers):2d} - size {sizes_list[i]:10d} B")
			
	def launch(self) -> T.Dict[str,SVDFile]:
		logger.info(f"Starting SVD parallel processing...")
		
		remaining_jobs = 0
		
		for process in self.process_list:
			process.start()
			remaining_jobs += 1
		ret = dict()
		while remaining_jobs > 0 :
			handler: SVDFile = self.fb_queue.get()
			if handler is None :
				remaining_jobs -= 1
				continue
			logger.info(f"Retrieve processed {handler.file_name}")
			ret[handler.file_name] = handler
		
		for process in self.process_list:
			process.join()

		self.fb_queue.close()
		
		return ret