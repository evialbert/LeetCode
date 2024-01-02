class Solution:
	def findMatrix(self, nums: List[int]) -> List[List[int]]:

		result = [[nums[0]]]

		for num in nums[1:]:

			check = True
			for row in range(len(result)):

				if num not in result[row]:
					result[row].append(num)
					check = False
					break

			if check == True:
				result.append([num])

		return result