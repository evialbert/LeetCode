class Solution {
public:
    int mod = 1e9+7;
    int dp[100001][2][3];
    int solve(int idx,int n,int absentCount,int lateCount)
    {
        if(idx==n)
        return 1;
        if(dp[idx][absentCount][lateCount]!=-1)
        return dp[idx][absentCount][lateCount];
        long long tak1 = 0,tak2 = 0,tak3 = 0;
        if(lateCount<2)
            tak1 = solve(idx+1,n,absentCount,lateCount+1);

        if(absentCount<1)
            tak2 = solve(idx+1,n,absentCount+1,0);

        tak3 = solve(idx+1,n,absentCount,0);
        
        return dp[idx][absentCount][lateCount] = (tak1+tak2+tak3)%mod;
    }
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(0,n,0,0);
    }
};