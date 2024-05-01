class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        long long ans=0;
        int n=grid.size();
        int m=grid[0].size();

        vector<long long>row(n);
        vector<long long>col(m);
        for(int i=0;i<n;i++) //calculate 1s in each row
        {
            long long cnt=0;
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)cnt++;
            }
            row[i]=cnt;
        }
        for(int i=0;i<m;i++)//calculate 1s in each column
        {
            long long cnt=0;
            for(int j=0;j<n;j++)
            {
                if(grid[j][i]==1)cnt++;
            }
            col[i]=cnt;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                ans+=(row[i]-1)*(col[j]-1); 
            }
        }
        return ans;
    }
};