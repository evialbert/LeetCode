class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        swap(m,n);
        vector<vector<long long>> dp(n,vector<long long>(m));

        dp[0][0] =1;
        dp[n-1][m-1] = (n*m);

        for(int i=0; i < n; i++){
            for(int j=0; j< m; j++){
                if(i==j and i==0 || i==n-1 and j==m-1) continue;
                dp[i][j] += waitCost[i][j] + ((i+1)*(j+1));
            }
        }

        for(int i=1;i<n; i++){
            dp[i][0] += dp[i-1][0];
        }
        for(int j=1;j<m;j++){
            dp[0][j] += dp[0][j-1];
        }

        for(int i=1; i<n; i++){
            for(int j=1;j<m; j++){
                dp[i][j] += min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
    }
};