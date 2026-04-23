class Solution {
    public int longestArithmetic(int[] nums) {
        int n = nums.length;
        if (n <= 3) {
            return n;
        }
        int m = n - 1;
        int[] D = new int[m];
        for (int i = 0; i < m; i++) {
            D[i] = nums[i+1] - nums[i];
        }
        int[] left = new int[m];
        left[0] = 1;
        for (int i = 1; i < m; i++) {
            left[i] = (D[i] == D[i-1]) ? left[i-1] + 1 : 1;
        }
        int[] right = new int[m];
        right[m-1] = 1;
        for (int i = m - 2; i >= 0; i--) {
            right[i] = (D[i] == D[i+1]) ? right[i+1] + 1 : 1;
        }
        int ans = 3;
        for (int i = 0; i < m; i++) {
            if (left[i] == m) {
                ans = Math.max(ans, m + 1);
            } else {
                ans = Math.max(ans, left[i] + 2);
            }
        }
        for (int i = 1; i < m; i++) {
            int sumD = D[i-1] + D[i];

            if (i >= 2 && sumD == 2 * D[i-2]) {
                ans = Math.max(ans, left[i-2] + 3);
            }

            if (i <= m - 2 && sumD == 2 * D[i+1]) {
                ans = Math.max(ans, right[i+1] + 3);
            }

            if (i >= 2 && i <= m - 2 && D[i-2] == D[i+1] && sumD == 2 * D[i-2]) {
                ans = Math.max(ans, left[i-2] + right[i+1] + 3);
            }
        }

        return ans;
    }
}