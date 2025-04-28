class Solution {
public:
    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
        vector<int> rev(n);
        for (auto e : edges) {
            rev[e[1]] += 1 << e[0];
        }

        vector<int> dp(1 << n, -1);
        dp[0] = 0;

        for (int mask = 0; mask < (1 << n); mask++) {
            if (dp[mask] == -1) continue;
            int cnt = __builtin_popcount(mask);
            for (int v = 0; v < n; v++) {
                if (!(mask & (1 << v)) && (mask & rev[v]) == rev[v]) {
                    dp[mask | (1 << v)] = max(dp[mask | (1 << v)], dp[mask] + (cnt + 1) * score[v]);
                }
            }
        }
        
        return dp[(1 << n) - 1];
    }

private:
    
};