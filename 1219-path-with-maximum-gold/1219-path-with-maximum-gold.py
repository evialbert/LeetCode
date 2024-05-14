class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        
        r,c = len(grid), len(grid[0])
        def dfs(i,j,gold):
            nonlocal res
            if i<0 or j<0 or i>=r or j>=c or (i,j) in visited or grid[i][j] == 0:
                res = max(res,gold)
                return 0
            visited.add((i,j))
            dfs(i+1,j,gold+grid[i][j])
            dfs(i-1,j,gold+grid[i][j])
            dfs(i,j+1,gold+grid[i][j])
            dfs(i,j-1,gold+grid[i][j])
            visited.remove((i,j))
            return res
        visited = set()
        res,rest = 0,0
        for i in range(r):
            for j in range(c):
                t = dfs(i,j,0)
                rest = max(rest, t)
        return rest