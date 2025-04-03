class Solution:
    def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
        [a,b,c] = sorted([a,b,c])
        if a == 1: return n
        def lcm(x,y): return x*y//math.gcd(x,y)
        AB, BC, AC, ABC, r, s = lcm(a,b), lcm(b,c), lcm(a,c), lcm(lcm(a,b),c), n*a//3, n*a+1
        def unc(x): return x//a + x//b + x//c - x//AB - x//BC - x//AC + x//ABC
        while unc(s-1) - n > 0:
            m = (r+s)//2
            if unc(m) - n > 0: s = m
            else: r = m
        return max(i*((s-1)//i) for i in [a,b,c])
	