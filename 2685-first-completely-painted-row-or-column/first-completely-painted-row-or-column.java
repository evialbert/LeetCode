class Solution {
    public int firstCompleteIndex(int[] arr, int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int[] hash = new int[m * n + 1];
        int ans = m * n;

        for (int i = 0; i < arr.length; i++)
            hash[arr[i]] = i;

        for (int i = 0; i < m; i++) {
            int index = -1;
            for (int j = 0; j < n; j++) {
                index = Math.max(index, hash[mat[i][j]]);
            }
            ans = Math.min(ans, index);
        }

        for (int i = 0; i < n; i++) {
            int index = -1;
            for (int j = 0; j < m; j++) {
                index = Math.max(index, hash[mat[j][i]]);
            }
            ans = Math.min(ans, index);
        }
        return ans;
    }
}