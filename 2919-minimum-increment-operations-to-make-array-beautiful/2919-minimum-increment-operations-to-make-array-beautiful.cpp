class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> dp(n+3,0);
        for(int idx=n-1 ; idx>=0; idx--){
            long long ans=1e14;
            for(int d=0 ; d<3 ; d++){
                if(idx-d>=0){
                    ans=min(ans,max(0LL,k-(long long)nums[idx-d])+dp[idx+3-d]);
                }
            }
            dp[idx]=ans;
        }
        return min(dp[0],min(dp[1],dp[2]));
    }
};