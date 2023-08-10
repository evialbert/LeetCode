class Solution {
public:
    typedef long long ll;
    bool search(vector<int>& nums, int target) {
        ll n = nums.size();
        return srch(nums, target, 0, n-1);
    }

    bool srch(vector<int>& nums, int target, int l, int r) {
        ll n = nums.size();
        while(l <= r) {
            ll mid = (l + r)/2;

            if (nums[mid] == target) return true;
            if (nums[l] == target) return true;
            if (nums[r] == target) return true;

            if (nums[mid] == nums[l]) {
                return srch(nums, target, l, mid-1) || srch(nums, target, mid+1, r);
            }

            if (nums[mid] >= nums[l]) {
                if (nums[mid] >= target && nums[l] <= target) {
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            } else {
                if (nums[mid] <= target && target <= nums[r]) {
                    l = mid+1;
                } else {
                    r = mid-1;
                }
            }
        }

        return false;
    }
};