class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1), cut(n, 1);
        int maxi = INT_MIN;
        int ans = 0;
        for (int ind=0; ind<n; ind++) {
            for (int prev=0; prev<ind; prev++) {
                if (arr[prev] < arr[ind] && 1 + dp[prev] > dp[ind]) {
                    dp[ind] = 1 + dp[prev];
                    cut[ind] = cut[prev];
                }
                else if(arr[prev] < arr[ind] && 1 + dp[prev] == dp[ind]) {
                    cut[ind] += cut[prev];
                }
            }
            maxi = max(maxi, dp[ind]);
        }
        for (int i=0; i<n; i++) {
            if (dp[i] == maxi) ans += cut[i];
        }
        return ans;
    }
};