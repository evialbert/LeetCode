class Solution:
    def maxSelectedElements(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        
        dp = defaultdict(int)

        for x in nums:
            a = b = 1
            # if x-1 is present in hash, then we increment x by 1
            if x - 1 in dp:
                a = dp[x-1] + 1
            # and if x is present in hash, then we increment x+1 by 1
            if x in dp:
                b = dp[x] + 1

            dp[x] = max(a, dp[x])
            dp[x+1] = max(b, dp[x+1])

        return max(dp.values())