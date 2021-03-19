class Solution {
     public boolean canIWin(int m, int t) {
        if(m>t) return true;
        if((m*(m+1))>>1 < t) return false;
        return helper(0, m, t, new int[1<<m]);
    }
    
    private boolean helper(int bits, int m, int t, int[] dp) {
        if(dp[bits] != 0) return dp[bits] == 1;
        
        for(int i=0; i<m; i++) {
            if(((bits >> i)&1) == 0 && (i+1 >= t || !helper(bits | (1<< i), m, t-i-1, dp))) {
                dp[bits] = 1;
                return true;
            }
        }
    
        dp[bits] = -1;
        return false;
    }
}