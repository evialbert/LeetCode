class Solution:
    def doesAliceWin(self, s: str) -> bool:
        ans=0
        s1=set('aeiou')
        for i in s:
            if i in  s1:
                ans+=1
        if ans==0:
            return False
        return True