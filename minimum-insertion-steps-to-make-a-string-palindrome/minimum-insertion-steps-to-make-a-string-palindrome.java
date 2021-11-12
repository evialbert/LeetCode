class Solution {
    public int minInsertions(String s) {
        
        StringBuilder sb = new StringBuilder(s);
        
		// Basically your answer would be [Assuming that you know how to find longest common subsequence] -->
		//s.length() - lcs(s1, reverse(s1), n , m);
		// where n == s1.length;
		// m = s1.reverse().length();
        return s.length() - getPalindromicSubSequence(s,sb.reverse().toString(), s.length(), sb.length());
        
    }
    
    static int getPalindromicSubSequence(String s1, String s2, int n, int m){
        
        int[][] dp = new int[n+1][m+1];
        
        for(int i = 0; i <= n; ++i){
            for(int j = 0; j <= m; ++j){
                if(i == 0) dp[i][j] =  0;
                if(j == 0) dp[i][j] = 0;
            }
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(s1.charAt(i-1) == s2.charAt(j-1)){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = Math.max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    
}