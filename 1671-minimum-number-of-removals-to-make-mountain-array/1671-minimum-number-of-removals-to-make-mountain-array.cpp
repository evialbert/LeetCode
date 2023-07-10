class Solution {
public:
    vector<int> lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        dp[0]=1;
        for(int i=1;i<n;i++){
            int ans=0;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    ans=max(ans,dp[j]);
                }
            }
            dp[i]=ans+1;
        }
        return dp;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> left = lengthOfLIS(nums);
        reverse(nums.begin(),nums.end());
        vector<int> right = lengthOfLIS(nums);
        int ans=0;
        reverse(right.begin(),right.end());
        for(int i=1;i<nums.size()-1;i++){
            if(left[i]!=1&&right[i]!=1)
            ans=max(ans,left[i]+right[i]-1);
        }
        return nums.size()-ans;
    }
};