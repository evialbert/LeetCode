class Solution {
public:
    int maxSum(const std::vector<int>& nums) {
        std::bitset<101> seen = {};
        int sum = std::numeric_limits<int>::min();
        for (int value : nums) {
            if (value > 0 && !seen[value]) {
                seen.set(value);
                if (sum < 0) {
                    sum = value;
                } else {
                    sum += value;
                }
            } else if (sum < 0 && value > sum) {
                sum = value;
            }
        }
        return sum;
    }
};