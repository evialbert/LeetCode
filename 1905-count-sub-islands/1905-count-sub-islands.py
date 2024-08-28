class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        m, n = len(grid1), len(grid1[0]) # dimensions 
        
        def fn(i, j): 
            """Return True if i, j is in a sub-island."""
            grid2[i][j] = 0 # mark as visited 
            ans = grid1[i][j]
            for ii, jj in (i-1, j), (i, j-1), (i, j+1), (i+1, j): 
                if 0 <= ii < m and 0 <= jj < n and grid2[ii][jj]: 
                    ans &= fn(ii, jj)
            return ans 
            
        ans = 0 
        for i in range(m):
            for j in range(n): 
                if grid2[i][j] and fn(i, j): ans += 1
        return ans 