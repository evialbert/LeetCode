class Solution {
public:
    int dp[10001];
    int solve(int target) {
        if(dp[target] > 0) {
            return dp[target];
        }
        int n = floor(log2(target)) + 1;  // making sure 2^(n - 1) - 1 <= target <= 2^n - 1
        if((1 << n) - 1 == target) { // 1 + 2 + 4 + 8 .... + 2^(n - 1) = 2^n - 1
            return dp[target] = n; // total n operations needed all As
        }
        // n operations to reach beyond target at position 2^n - 1
        // 1 operation to turn back
        // remaining operations same as solve(2^n - 1 - target)
        int ans = n + 1 + solve(((1 << n) - 1) - target);
        // n - 1 operations to reach as far as possible just before target
        // 1 operation to turn back
        // m operations to go back 2^m - 1 positions
        // 1 operation to turn forward
        // remaining operations same as solve(target - (2^(n - 1) - 1 - (2^m - 1)))
        for(int m = 0; m < n - 1; m++) {
            ans = min(ans, n - 1 + 1 + m + 1 + solve(target - (((1 << (n - 1)) - 1) - ((1 << m) - 1))));
        }
        return dp[target] = ans;
    }

    int racecar(int target) {
        memset(dp, -1, sizeof(dp));
        return solve(target);
    }
};