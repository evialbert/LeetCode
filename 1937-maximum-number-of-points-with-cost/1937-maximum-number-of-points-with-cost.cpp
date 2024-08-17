class Solution
{
public:
    long long maxPoints(vector<vector<int>>& points)
    {
        int n=points.size();
        int m=points[0].size();
        long long ar[m+1];
        long long res[m+1];
        for(int j=0; j<m; j++)res[j]=points[0][j];
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<m; j++)ar[j]=0;
            long long  ma=0;
            for(int j=0; j<m; j++)
            {
                ma=max(ma,res[j]);
                ar[j]=ma;
                ma--;
            }
            ma=0;
            for(int j=m-1; j>=0; j--)
            {
                ma=max(ma,res[j]);
                ar[j]=max(ma,ar[j]);
                ma--;
            }
            for(int j=0; j<m; j++)
            {
                res[j]=ar[j]+points[i][j];
            }
        }
        long long ans=0;
        for(int i=0; i<m; i++)
        {
            ans=max(ans,res[i]);
        }
        return ans;
    }
};
