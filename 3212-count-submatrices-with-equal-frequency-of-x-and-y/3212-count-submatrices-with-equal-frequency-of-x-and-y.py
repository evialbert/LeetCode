class Solution:
    def numberOfSubmatrices(self, grid: List[List[str]]) -> int:
        M = len(grid)
        N = len(grid[0])

        mat = [[0] * N for _ in range(M)]

        res = 0
        for m in range(M):
            for n in range(N):
                x, y = mat[m][n - 1] if n != 0 else (0, 0)
                u, v = mat[m - 1][n] if m != 0 else (0, 0)
                a, b = mat[m - 1][n - 1] if m != 0 and n != 0 else (0, 0)

                xs, ys = (x + u - a + (grid[m][n] == 'X'), y + v - b + (grid[m][n] == 'Y'))

                mat[m][n] = (xs, ys)

                if xs == ys and xs != 0:
                    res += 1

        return res