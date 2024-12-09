class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n), pre(n);
        pre[0] = nums[0];
        for(int i = 1; i < n; i++){
            pre[i] = pre[i - 1] + nums[i];
        }
        long long ans = pre[k - 1];
        dp[k - 1] = max(0LL, ans);
        for(int i = k; i < n; i++){
            ans = max({ans, pre[i] - pre[i - k] + dp[i - k], pre[i] - pre[i - k]});
            dp[i] = max({dp[i], pre[i] - pre[i - k] + dp[i - k], pre[i] - pre[i - k]});
        }
        return ans;
    }
};