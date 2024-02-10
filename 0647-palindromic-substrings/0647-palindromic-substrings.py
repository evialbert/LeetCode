class Solution:
    def countSubstrings(self, s: str) -> int:
        m = len(s)
        dp = []
        for i in range(m):
            x = []
            for j in range(m):
                if i == j:
                    x.append(1)
                else:
                    x.append(0)
            dp.append(x)
            
        for i in range(m):
            for j in range(i,m):
                if j - i == 1:
                    if s[i] == s[j]:
                        dp[i][j] = 1
            
        for i in range(m-1,-1,-1):
            for j in range(m-1,-1,-1):
                if j - i > 1:
                    if s[i] == s[j] and dp[i+1][j-1] == 1:
                        dp[i][j] = 1
                        
        res = 0
        for i in dp:
            res += sum(i)
        return res