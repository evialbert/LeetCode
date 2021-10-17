class Solution {
  public int getMaximumGold(int[][] grid) {
        int max = 0;
        int m = grid.length, n = grid[0].length;
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if(grid[r][c] == 0) continue;
                max = Math.max(max, dfs(grid, m, n, new boolean[m][n], r, c));
            }
        }
        return max;
    }
    
    public int dfs(int[][] grid, int m, int n, boolean[][] visiting, int r, int c) {
        if(r < 0 || c < 0 || r == m || c == n || grid[r][c] == 0 || visiting[r][c]) return 0;
        visiting[r][c] = true; //set to true when four sides exploration is in progress
        int left = dfs(grid, m, n, visiting, r, c - 1);
        int right = dfs(grid, m, n, visiting, r, c + 1);
        int up = dfs(grid, m, n, visiting, r - 1, c);
        int bottom = dfs(grid, m, n, visiting, r + 1, c);
        visiting[r][c] = false; //reset when done exploring all four sides
        return grid[r][c] + Math.max(left, Math.max(right, Math.max(up, bottom)));
    }
}