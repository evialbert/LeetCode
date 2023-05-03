class Solution {
public:
    int dp[301][301];
    int solve(vector<vector<char>> &matrix, int i, int j, int m, int n)
    {
        if(i>=m || j>=n || matrix[i][j] == '0')
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = 1 + min(min(solve(matrix, i+1, j, m, n), solve(matrix, i, j+1, m, n)), solve(matrix, i+1, j+1, m, n));
        
    }
    int maximalSquare(vector<vector<char>> &matrix) 
    {
        int ans = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j] == '1')
                    ans = max(ans, solve(matrix, i, j, m, n));
            }
        }
            
        return ans*ans;
    }
};