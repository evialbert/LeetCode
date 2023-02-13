class Solution {
public: 
    int nthUglyNumber(int n) {
        int dp[n];
        int a2 = 0, a3 = 0, a5 = 0;
        dp[0] = 1;
        for(int i = 1; i < n; i++) {
            dp[i] = min(dp[a2] * 2, min(dp[a3] * 3, dp[a5] * 5));
            if(dp[i] == dp[a2] * 2) a2++;
            if(dp[i] == dp[a3] * 3) a3++;
            if(dp[i] == dp[a5] * 5) a5++;
        }
        return dp[n - 1];
    }
};