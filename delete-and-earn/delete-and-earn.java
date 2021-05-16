class Solution {
    public int deleteAndEarn(int[] nums) {
		int[] dp = new int[10000];
		for(int i = 0; i < nums.length; i++) {
			dp[nums[i] - 1]++;
		}
		dp[0] = dp[0] * 1;
		dp[1] = Math.max(dp[0] * 1, dp[1] * 2);
		for(int j = 2; j < 10000; j++) {
			dp[j] = Math.max(dp[j - 2] + dp[j] * (j + 1), dp[j - 1]);
		}
		return dp[9999];
    }
}