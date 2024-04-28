class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        lower,upper=[-1]*26,[-1]*26
        for i in range(len(word)):
            ch=word[i]
            if ch.islower():
                lower[ord(ch)-97]=i
            elif upper[ord(ch)-65]==-1:
                upper[ord(ch)-65]=i
        ans=0
        for i in range(26):
            if lower[i]!=-1 and upper[i]!=-1 and upper[i]>lower[i]:
                ans+=1
        return ans
        