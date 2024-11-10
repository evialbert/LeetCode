class Solution {
public:
    int mod = 1e9+7;
    int sumOfGoodSubsequences(vector<int>& nums) {
        unordered_map<long long, long long> dp,sum;
        //to avoid overflow checking we are using map we can use array as well
        long long res = 0;
        int ma = *max_element(nums.begin(),nums.end());
        for(auto &num : nums) {
            dp[num] = (dp[num] + 1) % mod;
            sum[num] = (sum[num] + num) % mod;
            sum[num] = (sum[num] + sum[num-1] + (num*dp[num-1]) % mod) % mod;
            sum[num] = (sum[num] + sum[num+1] + (num*dp[num+1]) % mod) % mod;
            dp[num] = (dp[num] + dp[num-1]) % mod;
            dp[num] = (dp[num] + dp[num+1]) % mod;
        }
        for(int i = 0;i <= ma;i++) {
            res = (res + sum[i]) % mod;
        }
        return res;
    }
};