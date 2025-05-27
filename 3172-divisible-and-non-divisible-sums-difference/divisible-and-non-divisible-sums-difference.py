class Solution:
    def differenceOfSums(self, n: int, m: int) -> int:
        total = n*(n+1)/2
        if m==1:
            return int(-total)
        an = n//m
        if an==0:
            return int(total)
        num2 = an*((2*m + (an-1)*m)/2)
        return int(total-(2*num2))