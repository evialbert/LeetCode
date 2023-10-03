class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n=nums.size();
        unordered_map <int,int> mp;
        for(int i=0;i<n;i++)
            mp[nums[i]]++;
        int goodpairs=0;
        for(auto i=mp.begin();i!=mp.end();i++){
            if(i->second>=2)
                goodpairs+=((i->second)*(i->second-1))/2;
        }
        return goodpairs;
    }
};