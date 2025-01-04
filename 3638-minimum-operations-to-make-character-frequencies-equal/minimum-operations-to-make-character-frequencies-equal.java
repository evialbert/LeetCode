class Solution {
    private int f(int i, int passed, int tar, int[] v, int[][] dp) {
        if (i >= 26) return 0;
        if (dp[i][passed] != -1) return dp[i][passed];

        int ans = Integer.MAX_VALUE;
        if (v[i] > tar) {
            ans = Math.min(ans, (v[i] - tar) + f(i + 1, 0, tar, v, dp)); //delete the characters
            ans = Math.min(ans, (v[i] - tar) + f(i + 1, 1, tar, v, dp)); //pass the characters
        } else if (v[i] == tar) {
            ans = Math.min(ans, f(i + 1, 0, tar, v, dp)); //simply move to next character in string
        } else {
            // v[i] < tar
            if (passed == 1) {
                int req = 0;
                if (v[i - 1] < tar) {
                    req = (tar - v[i] - v[i - 1]);
                } else {
                    req = (tar - v[i] - (v[i - 1] - tar));
                }
                req = Math.max(req, 0);
                ans = Math.min(ans, req + f(i + 1, 0, tar, v, dp));
            } else {
                ans = Math.min(ans, (tar - v[i]) + f(i + 1, 0, tar, v, dp)); // insert the character
                ans = Math.min(ans, v[i] + f(i + 1, 0, tar, v, dp)); // delete all the characters
                ans = Math.min(ans, v[i] + f(i + 1, 1, tar, v, dp)); // pass all the characters
            }
        }
        return dp[i][passed] = ans;
    }

    public int makeStringGood(String s) {
        int n = s.length(), ans = Integer.MAX_VALUE;
        int[] v = new int[26];
        int maxi = 0;

        // Frequency array
        for (char ch : s.toCharArray()) {
            v[ch - 'a']++;
            maxi = Math.max(maxi, v[ch - 'a']);
        }

        // Try every frequency from 1 to maximum frequency
        for (int freq = 1; freq <= maxi; freq++) {
            int[][] dp = new int[26][2];
            for (int i = 0; i < 26; i++) {
                dp[i][0] = -1;
                dp[i][1] = -1;
            }
            ans = Math.min(ans, f(0, 0, freq, v, dp));
        }

        return ans;
    }
}