class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        i = 1
        while i in nums:
            i += 1
        return i