class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                        int cStart) {
        vector<vector<int>> ans;
        int sz = rows * cols, f = 0, k = 1;
        while (size(ans) < sz) {
            for (int x = 0; x < k; x++) {
                if (0 <= rStart && rStart < rows && 0 <= cStart &&
                    cStart < cols)
                    ans.push_back({rStart, cStart});
                if (f == 0)
                    cStart += 1;
                else if (f == 1)
                    rStart += 1;
                else if (f == 2)
                    cStart -= 1;
                else if (f == 3)
                    rStart -= 1;
            }
            f = (f + 1) % 4;
            if (f == 0 || f == 2)
                k++;
        }
        return ans;
    }
};