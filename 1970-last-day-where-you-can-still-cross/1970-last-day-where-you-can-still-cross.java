class Solution {
    public int latestDayToCross(int row, int col, int[][] cells) {
        int[][] grid = new int[row][col];
        int lo = 0, hi = row*col;
        while(lo < hi){
            int mid = (lo + hi + 1) >> 1;
            for (int i = 0; i < mid; i++){
                grid[cells[i][0]-1][cells[i][1]-1] = mid; // mark visited
            }
            boolean ok = false;
            for (int i = 0; i < col && !ok; i++){
                ok = dfs(0, i, grid, mid);
            }
            if (ok)
                lo = mid;
            else
                hi = mid - 1;
        }
        return lo;
    }

    private boolean dfs(int i, int j, int[][] grid, int visited){
        if (i < 0 || j < 0 || i == grid.length || j == grid[0].length || grid[i][j] == visited)
            return false;
        grid[i][j] = visited;
        return i == grid.length - 1
            || dfs(i + 1, j, grid, visited)
            || dfs(i - 1, j, grid, visited)
            || dfs(i, j + 1, grid, visited)
            || dfs(i, j - 1, grid, visited);
    }
}