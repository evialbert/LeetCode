class Solution {
public:
    
    void solve(int index, vector<int>& nums, vector<vector<int>>& ans){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> sett;
        for(int i = index; i < nums.size(); i++)
        {
            if(i != index && nums[i] == nums[index]) continue;
            if(sett.find(nums[i]) != sett.end()) continue;
            sett.insert(nums[i]);
            swap(nums[index], nums[i]);
            solve(index+1, nums, ans);
            swap(nums[index], nums[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        solve(0,nums, ans);
        
        return ans;
    }
};