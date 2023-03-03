class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int c = 0;
		for (int i = 0, end = grid[i].size() - 1; i < grid.size(); i++) {
			int start = 0;
			while (start <= end) {
				int mid = (start + end) / 2;
				if (grid[i][mid] < 0) {
					end = mid - 1;
				} else {
					start = mid + 1;
				}
			}
			c+= grid[i].size() - start;
			end = start - 1;
		}
		return c;
    }
};