class Solution {
    private static final int MOD = 1_000_000_007;
    
    public int numOfArrays(int n, int m, int k) {
        return dfs(0, 0, n, m, k, new Integer[n + 1][m + 1][n + 1]);
    }
    
    private int dfs(int start, int min, int n, int m, int counter, Integer[][][] dp){
        if(start == n){
            return counter == 0 ? 1 : 0;
        }
        if(counter < 0){
            return 0;
        }
        if(dp[start][min][counter] != null){
            return dp[start][min][counter];
        }
        int res = 0;
        for(int i = 1; i <= m; i++){
            if(i > min){
                res = (res + dfs(start + 1, i, n, m, counter - 1, dp) % MOD) % MOD;  // current number is greater than min, update min and decrease counter by 1
            }else{
                res = (res + dfs(start + 1, min, n, m, counter, dp) % MOD) % MOD; // current number is less or equal to min
            }
        }
        dp[start][min][counter] = res;
        return res;
    }
}