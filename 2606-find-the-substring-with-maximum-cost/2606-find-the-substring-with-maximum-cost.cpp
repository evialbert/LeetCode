class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int l = s.length();
        int res = INT_MIN;
        
        int n = vals.size();
        
        unordered_map<char, int> charVals;
        for (int i = 0; i < n; i++) {
            charVals[chars[i]] = vals[i];
        }

        vector<int> dp(l + 1, 0);

        int maxVal = 0;
        for (int i = 1; i <= l; i++) {
            char c = s[i - 1];
            if (charVals.count(c) > 0) {
                int val = charVals[c];
                dp[i] = max(dp[i - 1] + val, val);
            } else {
                int val = c - 'a' + 1;
                dp[i] = max(dp[i - 1] + val, val);
            }
            maxVal = max(maxVal, dp[i]);
        }

        return maxVal;

    }
};