
class Solution {
    public int minCost(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;
        if (k > 0 && grid[0][0] >= grid[m - 1][n - 1]) {
            return 0;
        }

        int mx = 0;
        for (int[] row : grid) {
            for (int x : row) {
                mx = Math.max(mx, x);
            }
        }

        int[] sufMinF = new int[mx + 2];
        Arrays.fill(sufMinF, Integer.MAX_VALUE);
        int[] minF = new int[mx + 1];
        int[] f = new int[n + 1];

        for (int t = 0; t <= k; t++) {
            Arrays.fill(minF, Integer.MAX_VALUE);
            Arrays.fill(f, Integer.MAX_VALUE / 2);
            f[1] = -grid[0][0];
            for (int[] row : grid) {
                for (int j = 0; j < n; j++) {
                    int x = row[j];
                    f[j + 1] = Math.min(Math.min(f[j], f[j + 1]) + x, sufMinF[x]);
                    minF[x] = Math.min(minF[x], f[j + 1]);
                }
            }
            boolean done = true;
            for (int i = mx; i >= 0; i--) {
                int mn = Math.min(sufMinF[i + 1], minF[i]);
                if (mn < sufMinF[i]) {
                    sufMinF[i] = mn;
                    done = false;
                }
            }
            if (done) {
                break;
            }
        }

        return f[n];
    }
}