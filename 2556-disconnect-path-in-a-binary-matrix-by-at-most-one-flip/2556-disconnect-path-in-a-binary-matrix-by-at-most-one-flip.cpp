class Solution {
public:
    bool dfs(vector<vector<int> >& grid,int i, int j, int n, int m)
    {
        if(i==n-1&&j==m-1)
            return true;
        
        grid[i][j]=0;
        
        int dc[2] = {0,1};
        int dr[2] = {1,0};
        
        for(int k=0;k<2;k++)
        {
            int newX = i + dr[k];
            int newY = j + dc[k];
            
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1)
            {
                if (dfs(grid, newX, newY, n, m))
                {
                    return true;
                }
                    
            }
        }
        return false;
    }
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        if(dfs(grid,0,0,n,m)==false)
        {
            return true;
        }
            
        if(dfs(grid,0,0,n,m)==false)
        {
            return true;
        }
        return false;
        
    }
};