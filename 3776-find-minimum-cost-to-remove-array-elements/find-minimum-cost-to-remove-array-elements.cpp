class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int min_cost(vector<int>& nums , int first , int level){
        // Base Case
            // Only one Element left
        if(level == n)
        {
            return nums[first];
        }
            // Two Elements left
        if(level == n - 1)
        {
            return max(nums[level] , nums[first]);
        }

        if(dp[level][first] != -1)
        {
            return dp[level][first];
        }

        int ans = INT_MAX;
        // Removing first & second
        ans = min(ans , max(nums[first] , nums[level]) + min_cost(nums , level + 1 , level + 2));
        
        // Removing first & third
        ans = min(ans , max(nums[first] , nums[level + 1]) + min_cost(nums , level , level + 2));

        // Removing second & third
        ans = min(ans , max(nums[level] , nums[level + 1]) + min_cost(nums , first , level + 2));

        return dp[level][first] = ans;
    }
    int minCost(vector<int>& nums) {
        n = nums.size();
        dp.resize(n + 1 , vector<int> (n + 1 , -1));

        int ans = min_cost(nums , 0 , 1);
        return ans;
    }
};