class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        nums=[i**2 for i in nums]
        nums.sort()
        return nums