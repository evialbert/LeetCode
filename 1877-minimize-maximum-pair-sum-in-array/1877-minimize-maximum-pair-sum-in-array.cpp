class Solution {
public:
    // time/space: O(nlogn)/O(1)
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int max_sum = INT_MIN;
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            max_sum = max(max_sum, nums[i] + nums[j]);
        }
        return max_sum;
    }
};