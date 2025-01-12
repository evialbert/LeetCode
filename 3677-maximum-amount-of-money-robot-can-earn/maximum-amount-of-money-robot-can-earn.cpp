class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size();
        int dp[501][501][3] = {0};
        if(coins[0][0]>=0){
            dp[0][0][2] = coins[0][0];
            dp[0][0][1] = coins[0][0];
            dp[0][0][0] = coins[0][0];
        }
        else {
            dp[0][0][2] = coins[0][0];
            dp[0][0][1] = 0;
            dp[0][0][0] = 0;
        }
        for(int i=1;i<n;i++)
        {
            if(coins[i][0]>=0){
                dp[i][0][2] = dp[i-1][0][2] + coins[i][0]; 
                dp[i][0][1] = dp[i-1][0][1] + coins[i][0]; 
                dp[i][0][0] = dp[i-1][0][0] + coins[i][0]; 
            }
            else {
                dp[i][0][2] = dp[i-1][0][2] + coins[i][0];
                dp[i][0][1] = max(dp[i-1][0][1] + coins[i][0], dp[i-1][0][2]);
                dp[i][0][0] = max(dp[i-1][0][0] +  coins[i][0], dp[i-1][0][1]);
            }
        }
        for(int i=1;i<m;i++)
        {
            if(coins[0][i]>=0){
                dp[0][i][2] = dp[0][i-1][2] + coins[0][i]; 
                dp[0][i][1] = dp[0][i-1][1]  +coins[0][i];
                dp[0][i][0] = dp[0][i-1][0]  +coins[0][i];
            }
            else {
                dp[0][i][2] = dp[0][i-1][2] + coins[0][i];
                dp[0][i][1] = max(dp[0][i-1][1] + coins[0][i], dp[0][i-1][2]);
                dp[0][i][0] = max(dp[0][i-1][0] +  coins[0][i], dp[0][i-1][1]);
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(coins[i][j]>=0){
                    dp[i][j][2] = max(dp[i-1][j][2], dp[i][j-1][2]) + coins[i][j]; 
                    dp[i][j][1] = max(dp[i-1][j][1], dp[i][j-1][1]) + coins[i][j]; 
                    dp[i][j][0] = max(dp[i-1][j][0], dp[i][j-1][0]) + coins[i][j]; 
                }
                else {
                    dp[i][j][2] = max(dp[i-1][j][2], dp[i][j-1][2]) + coins[i][j];
                    dp[i][j][1] = max(max(dp[i-1][j][1], dp[i][j-1][1]) + coins[i][j], max(dp[i-1][j][2], dp[i][j-1][2]));
                    dp[i][j][0] = max(max(dp[i-1][j][0], dp[i][j-1][0]) +  coins[i][j], max(dp[i-1][j][1], dp[i][j-1][1]));
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         for(int k=0;k<3;k++)
        //         {
        //             cout<<dp[i][j][k]<<",";
        //         }
        //         cout<<" ";
        //     }
        //     cout<<endl;
        // }
        return max(dp[n-1][m-1][0], max(dp[n-1][m-1][1], dp[n-1][m-1][2]));
    }
};