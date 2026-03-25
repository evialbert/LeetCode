class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        rows = len(grid)
        cols = len(grid[0])
        total = sum(sum(row) for row in grid)
        if total % 2 != 0:
            return False
        target = total // 2
        colSum = 0
        for i in range(cols - 1):
            for j in range(rows):
                colSum += grid[j][i]
            if colSum == target:
                return True
        rowSum = 0
        for j in range(rows - 1):
            for i in range(cols):
                rowSum += grid[j][i]
            if rowSum == target:
                return True
        return False
