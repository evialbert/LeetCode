class Solution {
    public int minDistance(String word1, String word2) {
        int commonLen = commonStringLength(word1, word2);
        
        return word1.length() + word2.length() - 2 * commonLen;
    }
    
    private int commonStringLength(String word1, String word2) {
        int n = word1.length();
        int m = word2.length();
        
        int[][] dp = new int[n + 1][m + 1];
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                char c1 = word1.charAt(i - 1);
                char c2 = word2.charAt(j - 1);
                
                if (c1 == c2) dp[i][j] = 1 + dp[i - 1][j - 1];
                
                else dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        return dp[n][m];
    }
}