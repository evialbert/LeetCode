class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> q(nums.begin(), nums.end());
        vector<bool> ans(n), dp(k + 1, false);
        dp[0] = true;

        sort(q.begin(), q.end());
        for (int x = 1; x <= n; x++) {
            // Add all numbers <= x into our subset-sum DP
            while (!q.empty() && q.front() <= x) {
                int val = q.front();
                for (int j = k; j - val >= 0; j--) {
                    dp[j] = dp[j] || dp[j - val];
                }
                q.pop_front();
            }

            int available = q.size(); // numbers >= x, they cap to x
            for (int val = k; val >= 0; val--) {
                if (!dp[val]) continue;
                if ((k - val) % x != 0) continue;
                int need = (k - val) / x;
                if (need <= available) {
                    ans[x - 1] = true;
                    break;
                }
            }
        }
        
        return ans;
    }
};