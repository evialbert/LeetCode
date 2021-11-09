class Solution {
	public int[] pathsWithMaxScore(List<String> board) {
		int[] ans = new int[2];
		int[][] dp = new int[board.size()][board.get(0).length()];
		long[][] paths = new long[board.size()][board.get(0).length()];
		int[][] dirs = { { 1, 0 }, { 0, 1 }, { 1, 1 } };
		paths[board.size() - 1][board.get(0).length() - 1] = 1;
		for (int i = board.size() - 1; i >= 0; i--) {
			for (int j = board.get(0).length() - 1; j >= 0; j--) {
				char c = board.get(i).charAt(j);
				if (c == 'X' || c == 'S') {
					dp[i][j] = 0;
				}
				int val = c == 'E' ? 0 : Character.getNumericValue(c);
				for (int[] dir : dirs) {
					int ii = i + dir[0], jj = j + dir[1];
					if (ii < board.size() && jj < board.size() && board.get(ii).charAt(jj) != 'X') {
						dp[i][j] = Math.max(dp[i][j], val + dp[ii][jj]);
					}
				}
				for (int[] dir : dirs) {
					int ii = i + dir[0], jj = j + dir[1];
					if (ii < board.size() && jj < board.size() && board.get(ii).charAt(jj) != 'X') {
						if (dp[ii][jj] == dp[i][j] - val) {
							paths[i][j] += paths[ii][jj];
							paths[i][j] %= (1e9 + 7);
						}
					}
				}
			}
		}
		ans[0] = dp[0][0];
		ans[1] = (int) (paths[0][0] % (1e9 + 7));
		return ans[1] == 0 ? new int[] { 0, 0 } : ans;
	}
}