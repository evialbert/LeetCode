class Solution {
    public long maxTotal(int[] nums, String s) {
        int n = nums.length;
        long[][] dp = new long[n + 1][2];
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 2; j++) {
                long ans = dp[i + 1][0];
                boolean token = s.charAt(i) == '1' && j == 0;
                if (token)
                    ans = Math.max(ans, nums[i] + dp[i + 1][0]);
                if (i + 1 < n && s.charAt(i + 1) == '1')
                    ans = Math.max(ans, nums[i] + dp[i + 1][1]);
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
}