class Solution {
    int[][] sum;
    void add(int x, int y, int v) {
        sum[x][y] = sum[x-1][y] + sum[x][y-1] - sum[x-1][y-1] + v;
    }
    int query(int x1, int y1, int x2, int y2) {
        return sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];
    }
    
    public int maxSumSubmatrix(int[][] matrix, int k) {
        int n = matrix.length, m = matrix[0].length;
        sum = new int[n+1][m+1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                add(i+1, j+1, matrix[i][j]);
            }
        }
        int ans = Integer.MIN_VALUE;
        for (int i = 1; i <= m; i++) {
            for (int j = i; j <= m; j++) {
                TreeSet<Integer> set = new TreeSet();
                set.add(0);
                for (int r = 1; r <= n; r++) {
                    int s = query(1, i, r, j);
                    var t =  set.ceiling(s-k);
                    if (t != null) {
                        ans = Math.max(ans, s - t);
                    }
                    set.add(s);
                }
            }
        }
        return ans;
    }
}