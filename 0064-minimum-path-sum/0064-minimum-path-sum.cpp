class Solution {
public:
    int dp[201][201];
    int n,m;
    
    int minPath(vector<vector<int>>& grid,int i,int j){
        if(i==n-1 && j==m-1){
            return grid[i][j];
        }
        if(i==n || j==m){
            return 1000000;
        }
        if(dp[i][j]!=0){
            return dp[i][j];
        }
        int down=0,right=0;
        down = grid[i][j] + minPath(grid,i+1,j);
        right = grid[i][j] + minPath(grid,i,j+1);
        
        
        return dp[i][j] = min(down,right);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,0,sizeof(dp));
        n = grid.size(), m = grid[0].size();
        return minPath(grid, 0,0);
    }
};