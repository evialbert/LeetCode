class Solution {
    public int lastStoneWeightII(int[] stones) {
        int n = stones.length;
        return minimumSubset(stones,n);
        
    }
    
  private static int minimumSubset(int[] arr, int n) {

		int range = 0;
		for (int i = 0; i < n; i++) {
			range += arr[i];
		}

		int min = Integer.MAX_VALUE;
		boolean[][] ans = isSubsetDP(arr, range / 2, n);
		for (int j = 0; j < (range / 2) + 1; j++) {
			if (ans[n][j]) {
				min = Math.min(range - 2 * j, min);
			}

		}
		return min;

	}

	private static boolean[][] isSubsetDP(int[] arr, int sum, int n) {
		boolean[][] dp = new boolean[n + 1][sum + 1];

		for (int i = 0; i < n + 1; i++) {
			for (int j = 0; j < sum + 1; j++) {
				if (i == 0)
					dp[i][j] = false;
				if (j == 0)
					dp[i][j] = true;
			}
		}

		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < sum + 1; j++) {
				if (arr[i - 1] <= j) {
					dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
				} else {
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
		return dp;
	}

	// simple recursion
	private static boolean isSubset(int[] arr, int sum, int n) {
		// base
		if (n == 0)
			return false;

		if (sum == 0 || sum == arr[n - 1])
			return true;

		return isSubset(arr, sum - arr[n - 1], n - 1) || isSubset(arr, sum, n - 1);

	}
}