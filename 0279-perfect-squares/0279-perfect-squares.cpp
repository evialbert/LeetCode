class Solution {
public:
    int solve(int n,vector<int>& dp){
        if(n==0)return 0;
        if(dp[n]!=-1)return dp[n];
        int t1=INT_MAX;
        int j = 1,t=1;
        while(t<=n){
            t1 = min(t1,1 + solve(n-t,dp));
            j += 1;
            t = j*j; 
        }
        return dp[n] = t1;
    }
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};