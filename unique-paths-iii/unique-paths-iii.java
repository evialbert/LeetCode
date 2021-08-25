class Solution {
    int ans = 0;
    public boolean isValid(int i, int j, int m, int n){
        return i < m && i >= 0 &&
            j < n && j >= 0;
    }
    public void dfs(int[][] grid, int i, int j, int nodes, int m, int n, int visited[][]){
        
        if(grid[i][j] == 2 && nodes == 0){
            ans++;
            return ;
        }
            
        int r[] = {0, 0, -1, 1};
        int c[] = {1, -1, 0, 0};
        
        visited[i][j] = 1;
        
        for(int k = 0 ; k < 4 ; k++){
            int x = i + r[k];
            int y = j + c[k];
            if(isValid(x, y, m, n) && grid[x][y] != -1 && visited[x][y] != 1){
                if(nodes - 1 != 0 && grid[x][y] == 2)continue;
                dfs(grid, x, y, nodes-1, m, n, visited);
            }
        }
        visited[i][j] = -1;
        return;
        
    }
    
    public int uniquePathsIII(int[][] grid) {
        int si = -1, sj = -1;
        int m = grid.length;
        int n = grid[0].length;
        int nodes = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 0)
                    nodes++;
                else if(grid[i][j] == 1){
                    si = i;
                    sj = j;
                }
            }
        }
        int visited[][] = new int [m][n];
        for(int i=0;i<m;i++)Arrays.fill(visited[i], -1);
        dfs(grid, si, sj, nodes+1, m, n, visited);
        
        return ans;
    }
}