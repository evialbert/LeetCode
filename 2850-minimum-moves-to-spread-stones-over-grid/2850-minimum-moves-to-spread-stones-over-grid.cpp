class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        vector<vector<int>> has;
        vector<pair<int, int>> need;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] > 1) {
                    has.push_back({i, j, grid[i][j] - 1});
                } else if (grid[i][j] == 0) {
                    need.emplace_back(i, j);
                }
            }
        }

        int n = (int)has.size();
        int m = (int)need.size();
        int all_set = (1 << m) - 1;
        
        auto cost = [&](int x, int y, int mask) -> int {
            int tot = 0;
            for (int i = 0; i < m; i++) {
                if (mask & (1 << i)) {
                    tot += abs(x - need[i].first) + abs(y - need[i].second);
                }
            }
            return tot;
        };
        
        vector<vector<int64_t>> dp(n + 1, vector<int64_t>(all_set + 1, -1));
        function<int64_t(int, int)> f = [&](int i, int mask) -> int64_t {
            if (all_set == mask)
                return 0;
            if (i == n) 
                return INT_MAX;
            int64_t& ans = dp[i][mask];
            if (ans != -1)
                return ans;
            ans = INT_MAX;
            for (int bs = 1; bs <= all_set; bs++) {
                if ((mask & bs) == 0 and __builtin_popcount(bs) <= has[i][2]) {
                    ans = min(ans, f(i + 1, mask | bs) + cost(has[i][0], has[i][1], bs));
                }
            }
            return ans;
        };
        return f(0, 0);
    }
};