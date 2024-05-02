class Solution {
public:
    long long dp[201][201][2];
    const int mod=1e9+7;
    long long find(int one,int zero,int flag,int limit)
    {
        if(one==0&&zero==0) return 1;
        long long ans=0;
        if(dp[one][zero][flag]!=-1) return dp[one][zero][flag]%mod;
        if(flag)
        {
            for(int i=1;i<=min(one,limit);i++)
            {
                ans+=find(one-i,zero,!flag,limit);
            }
        }
        else
        {
            for(int i=1;i<=min(zero,limit);i++)
            {
                ans+=find(one,zero-i,!flag,limit);
            }
        }
        return dp[one][zero][flag]= ans%mod;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,-1,sizeof(dp));
        int startWithOne=find(one,zero,1,limit)%mod;
        int startWithZero=find(one,zero,0,limit)%mod;
        return (startWithOne+startWithZero)%mod;
    }
};