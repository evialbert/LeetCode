class Solution {
   public int maxScore(List<List<Integer>> grid) {
        int res = Integer.MIN_VALUE;
        int m = grid.size();
        int n = grid.get(0).size();
        int[] dp = new int[n];
        for (int j = 0; j < n; j++) {
            dp[j] = Integer.MAX_VALUE;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int leftMin = Integer.MAX_VALUE, upperMin = Integer.MAX_VALUE;
                if (j - 1 >= 0) {
                    leftMin = Math.min(dp[j - 1], grid.get(i).get(j - 1));
                }
                if (i - 1 >= 0) {
                    upperMin = Math.min(dp[j], grid.get(i - 1).get(j));
                }
                dp[j] = Math.min(leftMin, upperMin);
                res = Math.max(res, grid.get(i).get(j) - dp[j]);
            }
        }
        return res;
    }
}