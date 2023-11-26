class Solution {
public:
    int ans = 0;
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,INT_MAX));
        dp[0][1] = prices[0];
        for(int i=1;i<n;i++){
            dp[i][1] = min(dp[i-1][0],dp[i-1][1])+prices[i];
            for(int j=i-1;j>=0&&(2*j+1>=i);j--){
                dp[i][0] = min(dp[i][0],dp[j][1]);
            }
        }
        return min(dp[n-1][0],dp[n-1][1]);
    }
};