class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        n=len(s)
        res=[]
        for i in range(n):
            for j in range(n):
                a=s[i:j+1]
                if len(a)!=0:
                    if a.count(mode(a))<=2:
                        res.append(len(a))
        return max(res)