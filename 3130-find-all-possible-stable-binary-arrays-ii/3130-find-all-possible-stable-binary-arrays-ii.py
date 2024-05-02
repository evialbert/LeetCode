class Solution:
    def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
        mod = 1_000_000_007 
        dp = [[[0]*2 for _ in range(one+1)] for _ in range(zero+1)]
        for i in range(1, min(zero+1, limit+1)): dp[i][0][0] = 1 
        for j in range(1, min(one+1, limit+1)): dp[0][j][1] = 1
        for i in range(1, zero+1): 
            for j in range(1, one+1): 
                dp[i][j][0] = (dp[i-1][j][1] + dp[i-1][j][0]) % mod 
                if i-1-limit >= 0: dp[i][j][0] = (dp[i][j][0] - dp[i-1-limit][j][1]) % mod
                dp[i][j][1] = (dp[i][j-1][0] + dp[i][j-1][1]) % mod
                if j-1-limit >= 0: dp[i][j][1] = (dp[i][j][1] - dp[i][j-1-limit][0]) % mod 
        return (dp[zero][one][0] + dp[zero][one][1]) % mod 