class Solution {
public:
    long m=1e9+7;
    int dp[10001][7][7];
    int distinctSequences(int n) {
        memset(dp,-1,sizeof(dp));
        return helper(7,7,1,n);
    }
    long helper(int pre1,int pre,int idx,int &n){
        if(idx==n+1)
            return 1;
        if(dp[idx][pre-1][pre1-1]!=-1)
            return dp[idx][pre-1][pre1-1];
        long ans=0;
        for(int i=1;i<=6;i++)
            if(__gcd(i,pre)==1 && i!=pre && i!=pre1)
                    ans=(ans+helper(pre,i,idx+1,n))%m;
        dp[idx][pre-1][pre1-1]=ans;
        return ans;
    }
};