class Solution {
public:
    const int INF = 1e9 + 7;
    int dfs(int v, int p, vector<vector<int>>& edge, vector<int>& XOR, vector<int>& nums) {
        int x = 0;
        for (int u : edge[v]) {
            if (u != p) {
                x ^= dfs(u, v, edge, XOR, nums);
            }
        }
        x ^= nums[v];
        XOR[v] = x;
        return x;
    }
    void dfs1(int v, int p, vector<vector<int>>& edge, vector<int>& XOR, int one, int total, int& sol) {
        for (int u : edge[v]) {
            if (u != p) {
                int two = XOR[u];
                int three = total ^ two;
                int bg = max({one, two, three});
                int sm = min({one, two, three});
                sol = min(sol, bg - sm);
                dfs1(u, v, edge, XOR, one, total, sol);
            }
        }
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> edge(n);
        for (const vector<int>& v : edges) {
            edge[v[0]].push_back(v[1]);
            edge[v[1]].push_back(v[0]);
        }
        int sol = INF;
        int total = 0;
        for (int i : nums) {
            total ^= i;
        }
        for (int i = 0; i < n; i++) {
            vector<int> XOR(n);
            for (int u : edge[i]) {
                dfs(i, u, edge, XOR, nums);
                int one = total ^ XOR[i];
                int tot = XOR[i];
                dfs1(i, u, edge, XOR, one, tot, sol);
            }
        }
        return sol;
    }
};