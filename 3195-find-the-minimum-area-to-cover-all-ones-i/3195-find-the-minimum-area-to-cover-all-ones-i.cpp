class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int minimum_x = n - 1;
        int maximum_x = 0;
        int minimum_y = m - 1;
        int maximum_y = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    minimum_x = min(minimum_x, j);
                    maximum_x = max(maximum_x, j);
                    minimum_y = min(minimum_y, i);
                    maximum_y = max(maximum_y, i);
                }
            }
        }
        return (maximum_x - minimum_x + 1) * (maximum_y - minimum_y + 1);
    }
};