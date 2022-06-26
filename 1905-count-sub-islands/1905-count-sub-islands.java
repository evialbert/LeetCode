class Solution {
    int m = 0, n = 0;
    
    public int countSubIslands(int[][] grid1, int[][] grid2) {
        m = grid1.length;
        n = grid1[0].length;
        int subIslands = 0;
        
        // get rid of useless(non-overlapping) islands from grid1
        for(int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid2[i][j] == 0)
                    grid1[i][j] = 0;
            }
        }
        
        // fill grid1 and grid2
        for(int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid2[i][j] == 1)
                    if (dfs(grid1, grid2, i, j))
                        subIslands++;
            }
        }
        
        return subIslands;
    }
    
    int[] dirs = new int[]{0,1,0,-1,0};
    
    public boolean dfs(int[][] grid1, int[][] grid2, int x, int y){
        if (x < 0 || x >= m || y < 0 || y >= n || grid2[x][y] == 0)
            return true;
        
        // return false if grid2 has an island, but grid1 doesn't
        if (grid1[x][y] == 0)
            return false;
        
        grid1[x][y] = 0;
        grid2[x][y] = 0;
        boolean isSubisland = true;

        for(int i = 0; i < 4; i++){
            isSubisland = dfs(grid1, grid2, x + dirs[i], y + dirs[i + 1]) && isSubisland;
        }
        
        return isSubisland;
    }
}