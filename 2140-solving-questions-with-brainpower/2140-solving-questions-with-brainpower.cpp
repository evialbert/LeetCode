class Solution {
public:
    long long dfs(int ind, vector<vector<int>>& questions, int n, vector<long long>& dp) {
        if (ind >= n) return 0;
        if (dp[ind] != -1) return dp[ind];
        long long pick = questions[ind][0] + dfs(ind + questions[ind][1] + 1, questions, n, dp);
        long long notPick = 0 + dfs(ind + 1, questions, n, dp);

        return dp[ind] = max(pick, notPick);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, -1);
        return dfs(0, questions, n, dp);
    }
};