class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int dp1 = 0;
        int dp2 = 0;
        int dp3 = 0;

        for (int i = 1; i <= n; i++) {
            int curr = costs[i - 1] + min(
                dp3 + 1,
                min(dp2 + 4, dp1 + 9)
            );

            dp1 = dp2;
            dp2 = dp3;
            dp3 = curr;
        }

        return dp3;
    }
};