class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, res = n;
        for (int j = 0; j < n; ++j) {
            while (nums[j] > (long long)k * nums[i]) {
                i++;
            }
            res = min(res, n - (j - i + 1));
        }
        return res;
    }
};