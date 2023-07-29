class Solution {
public:
    double soupServings(int n) {
        if(n>4800){
            return 1.0;
        }

        n = (n+24)/25;

        double dp[n+1][n+1];
        dp[0][0] = 0.5;
        for(int i=1;i<=n;i++){
            dp[0][i] = 1.0;
            dp[i][0] = 0.0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j] = 0.25 * (dp[(i-4 >= 0)?i-4:0][j] + dp[(i-3 >= 0)?i-3:0][(j-1>=0)?j-1:0] + dp[(i-2>=0)?i-2:0][(j-2>=0)?j-2:0] + dp[(i-1>=0)?i-1:0][(j-3>=0)?j-3:0]);
            }
        }

        return dp[n][n];
    }
};