class Solution {
    public int maxPathScore(int[][] grid, int k) {
        int n = grid.length, m = grid[0].length;
        int mxc = Math.min(k + 1, n + m + 5);
        int[][][] dp = new int[n][m][mxc];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int c = 0; c < mxc; c++)
                    dp[i][j][c] = -1;

        dp[0][0][0] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int c = 0; c < mxc; c++) {
                    if (dp[i][j][c] == -1) continue;

                    // move right
                    if (j + 1 < m) {
                        int cost = c + (grid[i][j + 1] > 0 ? 1 : 0);
                        if (cost < mxc) {
                            dp[i][j + 1][cost] = Math.max(dp[i][j + 1][cost],
                                                           dp[i][j][c] + grid[i][j + 1]);
                        }
                    }

                    // move down
                    if (i + 1 < n) {
                        int cost = c + (grid[i + 1][j] > 0 ? 1 : 0);
                        if (cost < mxc) {
                            dp[i + 1][j][cost] = Math.max(dp[i + 1][j][cost],
                                                           dp[i][j][c] + grid[i + 1][j]);
                        }
                    }
                }
            }
        }

        int ans = -1;
        for (int c = 0; c < mxc; c++)
            ans = Math.max(ans, dp[n-1][m-1][c]);
        return ans;
    }
}