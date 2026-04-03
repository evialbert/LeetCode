class Solution {
    int n;

public:
    long long helper(int idx, vector<int>& nums, vector<int>& colors,
                     vector<long long>& dp) {
        if (idx >= n) {
            return 0;
        }

        if (dp[idx] != -1) {
            return dp[idx];
        }

        long long skip = LLONG_MIN;
        long long take = LLONG_MIN;

        if (idx + 1 < n && colors[idx] == colors[idx + 1]) {
            skip = helper(idx + 1, nums, colors, dp);
            take = helper(idx + 2, nums, colors, dp) + nums[idx];
        } else {
            take = helper(idx + 1, nums, colors, dp) + nums[idx];
        }

        return dp[idx] = max(take, skip);
    }

    long long rob(vector<int>& nums, vector<int>& colors) {
        n = nums.size();
        vector<long long> dp(n, -1);
        return helper(0, nums, colors, dp);
    }
};