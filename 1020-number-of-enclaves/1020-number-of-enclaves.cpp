class Solution {
public:
int ct = 0;

void dfs(vector<vector<int>>& grid, int i, int j, int n, int m) {
	if (i < 0 || j < 0 || i >= n || j >= m) return;
	if (grid[i][j] != 1) return;
	grid[i][j] = 0;
	ct++;
	dfs(grid, i - 1, j, n, m);
	dfs(grid, i + 1, j, n, m);
	dfs(grid, i, j - 1, n, m);
	dfs(grid, i, j + 1, n, m);
}

int numEnclaves(vector<vector<int>>& grid) {
	int n = grid.size();
	int m = grid[0].size();
	for (int i = 0; i < n; ++i) {
		if (grid[i][0] == 1) dfs(grid, i, 0, n, m);
		if (grid[i][m - 1] == 1) dfs(grid, i, m - 1, n, m);
	}
	for (int i = 0; i < m; ++i) {
		if (grid[0][i] == 1) dfs(grid, 0, i, n, m);
		if (grid[n - 1][i] == 1) dfs(grid, n - 1, i, n, m);
	}
				ct = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] == 1) {
				dfs(grid, i, j, n, m);
			}
		}
	}
	return ct;
}
};