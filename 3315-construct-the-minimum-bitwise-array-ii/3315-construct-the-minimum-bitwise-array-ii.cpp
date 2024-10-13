class Solution {
public:
    int findMinX(int num) {
        // Edge case: if the number is 2, return -1
        if (num == 2)
            return -1;

        // Iterate through each bit position using a mask
        for (int mask = 1; mask <= num; mask <<= 1) {
            // Check if the current bit (mask) is not set in 'num'
            if ((num & mask) == 0) {
                // Flip the least significant bit to the right of the first '0' bit found
                return num ^ (mask >> 1);
            }
        }

        // If no '0' bit is not found, it means all bits are set (like in 3, 7, 15...), return half of the number
        return num >> 1;
    }

    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);

        for (int i = 0; i < nums.size(); ++i) {
            ans[i] = findMinX(nums[i]);
        }

        // Return the final array of minimum values
        return ans;
    }
};