class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<int> dp(k, 0);
        int res = 0;

        // iterate through all possible target values.
        // basically we want to iterate through
        // all possible values of (sub[i] + sub[j]) % k.
        for (int target = 0; target < k; target++){

            // for each target, we track it's longest subsequence called "candidate"
            // we return the max of each of these "candidate"'s at the end (res)
            int candidate = 0;
            for (int num : nums) {
                // for each number,
                // calculate match such that
                // (numModded + match) % k = target
                int numModded = num % k;
                int match = ((target + k) - numModded) % k;

                // so the longest subsequence ending in an element x such that 
                // x % k = numModded is just +1 of the current longest subsequence
                // ending in an element y such that y % k = match
                // (since (x+y) % k = target because
                // (numModded + match) % k = target,
                // which is what we want)
                dp[numModded] = dp[match] + 1;
                candidate = max(dp[numModded], candidate);
            }
            res = max(res, candidate);
            dp.assign(k, 0); // clear for each target
        }
        return res;
    }
};