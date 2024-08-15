class Solution {
    public int minFlips(int[][] grid) {

        int ans1 = 0;

        for (int i = 0; i < grid.length; i++) {
            int j = 0;
            int k = grid[0].length - 1;
            while (j < k) {
                if (grid[i][j] != grid[i][k]) {
                    ans1++;
                }
                j++;
                k--;
            }
        }

        int ans2 = 0;

        for (int i = 0; i < grid[0].length; i++) {
            int j = 0;
            int k = grid.length - 1;
            while (j < k) {
                if (grid[j][i] != grid[k][i]) {
                    ans2++;
                }
                j++;
                k--;
            }
        }

        return Math.min(ans1, ans2);
    }
}