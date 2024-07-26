class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> cost(n+1,vector<int>(n+1,INT_MAX));
        for(auto x:edges)
        {
            cost[x[0]][x[1]]=x[2];
            cost[x[1]][x[0]]=x[2];
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                if(cost[i][k]!=INT_MAX)
                for(int j=0;j<n;j++)
                {
                    if(i!=j && cost[k][j]!=INT_MAX)
                        cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
                }
            }
        }
        int res=0;
        int m=n;
        for(int i=0;i<n;i++)
        {
            int c=0;
            for(int j=0;j<n;j++)
            {
                if(cost[i][j]<=distanceThreshold && cost[i][j]!=INT_MAX)
                    c++;
            }
            if(c<=m)
            {
                m=c;
                res=i;
            }
        }
        return res;
    }
};