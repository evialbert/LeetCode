class Solution:
    def balancedStringSplit(self, s: str) -> int:
        count=0
        r,l = 0,0
        for i in s:
            if i=="R":
                r+=1
            else:
                l+=1
            if l==r:
                count+=1
                r,l = 0,0
        return count