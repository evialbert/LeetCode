class Solution {
    public int numberOfSets(int n, int k) {
        if (n - 1 >= k) {
            /* dp[i][j] = the number of ways to divide string of length i into (j+1) non-overlapping segments
               i is ALWAYS larger than or equal to j+1.
               dp[i][j] = dp[i-1][j] + (dp[i-1][j-1] + dp[i-2][j-1] + dp[i-3][j-1] + ... + dp[j][j-1])
             */
            int[] dp = new int[k];
            int[] sums = new int[k];
            int mod = (int)(1e9 + 7);
            
            /* diff is defined as (length - segments), whereas 'length' is the length of the line.
               each time, we start with dp[length][0] and goes diagonally to dp[length+1][1],...,dp[length+k-1][k-1] 
             */
            for (int diff = 1; diff < n - k + 1; diff++) {
                dp[0] = ((diff + 1) * diff) >> 1;
                sums[0] = (sums[0] + dp[0]) % mod;
                for (int segments = 2; segments <= k; segments++) {
                    dp[segments - 1] = (sums[segments - 2] + dp[segments - 1]) % mod;
                    sums[segments - 1] = (sums[segments - 1] + dp[segments - 1]) % mod;
                }
            }
            
            return dp[k - 1];
        } else {
            return 0;
        }
    }
}