class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, -1, 0, 1};
    int mod = 1e9 +7;
    int dp[51][51][51];
    int func(int m, int n, int maxMove, int i, int j){
        if(maxMove < 0) return 0;
        if(i>=m || j>=n || i<0 || j<0) return 1;
        if(dp[i][j][maxMove]!=-1) return dp[i][j][maxMove]%mod;
        int ans = 0;
        for(int k = 0; k < 4; k++){
            int ni = i+dr[k];
            int nj = j+dc[k];
            ans=(ans+func(m, n, maxMove-1, ni, nj))%mod;
        }
        return dp[i][j][maxMove] = ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return func(m, n, maxMove, startRow, startColumn);
    }
};