class Solution:
    def countTrapezoids(self, points: List[List[int]]) -> int:
        mod = 10**9 + 7
        count = Counter(y for _, y in points)
       
        res, lines = 0, 0
        for n in count.values():
            res = (res + lines * n * (n-1) // 2) % mod
            lines += n * (n-1) // 2
        return res