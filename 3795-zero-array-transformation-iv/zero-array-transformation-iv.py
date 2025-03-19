class Solution:
    def minZeroArray(self, nums: List[int], queries: List[List[int]]) -> int:
        if all(num == 0 for num in nums):
            return 0        
        n = len(nums)
        dp = [1] * n
        for i, (l, r, val) in enumerate(queries):
            for j in range(l, r + 1):
                dp[j] |= dp[j] << val
                if nums[j] > 0:
                    dp[j] &= (1 << (nums[j] + 1)) - 1
            if all(((dp[j] >> nums[j]) & 1) for j in range(n)):
                return i + 1
        return -1 