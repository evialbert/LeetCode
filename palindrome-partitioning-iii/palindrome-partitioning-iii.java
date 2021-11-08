class Solution {
   public int palindromePartition(String s, int k) {
	int n = s.length();
	// changes[i][j]: changes needed for s[i...j] to turn into a palindrome
	int[][] changes = new int[n][n];
	for (int len = 2; len <= n; ++len) {
		for (int i = 0, j = i + len - 1; j < n; ++i, ++j) {
			changes[i][j] = changes[i+1][j-1] + (s.charAt(i) == s.charAt(j) ? 0 : 1);
		}
	}

	// dp[i][j]: min changes needed for s[0 ... j] to break into i groups with each palindrome.
	int[][] dp = new int[k + 1][n];
	for (int i = 0; i < n; ++i) {
		// Starts with 1 group
		dp[1][i] = changes[0][i];
	}

	for (int i = 2; i <= k; ++i) {
		// Explore dp[i][end], since for i groups, first i - 1 groups take at least i - 1 letters (each group has at least 1 letter), 
		// the last group (i.e., group i) starts at least from index i - 1
		for (int end = i - 1; end < n; ++end) {
			int min = n; // Initiated to the largest possible
			for (int start = i - 1; start <= end; ++start) {
				min = Math.min(min, dp[i - 1][start - 1] + changes[start][end]);
			}
			dp[i][end] = min;
		}
	}
	return dp[k][n - 1];
}
}