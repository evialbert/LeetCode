//DFS algorithm
class Solution {
    private int[][] matrix;
    private int[][] dp;
    public int longestIncreasingPath(int[][] matrix) {
        int result = 0;
        this.dp = new int[matrix.length][matrix[0].length];
        this.matrix = matrix;
        for (int i = 0 ; i < matrix.length ; i++) {
            for (int j = 0 ; j < matrix[i].length ; j++) {
                result = Math.max(result, dfs(i, j, Integer.MIN_VALUE));
            }
        }
        
        return result;
    }
    
    private int dfs(int i, int j, int prev) {
        if (i < 0 || i > matrix.length - 1 || j < 0 || j > matrix[i].length - 1 || matrix[i][j] <= prev)
            return 0;
        
       if (dp[i][j] != 0)
           return dp[i][j];
        
        int up = dfs(i - 1, j, matrix[i][j]);
        int down = dfs(i + 1, j, matrix[i][j]);
        int left = dfs(i, j - 1, matrix[i][j]);
        int right = dfs(i, j + 1, matrix[i][j]);
        int maxPathLen = Math.max(up, Math.max(down, Math.max(left, right)));
        dp[i][j] = maxPathLen + 1;
        
        return dp[i][j];
    }
}