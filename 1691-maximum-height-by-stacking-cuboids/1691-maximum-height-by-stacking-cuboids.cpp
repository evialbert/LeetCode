class Solution {
private:
	bool check(vector<int> &a, vector<int> &b) {
		return a[0] <= b[0] && a[1] <= b[1] && a[2] <= b[2];
	}
public:
	int maxHeight(vector<vector<int>>& a) {
		int n = a.size();

		vector<int> dp(n, 0);

		for (auto &e : a) {
			sort(e.begin(), e.end());
		}

		sort(a.begin(), a.end());

		int ans = INT_MIN;
		for (int i = 0; i < n; ++i) {
            dp[i] = a[i][2];
			for (int j = 0; j < i; ++j) {
				if (check(a[j], a[i]) && dp[j] + a[i][2] > dp[i]) dp[i] = dp[j] + a[i][2];
			}
			ans = max(ans, dp[i]);
		}
		return ans;
	}
};