class Solution:
    def beautySum(self, s: str) -> int:
        d = {}
        for i in range(len(s)):
            c = {}
            for j in range(i,len(s)):
                c[s[j]] = c.get(s[j],0) + 1
                x = max(c.values())
                y = min(c.values())
                if x > 1 and len(c.values()) != 1:
                    d[s[i:j+1]] = d.get(s[i:j+1],0) + x-y
        return sum(d.values())