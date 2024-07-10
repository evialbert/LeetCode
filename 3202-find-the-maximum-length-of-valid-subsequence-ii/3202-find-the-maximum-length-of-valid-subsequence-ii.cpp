class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int sz = nums.size();
        int ans=0;
        vector<vector<int>> dp(sz,vector<int>(k));
        for (int i=0;i<sz;i++){
            for (int j=i-1;j>=0;j--){
                auto t = (nums[j]+nums[i])%k;
                dp[i][t]= max(dp[i][t],dp[j][t]+1);
                ans = max(ans,dp[i][t]);
            }
        }
        return ans+1;
    }
};