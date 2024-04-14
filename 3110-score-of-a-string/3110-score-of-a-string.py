class Solution:
    def scoreOfString(self, s: str) -> int:
        x = []

        for i in range(len(s)):
            l = int(ord(s[i]))
            x.append(l)
        
        cnt = 0
        
        for j in range(len(x)-1):
            cnt += abs(x[j] - x[j+1])
        
        return cnt