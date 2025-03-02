class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int j = 0;
        for(auto i : nums){
            if(!(i&1))
                nums[j++] = 0;
            else nums[j++] = 1;
        }
         sort(nums.begin(),nums.end());
        return nums;
    }
};