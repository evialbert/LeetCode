/*
i == j: dp[i][j] = 1
i < j:
    1. s[i] != s[j]: dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1]
    2. s[i] == s[j] = 'a':
        2.1. no 'a' in (i+1, j-1): dp[i][j] = dp[i + 1][j - 1] * 2 + 2
        2.2 only one 'a' in (i+1, j-1): dp[i][j] = dp[i + 1][j - 1] * 2 + 1
        2.3 multiple 'a' in (i+1, j-1): dp[i][j] = dp[i + 1][j - 1] * 2 - dp[left+1][right - 1]
*/

class Solution {
    public int countPalindromicSubsequences(String S) {
        int n = S.length();
        long[][] dp = new long[n][n];
        int mod = (int)Math.pow(10, 9) + 7;
        for(int len = 1; len <= n; len++) {
            for(int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if(i == j) dp[i][j] = 1;
                else if(i == j - 1) dp[i][j] = 2;
                else {
                    if(S.charAt(i) != S.charAt(j)) dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
                    else {
                        char c = S.charAt(i);
                        int left = i + 1, right = j - 1;
                        while(left < j && S.charAt(left) != c) left++;
                        while(right > i && S.charAt(right) != c) right--;
                        if(left == j) dp[i][j] = dp[i + 1][j - 1] * 2 + 2;
                        else if(left == right) dp[i][j] = dp[i + 1][j - 1] * 2 + 1;
                        else dp[i][j] = dp[i + 1][j - 1] * 2 - dp[left+1][right - 1];
                    }
                }
                dp[i][j] = (dp[i][j] < 0 ? dp[i][j] + mod : dp[i][j]) % mod;
            }
        }
        return (int)dp[0][n-1];
        
    }
}