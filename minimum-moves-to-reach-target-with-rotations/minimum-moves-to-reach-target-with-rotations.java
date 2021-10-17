class Solution {
    public int minimumMoves(int[][] grid) {
        // using BFS to search
        int n = grid.length;
        boolean[][][] visited = new boolean[n][n][2]; // 0: horizontal 1: vertical
        Queue<int[]> positions = new LinkedList<>();
        positions.add(new int[]{0, 0, 0});
        visited[0][0][0] = true;
        int res = -1;
        
        while (!positions.isEmpty()) {
            int size = positions.size();
            res++;
            while (size > 0) {
                int[] curr = positions.poll();
                int y = curr[0];
                int x = curr[1];
                int head = curr[2];

                if (y == n - 1 && x == n - 2 && head == 0) return res;
                if (head == 0) { // horizontal: can move right move down or clockwise
                    if (x + 2 < n && grid[y][x + 2] == 0 && !visited[y][x + 1][0]) { // can move to right
                        positions.add(new int[]{y, x + 1, 0});
                        visited[y][x + 1][0] = true;
                    }
                    if (y + 1 < n && grid[y + 1][x] == 0 && grid[y + 1][x + 1] == 0) {
                        if (!visited[y + 1][x][0]) {
                            positions.add(new int[]{y + 1, x, 0});
                            visited[y + 1][x][0] = true;
                        }
                        if (!visited[y][x][1]) {
                            positions.add(new int[]{y, x, 1});
                            visited[y][x][1] = true;
                        }
                    }
                } else { // vertical: can move right, move down or counterclockwise
                    if (x + 1 < n && grid[y][x + 1] == 0 && grid[y + 1][x + 1] == 0) { // move to right adn counterclockwise
                        if (!visited[y][x + 1][1]) {
                            positions.add(new int[]{y, x + 1, 1});
                            visited[y][x + 1][1] = true;
                        }
                        if (!visited[y][x][0]) {
                            positions.add(new int[]{y, x, 0});
                            visited[y][x][0] = true;
                        }
                        
                    }
                    if (y + 2 < n && grid[y + 2][x] == 0 && !visited[y + 1][x][1]) {
                        positions.add(new int[]{y + 1, x, 1});
                        visited[y + 1][x][1] = true;
                    } 
                }
                size--;
            }
        }
        return -1;
    }
}