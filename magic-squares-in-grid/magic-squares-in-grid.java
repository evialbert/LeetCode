class Solution {
    public int numMagicSquaresInside(int[][] grid) {
        final int m = grid.length;
        if (m < 3) return 0;
        final int n = grid[0].length;
        if (n < 3) return 0;

        int res = 0;
        for (int i = 0; i < m - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                res += isMagic(grid, i, j) == true ? 1 : 0;
            }
        }

        return res;
    }

    private boolean isMagic(final int[][] grid, final int x, final int y) {
        final Set<Integer> set = new HashSet<>();
        int[] dedup = new int[10];
        for (int i = x; i < x + 3; i++) {
            for (int j = y; j < y + 3; j++) {
                if (grid[i][j] > 9 || grid[i][j] <= 0 || dedup[grid[i][j]] == 1) return false;
                dedup[grid[i][j]] = 1;
            }
        }

        for (int i = x; i < x + 3; i++) {
            set.add(grid[x][y] + grid[x][y + 1] + grid[x][y + 2]);
        }
        for (int j = y; j < y + 3; j++) {
            set.add(grid[x][y] + grid[x + 1][y] + grid[x + 2][y]);
        }
        set.add(grid[x][y] + grid[x + 1][y + 1] + grid[x + 2][y + 2]);
        set.add(grid[x][y + 2] + grid[x + 1][y + 1] + grid[x + 2][y]);

        return set.size() == 1;
    }
}