class Solution {
    public int projectionArea(int[][] grid) {
        int N = grid.length;
        int result = 0;
        for (int i = 0; i < N; i++) {
            int maxXHeight = 0;
            int maxYHeight = 0;
            for (int j = 0; j < N; j++) {
                if (grid[i][j] > 0) {
                    result++;
                }
                maxXHeight = Math.max(maxXHeight, grid[i][j]);
                maxYHeight = Math.max(maxYHeight, grid[j][i]);
            }
            result += (maxXHeight + maxYHeight);
        }
        return result;
    }
}