class Solution {
    int[][] dirs = new int[][]{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int m;
    int n;
    public int[] hitBricks(int[][] grid, int[][] hits) {
        m = grid.length;
        n = grid[0].length;
        
        preprocess(grid, hits);
        
        int[] res = new int[hits.length];
        
        for (int k = hits.length - 1; k >= 0; k--) {
            int x = hits[k][0];
            int y = hits[k][1];
            if (grid[x][y] == 0) continue;
            grid[x][y] = 1;
            if(!isAttachedToRoof(x, y, grid)) continue;
            grid[x][y] = 2;
            for (int d = 0; d < dirs.length; d++) {
                int r = x + dirs[d][0];
                int c = y + dirs[d][1];
                if (r >= m || c >= n || r < 0 || c < 0) continue;
                if (grid[r][c] == 1) res[k] += dfs(grid, r, c);
            }  
        }
        return res;
    }
    
    
    private void preprocess(int[][] grid, int[][] hits) {
        // erase all bricks knocked off by hits
        for (int[] hit: hits) {
            grid[hit[0]][hit[1]] *= -1;
        }
        
        // preprocess mark all bricks attached to top with number 2
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1) dfs(grid, 0, j);
        }
    }
    
    // return true if an erased brick is attached to roof
    private boolean isAttachedToRoof(int x, int y, int[][] grid) {
        if (x == 0) return true;
        for (int d = 0; d < dirs.length; d++) {
                int r = x + dirs[d][0];
                int c = y + dirs[d][1];
                if (r >= m || c >= n || r < 0 || c < 0) continue;
                if (grid[r][c] == 2) return true;
        }
        return false;
    }

    // as iterating over all cells, mark them from 1 to 2
    private int dfs(int[][] grid, int x, int y) {
        int count = 1;
        grid[x][y] = 2;
        for (int d = 0; d < dirs.length; d++) {
            int r = x + dirs[d][0];
            int c = y + dirs[d][1];
            if (r >= m || c >= n || r < 0 || c < 0) continue;
            if (grid[r][c] == 1) {
                count += dfs(grid, r, c);          
            }
        }
        return count;
    }
}