class Solution {
public:
    
    int singleNonDuplicate(vector<int>& nums) {
        int start =0 , end = nums.size()-1 , mid=0;
        while(start<=end)
        {
            mid=(start+end)/2;
            if(mid==0)
                return nums[0];
            if(nums[mid-1]!=nums[mid] && nums[mid]!=nums[mid+1])
                return nums[mid];
            else if(nums[mid-1]==nums[mid] && mid%2==0)
                end=mid-1;
            else if(nums[mid-1]<nums[mid] && mid%2==1)
                end=mid-1;
            else
                start=mid+1;
            
        }
        return nums[0];
    }
};