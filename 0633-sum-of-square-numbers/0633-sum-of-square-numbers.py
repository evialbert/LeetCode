class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        first=0
        last=int(sqrt(c))
        if c<=2:
            return True
        
        while first<=last:
            k=(first*first) + (last*last) 
            if k==c:
                return True
            elif k<c:
                first=first+1
            else:
                last=last-1
        return False