class Solution:
    def minimumSubstringsInPartition(self, s: str) -> int:
        n = len(s)
        dp = [0] * n
        dp[0] = 1
        for i in range(1, n):
            ans = float('inf')
            freq = {}
            for j in range(i, -1, -1):
                freq[s[j]] = freq.get(s[j], 0) + 1
                if len(set(freq.values())) == 1:
                    ans = min(ans, dp[j - 1] + 1)
            dp[i] = ans
        return dp[-1]
