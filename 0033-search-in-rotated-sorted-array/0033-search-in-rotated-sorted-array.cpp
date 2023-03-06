class Solution {
public:
    int search(vector<int>& nums, int target) {
        int rot = nums[0];
        int l = 0, r = nums.size()-1;
        while(l <= r) {
            int mid = (l+r)/2;
            if (nums[mid] == target)
                return mid;
            if (target >= rot) {
                if (nums[mid] < rot || (nums[mid] >= rot && nums[mid] > target))
                    r = mid-1;
                else
                    l = mid+1;
            } else {
                if (nums[mid] >= rot || (nums[mid] < rot && nums[mid] < target))
                    l = mid+1;
                else
                    r = mid-1;
            }
        }
        return -1;
    }
};