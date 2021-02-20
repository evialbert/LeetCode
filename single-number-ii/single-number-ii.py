class Solution:
	def singleNumber(self, nums: List[int]) -> int:

		# Let the numbers be x,y,z,.....
		# require sum should be 3x+3y+3z
		# original sum = 3x+3y+z
		# Subtract require sum from original sum
		# (3x+3y+3z) - (3x+3y-z) = 2z
		# div the ans by 2 = 2z/2 = z--> our ans

		return (3 * sum(set(nums)) - sum(nums)) // 2