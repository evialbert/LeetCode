class Solution {
    int m, n;
    vector<vector<vector<long long>>> dp;
    int helper(vector<vector<int>>& grid, int i, int j, int dir) {
        if(i>=m || j>= n) return 0;
        if(i == m-1 && j == n-1){
            return 1;
        }

        if(grid[i][j] == 0){
            if(dp[i][j][0] != -1){
                return dp[i][j][0];
            }
            if(dp[i][j][1] != -1){
                return dp[i][j][1];
            }
        }
        else {
            if(dp[i][j][dir] != -1){
                return dp[i][j][dir];
            }    
        }

        if(grid[i][j] == 0){
            return dp[i][j][dir] = (helper(grid, i+1, j, 1) + helper(grid, i, j+1, 0)) % 1000000007;
        }

        if(dir == 0){
            return dp[i][j][dir] = helper(grid, i+1, j, 1);
        }

        return dp[i][j][dir] = helper(grid, i, j+1, 0);        
    }
public:
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.resize(m, vector<vector<long long>>(n,vector<long long>(2, -1)));
        return helper(grid, 0, 0, 0) ;
    }
};