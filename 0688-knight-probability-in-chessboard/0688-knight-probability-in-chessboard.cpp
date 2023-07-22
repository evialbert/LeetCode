class Solution {
public:
    double dp[30][30][105];   
    vector<int> dx = {-2, -2, -1, 1, 2, 2, 1, -1};
    vector<int> dy = {-1, 1, 2, 2, 1, -1, -2, -2};
    
    double dfs(int i, int j, int n, int moves)
    {        
        if(i < 0 || i >= n || j < 0 || j >= n)
            return 0;

        if(moves <= 0)
            return 1;
        if(dp[i][j][moves] != 0)
            return dp[i][j][moves];      
        double ans = 0;
        
        for(int k = 0; k < 8; k++)
        {
            int new_row = i + dx[k];
            
            int new_col = j + dy[k];
            
            ans += dfs(new_row, new_col, n, moves - 1);
        }
        return dp[i][j][moves] = ans / 8.0;
    }
    
    double knightProbability(int n, int k, int row, int column) {
        memset(dp, 0, sizeof(dp));
        return dfs(row, column, n, k);
    }
};