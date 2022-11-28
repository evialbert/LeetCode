class Solution {
public:
    int res = 0, cur = 0;
    vector<vector<int>> next{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void DFS(vector<vector<int>>& grid, int row, int cal) {
        cur++;
        grid[row][cal] = 0;
        res = max(res, cur);
        for(int k = 0; k < 4; k++) {
            int i = row + next[k][0];
            int j = cal + next[k][1];
            if(i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1) {
                DFS(grid, i, j);
            }
        }
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    cur = 0;
                    DFS(grid, i, j);
                }
            }
        }
        return res;
    }
};