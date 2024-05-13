class Solution:
    def matrixScore(self, grid: List[List[int]]) -> int:
        n=len(grid)
        m=len(grid[0])
        ans=0
        for j in range(m):
            col=sum(grid[i][j]==grid[i][0] for i in range(n))
            ans+=max(col,n-col)*2**(m-1-j)
        return ans    