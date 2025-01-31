class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        unordered_map<int, int> areas;
        int area = 0;
        int max_area = 0;
        for (int i = 0 ; i < grid.size() ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (grid[i][j] == 1) {
                    int counter = 0;
                    area++;
                    fill(grid, i, j, counter, -area);
                    areas[-area] = counter;
                    max_area = max(max_area, counter);
                }
            }
        }

        int dx[] = {1, 0, 0, -1},
            dy[] = {0, -1, 1, 0};

        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (grid[i][j] == 0) {
                    unordered_map<int, int> used_areas;
                    int total_area = 1;
                    for (int k = 0; k < 4; k++) {
                        int xx = i + dx[k];
                        int yy = j + dy[k];
                        if (inside(xx, yy, n, m) && grid[xx][yy] < 0) {
                            if (used_areas.find(grid[xx][yy]) == used_areas.end())
                                total_area += areas[grid[xx][yy]];
                            used_areas[grid[xx][yy]] = 1;
                        }
                        max_area = max(max_area, total_area);
                    }
                }
            }
        }

        return max_area;
    }
private:
    int inside(int i, int j, int n, int m) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    void fill(vector<vector<int>>& grid, int i, int j, int& counter, int area) {
        counter++;
        grid[i][j] = area;
        if (inside(i + 1, j, grid.size(), grid[0].size()) && grid[i + 1][j] == 1)
            fill(grid, i + 1, j, counter, area);
        if (inside(i - 1, j, grid.size(), grid[0].size()) && grid[i - 1][j] == 1)
            fill(grid, i - 1, j, counter, area);
        if (inside(i, j + 1, grid.size(), grid[0].size()) && grid[i][j + 1] == 1)
            fill(grid, i, j + 1, counter, area);
        if (inside(i, j - 1, grid.size(), grid[0].size()) && grid[i][j - 1] == 1)
            fill(grid, i, j - 1, counter, area);
    }
};