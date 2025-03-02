class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if (nums.size() == k) {
            return *max_element(nums.begin(), nums.end());
        }
        map<int, int> mpp;
        for (auto it : nums) {
            mpp[it]++;
        }
        int cnt1 = mpp[nums[0]];
        int cnt2 = mpp[nums[nums.size() - 1]];
        int maxi = INT_MIN;
        if (k == 1) {
            for (auto it : mpp) {
                if (it.second == 1) {
                    maxi = max(maxi, it.first);
                }
            }
            return (maxi == INT_MIN) ? -1 : maxi;
        }
        if (cnt1 == 1 && cnt2 > 1)
            return nums[0];
        if (cnt2 == 1 && cnt1 > 1)
            return nums[nums.size() - 1];

        if (cnt1 == 1 && cnt2 == 1)
            return max(nums[0], nums[nums.size() - 1]);
        return -1;
    }
};