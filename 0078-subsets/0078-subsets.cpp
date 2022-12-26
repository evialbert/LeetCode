class Solution {
public:
        void f(vector<int> nums, vector<vector<int>> &ans, vector<int> &ds, int i)
        {
             if(i==nums.size())
             {
                    ans.push_back(ds);
                     return;
             }
                ds.push_back(nums[i]);
                f(nums, ans, ds, i+1);
                ds.pop_back();
                f(nums, ans, ds, i+1);
        }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
            vector<int> ds;
            f(nums, ans, ds, 0);
            return ans;
    }
};