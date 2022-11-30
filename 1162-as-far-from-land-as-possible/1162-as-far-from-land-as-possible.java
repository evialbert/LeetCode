class Solution {
    public int maxDistance(int[][] grid) {
        
        int n = grid.length;
        int m = grid[0].length;
        int[][] dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        Queue<Integer> queue = new LinkedList<>();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    queue.add(i * m + j);
                }
            }
        }
        
        if(queue.size() == 0 || queue.size() == n * m) {     //Found no 1's in the grid  //Empty queue
            return -1;                                       //Found no 0's in the grid  //Full queue
        }
        
        int level = 0;
        while(!queue.isEmpty()) {
            int size = queue.size();
            while(size-- > 0){
                int idx = queue.poll();
                int r = idx / m;
                int c = idx % m;
                for(int d = 0; d < dir.length; d++) {
                    int x = r + dir[d][0];
                    int y = c + dir[d][1];
                    if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 0) {
                        queue.add(x * m + y);
                        grid[x][y] = 1;
                    }
                }
            }
            level++;
        }
        return level - 1;
    }
}