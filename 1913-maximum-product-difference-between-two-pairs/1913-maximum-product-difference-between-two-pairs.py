class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:
        nums.sort()
        a, b = nums[0], nums[1]
        c, d = nums[-1], nums[-2]
        return (c * d) - (a * b)