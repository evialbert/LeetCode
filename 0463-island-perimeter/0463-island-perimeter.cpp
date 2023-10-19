class Solution {
    
    int dfs(int i,int j,vector<vector<int>>&grid)
    {
            if(i<0 ||j<0|| i>=grid.size()|| j>=grid[0].size() || grid[i][j]==2||!grid[i][j])return 0;
            grid[i][j]=2;
            int temp=4;
            if(i>0 && grid[i-1][j])temp--;
            if(j>0 && grid[i][j-1])temp--;
            if(i<grid.size()-1 && grid[i+1][j])temp--;
            if(j<grid[0].size()-1 && grid[i][j+1])temp--;

            return temp+dfs(i-1,j,grid)+dfs(i,j-1,grid)+dfs(i+1,j,grid)+dfs(i,j+1,grid);
            
            
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
           for(auto i=0;i<grid.size();i++){
                for(auto j=0;j<grid[0].size();j++){
                    if(grid[i][j])
                  return dfs(i,j,grid);
                }
           }       
   return ans; }
};