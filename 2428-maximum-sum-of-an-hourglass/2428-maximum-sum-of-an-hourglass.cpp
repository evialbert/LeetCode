class Solution {
public:
    int dir[6][2]={{0,1},{0,2},{1,1},{2,0},{2,1},{2,2}};
    int n,m;
    
    bool solve(int i,int j,int& temp,vector<vector<int>>& grid){
        temp+=grid[i][j];
        for(int k=0;k<6;k++){
            int x=i+dir[k][0];
            int y=j+dir[k][1];
            if(x<0 or y<0 or x>=n or y>=m)return false;
            else temp+=grid[x][y];
        }
        return true;
    }
    
    int maxSum(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int temp=0;
                if(solve(i,j,temp,grid)){
                    ans=max(ans,temp);
                }
            }
        }
        return ans;
    }
};