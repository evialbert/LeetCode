class Solution:
    def minElement(self, nums: List[int]) -> int:
        return min(sum(map(int, str(x))) for x in nums)