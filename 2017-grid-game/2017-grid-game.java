class Solution {
    public long gridGame(int[][] grid) {
        long ans = Long.MAX_VALUE, sum = Arrays.stream(grid[0]).asLongStream().sum(), pre = 0;
        for (int i = 0; i < grid[0].length; i++){
            if (i > 0){
                pre += grid[1][i - 1]; // BOTTOM WHITE BLOCK
            }
            sum -= grid[0][i]; // TOP WHITE BLOCK
            ans = Math.min(ans, Math.max(sum, pre)); // MINIMIZE THE MAX OF THE TWO
        }
        return ans;
    }
}