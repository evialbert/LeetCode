class Solution:
	def countSubarrays(self, nums: List[int]) -> int:

		result = 0

		for index in range(len(nums) - 2):

			subarray = nums[index : index + 3]

			if (subarray[0] + subarray[2]) == (subarray[1] / 2):

				result = result + 1

		return result