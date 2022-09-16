class Solution {
    public int countPyramids(int[][] grid) {
        int R = grid.length;
        int C = grid[0].length;
        int []dp = new int[C];
        int res = 0;
        for(int i = R-1; i>=0; i--){
            int prev = 0;
            for(int j = C-1; j>=0 ;j--){
                int curr = dp[j];
                if(grid[i][j] == 0)
                    dp[j] = 0;
                else
                    dp[j] = 1 + Math.min(prev, Math.min(dp[j], j==0?0:dp[j-1]));
                res += Math.max(0, dp[j]-1);
                prev = curr;
            }
        }
        Arrays.fill(dp, 0);
        for(int i = 0; i<R; i++){
            int prev = 0;
            for(int j = 0; j<C ;j++){
                int curr = dp[j];
                if(grid[i][j] == 0)
                    dp[j] = 0;
                else
                    dp[j] = 1 + Math.min(prev, Math.min(dp[j], j==(C-1)?0:dp[j+1]));
                res += Math.max(0, dp[j]-1);
                prev = curr;
            }
        }
        return res;
    }
}