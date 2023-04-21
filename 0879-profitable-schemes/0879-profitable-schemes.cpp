class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[101][101][101];

    int f(int i, int p, int c, int n, int minProfit, vector<int>& group, vector<int>& profit) {
        if(i == group.size()) {
            return p >= minProfit;
        }

        if(dp[i][p][c] != -1) return dp[i][p][c];

        int skip = f(i+1, p, c, n, minProfit, group, profit);
        int take = 0;
        if(c + group[i] <= n)
            take = f(i+1, min(p + profit[i], minProfit), c+group[i], n, minProfit, group, profit);

        dp[i][p][c] = (skip + take) % MOD;
        return dp[i][p][c] % MOD;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp, -1, sizeof(dp));
        return f(0, 0, 0, n, minProfit, group, profit);
    }
};