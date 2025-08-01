class Solution
{
public:
    vector<int> findCoins(vector<int>& numWays)
    {
        int n=(int)numWays.size();
        int target[n+1];
        int dp[n+1];
        vector<int> ret;
        target[0]=1;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            target[i]=numWays[i-1];
        }
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            if(target[i]==dp[i])
            {
                continue;
            }
            if(target[i]==dp[i]+1)
            {
                ret.push_back(i);
                for(int j=i;j<=n;j++)
                {
                    dp[j]=dp[j]+dp[j-i];
                }
            }
            else
            {
                return {};
            }
        }
        return ret;
    }
};