class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans=0;
        int odd=0;
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0]=1;
        for(auto i:nums){
            if(i&1) odd++;
            mp[odd]++;
            if(mp.find(odd-k)!=mp.end()){
                ans+=mp[odd-k];
            }
        }
        return ans;
    }
};