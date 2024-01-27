class Solution {
public:
    int kInversePairs(int n, int k) {
        long long int dp[n+1][k+1];
        int mod=1e9+7;
        memset(dp, 0, sizeof(dp));
        for(int i=0;i<=n;i++) dp[i][0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                if(j>=i) dp[i][j]=(((dp[i][j-1])+(dp[i-1][j])-(dp[i-1][j-i])+mod)%mod);
                else dp[i][j]=((dp[i][j-1])%mod + (dp[i-1][j])%mod)%mod;
            }
        }
        return dp[n][k];
    }
};