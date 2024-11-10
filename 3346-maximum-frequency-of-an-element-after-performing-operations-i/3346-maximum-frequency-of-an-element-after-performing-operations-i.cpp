class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        // Calculate lower and upper bounds of values in nums
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        int valueRange = maxVal - minVal + 1;

        // Create a prefix sum array to store frequency counts, adjusting for range and operations
        vector<int> prefixSum(valueRange + k + 1, 0);
        int maxFreq = 0;

        // Populate prefix sum array with frequency counts
        for (int num : nums) {
            ++prefixSum[num - minVal + 1];
        }

        // Build prefix sums for cumulative frequencies
        for (int i = 1; i < prefixSum.size(); ++i) {
            prefixSum[i] += prefixSum[i - 1];
        }

        // Iterate over each possible target value within the bounds
        for (int target = minVal; target <= maxVal; ++target) {
            int targetIdx = target - minVal;

            // Calculate frequencies of numbers greater, equal, and less than the target
            int countGreater = prefixSum[targetIdx + k + 1] - prefixSum[targetIdx + 1];
            int countEqual = prefixSum[targetIdx + 1] - prefixSum[targetIdx];
            int countLesser = prefixSum[targetIdx] - (targetIdx - k >= 0 ? prefixSum[targetIdx - k] : 0);

            // Determine max frequency achievable with available operations
            int achievableCount = countEqual + min(numOperations, countGreater + countLesser);
            maxFreq = max(maxFreq, achievableCount);
        }

        return maxFreq;
    }
};