class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        n = len(nums)
        if n == 0:
            return []

        nums.sort()
        dp = [[num] for num in nums]

        for i in range(n):
            for j in range(i):
                if nums[i] % nums[j] == 0 and len(dp[i]) < len (dp[j]) + 1:
                    dp[i] = dp[j] + [nums[i]]

        return max(dp, key=len)
        