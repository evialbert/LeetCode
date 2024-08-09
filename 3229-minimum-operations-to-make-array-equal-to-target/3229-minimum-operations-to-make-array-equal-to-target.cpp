class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
    int n = nums.size();
    long increase = 0, decrease = 0, operations = 0;

    for (int i = 0; i < n; ++i) {
        int difference = target[i] - nums[i];

        if (difference > 0) {
            if (increase < difference)
                operations += difference - increase;
            increase = difference;
            decrease = 0;
        } else if (difference < 0) {
            if (decrease < -difference)
                operations += -difference - decrease;
            decrease = -difference;
            increase = 0;
        } else {
            increase = decrease = 0;
        }
    }

    return operations;
    }
};