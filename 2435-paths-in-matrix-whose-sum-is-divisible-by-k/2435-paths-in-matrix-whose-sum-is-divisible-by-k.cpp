class Solution {
public:
    vector<vector<vector<int>>> dp;
    const int mod=1e9+7;
    
    int find(vector<vector<int>>& grid,int k,int i,int j,int sum){
        if(i<0 || j<0)return 0;
        if(i==0 && j==0)return (sum+grid[0][0])%k==0?1:0;
        if(dp[i][j][sum%k]!=-1)return dp[i][j][sum%k];
        int up=find(grid,k,i-1,j,sum+grid[i][j]);
        int left=find(grid,k,i,j-1,sum+grid[i][j]);
        return dp[i][j][sum%k]=(up+left)%mod;
    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        dp=vector<vector<vector<int>>>(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(k,-1)));
        return find(grid,k,grid.size()-1,grid[0].size()-1,0);
    }
};