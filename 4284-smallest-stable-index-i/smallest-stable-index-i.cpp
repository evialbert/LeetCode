class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int index = -1;
        for (int i = 0; i < n; i++) {
            int maxi = *max_element(nums.begin(), nums.begin() + i);
            int mini = *min_element(nums.begin() + i, nums.end());
            int sum = maxi - mini;
            if (sum <= k) {
                return i;
            }
        }
        return index;
    }
};