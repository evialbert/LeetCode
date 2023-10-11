class Solution {
public:

    int dp[1001][1001][2];
    
    int f(int i, int j, vector<vector<int>>& grid, int mode){
        if(dp[i][j][mode] != -1) return dp[i][j][mode];
        int ans = 0;
        int x = mode ? i + 1 : i - 1;
        if(x < grid.size() and x >= 0 and j - 1 >= 0 and j + 1 < grid[0].size() and grid[x][j] and grid[x][j - 1] and grid[x][j + 1]){
           ans = 1 + min(f(x, j - 1, grid, mode), f(x, j + 1, grid, mode));
        }
        return dp[i][j][mode] = ans;
    }

    int countPyramids(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof dp);
        int ans = 0;
        for(int i = 0, n = grid.size(), m = grid[0].size(); i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]){
                    ans += f(i, j, grid, 0) + f(i, j, grid, 1);
                }
            }
        }
        return ans;
    }
};