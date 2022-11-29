class Solution {
public:
    bool dfs(int i,int j,vector<vector<int>>&grid1,vector<vector<int>>& grid2,int N,int M){
        if(i<0 or j<0 or i>=N or j>=M or grid2[i][j]==0){return true;}
            
        if(grid1[i][j]==0){return false;}
        grid2[i][j]=0;
        
        bool a=dfs(i-1,j,grid1,grid2,N,M);
        bool b=dfs(i+1,j,grid1,grid2,N,M);
        bool c=dfs(i,j+1,grid1,grid2,N,M);
        bool d=dfs(i,j-1,grid1,grid2,N,M);
        return a and b and c and d ;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int N=grid1.size();
        int M=grid1[0].size();
        
        int c=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(grid2[i][j]==0)continue;
                if(dfs(i,j,grid1,grid2,N,M))c++;
        }
    }
    return c; 
    }      
};