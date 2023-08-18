class Solution {
public:
    int getmin(int i, int j, vector<vector<int>> &dp, int x)
    {        
        if(i==0 and j==0) return x;
        int n = dp.size(), m = dp[0].size();
        
        if(i==0) return dp[i][j-1] + x;
        if(j==0) return dp[i-1][j] + x;
        return min(dp[i-1][j], dp[i][j-1]) + x;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, 0));
        
        dp[0][0] = grid[0][0];
        
        for (int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                dp[i][j] = getmin(i,j, dp, grid[i][j]);
            }
        }
        return dp[n-1][m-1];
    }
};