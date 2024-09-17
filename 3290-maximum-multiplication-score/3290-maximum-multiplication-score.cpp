class Solution {
public:
    long long maxScore(std::vector<int>& a, std::vector<int>& b) {
        int n = b.size();
        std::vector<long long> dp(n, LLONG_MIN);
        std::vector<long long> prev(n, LLONG_MIN);

        // Initialize the first row of dp
        for (int j = 0; j < n; ++j) {
            dp[j] = (long long)a[0] * b[j];
        }

        for (int i = 1; i < 4; ++i) {
            prev = dp;
            std::vector<long long> new_dp(n, LLONG_MIN);

            long long current_max = LLONG_MIN;

            for (int j = i; j < n; ++j) {
                current_max = std::max(current_max, prev[j - 1]);
                new_dp[j] = current_max + (long long)a[i] * b[j];
            }

            dp = new_dp;
        }

        return *std::max_element(dp.begin(), dp.end());
    }
};