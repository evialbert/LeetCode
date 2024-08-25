class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k--)
        {
            int min = 0;
            for(int i=1; i<nums.size(); i++)
            {
                if(nums[i]<nums[min])
                    min = i;
            }
            nums[min] *= multiplier;
        }
        return nums;
    }
};