class Solution {
    
    private boolean dfs(int[][] grid, int i, int j, int m , int n) {
        if(i<0 || j<0 || i>=m || j>=n) {
            return false;
        } if (grid[i][j] == 1 || grid[i][j] == -1) {
            return true;
        }
        grid[i][j] = -1;
        boolean left = dfs(grid,i,j-1,m,n);//left
        boolean top = dfs(grid, i-1,j,m,n);//top
        boolean right = dfs(grid, i,j+1,m,n);//right
        boolean bottom = dfs(grid, i+1,j,m,n);//bottom
        return left && right && top && bottom;
    }
    public int closedIsland(int[][] grid) {
        int count = 0;
        for(int i=1; i<grid.length-1; i++) {
            for(int j=1; j<grid[0].length-1; j++) {
                if(grid[i][j] == 0) {
                    if(dfs(grid, i, j, grid.length,grid[0].length)) {
                        count++;   
                    }
                }
            }
        }
        return count;
    }
}