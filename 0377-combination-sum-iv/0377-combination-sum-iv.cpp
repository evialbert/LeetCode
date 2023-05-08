class Solution 
{
public: 
    int combinationSum4(vector<int>& nums, int target) 
    {
        vector<unsigned int> dp(target + 1);
        dp[0] = 1;
        sort (nums.begin(), nums.end());
        for (int i = 1; i <= target; i++) 
        {
            for (auto it : nums) 
            {
                if (i < it) break;
                dp[i] += dp[i - it];
            }
        }
        return dp.back();
    }
    
};