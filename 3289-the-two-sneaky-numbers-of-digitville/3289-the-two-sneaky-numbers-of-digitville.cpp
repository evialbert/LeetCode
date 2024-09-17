class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_set<int>set;
        vector<int>ans;
        for(auto &it:nums)
        {
            if(set.count(it))ans.push_back(it);
            set.insert(it);
        }
        return ans;
    }
};