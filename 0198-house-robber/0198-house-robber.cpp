class Solution {
public:
    int dfs(vector<int>& nums , int idx , vector<int> &dp){
        if(idx >= nums.size()){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        int take = nums[idx] + dfs(nums , idx+2 , dp); 
        int notTake = dfs(nums , idx+1 , dp);
        dp[idx] = max(take , notTake);
        return dp[idx];
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() , -1);
        return dfs(nums , 0 , dp);
    }
};