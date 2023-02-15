class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix.size(), 0));
        for(int i=matrix.size()-1;i>=0;i--){
            for(int j=0;j<matrix.size();j++){
                if(i==matrix.size()-1)
                    dp[i][j] = matrix[i][j];
                else{
                    int temp = INT_MAX;
                    if(j-1>=0 && j-1<dp[0].size())
                        temp = min(temp, dp[i+1][j-1]);
                    if(j>=0 && j<dp[0].size())
                        temp = min(temp, dp[i+1][j]);
                    if(j+1>=0 && j+1<dp[0].size())
                        temp = min(temp, dp[i+1][j+1]);
                    dp[i][j] = matrix[i][j] + temp;
                }
            }
        }
        sort(dp[0].begin(), dp[0].end());
        return dp[0][0];
    }
};