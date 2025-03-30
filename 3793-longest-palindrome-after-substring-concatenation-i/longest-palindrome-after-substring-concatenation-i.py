class Solution:
    def longestPalindrome(self, s: str, t: str) -> int:
        t = t[::-1]
        m = len(s)
        n = len(t)
        res = {}
        ans = 1
        for i in range(len(s)-1):
            for j in range(i+1,len(s)):
                if s[i:j+1] == s[i:j+1][::-1]:
                    ans = max(ans,j-i+1)
                if s[i+1:j+1] == s[i+1:j+1][::-1]:
                    res[i] = (j-i)
                    ans = max(res[i],ans)
        res1 = {}
        for i in range(len(t)-1):
            for j in range(i+1,len(t)):
                if t[i:j+1] == t[i:j+1][::-1]:
                    ans = max(ans,j-i+1)
                if t[i+1:j+1] == t[i+1:j+1][::-1]:
                    res1[i] = (j-i)
                    ans = max(ans,res1[i])
        res1[len(t)-1] = 0
        res[len(s)-1] = 0
        dp = [[0]*(len(t)+1) for _ in range(len(s)+1)]

        for i in range(1,len(s)+1):
            for j in range(1,len(t)+1):
                if s[i-1] == t[j-1]:
                    dp[i][j] = max(dp[i][j],(dp[i-1][j-1]+1))
               
                    # print(res[i-1],res1[j-1])
                    x = max(res[i-1],res1[j-1])
                    # print(i,j,res,res1)
                    ans = max(ans,(dp[i][j]*2)+x)
        return ans


                    

          