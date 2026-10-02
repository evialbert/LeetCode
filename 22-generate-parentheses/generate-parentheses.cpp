class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n + 1);
        dp[0] = {""};

        for (int pair = 1; pair <= n; pair++) {
            for (int l = 0; l < pair; l++) {
                int r = pair - 1 - l;

                for (string a : dp[l]) {
                    for (string b : dp[r]) {
                        dp[pair].push_back("(" + a + ")" + b);
                    }
                }

            }
        }

        return dp[n];
    }
};