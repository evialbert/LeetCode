class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        map<int,int>mp1;
        vector<pair<int,int>>v;
        for(auto x:nums)
        {
            int val=x%space;
            mp1[val]++;
            v.push_back({val,x});
        }
        int ans=INT_MAX;
        int val=INT_MIN;
        for(auto x:v)
        {
          if(mp1[x.first]>val)
          {
              val=mp1[x.first];
              ans=x.second;
          }
          if(mp1[x.first]==val)
          {
              ans=min(ans,x.second);
          }
        }
        return ans;
    }
};