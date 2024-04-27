class Solution {
public:
    int dp[109][109], n, m;

    int solve(int i, int j, string& ring, string& key) {
        if (j == m)
            return 0;

        int &ans = dp[i][j], cnt;
        if (~ans)
            return ans;
        ans = 1e6;

        cnt = 1;
        for (int k = i;; k++) {
            if (ring[k % n] == key[j]) {
                ans = min(ans, solve(k % n, j + 1, ring, key) + cnt);
                break;
            }
            cnt++;
        }

        cnt = 1;
        for (int k = i;; k--) {
            if (ring[(k + n) % n] == key[j]) {
                ans = min(ans, solve((k + n) % n, j + 1, ring, key) + cnt);
                break;
            }
            cnt++;
        }

        return ans;
    }

    int findRotateSteps(string ring, string key) {
        n = ring.size(), m = key.size();
        memset(dp, -1, sizeof dp);
        return solve(0, 0, ring, key);
    }
};