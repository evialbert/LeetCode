class Solution {
    public int longestPalindromeSubseq(String s) {
        char[] arr = s.toCharArray();
        int[][] memo = new int[arr.length][arr.length];
        
        return lps(arr, 0, arr.length - 1, memo);
    }
    
    private int lps(char[] chars, int i, int j, int[][] memo) {
        if(i >= j) {
            return i == j ? 1 : 0;
        }
        
        if(memo[i][j] > 0) {
            return memo[i][j];
        }
        
        if(chars[i] == chars[j]) {
            return memo[i][j] = 2 + lps(chars, i + 1, j - 1, memo);
        }
        
        return memo[i][j] = Math.max(lps(chars, i + 1, j, memo), lps(chars, i, j - 1, memo));
    }
}