class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int curr = nums[0] - k, res = 1;
        for (int i = 1; i < nums.size(); ++i) {
            auto lo = nums[i] - k, hi = nums[i] + k;
            if (hi < curr + 1) {
                continue;
            }
            curr = max(lo, curr + 1);
            ++res;
        }
        return res;
    }
};