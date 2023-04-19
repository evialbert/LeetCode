class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n=nums.size(),xoR=0;
        long count=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            xoR^=nums[i];
            if(xoR==0)
                count++;
            if(mp.find(xoR)!=mp.end())
                count+=mp[xoR];
            mp[xoR]++;
        }
        return count;
    }
};