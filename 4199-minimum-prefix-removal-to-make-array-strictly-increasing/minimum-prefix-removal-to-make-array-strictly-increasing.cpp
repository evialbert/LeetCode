class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n = nums.size();
        int i=n-2;
         for(;i>=0;){
            if(nums[i]>=nums[i+1]){
                break;
            }
            i--;
         }
         return i+1;
    }
};