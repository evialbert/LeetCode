class Solution {
    public int[] findPeakGrid(int[][] mat) {
        if (mat == null || mat.length == 0 || mat[0].length == 0) {
            return null;
        }
        int i = 0, j = 0;
        while (i < mat.length && j < mat[0].length) {
            if (i + 1 < mat.length && mat[i + 1][j] > mat[i][j]) {
                i += 1;
            } else if (j + 1 < mat[0].length && mat[i][j + 1] > mat[i][j]) {
                j += 1;
            } else if (i - 1 >= 0 && mat[i - 1][j] > mat[i][j]) {
                i -= 1;
            } else if (j - 1 >= 0 && mat[i][j - 1] > mat[i][j]) {
                j -= 1;
            } else {
                return new int[]{i, j};
            }
        }
        return new int[]{i, j};
    }
}