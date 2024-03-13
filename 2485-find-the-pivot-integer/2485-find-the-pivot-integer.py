class Solution:
    def pivotInteger(self, n: int) -> int:
        l,h=1,n
        m=(l+h)>>1
        while l<=h:
            s1=m*(m+1)//2
            s2=(m+n)*(n-m+1)//2
            if s1==s2:
                return m
            elif s1<s2:
                l=m+1
            else:
                h=m-1
            m=(l+h)>>1
        return -1