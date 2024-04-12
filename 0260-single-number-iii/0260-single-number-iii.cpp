class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        vector<int> ans;
        for(auto it: mp ){
            if(it.second == 1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};