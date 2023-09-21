class Solution {
public:
    int firstOccurence(vector<int>& nums, int target) {
        int beg = 0, end = nums.size() - 1;
        int mid;
        
        while (beg <= end) {
            mid = beg + (end - beg) / 2;
            
            if (nums[mid] == target) {
                if (mid - 1 >= 0 && nums[mid - 1] == target) {
                    end = mid - 1;
                    continue;
                }
                return mid;
            } else if (nums[mid] < target) {
                beg = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
    
    int lastOccurence(vector<int>& nums, int target) {
        int beg = 0, end = nums.size() - 1;
        int mid;
        
        while (beg <= end) {
            mid = beg + (end - beg) / 2;
            
            if (nums[mid] == target) {
                if (mid + 1 < (int)nums.size() && nums[mid + 1] == target) {
                    beg = mid + 1;
                    continue;
                }
                return mid;
            } else if (nums[mid] < target) {
                beg = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> range(2);
        range[0] = firstOccurence(nums, target);
        range[1] = lastOccurence(nums, target);
        return range;
    }
};