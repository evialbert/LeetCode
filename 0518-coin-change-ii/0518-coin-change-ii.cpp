class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, 0));
        
        for(int i=1; i<=coins.size(); ++i)
            for(int j=0; j<=amount; ++j){
                if(j==0) dp[i][j]=1;
                else if(j<coins[i-1]) dp[i][j]=dp[i-1][j];
                else dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
            }
        
        return dp[coins.size()][amount];
    }
};