class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long res=0;
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
            mp[nums[i]-i]++;
        for(auto it:mp)
        {
            n-=it.second;
            res+=(long long)n*it.second;
        }
        return res;
    }
};