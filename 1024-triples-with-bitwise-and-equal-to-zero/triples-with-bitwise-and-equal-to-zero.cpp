class Solution {
public:
    int countTriplets(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto &i: nums){
            for(auto &j: nums){
                mp[i&j]++;
            }
        }
        int ans = 0;
        for(auto &i: nums){
            for(auto &j: mp){
                if((i&j.first)==0)ans += j.second;
            }
        }
        return ans;
    }
};