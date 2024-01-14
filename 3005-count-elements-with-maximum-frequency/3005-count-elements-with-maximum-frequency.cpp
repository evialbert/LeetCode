class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> mp;
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++;
        }
        int maxi = -1;
        for(auto it : mp){
            if(it.second > maxi){
                maxi = it.second;
            }
        }
        int cnt = 0;
        for(auto it : mp){
            if(it.second == maxi){
                cnt += maxi;
            }
        }
        
        return cnt;
    }
};