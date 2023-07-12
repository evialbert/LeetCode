class Solution {
    int n,m;
    int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
     int dp[140][8][8][8][8];
    vector<int> cat,food,mouse;
    int solve(int c0,int c1,int m0,int m1,vector<string>& grid, int cj, int mj,int turn)
    {
        if(turn>=128)
        {
            return 0;
        }
        if (dp[turn][m0][m1][c0][c1] != -1) return dp[turn][m0][m1][c0][c1];
        int ret=turn%2==0?0:1;
        if(turn%2==0)//mouse
        {
            if(c0==m0 && c1==m1)
            {
                ret=0;
            }
            else if(m0==food[0] && m1==food[1])
            {
                ret=1;
            }
             else if(c0==food[0] && c1==food[1])
            {
                ret=0;
            }
            else
            {
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<=mj;j++)
                    {
                        int x=m0+j*dx[i];
                        int y=m1+j*dy[i];
                        
                        if(x>=0 && y>=0 && y<m && x<n && grid[x][y]!='#')
                        {
                            if(solve(c0,c1,x,y,grid,cj,mj,turn+1))
                            {
                                ret=1;
                                break;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                
            }
            
        }
        else
        {
             if(c0==m0 && c1==m1)
            {
                ret=0;
            }
            else if(c0==food[0] && c1==food[1])
            {
                ret=0;
            }
               else if(m0==food[0] && m1==food[1])
            {
                ret=1;
            }
            else
            {
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<=cj;j++)
                    {
                        int x=c0+j*dx[i];
                        int y=c1+j*dy[i];
                        
                        if(x>=0 && y>=0 && y<m && x<n && grid[x][y]!='#')
                        {
                            if(solve(x,y,m0,m1,grid,cj,mj,turn+1)==0)
                            {
                                ret=0;
                                break;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                
            }
            
        }
        return dp[turn][m0][m1][c0][c1]=ret;
    }
public:
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
         memset(dp, -1, sizeof(dp));
          cat.resize(2); mouse.resize(2); food.resize(2);
        int R = grid.size();int C = grid[0].size();
        n=R;m=C;
          for (int i=0; i<R; i++) {
           for (int j=0; j<C; j++) {
                if (grid[i][j] == 'C') cat[0] = i, cat[1] = j;
                else if (grid[i][j] == 'M') mouse[0] = i, mouse[1] = j;
                else if (grid[i][j] == 'F') food[0] = i, food[1] = j;
            }
        }
        return solve(cat[0],cat[1],mouse[0],mouse[1],grid,catJump,mouseJump,0);
    }
};