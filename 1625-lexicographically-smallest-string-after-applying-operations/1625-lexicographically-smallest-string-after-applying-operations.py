class Solution:
    def rotate(self,s,b):
        k = b%len(s)
        return s[len(s)-k:] + s[:len(s)-k]
    def add(self,s,a):
        res = ""
        for i in range(len(s)):
            if i%2==0:
                res+=s[i]
            else:
                res+=str((int(s[i])+a)%10)
        return res 
    def findLexSmallestString(self, s, a, b):
        Visit = set() 
        def dp(t):
            if t in Visit:
                return 
            Visit.add(t)
            dp(self.rotate(t,b))
            dp(self.add(t,a))
        dp(s)
        return min(Visit)