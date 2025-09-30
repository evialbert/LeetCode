class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n+1, 1e10);
        dp[0] = 0;
        unordered_map<int,int> mpp;
        mpp[0] = 0;
        long long prefix = 0;
        for(int i = 0; i < n; i++){
            prefix += nums[i];
            int rem = ((prefix % k) + k) % k;
            dp[i+1] = dp[i] + nums[i];
            if(mpp.count(rem)){
                int j = mpp[rem];
                dp[i+1] = min(dp[i+1], dp[j]);
            }

            mpp[rem] = i+1;
        }

        return dp[n];
    }
};