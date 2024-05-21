class Solution:
	def subsets(self, nums: List[int]) -> List[List[int]]:
		n = len(nums)
		length = 1 << n
		res = []
		for i in range(length):
			temp = []
			for j in range(n):
				if i & (1 << j):
					temp.append(nums[j])
			res.append(temp)
		return res