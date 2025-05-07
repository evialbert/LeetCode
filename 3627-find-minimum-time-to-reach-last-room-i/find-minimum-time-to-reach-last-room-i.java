class Solution {
    public int minTimeToReach(int[][] moveTime) {
        int rows = moveTime.length;
        int cols = moveTime[0].length;

        // Initialize the minTime array to track minimum time to reach each cell
        int[][] minTime = new int[rows][cols];
        for (int[] row : minTime) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }

        // Min-heap priority queue: stores {current_time, row, col}
        PriorityQueue<int[]> rooms = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        rooms.offer(new int[]{0, 0, 0});  // Start at (0,0) with time 0

        // Possible movement directions: down, up, right, left
        int[][] directions = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!rooms.isEmpty()) {
            int[] currRoom = rooms.poll();
            int time = currRoom[0];
            int row = currRoom[1];
            int col = currRoom[2];

            // If we've reached the bottom-right corner, return the time
            if (row == rows - 1 && col == cols - 1) {
                return time;
            }

            // Explore all 4 directions from the current cell
            for (int[] dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                // Check if the new position is within bounds
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                    // Calculate the earliest time we can reach the new room
                    int newTime = Math.max(time + 1, moveTime[newRow][newCol] + 1);

                    // If this new time is better, update and add to queue
                    if (newTime < minTime[newRow][newCol]) {
                        minTime[newRow][newCol] = newTime;
                        rooms.offer(new int[]{newTime, newRow, newCol});
                    }
                }
            }
        }

        // If we can't reach the destination, return -1
        return -1;
    }
}