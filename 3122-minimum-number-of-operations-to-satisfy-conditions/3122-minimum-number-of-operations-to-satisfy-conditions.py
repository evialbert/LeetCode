class Solution:
    def minimumOperations(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        cnt = Counter([grid[i][0] for i in range(m)])
        book = {k: m - v for k, v in cnt.most_common(3)}
        book[-1] = m
        
        for j in range(1, n):
            cnt = Counter([grid[i][j] for i in range(m)])
            mc = cnt.most_common(3)
            new = {k: float('inf') for k, v in mc}
            for k1, v1 in mc:
                for k0, v0 in book.items():
                    if k1 != k0:
                        new[k1] = min(new[k1], v0 + (m - v1))
            new[-1] = min(book.values()) + m
            book = new
        return min(book.values())