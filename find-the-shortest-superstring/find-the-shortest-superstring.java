class Solution {
    public String shortestSuperstring(String[] A) {
        int n = A.length;
        int[][] g = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i][j] = dist(A[i], A[j]);
            }
        }
        int[][] dp = new int[1 << n][n];
        int[][] path = new int[1 << n][n];
        for (int[] row : dp) Arrays.fill(row, Integer.MAX_VALUE / 2); 
        for (int[] row : path) Arrays.fill(row, -1); 
        for (int i = 0; i < n; i++) dp[1 << i][i] = A[i].length();
        for (int i = 0; i < 1 << n; i++) {
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0) {
                    for (int k = 0; k < n; k++) {
                        if ((i & (1 << k)) == 0 && dp[i | 1 << k][k] > dp[i][j] + g[j][k]) {
                            dp[i | 1 << k][k] = dp[i][j] + g[j][k];
                            path[i | 1 << k][k] = j;
                        } 
                    }
                }
            }
        }
        int idx = 0, len = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            if (dp[(1 << n) - 1][i] < len) {
                idx = i;
                len = dp[(1 << n) - 1][i];
            } 
        }
        StringBuilder sb = new StringBuilder();
        sb.append(A[idx]);
        int state = (1 << n) - 1;
        while (true) {
            int prev = path[state][idx];
            if (prev == -1) break; 
            int overlap = A[idx].length() - g[prev][idx];
            int tmp = A[prev].length();
            sb.insert(0, A[prev].substring(0, tmp - overlap));
            state -= (1 << idx);
            idx = prev;
        }
        return sb.toString();
    }
    private int dist(String s1, String s2) {
        for (int i = s2.length() - 1; i >= 0; i--) {
            if (s1.endsWith(s2.substring(0, i + 1))) return s2.length() - i - 1;
        }
        return s2.length();
    }
}