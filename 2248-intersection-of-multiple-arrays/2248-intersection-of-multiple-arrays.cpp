class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> hsh(1005,0),ans;
        for(auto&_nums:nums)
            for(int&x:_nums)
                hsh[x]++;
        for(int i=1; i<hsh.size(); i++)
            if(hsh[i]==nums.size()) ans.push_back(i);
        return ans;
    }
};