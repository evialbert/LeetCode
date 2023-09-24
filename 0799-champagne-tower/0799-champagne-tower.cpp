class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double dp[101][101] = {0.00};
        
        dp[0][0] = poured;
        
        for(int i=0 ; i<100 ; i++){
            for(int j=0 ; j<=i ; j++){
                
                if(dp[i][j]>=1){
                    dp[i+1][j] += (dp[i][j]-1)/2.0;
                    dp[i+1][j+1] += (dp[i][j]-1)/2.0;
					
                    dp[i][j] = 1;                // making dp[i][j] =1 -->means that our current glass is now completely filled and we will move to next glass
                }
            }
        }
        return dp[query_row][query_glass];
    }
    };