class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        long long n = matrix.size(), m = matrix[0].size();
        long long i = 0, j = m - 1;
        while ((i >= 0 && i < n) && (j >= 0 && j < m)) {
            if (matrix[i][j] == target) {
                return true;
            }
            else if (matrix[i][j] > target) {
                j--;
            }
            else {
                i++;
            }
        }
        return false;
    }
};