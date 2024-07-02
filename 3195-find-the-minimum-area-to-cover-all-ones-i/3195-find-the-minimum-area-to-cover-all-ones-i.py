class Solution:
    def minimumArea(self, grid: List[List[int]]) -> int:
        rowMax = colMax = float('-inf')
        rowMin = colMin = float('inf')
        n = len(grid)
        m = len(grid[0])
        for i in range(n):
            for j in range(m):
                if grid[i][j]==1:
                    rowMin = min(rowMin,i)
                    rowMax = max(rowMax,i)
                    colMin = min(colMin,j)
                    colMax = max(colMax,j)
        return (rowMax - rowMin + 1)*(colMax - colMin + 1) if rowMax!=float('-inf') else 0
        