class Solution:
    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        length = len(grid)
        for i in range(1, length):
            for j in range(len(grid[0])):
                grid[i][j] += min(grid[i-1][:j] + grid[i-1][j+1:])
        return min(grid[-1])      