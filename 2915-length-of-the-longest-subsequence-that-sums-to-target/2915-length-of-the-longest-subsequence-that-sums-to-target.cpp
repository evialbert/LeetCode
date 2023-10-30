class Solution {
public:
    int solve(vector<int>&nums , int index, int target,vector<vector<int>>&dp){
        if(target<0){
            return -1e9;
        }
        if(target==0){
            return 0;
        }
        if(index>=nums.size()){
            return -1e9;
        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        int inc = 1+ solve(nums, index+1 , target-nums[index],dp);
        int exc = solve(nums,index+1,  target,dp);
        return dp[index][target]=max(inc , exc);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(), vector<int>(target+1, -1));
        int ans = solve(nums, 0 ,target,dp);
        if(ans <=0){
            return -1;
        }
        return ans;
    }
};