class Solution {
public:
    vector<int> nums;
    long long helper(int i, vector<long long>& dp){
        if(i >= nums.size()) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        long long a, b=0;
        a= nums[i] + helper(i+1, dp);
        if(i+1 < nums.size()){
            b = nums[i] - nums[i+1] + helper(i+2, dp);
            return dp[i] = max(a, b);
        }
        else return dp[i] = a;
        
    }
    long long maximumTotalCost(vector<int>& nums) {
        this->nums= nums;
        vector<long long> dp(nums.size(),-1);
        return helper(0,dp);
       
    }
};