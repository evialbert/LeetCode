class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold)
    {
        int n =  nums.size();
        vector<int>dp(n,0);

        for(int i = 0; i<n;i++)
        {
            if(nums[i]%2==0 and nums[i]<=threshold) //can be a potential start
             dp[i]=1;

            if(i==0) // takin about first element
             continue;


             if(nums[i]<=threshold and nums[i-1]%2!=nums[i]%2 and dp[i-1]!=0)
              dp[i]=dp[i-1]+1; 
        }
        return *max_element(dp.begin(),dp.end());
    }
};