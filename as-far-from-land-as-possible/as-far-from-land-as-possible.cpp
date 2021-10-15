class Solution {
public:
    
    int maxDistance(vector<vector<int>>& grid) {
        
        int m = grid.size(); 
        int n = m > 0 ? grid[0].size() : 0;
        
        // x, y, level
        using QEntry = tuple<int,int,int>;
        queue<QEntry> q;
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j, 0});
                }
            }
        }
        
        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        
        int res = -1;
        while (!q.empty()) {
            auto [x, y, level] = q.front();
            q.pop();
            
            if (grid[x][y] == 0) {
                grid[x][y] = level;
                res = max(res, grid[x][y]);
            }
            
            
            for (const vector<int>& v : dir) {
                
                int nx = x + v[0];
                int ny = y + v[1];
                
                if (nx < 0 || ny < 0 || nx >= grid.size() 
                   || ny >= grid[0].size() || grid[nx][ny] != 0) continue;
                q.push({nx, ny, level+1});
            }
        }
        
        return res;
    }
};