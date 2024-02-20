class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        return sum(range(0, len(nums) + 1)) - sum(nums)
