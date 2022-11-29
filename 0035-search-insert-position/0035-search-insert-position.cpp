class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        while(left <= right)
        {
            mid = left + (right - left) / 2;
            
            if(nums[mid] == target)
                return mid;
            
            (nums[mid] > target) ? (right = mid - 1) : (left = mid + 1);
        }
        return left;
    }
};