class Solution {
public:
    long long maximumTripletValue(vector<int> &nums) {
        // support variables
        int len = nums.size();
        long long dp[3], val = nums[1], diff = nums[2], prod;
        // preparing dp
        dp[0] = nums[0];
        dp[1] = dp[0] - nums[1];
        dp[2] = max(dp[1] * nums[2], 0ll);
        // checking all the possible combinations
        for (int i = 3; i < len; i++) {
            prod = nums[i];
            // updating the first value
            dp[0] = max(dp[0], val);
            dp[1] = max(dp[1], dp[0] - diff);
            dp[2] = max(dp[2], dp[1] * prod);
            // preparing for the next round
            val = diff, diff = prod;
        }
        return dp[2];
    }
};