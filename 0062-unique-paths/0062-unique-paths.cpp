class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 and j==n-1){
                    dp[i][j]=1;
                    continue;
                }
                int bottom=0;
                int right=0;

                if(i+1<m)
                    bottom=dp[i+1][j];
                if(j+1<n)
                    right=dp[i][j+1];
                
                dp[i][j]=right+bottom;
            }
        }
        return dp[0][0];
    }
};