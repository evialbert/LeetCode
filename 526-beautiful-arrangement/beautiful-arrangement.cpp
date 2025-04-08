class Solution {
public:
    bool bitSet(int n, int i) {
        return n & (1 << i);
    }

    int setBit(int n, int i) {
        return n | (1 << i);
    }

    int dfs(int n, int i, int used, std::vector<std::vector<int>> &dp) {
        if (i > n) return 1;

        if (dp[i][used] != -1) return dp[i][used];

        int ans = 0;

        for (int j = 1; j <= n; ++j) {
            if (bitSet(used, j)) continue;

            if (i % j == 0 || j % i == 0) {
                ans += dfs(n, i + 1, setBit(used, j), dp);
            }
        }
        return dp[i][used] = ans;
    }

    int countArrangement(int n) {
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>((1 << 16) + 1, -1));
        return dfs(n, 1, 0, dp);
    }
};