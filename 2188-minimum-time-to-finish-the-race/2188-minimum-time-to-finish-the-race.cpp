class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        vector<int>dp(numLaps, INT_MAX);
        int mx = 0;
        for (int i = 0; i < tires.size(); i++) {
            int curr = 0, p = 0;
            while (curr < changeTime && p < dp.size()) {
                curr += tires[i][0] * pow(tires[i][1], p);
                dp[p] = min(dp[p], curr + changeTime);
                p++;
            }
            mx = max(mx, p);
        }
        for (int i = 1; i < dp.size(); i++)
            for (int j = 0; j < min(mx, i); j++)
                dp[i] = min(dp[i], dp[j] + dp[i - j - 1]);
        return dp.back() - changeTime;
    }
};