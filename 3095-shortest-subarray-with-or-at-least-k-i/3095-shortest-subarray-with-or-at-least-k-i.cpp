class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int minLen = INT_MAX;
        for (int i = 0; i < n; i++) {
            int tempVal = 0;
            for (int j = i; j < n; ++j) {
                tempVal |= nums[j];
                if (tempVal >= k) {
                    minLen = min(minLen, j - i + 1);
                    break;
                }
            }
        }
        return minLen == INT_MAX ? -1 : minLen;
    }
};