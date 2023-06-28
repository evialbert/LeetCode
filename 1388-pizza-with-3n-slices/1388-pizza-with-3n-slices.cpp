class Solution {
private:
	int f(int i, int e, vector<int> &slices, int n, vector<vector<int>> &dp) {
		if (n == 0 || i > e) return 0;
        if(dp[i][n] != -1) return dp[i][n];
		int take = slices[i] + f(i + 2, e, slices, n - 1, dp);
		int not_take = f(i + 1, e, slices, n, dp);
		return dp[i][n] = max(take, not_take);
	}
public:
	int maxSizeSlices(vector<int>& slices) {
		int n = slices.size();
        vector<vector<int>> dp1(n, vector<int>(n, -1));
		int case1 = f(0, n - 2, slices, n / 3, dp1);
        vector<vector<int>> dp2(n, vector<int>(n, -1));
		int case2 = f(1, n - 1, slices, n / 3, dp2);
		return max(case1, case2);
	}
};