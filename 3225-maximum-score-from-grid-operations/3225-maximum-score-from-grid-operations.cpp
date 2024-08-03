class Solution {
public:
    long long dp[102][101][2];
    long long f(int i,int j,int fl,vector<vector<int>> &grid,int m) {
        if(m==1 || j>=m) return 0;
        if(dp[i+1][j][fl]!=-1) return dp[i+1][j][fl];
        long long ans = f(grid.size()-1,j+1,0,grid,m);;
        long long sum = 0;
        if(j==0) {
            for(int ind=0;ind<grid.size();ind++) {
                sum += grid[ind][j];
                ans = max(ans,sum+f(ind,j+1,1,grid,m));
            }
        }
        else if(j<m-1) {
            if(fl==0) {
                for(int ind=i;ind>=0;ind--) {
                    sum += grid[ind][j];
                    ans = max(ans,sum+f(ind-1,j+1,0,grid,m));
                }
                for(int ind = i+1;ind<grid.size();ind++) {
                    sum += grid[ind][j];
                    ans = max(ans,sum+f(ind,j+1,1,grid,m));
                }
            }
            else {
                for(int ind=i+1;ind<grid.size();ind++) {
                    sum += grid[ind][j];
                    ans = max(ans,sum+f(ind,j+1,1,grid,m));
                }
            }
        }
        else {
            if(fl==0) for(int ind=0;ind<=i;ind++) ans += grid[ind][j];
        }
        return dp[i+1][j][fl] = ans;
    }
    long long maximumScore(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return f(-1,0,0,grid,grid[0].size());
    }
};