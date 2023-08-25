class Solution {
public:
    
    
    int solve(vector<vector<int>>& g,int n,int i1,int j1,int i2,int j2,vector<vector<vector<vector<int>>>> &dp){
        if(i1>=n || j1>=n  || i2>=n || j2>=n){
            return -1e8;
        }
        
        if(g[i1][j1] == -1 || g[i2][j2] == -1){
            return -1e8;
        }
        
        if(i1 == n-1 && j1 == n-1){
            return g[i1][j1];
        }
        
        if(dp[i1][j1][i2][j2] != -1){
            return dp[i1][j1][i2][j2];
        }
        
        int val = 0;
        
        if(i1 == i2 && j1 == j2){
            val = g[i1][j1];
        }
        
        else{
            val = g[i1][j1] + g[i2][j2];
        }
        
        int downDown =solve(g,n,i1+1,j1,i2+1,j2,dp);
        int downRight =solve(g,n,i1+1,j1,i2,j2+1,dp);
        int rightDown =solve(g,n,i1,j1+1,i2+1,j2,dp);
        int rightRight =solve(g,n,i1,j1+1,i2,j2+1,dp);
        
        
        return dp[i1][j1][i2][j2]=val+max(max(downDown,downRight),max(rightDown,rightRight));
    }
    
    int cherryPickup(vector<vector<int>>& g) {
        int n = g.size();
        vector<vector<vector<vector<int>>>> dp(n,vector<vector<vector<int>>> (n,vector<vector<int>> (n,vector<int> (n,-1))));
        
        return max(0,solve(g,n,0,0,0,0,dp));
    }
};