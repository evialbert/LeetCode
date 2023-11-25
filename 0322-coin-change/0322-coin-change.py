class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [float(inf)]*(amount+1)
        dp[0] = 0
        for i in range(1,amount+1):
            for j in coins:
                t = i-j
                if t>=0:
                    dp[i]=min(dp[i],dp[t]+1)
        # print(dp)
        if dp[-1]==float(inf):
            return -1
        return dp[-1]