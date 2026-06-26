/**
 * Time Complexity: O(rows * cols)
 * Space Complexity: O(1)
 * where `rows` is the number of the rows of the matrix `grid`
 *       `cols` is the number of the columns of the matrix `grid`
 */
class Solution {
 public:
  int maxScore(const vector<vector<int>> &grid) {
    const int rows = static_cast<int>(grid.size());
    const int cols = static_cast<int>(grid.front().size());
    int ret = numeric_limits<int>::min();
    for (int r = 0; r < rows; ++r) {
      int item = numeric_limits<int>::min();
      for (int current = grid[r][0], c = 1; c < cols; ++c) {
        item = max(item, current + grid[r][c]);
        current = max(0, current) + grid[r][c];
      }
      ret = max(ret, item);
    }

    for (int c = 0; c < cols; ++c) {
      int item = numeric_limits<int>::min();
      for (int current = grid[0][c], r = 1; r < rows; ++r) {
        item = max(item, current + grid[r][c]);
        current = max(0, current) + grid[r][c];
      }
      ret = max(ret, item);
    }

    for (int r = 1; r < rows - 1; ++r) {
      for (int c = 1; c < cols - 1; ++c) {
        ret = max(ret, grid[r][c]);
      }
    }
    return ret;
  }
};