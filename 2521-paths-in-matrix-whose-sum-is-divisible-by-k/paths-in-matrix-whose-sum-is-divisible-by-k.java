class Solution {
    int[][][] memo;
    int r , c;
    int mod = 1000000007;
    public int numberOfPaths(int[][] grid, int k) {
        int m = grid.length, n = grid[0].length;
        r = m;
        c = n;
        memo = new int[m][n][k];
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                for(int l = 0; l < k; l++) {
                    memo[i][j][l] = -1;
                }
            }
        }

        return dfs(0, 0, 0, grid, k);
        
    }

    private int dfs(int i, int j, int currSum, int[][] grid, int k) {
      if(i < 0 || i >= r || j < 0 || j >= c) return 0;
      currSum += grid[i][j];
      if(i == r - 1 && j == c - 1) {
        if(currSum % k == 0) return 1;
        else return 0;
      }
      int rem = currSum % k;

      if(memo[i][j][rem] != -1) return memo[i][j][rem];
      int ans = 0;

      ans += (dfs(i + 1, j, currSum, grid, k) % mod);
      ans += (dfs(i, j + 1, currSum, grid, k) % mod);

      return memo[i][j][rem] = ans % mod;
    }
}