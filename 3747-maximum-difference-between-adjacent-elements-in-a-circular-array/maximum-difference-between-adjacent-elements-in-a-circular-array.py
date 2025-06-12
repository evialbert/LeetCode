class Solution:
    def maxAdjacentDistance(self, nums: List[int]) -> int:
        n = len(nums)
        maxDiff = 0
        for i in range(n):
            j = (i +1 ) % n
            maxDiff = max(maxDiff, abs(nums[i] - nums[j]))
            
        return maxDiff        