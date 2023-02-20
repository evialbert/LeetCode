class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        dp[0] = 1;
        int max = 1, sign;
        sign = 0;
        for(int i=1; i<n; i++)
        {
            if((nums[i] - nums[i-1] > 0 && sign != 1) || (nums[i] - nums[i-1] < 0 && sign != -1))
            {
                dp[i] = 1 + dp[i-1];
                sign = (nums[i] - nums[i-1] > 0)?1:-1;
            }
            else
                dp[i] = max;
            max = (dp[i]>max)?dp[i]:max;
        }
        for(auto x:dp)
            cout<<x<<endl;
        return dp[n-1];
    }
};