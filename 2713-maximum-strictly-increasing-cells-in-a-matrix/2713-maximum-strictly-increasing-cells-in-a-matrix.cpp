class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& grid) {
        map<int,vector<pair<int,int>>>v;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                v[grid[i][j]].push_back({i,j});
            }
        }
        vector<int>res(grid.size()+grid[0].size(),0);
        int dp[grid.size()][grid[0].size()];
        int ans=0;
        memset(dp,0,sizeof(dp));
        vector<int>row(grid[0].size(),0),col(grid.size(),0);
        for(auto it:v){
            for(auto pos:it.second){
                int x=pos.first,y=pos.second;
                dp[x][y]=1+max(res[x],res[grid.size()+y]);
                
            }
            for(auto pos:it.second){
                int x=pos.first,y=pos.second;
                res[x]=max(res[x],dp[x][y]);
                res[grid.size()+y]=max(res[grid.size()+y],dp[x][y]);
                ans=max(ans,res[x]);
                ans=max(ans,res[grid.size()+y]);
            }
        }
        return ans;
    }
};