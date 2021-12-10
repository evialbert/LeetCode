class Solution {
    //{ x,  y}
    int[][][] dir = {{{-1,0},{1,0}}, // left, right
                     {{0,-1},{0,1}}, // up, down
                     {{-1,0},{0,1}}, // left, down
                     {{1,0},{0,1}}, // right, down
                     {{-1, 0},{0,-1}}, // left, up
                     {{1,0},{0,-1}}, // right up
                    };
    public boolean isSafe(int[][] grid, int i, int j, int m, int n){
        if(i<0 || i>=m || j<0||j>=n)
            return false;
        return true;
    }
    public boolean dfs(int[][] grid, boolean[][] visited, int i, int j, int m, int n){
        if(visited[i][j])
            return false;
        if(i==m-1 && j==n-1)
            return true;
        // System.out.println(i+" "+j);
        visited[i][j] = true;
        int[][] allowedDirection = dir[grid[i][j]-1];
        for(int[] d:allowedDirection){
            int i_=i+d[1];
            int j_=j+d[0];
            // go to the next cell and check whether you can come back or not
            if(isSafe(grid, i+d[1], j+d[0], m, n)){
                int new_street = grid[i_][j_];
                int[][] allowed_ = dir[new_street-1];
                boolean canComeBack = false;
                for(int[] d_:allowed_){
                    if(i_+d_[1]==i && j_+d_[0]==j){
                        canComeBack = true;
                        break;
                    }
                }
                if(canComeBack && dfs(grid, visited, i+d[1], j+d[0], m, n))
                    return true;
            }
        }
        visited[i][j] = false; // backtrack
        return false;
    }
    public boolean hasValidPath(int[][] grid) {
        int m =  grid.length;
        int n = grid[0].length;
        return dfs(grid, new boolean[m][n], 0, 0, m, n);
    }
}