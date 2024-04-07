class Solution:
    def getSmallestString(self, s: str, k: int) -> str:
        if k==0:
            return s
        i = 0
        while k>=0 and i<len(s):
            tmp = ord(s[i])-ord('a')
            tmp = min(tmp, 26-tmp)
            if tmp<=k:
                s = s[:i]+'a'+s[i+1:]
                k -= tmp
                i += 1
            else:
                s = s[:i]+chr(ord(s[i])-k)+s[i+1:]
                break
        return s