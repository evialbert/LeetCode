class Solution {
public:
    int CONT = 1;
    int STOP = 0;
    long long maximumStrength(vector<int>& nums, int k) {
        // ALL INDICES in below comments are 1-index. First element is the padding data.
        vector mem = vector(k + 1, vector(nums.size() + 1, vector<long long>(2, LLONG_MIN)));
        // Padding data
        for (int j = 0; j <= nums.size(); j++)
        {
            for (int k = 0; k < 2; k++)
            {
                mem[0][j][k] = 0;
            }
        }
        // Build subarray from 1 to k
        long long f = k;
        for (int i = 1; i <= k; i++, f = (f > 0 ? -(f - 1) : -(f + 1)))
        {
            // Build ith subarray
            for (int j = i; j <= nums.size(); j++)
            {
                // Stop adding number to the built_subarrays[i]
                // and just keep the previous result
                mem[i][j][STOP] = max(mem[i][j - 1][STOP], mem[i][j - 1][CONT]);
                // Make this number as the start number of built_subarrays[i]
                long long past_max = max(mem[i - 1][j - 1][STOP], mem[i - 1][j - 1][CONT]);
                mem[i][j][CONT] = f * nums[j - 1] + past_max;
                // Add this number to built_subarrays[i] if built_subarrays[i]
                // is not empty
                if (mem[i][j - 1][CONT] != LLONG_MIN)
                    mem[i][j][CONT] = max(mem[i][j][CONT], mem[i][j - 1][CONT] + f * nums[j - 1]);
            }
        }
        return max(mem.back().back()[0], mem.back().back()[1]);
    }
};