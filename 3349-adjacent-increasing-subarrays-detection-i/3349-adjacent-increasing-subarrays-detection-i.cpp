class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if(k==1) return true;
        int n = nums.size();
        int len = 0;
        for(int i=1;i+k<n;i++){
            if(nums[i-1]<nums[i] && nums[i+k-1]<nums[i+k]) len++;
            else len = 0;

            if(len==k-1) return true;
        }
        return false;
    }
};