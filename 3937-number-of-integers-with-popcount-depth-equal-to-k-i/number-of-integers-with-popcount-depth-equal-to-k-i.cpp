class Solution {
public:
    long long digit_dp(long long n, set<int>& S) {
        vector<int> digits;
        long long num = n;
        while (num) {
            digits.push_back(num % 2);
            num /= 2;
        }
        reverse(digits.begin(), digits.end());
        int m = digits.size();

        long long dp[51][2][51];
        memset(dp, 0, sizeof(dp));
        dp[0][1][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int tight = 0; tight < 2; tight++) {
                for (int c = 0; c <= i; c++) {
                    if (dp[i][tight][c] == 0) continue;
                    int lim = (tight) ? digits[i] : 1;
                    for (int d = 0; d <= lim; d++) {
                        int new_tight = (tight && (d == digits[i])) ? 1 : 0;
                        int new_c = c + (d == 1 ? 1 : 0);
                        dp[i+1][new_tight][new_c] += dp[i][tight][c];
                    }
                }
            }
        }

        long long total = 0;
        for (int tight = 0; tight < 2; tight++) {
            for (int c = 0; c <= m; c++) {
                if (S.find(c) != S.end()) {
                    total += dp[m][tight][c];
                }
            }
        }
        return total;
    }

    long long popcountDepth(long long n, int k) {
        if (k == 0) {
            return 1;
        }
        const int maxN = 500;
        vector<int> depth(maxN + 1, 0);
        depth[1] = 0;
        for (int i = 2; i <= maxN; i++) {
            int cnt = 0;
            int x = i;
            while (x) {
                cnt++;
                x &= (x - 1);
            }
            depth[i] = 1 + depth[cnt];
        }

        set<int> S;
        for (int i = 1; i <= maxN; i++) {
            if (depth[i] == k - 1) {
                S.insert(i);
            }
        }

        long long total = digit_dp(n, S);
        if (k == 1) {
            total--;
        }
        return total;
    }
};