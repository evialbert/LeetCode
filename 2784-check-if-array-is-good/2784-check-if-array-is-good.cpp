class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        
        for(int i=1; i<=n-2; i++){
            if(mp[i] != 1) return false; 
        }
        return mp[n-1] == 2;
    }
};