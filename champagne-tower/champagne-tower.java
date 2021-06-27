class Solution {
    public double champagneTower(int poured, int query_row, int query_glass) {
        
        //think like 90deg triangle
        // 1
        // 1 1
        // 1 1 1 1
		// . . . . . .  so on
        
        //go through till rows+1 and column+2 
        //Why column+2 ? Because  single glass can have 2 sub glass
        double[][] dp = new double[query_row+1][query_glass+2];
        
        dp[0][0] = poured;
        
        for(int i=0;i<query_row;i++){
            for(int j=0;j<=query_glass;j++){
                if(dp[i][j]>1.0){
                    double spare = dp[i][j]-1.0;
                    dp[i][j]=1.0;
                    
                    //split equally both side
                    dp[i+1][j]+=spare/2;
                    dp[i+1][j+1]+=spare/2;
                    
                }
            }
        }
        //for large test cases 10^9 poured_Champagne but still we haven't achived 1.0 
        return Math.min(dp[query_row][query_glass],1.0);
    }
}