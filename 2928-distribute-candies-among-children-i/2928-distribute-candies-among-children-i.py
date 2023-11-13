class Solution:
    def distributeCandies(self, n: int, limit: int) -> int:
        if(n > limit * 3): return 0
        def combo(x):
            return x*(x-1)/2
        res = combo(n+2)

        if(n > limit): res -= 3 * combo(n-limit+ 1)
        if n - 2 >= 2 * limit: res += 3 * combo(n-2* limit)
        return int(res)