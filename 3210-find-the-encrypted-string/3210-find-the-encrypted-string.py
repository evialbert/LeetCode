class Solution:
    def getEncryptedString(self, s: str, k: int) -> str:
        n=len(s)
        res=""
        for i in range(n):
            x=i+k
            if(x>=n):
                x=x%n
            res+=s[x]
        return res