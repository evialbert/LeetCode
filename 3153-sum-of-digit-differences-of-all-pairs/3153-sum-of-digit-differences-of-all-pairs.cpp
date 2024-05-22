class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        uint64_t size = nums.size();
        uint64_t n_len = log10(nums[0])+1;
        uint64_t total = (n_len * size * (size-1))/2;
        vector<vector<uint64_t>> f(n_len, vector<uint64_t>(10, 0));
        uint64_t same_count = 0;
        for (int i = 0; i < size; ++i) {
            int num = nums[i], d;
            for (int j = 0; j < n_len; ++j) {
                d = num % 10;
                same_count += f[j][d];
                ++f[j][d];
                num /= 10;
            }
        }

        return total - same_count;
    }
};