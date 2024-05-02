class Solution:
    def buildCounters(self, grid, m, n):
        rCnt, cCnt = Counter(), Counter()
        for r in range(m):
            for c in range(n):
                rCnt[r] += grid[r][c]
                cCnt[c] += grid[r][c]
        return rCnt, cCnt

    def numberOfRightTriangles(self, grid):
        m, n = len(grid), len(grid[0])
        rCnt, cCnt = self.buildCounters(grid, m, n)
        return sum(
            (cCnt[c] - 1) * (rCnt[r] - 1)
            for r in range(m)
            for c in range(n)
            if grid[r][c]
        )