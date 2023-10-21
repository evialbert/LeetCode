class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int j = n - 1;
        for(int i = n - 1 ; i >= 0 ; i--)
        {
            if(nums[i] == val)
            {
                swap(nums[i],nums[j]);
                j--;
            }
        }
        return j + 1;
    }
};