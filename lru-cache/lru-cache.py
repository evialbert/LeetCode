class LRUCache(object):

	def __init__(self, capacity):
		self.dic = OrderedDict()
		self.capacity = capacity

	def get(self, key):
		if key not in self.dic:
			return -1
		v = self.dic.pop(key)
		self.dic[key] = v
		return v

	def put(self, key, value):
		if key in self.dic:
			self.dic.pop(key)
		elif len(self.dic) >= self.capacity:
			self.dic.popitem(last=False)
		self.dic[key] = value