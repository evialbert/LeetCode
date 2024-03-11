class Solution:
    def minimumOperationsToWriteY(self, grid: List[List[int]]) -> int:
        n = len(grid)
        mid = n // 2

        # counts of [0,1,2] in y and other
        y = [0]*3
        other = [0]*3
        for i in range(n):
            for j in range(n):
                x = grid[i][j]
                if(
                    (i == j and i <= mid and j <= mid) #top left diag
                    or (i == n - 1 - j and i <= mid and n - 1 - j <= mid) #top right diag
                    or (i >= mid and j == mid) #bottom mid
                ):
                    y[x] += 1
                else:
                    other[x] += 1

        ans = float("inf")
        for p in permutations([0, 1, 2], 2):
            ans = min(ans, sum(y) - y[p[0]] + sum(other) - other[p[1]])
        return ans