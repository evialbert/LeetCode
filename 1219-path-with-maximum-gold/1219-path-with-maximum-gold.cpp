class Solution {
private:
    int dy[4] = {0,0,1,-1}; // For traveling in all 4 direction
    int dx[4] = {1,-1,0,0};
    int maxi = 0; // For maintaining maximum gold
    bool Issafe(vector<vector<int>>& grid, vector<vector<int>> &vis, int r, int c, int m, int n){
        return r>=0 and c>=0 and r<m and c<n and vis[r][c]==0 and grid[r][c]!=0;  // For checking for Safety 
    }
    void dfs(vector<vector<int>>& grid, vector<vector<int>> &vis, int r, int c, int m, int n, int cnt){
        vis[r][c] = 1;
        cnt += grid[r][c];
        for(int k=0; k<4; k++){  // Tra el in all 4  Direction
            int nr = r+dy[k];
            int nc = c+dx[k];
            if(Issafe(grid, vis, nr, nc, m, n)){
                dfs(grid,vis, nr, nc, m, n, cnt);  
            }
            maxi = max(maxi, cnt);
        }
        vis[r][c] = 0; // Backtrack for travel again
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]!=0){
                    int cnt = 0;
                    dfs(grid,vis, i, j, m, n, cnt);
                }
            }
        }
        return maxi;
    }
};