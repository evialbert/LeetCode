class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        int n=points.size();
        vector<int> temp(n);
        for(int i=0;i<n;i++)
        {
            temp[i]=points[i][0];
        }
        sort(temp.begin(),temp.end());
        int j=0,count=0;
        for(int i=0;i<n;i++)
        {
            if(temp[i]-temp[j]<=w)
                continue;
            else
            {
                count++;
                j=i;
            }
        }
        count++;
        return count;
    }
};