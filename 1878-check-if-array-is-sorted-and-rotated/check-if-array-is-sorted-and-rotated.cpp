class Solution {
public:
    bool check(vector<int>& nums) {
        int dec = 0;
        int n = nums.size();
        for(int i = 1; i < n; i++)
        {
            if(nums[i] < nums[i - 1])
            {
                if(dec == 0)
                {
                    dec = 1;
                }
                else return false;
            }
        }
        if(dec == 0) return nums[0] <= nums.back();
        else return nums[0] >= nums.back();
    }
};