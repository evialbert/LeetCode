class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) 
    {
        const int MOD = 1e9 + 7;
        int n = nums.size(), last_idx = -1;
        vector<int> dp(n + 1, 0);
        for(int i = 1; i <= n; i++)
        {
            if(nums[i - 1] == 1)
            {
                if(last_idx == -1)
                {
                    dp[i] = 1;
                }
                else
                {
                    int total = (i - last_idx - 1);
                    dp[i] = (total * 1LL *  dp[i - 1]) % MOD;
                }
                last_idx = i - 1;
            }
            else
            {
                dp[i] = dp[i - 1];
            }
        }
        return dp[n];
    }
};