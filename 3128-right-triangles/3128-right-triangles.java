class Solution {
    public long numberOfRightTriangles(int[][] grid) {
        long result = 0;
        int[] rowMap = new int[grid.length], colMap = new int[grid[0].length];
        createfreqRowCol(grid, rowMap, colMap);
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1) {
                    int row = rowMap[i], column = colMap[j];
                    result = result + (row - 1) * (column - 1);
                }
            }
        }
        return result;
    }
    
    private void createfreqRowCol(int[][] grid, int[] rowMap, int[] colMap) {
        for (int i = 0; i < grid.length; i++) {
            int count = 0;
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1) {
                    rowMap[i]++;
                    colMap[j]++;
                }
            }
        }
    }

}