class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), res = 0, s1 = 0, s2 = 0;
        
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < m / 2; j++) {
                int ones = grid[i][j] + grid[i][m - 1 - j] + grid[n - 1 - i][j] + grid[n - 1 - i][m - 1 - j];
                res += min(ones, 4 - ones);
            }

            if (m % 2) {
                int ones = grid[i][m / 2] + grid[n - 1 - i][m / 2];
                s1 += (ones == 1), s2 += (ones == 2);
            }
        }

        if (n % 2) {
            for (int i = 0; i < m / 2; i++) {
                int ones = grid[n / 2][i] + grid[n / 2][m - 1 - i];
                s1 += (ones == 1), s2 += (ones == 2);
            }
            if (m % 2) res += grid[n / 2][m / 2];
        }

        if (!(s2 % 2) || s1) return res + s1;
        return res + 2;
    }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
};
