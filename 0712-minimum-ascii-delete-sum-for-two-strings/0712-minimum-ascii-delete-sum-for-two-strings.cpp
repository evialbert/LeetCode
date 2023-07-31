class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        int dp[1001][1001] = {{0}};
        dp[0][0] = 0;
        for(int i=1;i<=n;i++)
            dp[i][0] = s1[i-1] + dp[i-1][0];
        for(int i=1;i<=m;i++)
            dp[0][i] = s2[i-1] + dp[0][i-1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j] = min(s1[i-1]+dp[i-1][j], s2[j-1]+dp[i][j-1]);
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            }
        }
        return dp[n][m];
    }
};