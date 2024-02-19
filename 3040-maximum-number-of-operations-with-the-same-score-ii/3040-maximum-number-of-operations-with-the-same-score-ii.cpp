class Solution {
public:
    int solve(int i, int j, int sum, vector<int>& nums, vector<vector<int>>& dp) {
        if (i >= j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        int a = 0, b = 0, c = 0;
        
        if (i + 1 <= j && nums[i] + nums[i + 1] == sum) {
            a = 1 + solve(i + 2, j, sum, nums, dp);
        }
        if (j - 1 >= i && nums[j] + nums[j - 1] == sum) {
            b = 1 + solve(i, j - 2, sum, nums, dp);
        }
        if (nums[i] + nums[j] == sum) {
            c = 1 + solve(i + 1, j - 1, sum, nums, dp);
        }
        
        return dp[i][j] = max({a, b, c});
    }
    
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> dp1(n, vector<int>(n, -1));
        vector<vector<int>> dp2(n, vector<int>(n, -1));
        vector<vector<int>> dp3(n, vector<int>(n, -1));
        
        int a = solve(2, n - 1, nums[0] + nums[1], nums, dp1);
        int b = solve(0, n - 3, nums[n - 1] + nums[n - 2], nums, dp2);
        int c = solve(1, n - 2, nums[0] + nums[n - 1], nums, dp3);
        
        return 1 + max({a, b, c});
    }
};