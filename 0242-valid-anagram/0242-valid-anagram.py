class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        ls1=list(s)
        ls2=list(t)
        ls1.sort()
        ls2.sort()
       
        if ls1==ls2:
         return True
        return False