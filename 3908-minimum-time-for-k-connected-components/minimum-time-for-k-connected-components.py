class DSU:
    def __init__(self, n):
        self.pile = list(range(n))
        self.cnt = n
    def find(self, x):
        while self.pile[x] != x:
            self.pile[x] = self.pile[self.pile[x]]
            x = self.pile[x]
        return x
    def union(self, a, b):
        ra = self.find(a)
        rb = self.find(b)
        if ra != rb:
            self.pile[rb] = ra
            self.cnt -= 1

class Solution:
    def minTime(self, n: int, edges: list[list[int]], k: int) -> int:
        timeBy = {}
        for u, v, t in edges:
            timeBy.setdefault(t, []).append((u, v))
        times = sorted(timeBy.keys(), reverse=True)
        dsu = DSU(n)
        mini = None
        for t in times:
            if dsu.cnt >= k:
                mini = t
            for u, v in timeBy[t]:
                dsu.union(u, v)
        if dsu.cnt >= k:
            mini = 0
        return mini