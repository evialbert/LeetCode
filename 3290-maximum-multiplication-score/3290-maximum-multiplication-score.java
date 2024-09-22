class Solution {
    long[][] dp = new long[5][100001];

    public long solve(int i, int j, int[] a, int[] b, int n) {
        if (i == 4) {
            return 0;
        }
        if (j >= n) {
            return (long) -1e11;
        }
        if (dp[i][j] != (long) -1e11) {
            return dp[i][j];
        }

        long x = (long) a[i] * b[j] + solve(i + 1, j + 1, a, b, n);
        long y = solve(i, j + 1, a, b, n);

        dp[i][j] = Math.max(x, y);
        return dp[i][j];
    }

    public long maxScore(int[] a, int[] b) {
        for (int i = 0; i < 5; i++) {
            Arrays.fill(dp[i], (long) -1e11);
        }
        int n = b.length;
        return solve(0, 0, a, b, n);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] a = {1, 2, 3, 4, 5};
        int[] b = {6, 7, 8, 9, 10};
        System.out.println(solution.maxScore(a, b));  // Output: the maximum score based on the problem statement
    }
}
