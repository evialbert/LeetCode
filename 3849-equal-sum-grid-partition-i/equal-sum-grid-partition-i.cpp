class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long sum=0;
        int n=grid.size();
        int m=grid[0].size();
        for(auto it : grid)
            {
                for(auto i : it)
                    sum+=i;
            }
        if(sum%2)return false;
        vector<long long>col(m-1,0);
        vector<long long>row(n-1,0);
        long long s=0, t=0;
        for(int j=0;j<m-1;j++)
            {
                for(int i=0;i<n;i++)
                    {
                        s+=grid[i][j];
                    }
                col[j]=s;
            }

        for(int i=0;i<n-1;i++)
            {
                for(int j=0;j<m;j++)
                    {
                        t+=grid[i][j];
                    }
                row[i]=t;
            }

        for(int i=0;i<n-1;i++)
            {
                if(sum/2 == row[i])
                    return true;
            }
        for(int i=0;i<m-1;i++)
            {
                if(sum/2 == col[i])
                    return true;
            }
        return false;
        
    }
};