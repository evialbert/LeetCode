class Solution {
public:
    int mod = 1e9 + 7;
    int f(vector<int>& nums, int mask, int prev, int ind, vector<vector<int>>& dp) {
        if(ind == nums.size()) {
            return 1;
        }
        if(dp[prev+1][mask] != -1) return dp[prev+1][mask];
        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            if((mask & (1<<i))) continue;
            if(prev == -1 or nums[i] % nums[prev] == 0 or nums[prev] % nums[i] == 0)
            {
                ans += f(nums, mask | (1<<i), i, ind+1, dp);
                ans = ans % mod;
            }
        }
        return dp[prev+1][mask] = ans;
    }
    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        vector<vector<int>> dp(15, vector<int>((1<<14)+5, -1));
        return f(nums, 0, -1, 0, dp);
    }
};