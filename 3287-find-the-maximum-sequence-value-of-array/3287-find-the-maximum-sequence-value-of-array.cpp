class Solution {
    vector<vector<vector<int>>> func(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(k + 1, vector<int>(129)));
        dp[0][1][nums[0]] = 1;
        dp[0][0][0] = 1;

        for (int i = 1; i < n; i++) {
            dp[i][0][0] = 1;
            for (int j = 1; j <= k; j++) {
                for (int x = 0; x <= 128; x++) {
                    if (!dp[i][j][x])
                        dp[i][j][x] = dp[i - 1][j][x];
                    int next = nums[i] | x;
                    if (dp[i - 1][j - 1][x])
                        dp[i][j][next] = dp[i - 1][j - 1][x];
                }
            }
        }
        return dp;
    }

public:
    int maxValue(vector<int>& nums, int k) {
        vector<vector<vector<int>>> left = func(nums, k);
        reverse(begin(nums), end(nums));
        vector<vector<vector<int>>> right = func(nums, k);
        reverse(begin(right), end(right));
        int n = nums.size();
        int res = 0;
        for (int i = k - 1; i + k < nums.size(); i++) {
            for (int a = 0; a <= 128; a++) {
                for (int b = 0; b <= 128; b++) {
                    if (left[i][k][a] && right[i + 1][k][b]) {
                        res = max(res, a ^ b);
                    }
                }
            }
        }
        return res;
    }
};