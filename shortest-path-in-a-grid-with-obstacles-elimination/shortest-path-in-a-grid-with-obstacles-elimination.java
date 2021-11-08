class Solution {
    public int shortestPath(int[][] grid, int k) {
        int n = grid.length, m = grid[0].length;
        int[][] dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        Queue<int[]> q = new LinkedList<>();
        boolean[][][] vis = new boolean[n][m][k + 1];
		// we are storing row, column, obstacle balance, current steps
        q.add(new int[]{0, 0, k, 0});
        int step = 0;
        while(!q.isEmpty()){
            int[] rem = q.remove();
            if(rem[0] == n - 1 && rem[1] == m - 1) return rem[3];
            for(int d = 0 ; d < dir.length ; d++){
                int r = rem[0] + dir[d][0];
                int c = rem[1] + dir[d][1];
                if(r < n && c < m && r >= 0 && c >= 0){
                    int newK = rem[2] - grid[r][c];
                    if(newK < 0 || vis[r][c][newK]) continue;
                    
                    q.add(new int[]{r, c, newK, rem[3] + 1});
                    vis[r][c][newK] = true;
                }
            }
        }
        return -1;
    }
}