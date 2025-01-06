class Solution {
    public int longestSubsequence(int[] nums) {
        int max = 1;
        for (int value : nums) max = Math.max(max, value);
        int[][] dp = new int[max+1][max];
        for (int num : nums) {
            int thisMax = 1;
            for (int i = max-1; i >= 0; i--) {
                if (num - i > 0 && dp[num - i][i] >= thisMax) thisMax = dp[num - i][i] + 1;
                if (num + i < max+1 && dp[num + i][i] >= thisMax) thisMax = dp[num + i][i] + 1;
                dp[num][i] = thisMax;
            }
        }
        max = 0;
        for (int[] row : dp) max = Math.max(max, row[0]);
        return max;
    }
}