class Solution:
    def tallestBillboard(self, rods: List[int]) -> int:
        dp = {0: 0}
        for x in rods: 
            for k, v in dp.copy().items(): 
                dp[k+x] = max(dp.get(k+x, 0), v)
                if k >= x: dp[k-x] = max(dp.get(k-x, 0), v+x)
                else: dp[x-k] = max(dp.get(x-k, 0), v+k)
        return dp[0]