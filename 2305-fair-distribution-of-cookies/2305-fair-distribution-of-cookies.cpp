class Solution {
public:
    int k, res = INT_MAX;
    vector<int> d = {0, 0, 0, 0, 0, 0, 0, 0};

    void dfs(vector<int> cookies, int index, int f) {
        if (index == cookies.size()) {
            int curr = 0;
            for (int i = 0; i < k; i++) curr = max(curr, d[i]);
            res = min(res, curr);
            return;
        }

        for (int i = 0; i < f; i++) {
            d[i] += cookies[index];
            dfs(cookies, index + 1, f);
            d[i] -= cookies[index];
        }

        if (f < k) {
            d[f] += cookies[index];
            dfs(cookies, index + 1, f + 1);
            d[f] -= cookies[index];
        }

    }

    int distributeCookies(vector<int>& cookies, int K) {
        k = K;
        dfs(cookies, 0, 0);
        return res;
    }
};