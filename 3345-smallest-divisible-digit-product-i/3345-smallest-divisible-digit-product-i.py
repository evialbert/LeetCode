class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        def good(x):
            p=1
            for c in str(x):
                p*=int(c)
            return p%t==0
        while not good(n):
            n+=1
        return n       