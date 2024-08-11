class Solution {
private:
    void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();
        vis[r][c] = 1;
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};
        for(int i=0; i<4; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1 && !vis[nr][nc]){
                dfs(nr,nc,vis,grid);
            }
        }
    }
    int islands(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    cnt++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
public:
    int minDays(vector<vector<int>>& grid) {
        if(islands(grid)!=1) return 0;

        int m = grid.size();
        int n = grid[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    if(islands(grid)!=1) return 1;
                    grid[i][j]=1;
                }
            }
        }

        return 2;
    }   
};