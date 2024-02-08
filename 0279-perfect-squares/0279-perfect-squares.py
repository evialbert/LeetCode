class Solution:
    def numSquares(self, n: int) -> int:
        dp = [float('inf')]*(n+1)
        dp[0] = 0
        for i in range(1, n + 1):
            min_val = float('inf')

            j = 1
            while j * j <= i:
                min_val =min(min_val,dp[i - j * j] + 1)
                j += 1
            dp[i] = min_val
        
        return dp[n]