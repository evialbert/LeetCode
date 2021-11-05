class Solution {
public int countServers(int[][] grid) {
    int R = grid.length;
    int C = grid[0].length;
    boolean[][] visited = new boolean[R][C];
    
    int communicatingServers = 0;
    
    for(int r = 0; r < R; r++)
    {
        for(int c = 0; c < C; c++)
        {
            if(!visited[r][c] && grid[r][c] == 1)
            {
                int count = dfs(r, c, R, C, visited, grid);
                if(count > 1)
                {
                    communicatingServers += count;
                }
            }
        }
    }
    
    return communicatingServers;
}

int dfs(int r, int c, int R, int C, boolean[][] visited, int[][] grid)
{
    if(r < 0 || r >= R || c < 0 || c >= C || visited[r][c])
    {
        return 0;
    }
    
    visited[r][c] = true;
    int res = 1;
    for(int j = 0; j < C; j++)
    {
        if(grid[r][j] == 1)
        {
            res += dfs(r, j, R, C, visited, grid);
        }
    }
    
    for(int i = 0; i < R; i++)
    {
        if(grid[i][c] == 1)
        {
            res += dfs(i, c, R, C, visited, grid);
        }
    }
            
    return res;
}
}