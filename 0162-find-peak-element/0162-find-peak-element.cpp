class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size()-1, mid;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (nums[mid] < nums[mid + 1]) 
                low = mid + 1;
            else high = mid;
        }
        return low;
    }
};