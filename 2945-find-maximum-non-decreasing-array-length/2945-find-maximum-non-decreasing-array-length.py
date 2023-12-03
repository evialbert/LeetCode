class Solution:
    def findMaximumLength(self, nums: List[int]) -> int:
        n = len(nums)
        presum = [0] * (n + 1)
        for i in range(n):
            presum[i+1] = presum[i] + nums[i]
        
        last = [0] * (n + 1)
        stack = [0] * (n + 1)
        dp = [0] * (n + 1)
        l = 0
        r = 1
        for i in range(1, n + 1):
            while l + 1 < r and presum[i] >= presum[stack[l + 1]] + last[stack[l + 1]]:
                l += 1
            last[i] = presum[i] - presum[stack[l]]
            dp[i] = dp[stack[l]] + 1
            while l < r and presum[i] + last[i] < presum[stack[r - 1]] + last[stack[r - 1]]:
                r -= 1
            stack[r] = i
            r += 1
        return dp[-1]