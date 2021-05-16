class Solution {
    private static final int MOD = (int) 1e9 + 7;
    
    public int kInversePairs(int n, int k) {
        int[][] dp = new int[2][k + 1];
        dp[0][0] = 1;
        
        for (int i = 1; i <= n; i++) {
            int cur = i & 1;
            int prev = cur ^ 1;
            int sum = 0;
            
            int limit = Math.min(k, i * (i - 1) / 2);
            for (int j = 0; j <= limit; j++) {
                sum += dp[prev][j];
                
                if (j >= i) {
                    sum -= dp[prev][j-i];
                }
                
                sum = (sum % MOD + MOD) % MOD;
                dp[cur][j] = sum;
            }
        }
        
        return dp[n & 1][k];
    }
}