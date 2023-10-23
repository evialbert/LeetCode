class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        l=[1]
        a = 4
        l.append(a)
        while(a<=n):
            a = a*4
            l.append(a)
        print(l)
        return n in l