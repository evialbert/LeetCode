class Solution {
public:
    int solve(vector<int>&nums,int i,int j)
    {
        while(i<=j)
        {
            int mid = (i+j)/2;
            if(mid>0 && nums[mid]<nums[mid-1]) return nums[mid];
            if(nums[mid]>nums[j])
                return solve(nums,mid+1,j);
            else return solve(nums,i,mid-1);
        }
        return -1;
    }
    int findMin(vector<int>& nums) {
        int ans = solve(nums,0,nums.size()-1);
        return (ans==-1)?nums[0]:ans;
    }
};