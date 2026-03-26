class Solution {
    public boolean canPartitionGrid(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        long[] rowSum = new long[m];
        long T = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowSum[i] += grid[i][j];
                T += grid[i][j];
            }
        }
        long[] rowPrefix = new long[m + 1];
        for (int i = 1; i <= m; i++) {
            rowPrefix[i] = rowPrefix[i - 1] + rowSum[i - 1];
        }
        long[] colSum = new long[n];
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                colSum[j] += grid[i][j];
            }
        }
        long[] colPrefix = new long[n + 1];
        for (int j = 1; j <= n; j++) {
            colPrefix[j] = colPrefix[j - 1] + colSum[j - 1];
        }
        // Check equal sums without discount
        for (int k = 1; k < m; k++) {
            long s1 = rowPrefix[k];
            if (s1 == T - s1) return true;
        }
        for (int k = 1; k < n; k++) {
            long s1 = colPrefix[k];
            if (s1 == T - s1) return true;
        }
        final int MAXV = 100000;
        // Horizontal top prefixes (when top larger)
        if (m >= 2) {
            int[] freq = new int[MAXV + 1];
            for (int k = 1; k < m; k++) {
                for (int j = 0; j < n; j++) {
                    int v = grid[k - 1][j];
                    if (v <= MAXV) freq[v]++;
                }
                long s1 = rowPrefix[k];
                long s2 = T - s1;
                if (s1 <= s2) continue;
                long dd = s1 - s2;
                if (dd > MAXV) continue;
                int D = (int) dd;
                int h = k;
                int w = n;
                int rlo = 0;
                int rhi = k - 1;
                int clo = 0;
                int chi = n - 1;
                boolean can = false;
                if (h == 1 && w == 1) {
                    // cannot
                } else if (h >= 2 && w >= 2) {
                    if (freq[D] > 0) can = true;
                } else {
                    if (grid[rlo][clo] == D || grid[rlo][chi] == D || grid[rhi][clo] == D || grid[rhi][chi] == D) {
                        can = true;
                    }
                }
                if (can) return true;
            }
        }
        // Horizontal bottom suffixes (when bottom larger)
        if (m >= 2) {
            int[] freq = new int[MAXV + 1];
            for (int bh = 1; bh < m; bh++) {
                int add_row = m - bh;
                for (int j = 0; j < n; j++) {
                    int v = grid[add_row][j];
                    if (v <= MAXV) freq[v]++;
                }
                int topk = m - bh;
                long s1 = rowPrefix[topk];
                long s2 = T - s1;
                if (s2 <= s1) continue;
                long dd = s2 - s1;
                if (dd > MAXV) continue;
                int D = (int) dd;
                int h = bh;
                int w = n;
                int rlo = m - bh;
                int rhi = m - 1;
                int clo = 0;
                int chi = n - 1;
                boolean can = false;
                if (h == 1 && w == 1) {
                    // cannot
                } else if (h >= 2 && w >= 2) {
                    if (freq[D] > 0) can = true;
                } else {
                    if (grid[rlo][clo] == D || grid[rlo][chi] == D || grid[rhi][clo] == D || grid[rhi][chi] == D) {
                        can = true;
                    }
                }
                if (can) return true;
            }
        }
        // Vertical left prefixes (left larger)
        if (n >= 2) {
            int[] freq = new int[MAXV + 1];
            for (int k = 1; k < n; k++) {
                int add_col = k - 1;
                for (int i = 0; i < m; i++) {
                    int v = grid[i][add_col];
                    if (v <= MAXV) freq[v]++;
                }
                long s1 = colPrefix[k];
                long s2 = T - s1;
                if (s1 <= s2) continue;
                long dd = s1 - s2;
                if (dd > MAXV) continue;
                int D = (int) dd;
                int h = m;
                int w = k;
                int rlo = 0;
                int rhi = m - 1;
                int clo = 0;
                int chi = k - 1;
                boolean can = false;
                if (h == 1 && w == 1) {
                    // cannot
                } else if (h >= 2 && w >= 2) {
                    if (freq[D] > 0) can = true;
                } else {
                    if (grid[rlo][clo] == D || grid[rlo][chi] == D || grid[rhi][clo] == D || grid[rhi][chi] == D) {
                        can = true;
                    }
                }
                if (can) return true;
            }
        }
        // Vertical right suffixes (right larger)
        if (n >= 2) {
            int[] freq = new int[MAXV + 1];
            for (int bw = 1; bw < n; bw++) {
                int add_col = n - bw;
                for (int i = 0; i < m; i++) {
                    int v = grid[i][add_col];
                    if (v <= MAXV) freq[v]++;
                }
                int leftk = n - bw;
                long s1 = colPrefix[leftk];
                long s2 = T - s1;
                if (s2 <= s1) continue;
                long dd = s2 - s1;
                if (dd > MAXV) continue;
                int D = (int) dd;
                int h = m;
                int w = bw;
                int rlo = 0;
                int rhi = m - 1;
                int clo = n - bw;
                int chi = n - 1;
                boolean can = false;
                if (h == 1 && w == 1) {
                    // cannot
                } else if (h >= 2 && w >= 2) {
                    if (freq[D] > 0) can = true;
                } else {
                    if (grid[rlo][clo] == D || grid[rlo][chi] == D || grid[rhi][clo] == D || grid[rhi][chi] == D) {
                        can = true;
                    }
                }
                if (can) return true;
            }
        }
        return false;
    }
}