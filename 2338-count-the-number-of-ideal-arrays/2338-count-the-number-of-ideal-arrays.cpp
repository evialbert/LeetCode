class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> comb;
    static const int mod = (1e9 + 7);
    int idealArrays(int n, int mx) {
        int k = min({15, n + 1, mx + 1});
        dp = vector<vector<int>>(mx + 1, vector<int>(k, 1));
        comb = vector<vector<int>>(n, vector<int>(k));
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < k; j++) {
                if (j > i) break;
                if (i == j) comb[i][j] = 1;
                else if (j == 1) comb[i][j] = i;
                else comb[i][j] = (comb[i - 1][j - 1] + comb[i- 1][j]) % mod;
            }
        }
        long long ans = mx;
        for (int l = 2; l < k; l++) {
            for (int i = 1; i <= mx; i++) {        
                long long cur = 0;
                for (int a = i + i; a <= mx; a += i) {
                    cur = (cur + dp[a][l - 1]) % mod;
                }
                dp[i][l] = cur;
                ans = (ans + cur * comb[n - 1][l - 1]) % mod;
            }
        }
        return ans;
    }
};