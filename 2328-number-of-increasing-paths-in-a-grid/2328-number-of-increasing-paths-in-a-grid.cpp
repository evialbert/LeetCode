class Solution {
    vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
    vector<vector<int>> memo;
    int mod = 1000000007;
public:

    int solve(int i, int j, vector<vector<int>>& grid){
        if(memo[i][j]) return memo[i][j];

        unsigned long long ans = 1;
        for(auto d : dir){
            int ni = i + d.first;
            int nj = j + d.second;
            if(ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size() && grid[i][j] < grid[ni][nj])
            {
                ans += solve(ni, nj, grid) % mod;
            }
        }
        return memo[i][j] = ans % mod;
    }

    int countPaths(vector<vector<int>>& grid) {
        unsigned long long ans = 0;
        memo.resize(grid.size(), vector<int>(grid[0].size()));
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                ans += (solve(i, j, grid) % mod);
            }
        }
        return ans % mod;
    }
};
