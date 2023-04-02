class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
       
       return min({nums[nums.size()-2]-nums[1],nums[nums.size()-1]-nums[2],nums[nums.size()-3]-nums[0]});
       
    }
};