class Solution {
public:
    int maxTrailingZeros(vector<vector<int>>& grid) 
    {
        int m=grid.size(),n=grid[0].size();
        vector<vector<pair<int,int>>>prefix(m,vector<pair<int,int>>(n,{0,0}));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                int cnt1=0,cnt2=0;
                while(grid[i][j]%2==0)cnt1++,grid[i][j]/=2;
                while(grid[i][j]%5==0)cnt2++,grid[i][j]/=5;
                prefix[i][j].first=cnt1;
                prefix[i][j].second=cnt2;
            }
        auto record=prefix;
        for(int i=0;i<m;i++)
            for(int j=1;j<n;j++)
            {
                prefix[i][j].first+=prefix[i][j-1].first;
                prefix[i][j].second+=prefix[i][j-1].second;
            }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int v1=0,v2=0;
            for(int j=0;j<m;j++)
            {
                ans=max(ans,min(v1+prefix[j][i].first,v2+prefix[j][i].second));
                int v3=prefix[j][n-1].first,v4=prefix[j][n-1].second;
                if(i-1>=0)v3-=prefix[j][i-1].first,v4-=prefix[j][i-1].second;
                ans=max(ans,min(v1+v3,v2+v4));
                v1+=record[j][i].first,v2+=record[j][i].second;
            }
        }
        for(int i=0;i<n;i++)
        {
            int v1=0,v2=0;
            for(int j=m-1;j>=0;j--)
            {
                ans=max(ans,min(v1+prefix[j][i].first,v2+prefix[j][i].second));
                int v3=prefix[j][n-1].first,v4=prefix[j][n-1].second;
                if(i-1>=0)v3-=prefix[j][i-1].first,v4-=prefix[j][i-1].second;
                ans=max(ans,min(v1+v3,v2+v4));
                v1+=record[j][i].first,v2+=record[j][i].second;
            }
        }
        return ans;
    }
};