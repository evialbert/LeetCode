class Solution {
    public int countIslands(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;

        int count = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    int val = dfs(grid, i, j);
                    if (val % k == 0) count++;
                }
            }
        }

        return count;
    }

    private int dfs(int[][] grid, int i, int j) {
        int m = grid.length;
        int n = grid[0].length;
        
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0) return 0;
        
        int val = grid[i][j];
        grid[i][j] = 0;
        
        return val + dfs(grid, i - 1, j) 
            + dfs(grid, i + 1, j) 
            + dfs(grid, i, j - 1) 
            + dfs(grid, i, j + 1);
    }
}