class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // M acts as a map to store the last seen index of a number.
        // The constraint is 1 <= nums[i] <= 10000.
        vector<int> M(10001, -1);
        
        int st = 0; // Start pointer of the sliding window
        int maxSum = 0;
        int currSum = 0;
        
        // 'i' is the end pointer of the sliding window
        for (int i = 0; i < nums.size(); i++) {
            
            // If the current number was seen before AND its last occurrence is inside our current window
            if (M[nums[i]] != -1 && M[nums[i]] >= st) {
                
                // Shrink the window from the left until the previous occurrence is removed
                int prev_occurrence_idx = M[nums[i]];
                while (st <= prev_occurrence_idx) {
                    currSum -= nums[st];
                    st++;
                }
            }
            
            // Update the last seen index of the current number
            M[nums[i]] = i;
            
            // Add the current number to the window's sum
            currSum += nums[i];
            
            // Update the maximum sum found so far
            maxSum = max(maxSum, currSum);
        }
        
        return maxSum;
    }
};