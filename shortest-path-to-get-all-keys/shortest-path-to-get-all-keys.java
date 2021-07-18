class Solution {
    private int[][] DS = new int[][]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    public int shortestPathAllKeys(String[] grid) {
        int numKeys = 0;
        int[] start = new int[2];
        int m = grid.length;
        int n = grid[0].length();
        char[][] cs = new char[m][n];
        for (int i = 0; i < m; ++i) {
            cs[i] = grid[i].toCharArray();
            for (int j = 0; j < n; ++j) {
                if (Character.isLowerCase(cs[i][j])) {
                    ++numKeys;
                } else if (cs[i][j] == '@') {
                    start[0] = i;
                    start[1] = j;
                }
            }
        }
        int end = (1 << numKeys) - 1;
        Queue<int[]> q = new LinkedList<>();
        boolean[][][] visited = new boolean[m][n][1 << numKeys];
        q.offer(new int[]{start[0], start[1], 0});
        visited[start[0]][start[1]][0] = true;
        int steps = 0;
        while (!q.isEmpty()) {
            int size = q.size();
            for (int k = 0; k < size; ++k) {
                int[] p = q.poll();
                if (Character.isLowerCase(cs[p[0]][p[1]])) {
                    p[2] |= 1 << (cs[p[0]][p[1]] - 'a');
                }
                if (p[2] == end) {
                    return steps;
                }
                for (int[] d : DS) {
                    int x = p[0] + d[0];
                    int y = p[1] + d[1];
                    if (0 <= x && x < m && 0 <= y && y < n) {
                        if (cs[x][y] == '#' || visited[x][y][p[2]] || Character.isUpperCase(cs[x][y]) && ((1 << (cs[x][y] - 'A')) & p[2]) == 0) {
                            continue;
                        }
                        visited[x][y][p[2]] = true;
                        q.offer(new int[]{x, y, p[2]});
                    }
                }
            }
            ++steps;
        }
        return -1;
    }
}