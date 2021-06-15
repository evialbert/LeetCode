class Solution {
    int[][] dp;
    static int M = 1000000007;
    public int numTilings(int N) {
        dp = new int[N+1][3];
        for(int i=0; i<N+1; i++){
            dp[i][0] = -1;
            dp[i][1] = -1;
            dp[i][2] = -1;
        }
        return solve(N, 0);
    }
    
    public int solve(int n, int a){
        // considering the nth column
        // a=0 nothing filled
        // a=1 top cell of nth column is filled
        // a=2 bottom cell of nth column is filled
        
        if(n==0 && a==0){
			// perfectly filled
            return 1;
        }
        
        if(n<=0){
            return 0;
        }
        
        if(dp[n][a] != -1){
            return dp[n][a];
        }
        
        long x = 0;        
        
        // nothing filled
        if(a == 0){
            // 2X1 vertically 
            x = solve(n-1, 0);
            
            // 2X1 horizontally
            x += solve(n-2, 0);
            
            // _| shape
            x += solve(n-1, 2);
            
            // 7 shape
            x += solve(n-1, 1);
        }
        // top cell is already filled
        else if(a == 1){
            // L shape
            x = solve(n-2, 0);
            
            // 2X1 horizontally in bottom row
            x += solve(n-1, 2);
        }
        // bottom cell is filled
        else{
            // inverted L
            x = solve(n-2, 0);
            
            // 2X1 horizontally in top row
            x += solve(n-1, 1);
        }
        
        x = x%M;
        return dp[n][a] = (int)x;
        
    }
}