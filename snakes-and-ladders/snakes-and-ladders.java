class Solution {
    public int snakesAndLadders(int[][] board) {
        if (board == null || board.length == 0 || board[0].length == 0) {
            return 0;
        }
        int rows = board.length;
        int cols = board[0].length;
        int dest = rows * cols;
        int start = 1;
        Queue<Integer> queue = new LinkedList<>();
        Set<Integer> visited = new HashSet<>();
        queue.offer(start);
        visited.add(start);
        int steps = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int curr = queue.poll();
                if (curr == dest) {
                    return steps;
                }
                for (int diff = 1; diff <= 6 && diff + curr <= dest; diff++) {
                    int[] coor = getCoordinates(diff + curr, rows, cols);
                    int next = board[coor[0]][coor[1]] == -1 ? diff + curr : board[coor[0]][coor[1]];
                    if (!visited.contains(next)) {
                        queue.offer(next);
                        visited.add(next);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
    
    private int[] getCoordinates(int n, int rows, int cols) {
        int r_idx = rows - 1 - (n - 1) / cols;
        int c_idx = (n - 1) % cols;
        if (r_idx % 2 != rows % 2) {
            return new int[]{r_idx, c_idx};
        } else {
            return new int[]{r_idx, cols - 1 - c_idx};
        }
    }
}