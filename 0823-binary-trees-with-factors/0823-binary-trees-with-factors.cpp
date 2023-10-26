class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int MOD = 1000000007;
        sort(arr.begin(), arr.end()); // Sort the array.

        unordered_map<int, long long> dp; // Use a map to store the number of trees for each value.

        for (int i = 0; i < arr.size(); i++) {
            dp[arr[i]] = 1; // A single node tree with the value arr[i].
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0) { // If arr[j] is a factor of arr[i].
                    int factor = arr[i] / arr[j];
                    if (dp.count(factor)) {
                        dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[factor]) % MOD;
                    }
                }
            }
        }

        long long result = 0;
        for (auto& entry : dp) {
            result = (result + entry.second) % MOD;
        }

        return static_cast<int>(result);
    }
};