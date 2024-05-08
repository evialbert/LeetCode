class Solution:
	def findRelativeRanks(self, score: List[int]) -> List[str]:

		result = []
		hashmap = defaultdict(int)
		rank = sorted(score , reverse = True)

		for index in range(len(rank)):

			hashmap[rank[index]] = index

		for num in score:

			if hashmap[num] == 0:
				result.append('Gold Medal')
			elif hashmap[num] == 1:
				result.append('Silver Medal')
			elif hashmap[num] == 2:
				result.append('Bronze Medal')
			else:
				result.append(str(hashmap[num] + 1))

		return result