class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int cnt=0;
        int n=nums.size();
        vector<int> dp(n, -1);
        dp[0]=0;
        for(int i=1; i<n; i++)
        {
            for(int j=i-1; j>=0; j--)
            {
                if(abs(nums[j]-nums[i])<=target && dp[j]!=-1)
                dp[i]=max(1+dp[j],dp[i]);
            }
        }
        return dp[n-1];
    }
};