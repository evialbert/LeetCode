class Solution {
public:
    int find(int i, vector<int> &ds) {
        return ds[i] < 0 ? i : ds[i] = find(ds[i], ds);
    }
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        vector<int> ds(n + 1, -1);
        for (int i = threshold + 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                int pi = find(i, ds), pj = find(j, ds);
                if (pi != pj) {
                    if (ds[pi] > ds[pj]) swap(pi, pj);
                    ds[pi] += ds[pj];
                    ds[pj] = pi;
                }
            }
        }
        vector<bool> ans;
        for (auto& q : queries)
            ans.push_back(find(q[0], ds) == find(q[1], ds));
        return ans;
    }
};