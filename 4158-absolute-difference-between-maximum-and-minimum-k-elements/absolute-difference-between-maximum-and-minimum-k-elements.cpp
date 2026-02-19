class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int small = 0, big = 0;
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        while (k != 0) {
            small += nums[left];
            big += nums[right];
            left++;
            right--;
            k--;
        }

        return abs(big - small);
    }
};