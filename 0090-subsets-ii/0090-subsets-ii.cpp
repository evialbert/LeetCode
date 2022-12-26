class Solution {
public:
    vector<vector<int>> ans;
    void subset(int i,vector<int>& nums,vector<int> sub){
        if(i==nums.size()){
            ans.push_back(sub);
            return;
        }
        sub.push_back(nums[i]);
        subset(i+1,nums,sub);
        sub.pop_back();
        while(i+1<nums.size() && nums[i]==nums[i+1]){
            i++;
        }
        subset(i+1,nums,sub);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        subset(0,nums,{});
        return ans;
    }
};