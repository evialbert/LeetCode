#define ll long long int

class Solution {
public:
    ll dp[50001][4][4];

    ll tdp(int in, int pc, int nc, vector<vector<int>>&A, int n){
        if(in >= (n>>1))return 0;
        if(dp[in][pc][nc]!=-1)return dp[in][pc][nc];
        ll ans = LLONG_MAX;
        for(int i=0;i<3;i++){
            if((i+1)!=pc){
                for(int j=0;j<3;j++){
                    if(((j+1)!=nc) && i!=j)ans=min(ans, A[in][i]+A[n-1-in][j]+tdp(in+1, i+1, j+1, A, n));
                }
            }
        }
        return dp[in][pc][nc]=ans;
    }

    long long minCost(int n, vector<vector<int>>& cost) {
        memset(dp, -1, sizeof(dp));
        return tdp(0, 0, 0, cost, n);
    }
};