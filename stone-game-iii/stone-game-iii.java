class Solution {
    public String stoneGameIII(int[] piles) {
        int score = getAliceScore(piles);       
        if(score > 0) 
            return "Alice";
        else if(score < 0) 
            return "Bob";     
        return "Tie";
    }
    
    private int getAliceScore(int[] piles){
        int n = piles.length;
        int[] dp = new int[n + 1];
        for (int i = n - 1; i >= 0; i = i-1) {          
             dp[i] = piles[i] - dp[i + 1];           
             if (i < n - 1) {
                 dp[i] = Math.max(piles[i] + piles[i+1] - dp[i + 2],  dp[i]);
             }          
             if (i < n - 2) {
                 dp[i] = Math.max(piles[i] + piles[i+1] + piles[i+2] - dp[i + 3],  dp[i]);
             }
        }
        return dp[0];
    }
}