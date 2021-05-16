class Solution {
 public int cherryPickup(int[][] g) {
        int n = g.length;
        int[][][] dp = new int[n][n][n];
        
        for(int x1 = 0; x1 < n; x1++) {
            for(int y1 = 0; y1 < n; y1++) {
                Arrays.fill(dp[x1][y1], Integer.MIN_VALUE);
            }   
        }
        
        dp[0][0][0] = g[0][0];
        
        
        for(int x1 = 0; x1 < n; x1++) {
            for(int y1 = 0; y1 < n; y1++) {
                if(g[x1][y1] == -1) continue;
                for(int x2 = 0; x2 < n; x2++) {
                    int y2 = x1 + y1 - x2;
                    if(y2 < 0 || y2 >= n || g[x2][y2] == -1) continue;
					
                    int max = Integer.MIN_VALUE;
                    //x1, y1-1, x2, y2-1
                    if(checkValid(x1, y1-1, x2, n, g)) max = Math.max(max, dp[x1][y1-1][x2]); 
                        
                    //x1-1, y1, x2, y2-1
                    if(checkValid(x1-1, y1, x2, n, g)) max = Math.max(max, dp[x1-1][y1][x2]);                         
                        
                    //x1, y1-1, x2-1, y2
                    if(checkValid(x1, y1-1, x2-1, n, g)) max = Math.max(max, dp[x1][y1-1][x2-1]); 
                        
                    //x1-1, y1, x2-1, y2
                    if(checkValid(x1-1, y1, x2-1, n, g)) max = Math.max(max, dp[x1-1][y1][x2-1]);
                    
                    if(max == Integer.MIN_VALUE) continue;
                    
                    int v = g[x1][y1] + g[x2][y2];
                    if(x1 == x2) v /= 2;
                    dp[x1][y1][x2] = max + v;
                }
            }
        }
        
        return dp[n-1][n-1][n-1] == Integer.MIN_VALUE ? 0 : dp[n-1][n-1][n-1];
    }
    
    boolean checkValid(int x1, int y1, int x2, int n, int[][] g) {
        int y2 = x1 + y1 - x2;
        return x1 >= 0 && x1 < n
            && y1 >= 0 && y1 < n
            && x2 >= 0 && x2 < n
            && y2 >= 0 && y2 < n 
            && g[x1][y1] != -1
            && g[x2][y2] != -1;
    }
}