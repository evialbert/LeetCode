class Solution {
public:
    set<vector<int>> ans;
    vector<int> subset;
    void genrateSubsequences(vector<int>& nums,int idx)
    {
        if(nums.size()==idx)
        {
            if(subset.size()>1)
                ans.insert(subset);
            return;
        }
        if(subset.size()==0 || subset[subset.size()-1]<=nums[idx])
        {
            subset.push_back(nums[idx]);
            genrateSubsequences(nums,idx+1);
            subset.pop_back();
        }
        genrateSubsequences(nums,idx+1);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        genrateSubsequences(nums,0);
        vector<vector<int>> res(ans.begin(),ans.end());
        return res;
    }
};