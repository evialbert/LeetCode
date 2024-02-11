class Solution {
public:
    int dp[70][70][70];
    vector<int>dy = {-1, 0, 1};
   
    int solve(int i, int j1, int j2, vector<vector<int>>& grid){
        if(i == grid.size() - 1){
            return grid[i][j1] + (j1 == j2 ? 0 : grid[i][j2]);
        }
        int &ret = dp[i][j1][j2];
        if(~ret)return ret;
        ret = 0;
        int add = grid[i][j1] + (j1 == j2 ? 0 : grid[i][j2]);
        for(int j = 0; j < 3; ++j){
            int col1 = j1 + dy[j];
            for(int k = 0; k < 3; ++k){
                int col2 = j2 + dy[k];
                if(col1 >= 0 && col1 < grid[0].size() && col2 >= 0 && col2 < grid[0].size()){  
                    ret = max(ret, solve(i + 1, col1, col2, grid) + add);
                }
            }
        }
        return ret;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof dp);
        return solve(0, 0, grid[0].size() - 1, grid);
    }
};