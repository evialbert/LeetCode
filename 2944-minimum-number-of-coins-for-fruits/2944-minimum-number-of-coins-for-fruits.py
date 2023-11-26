class Solution:
    def minimumCoins(self, prices: List[int]) -> int:
        n = len(prices)
        prices = [0] + prices
        dp = [[float("inf"), float("inf")] for _ in range(n + 1)]
        dp[0][0] = 0
        dp[0][1] = 0
        for i in range(1, n + 1):
            dp[i][0] = min(min(dp[i - 1]) + prices[i], dp[i][0])
            for j in range(i, min(n + 1, i + i + 1)):
                dp[j][1] = min(dp[j][1], dp[i][0])
        return min(dp[-1])