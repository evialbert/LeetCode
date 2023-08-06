class Solution {
public:
    int numMusicPlaylists(int n, int g, int k) {
        long long dp[g + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i = 1; i<= g; ++i){
            for(int j = 1; j<=n; ++j){
                //new
                dp[i][j] += (n - j + 1) * dp[i - 1][j - 1];
                //old
                dp[i][j] += max(j - k, 0) * dp[i - 1][j];
                dp[i][j] %= 1000000007;
                }
            }
        return dp[g][n];
    }
};