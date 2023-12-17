class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int>m;
        vector<int>v;
        for (int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                m[grid[i][j]]++;
            }
        }
        int n=grid.size()*grid.size();
        for(int i=0;i<=n;i++)
        {
            if(m[i]==2 && i!=0)
                v.push_back(i);
        }
        for(int i=0;i<=n;i++)
        {
            if(m[i]==0 && i!=0)
                v.push_back(i);
        }       
        return v;
    }
};