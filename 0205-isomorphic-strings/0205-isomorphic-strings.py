class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        d = {}
        n = len(s)
        flag = False
        for i in range(n):
            if(s[i] not in d and t[i] not in d.values()):
                d[s[i]] = t[i]
            elif(s[i] in d and t[i] != d[s[i]]):
                return False
            elif(s[i] not in d and t[i] in d.values()):
                return False
        return True