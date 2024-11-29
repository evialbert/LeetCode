class Solution {
    // Direction vectors for moving in four directions: right, left, down, up
    int[][] dir = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
    int m, n;
    boolean[][] visited;

    public int minimumTime(int[][] grid) {
        // Base case: If both adjacent cells from the start are inaccessible, return -1
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        // Initialize dimensions of the grid
        m = grid.length;
        n = grid[0].length;

        // Priority queue to implement Dijkstra's algorithm (min-heap based on time)
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[2] - b[2]);
        visited = new boolean[m][n];

        // Add the starting cell to the priority queue: {row, col, time}
        pq.offer(new int[]{0, 0, 0});

        // Process the priority queue until empty
        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int row = curr[0], col = curr[1], time = curr[2];

            // If the bottom-right cell is reached, return the time taken
            if (row == m - 1 && col == n - 1) return time;

            // Skip if the current cell is already visited
            if (visited[row][col]) continue;

            // Mark the current cell as visited
            visited[row][col] = true;

            // Explore all four possible directions
            for (int[] d : dir) {
                int r = row + d[0], c = col + d[1];

                // Check if the neighboring cell is valid (within bounds and not visited)
                if (!valid(r, c)) continue;

                // Calculate the earliest time to reach the neighboring cell
                // Adjust time based on parity to match the cell's constraint
                int f = (grid[r][c] - time) % 2 == 0 ? 1 : 0;
                int t = Math.max(time + 1, grid[r][c] + f);

                // Add the neighboring cell to the priority queue
                pq.offer(new int[]{r, c, t});
            }
        }
        // If the bottom-right cell is unreachable, return -1
        return -1;
    }

    // Helper method to check if a cell is within bounds and not visited
    private boolean valid(int i, int j) {
        return i >= 0 && j >= 0 && i < m && j < n && !visited[i][j];
    }
}