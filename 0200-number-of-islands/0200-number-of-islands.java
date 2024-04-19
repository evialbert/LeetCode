class Solution {
    public int numIslands(char[][] grid) {
        int islandCount = 0;

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == '1') {
                    islandCount++;
                    searchIslandDFS(grid, i, j);
                }
            }
        }

        return islandCount;
    }

    public void searchIslandDFS(char[][] grid, int i, int j) {
        // Check the boundaries and the current cell's value.
        if (i < 0 || i >= grid.length || j < 0 || j >= grid[i].length || grid[i][j] == '0') {
            return;
        }

        // Set the value of the grid cell to '0'.
        grid[i][j] = '0';

        // Explore all four directions.
        searchIslandDFS(grid, i + 1, j);
        searchIslandDFS(grid, i - 1, j);
        searchIslandDFS(grid, i, j + 1);
        searchIslandDFS(grid, i, j - 1);
    }
}