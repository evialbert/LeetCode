class Solution:
    def maxTotalReward(self, rewardValues: List[int]) -> int:
        
        rewardValues.sort()
        maxReward = rewardValues[-1]
        dp = [0] * (maxReward * 2 + 1)
        for v in rewardValues:
            for i in range(v):
                if dp[i+v] < dp[i] + v:
                    dp[i+v] = dp[i] + v
        return max(dp)