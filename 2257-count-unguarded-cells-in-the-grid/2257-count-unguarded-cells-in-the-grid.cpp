class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m,vector<int>(n,-1));
        int l=guards.size();
        
        for(int i=0;i<l;i++)
        {
            grid[guards[i][0]][guards[i][1]]=0;
        }
        
        int l2=walls.size();
        for(int i=0;i<l2;i++)
        {
            grid[walls[i][0]][walls[i][1]]=2;
        }
        
        for(int i=0;i<l;i++)
        {
           int x,y;
            x=guards[i][0];
            y=guards[i][1];
            int p;
            p=x+1;
            
            while(p<m)
            {

                if(grid[p][y]==2||grid[p][y]==0)
                {
                    break;
                }                
                grid[p][y]=1;
                p++;
            }
            
            p=x-1;
            while(p>=0)
            {
                  if(grid[p][y]==2||grid[p][y]==0)
                {
                    break;
                }                
                grid[p][y]=1;
                p--;
            }
             p=y-1;
            while(p>=0)
            {
                  if(grid[x][p]==2||grid[x][p]==0)
                {
                    break;
                }                
                grid[x][p]=1;
                p--;
            }
             p=y+1;
            while(p<n)
            {
                  if(grid[x][p]==2||grid[x][p]==0)
                {
                    break;
                }                
                grid[x][p]=1;
                p++;
            }
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==-1)
                ans++;
            }
        }
        return ans;
    }
};