class Solution {
    public int numDecodings(String s) {
        int n = s.length();
        long[] dp = new long[n + 1];
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            char second = s.charAt(i - 1);
            if (second == '*') {
                dp[i] += dp[i - 1] * 9;
            } else if (second >= '1' && second <= '9') {
                dp[i] += dp[i - 1];
            }
            if (i >= 2) {
                char first = s.charAt(i - 2);
                if (first == '*') {
                    if (second == '*') {
                        dp[i] += dp[i - 2] * 15;
                    } else if (second >= '0' && second <= '6'){
                        dp[i] += dp[i - 2] * 2;
                    } else if (second >= '7' && second <= '9') {
                        dp[i] += dp[i - 2] * 1;
                    }
                } else if (first == '1') {
                   if (second == '*') {
                        dp[i] += dp[i - 2] * 9;
                    } else if (second >= '0' && second <= '9') {
                        dp[i] += dp[i - 2];
                    }                    
                } else if (first == '2') {
                   if (second == '*') {
                        dp[i] += dp[i - 2] * 6;
                    } else if (second >= '0' && second <= '6'){
                        dp[i] += dp[i - 2];
                    }                
                }
            }
            dp[i] %= 1000_000_007;
        }
        return (int)dp[n];
    }
}