class Solution 
{
public:
    long long dp[2][100011];
    long long maxEnergy(long long prev, long long i, vector<int> &a, vector<int> &b)
    {
        if(i>=a.size()) return 0;
        if(prev!=-1 && dp[prev][i]!=-1) return dp[prev][i];
        long long ans=0;
        if(prev==0) 
        {
            ans=max(ans,a[i]+maxEnergy(0,i+1,a,b));
            ans=max(ans,maxEnergy(1,i+1,a,b));
        }
        else if(prev==1) 
        {
            ans=max(ans,b[i]+maxEnergy(1,i+1,a,b));
            ans=max(ans,maxEnergy(0,i+1,a,b));
        }
        else
        {
            ans=max(ans,a[i]+maxEnergy(0,i+1,a,b));
            ans=max(ans,b[i]+maxEnergy(1,i+1,a,b));
        }
        return dp[prev][i]=ans;
    }
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) 
    {
        memset(dp,-1,sizeof(dp));
        return maxEnergy(-1,0,energyDrinkA,energyDrinkB);
    }
};