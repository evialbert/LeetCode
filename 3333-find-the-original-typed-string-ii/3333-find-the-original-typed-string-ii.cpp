class Solution {
public:
    int possibleStringCount(string word, int k) {
        int mod = 1e9 + 7;
        vector<int> rle;
        long long ans = 1;
        int cnt = 1;
        for (int i = 1; i < word.size(); i++) {
            if (word[i - 1] != word[i]) {
                ans = (ans * cnt) % mod;
                rle.emplace_back(cnt);
                cnt = 0;
            }
            cnt++;
        }
        ans = (ans * cnt) % mod;
        rle.emplace_back(cnt);
        int N = rle.size();
        if (k <= N) return ans;
        vector<int> dp(k, 0), ndp(k);
        dp[0] = 1;
        for (int i = 0; i < N; i++) {
            ndp.assign(k, 0);
            int wsum = 0;
            for (int j = i; j < k; j++) {
                ndp[j] = (ndp[j] + wsum) % mod;
                wsum = (wsum + dp[j]) % mod;
                if (j >= rle[i]) wsum = (wsum - dp[j - rle[i]] + mod) % mod;
            }
            swap(ndp, dp);
        }
        for (const int& x : dp) {
            ans = (ans - x + mod) % mod;
        }
        return ans;
    }
};