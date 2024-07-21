class Solution {
    public int numberOfSubmatrices(char[][] grid) {
        int ans = 0, r = grid.length, c = grid[0].length, x = 0, y = 0, k = 0;
        int[][] arr = new int[2][c];
        for (int i = 0; i < r; i++,k=0) {
            x = 0;
            y = 0;
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 'X') {
                    x++;
                } else if (grid[i][j] == 'Y')
                    y++;
                arr[0][k] += x;
                arr[1][k] += y;
                if (arr[0][k] == arr[1][k] && arr[0][k] != 0)
                    ans++;
                k++;
            }
        }
        return ans;
    }
}