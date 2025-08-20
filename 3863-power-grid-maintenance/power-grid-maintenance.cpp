class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        vector<vector<int>> adj(c + 1, vector<int>());
        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        map<int, set<int>> comp;
        map<int, int> mp;

        vector<int> vis(c + 1, 0);
        int id = 0;

        std::function<void(int, int)> dfs = [&](int node, int id) -> void {
            vis[node] = 1;
            mp[node] = id;
            comp[id].insert(node);
            for (const auto& it : adj[node]) {
                if (!vis[it]) {
                    dfs(it, id);
                }
            }
        };

        for (int i = 1; i <= c; i++) {
            if (!vis[i]) {
                id++;
                dfs(i, id);
            }
        }

        int q = queries.size();
        vector<int> ans;

        for (int i = 0; i < q; i++) {
            int op = queries[i][0];
            int node = queries[i][1];
            int compId = mp[node];
            if (op == 1) {
                if (comp[compId].size() == 0) {
                    ans.push_back(-1);
                    continue;
                }
                if (comp[compId].contains(node)) {
                    ans.push_back(node);
                    continue;
                }
                int x = *comp[compId].begin();
                ans.push_back(x);
            } else {
                comp[compId].erase(node);
            }
        }

        return ans;
    }
};