class Solution {
public:
    int maxScore(vector<vector<int>>& grid) 
    {
        int n = grid.size(), m = grid[0].size(), ans = INT_MIN;
        vector<vector<int>> dp = grid;
        int maxi = grid[n - 1][m - 1];
        for (int i = m - 1; i >= 0; i--) dp[n - 1][i] = maxi, maxi = max(maxi, grid[n - 1][i]);
        maxi = grid[n - 1][m - 1];
        for (int i = n - 1; i >= 0; i--) dp[i][m - 1] = maxi, maxi = max(maxi, grid[i][m - 1]);
        dp[n - 1][m - 1] = -1e9;
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = m - 2; j >= 0; j--)
            {
                dp[i][j] = max({dp[i + 1][j], dp[i][j + 1], grid[i + 1][j], grid[i][j + 1]});
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++) ans = max(ans, dp[i][j] - grid[i][j]);
        }
        return ans;
    }
};