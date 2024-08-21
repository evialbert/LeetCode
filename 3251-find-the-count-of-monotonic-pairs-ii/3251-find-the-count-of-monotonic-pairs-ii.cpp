class Solution {
public:
    int dp[2001][2001],sp[2001][2001],mod=1e9+7;
    int countOfPairs(vector<int>& nums) {
        memset(dp,0,sizeof(dp));
        int n=nums.size();
        for(int i=0;i<=1000;i++) dp[n][i]=1;
        for(int i=1000;i>=0;i--) sp[n][i]=(dp[n][i]+sp[n][i+1])%mod;
        for(int ind=n-1;ind>=0;ind--) {
            for(int prev=1000;prev>=0;prev--) {
                int sum=0,mx=0;
                if(ind!=0) mx=max(nums[ind]-nums[ind-1]+prev,prev);
                if(ind==0 && prev<=nums[ind]) 
                    sum=(sum+sp[ind+1][prev]-sp[ind+1][nums[ind]+1])%mod;
                else if(ind!=0 && mx<=nums[ind]) 
                    sum=(sum+sp[ind+1][mx]-sp[ind+1][nums[ind]+1])%mod;
                dp[ind][prev]=sum;
                sp[ind][prev]=(dp[ind][prev]+sp[ind][prev+1])%mod;
            }
        }
        return dp[0][0];
    }
};