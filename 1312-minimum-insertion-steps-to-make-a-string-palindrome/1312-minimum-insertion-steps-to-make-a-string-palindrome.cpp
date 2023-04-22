class Solution {
    string s;
    vector<vector<int>> cache;

public:

    int dp(int i, int j) {
        if (i > j) return 0;
        if (cache[i][j] != -1) return cache[i][j];
        int ans = 0;
        if (s[i] == s[j]) {
            ans = dp(i + 1, j - 1);
        } else {
            ans = 1 + min(dp(i + 1, j), dp(i, j - 1));
        }

        return cache[i][j] = ans;
    }

    int minInsertions(string s) {
        int n = s.length();
        this->s = s;
        cache = vector<vector<int>>(n, vector<int>(n, -1));
        return dp(0, n - 1);
    }
};