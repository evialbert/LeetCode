class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        """
        BFS or DP
        """
        i, j = len(grid)-1, len(grid[0])-1
        memo = {}
        return self.getMin(grid, i, j, memo)
    
    def getMin(self, grid, i, j, memo):
        
        if (i, j) in memo:
            return memo[(i,j)]
        
        if i == 0 and j == 0 :
            return grid[0][0]
        
        topMin = self.getMin(grid, i-1, j, memo) if i>0 else float('inf')
        leftMin = self.getMin(grid, i, j-1, memo) if j>0 else float('inf')
        
        levelMin = grid[i][j] + min(topMin, leftMin)
        memo[(i,j)] = levelMin
        return levelMin
        