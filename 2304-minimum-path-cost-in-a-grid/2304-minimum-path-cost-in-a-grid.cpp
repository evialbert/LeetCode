class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) 
    {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0)
                {
                    dp[i][j]=grid[i][j];
                    continue;
                }
                int min_path=INT_MAX;
                for(int k=0;k<n;k++)
                {
                    min_path=min(min_path,dp[i-1][k]+moveCost[grid[i-1][k]][j]);
                }
                dp[i][j]=min_path+grid[i][j];
            }
        }
        
        int res=INT_MAX;
        for(int i=0;i<n;i++)
        {
            res=min(res,dp[m-1][i]);
        }
        
        
        return res;
    }
};