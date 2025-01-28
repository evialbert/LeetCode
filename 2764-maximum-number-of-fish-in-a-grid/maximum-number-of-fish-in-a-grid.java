class Solution {

    int[] drow = {-1, 0, 1, 0};
    int[] dcol = {0, -1, 0, 1};

    public int dfs(int[][] grid, int i, int j, int n, int m){
        int count = grid[i][j];
        grid[i][j] = 0;
       
        for(int k = 0; k<4;k++){
            int row = i+drow[k];
            int col = j+dcol[k];

            if(row>=0 && row<n && col>=0 && col<m && grid[row][col] !=0)
                count+= dfs(grid, row, col, n, m);
        }
        return count;
    }

    public int findMaxFish(int[][] grid) {
        int n = grid.length, m=grid[0].length;
        int max = 0;

        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] != 0){
                    max = Math.max(max, dfs(grid, i, j, n, m));
                }
            }
        }
        return max;
    }
}