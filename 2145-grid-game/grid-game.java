class Solution {
    public long gridGame(int[][] grid) {
        long r1 = 0;
        for (int x : grid[0]) {
            r1 += x;
        }

        int n = grid[0].length;
        long r2 = 0;
        long minimumSum = (long) (n + 1) * 100000;

        for(int i = 0; i < n; ++i) {
            r1 -= grid[0][i];
            minimumSum = Math.min(minimumSum, Math.max(r1, r2));
            r2 += grid[1][i];
        }

        return minimumSum;
    }
}