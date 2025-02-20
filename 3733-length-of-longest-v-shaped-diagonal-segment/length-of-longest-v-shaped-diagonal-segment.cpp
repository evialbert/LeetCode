class Solution {
public:
    int dir[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    int n, m;
    int expected(int step) {
        if (step == 0)
            return 1;
        return (step % 2 == 1) ? 2 : 0;
    }
    int dfs(vector<vector<int>>& grid, int r, int c, int step, bool turned,
            int d) {
        int exp = expected(step + 1);
        int ans = 1;
        int nr = r + dir[d][0], nc = c + dir[d][1];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == exp) {
            ans = max(ans, 1 + dfs(grid, nr, nc, step + 1, turned, d));
        }
        if (!turned) {
            pair<int, int> nDir = {dir[d][1], -dir[d][0]};
            int nd = -1;
            for (int i = 0; i < 4; i++) {
                if (dir[i][0] == nDir.first && dir[i][1] == nDir.second) {
                    nd = i;
                    break;
                }
            }
            int nr2 = r + nDir.first, nc2 = c + nDir.second;
            if (nd != -1 && nr2 >= 0 && nr2 < n && nc2 >= 0 && nc2 < m &&
                grid[nr2][nc2] == exp) {
                ans = max(ans, 1 + dfs(grid, nr2, nc2, step + 1, true, nd));
            }
        }
        return ans;
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    for (int d = 0; d < 4; d++) {
                        maxi = max(maxi, dfs(grid, i, j, 0, false, d));
                    }
                }
            }
        }
        return maxi;
    }
};