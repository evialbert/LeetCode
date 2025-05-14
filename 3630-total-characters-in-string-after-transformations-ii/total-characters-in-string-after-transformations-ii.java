class Solution {
      private static final int MOD = 1_000_000_007;
    public int lengthAfterTransformations(String s, int t, List<Integer> nums) {
      
        long[] freq = new long[26];
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }

        // Build transformation matrix
        long[][] mat = new long[26][26];
        for (int i = 0; i < 26; i++) {
            int count = nums.get(i);
            for (int j = 1; j <= count; j++) {
                mat[i][(i + j) % 26]++;
            }
        }

        // Raise matrix to the t-th power
        long[][] matPow = matrixPower(mat, t);

        // Multiply matPow with freq vector to get final counts
        long total = 0;
        for (int i = 0; i < 26; i++) {
            long sum = 0;
            for (int j = 0; j < 26; j++) {
                sum = (sum + matPow[j][i] * freq[j]) % MOD;
            }
            total = (total + sum) % MOD;
        }

        return (int) total;
    }

    // Matrix exponentiation function
    private long[][] matrixPower(long[][] mat, int power) {
        int n = 26;
        long[][] res = new long[n][n];

        // Initialize res to identity matrix
        for (int i = 0; i < n; i++) {
            res[i][i] = 1;
        }

        while (power > 0) {
            if ((power & 1) == 1) {
                res = multiply(res, mat);
            }
            mat = multiply(mat, mat);
            power >>= 1;
        }

        return res;
    }

    // Matrix multiplication function
    private long[][] multiply(long[][] a, long[][] b) {
        int n = 26;
        long[][] result = new long[n][n];

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (a[i][k] == 0) continue;
                for (int j = 0; j < n; j++) {
                    result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;
                }
            }
        }

        return result;
    }
}