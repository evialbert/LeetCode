class Solution {
public:
    void dfs1(int u, int par, vector<vector<int>>& adj, vector<int>& weight, vector<int>& downScore) {
        downScore[u] = weight[u];
        for(auto &v : adj[u]) {
            if(v == par) {
                continue;
            }
            dfs1(v, u, adj, weight, downScore);
            downScore[u] += max(0, downScore[v]);
        }
    }

    void dfs2(int u, int par, vector<vector<int>>& adj, vector<int>& weight, vector<int>& downScore, vector<int>& upScore, vector<int>& ans) {
        ans[u] = downScore[u] + upScore[u];
        for(auto &v : adj[u]) {
            if(v == par) {
                continue;
            }
            int removedContribution = downScore[u] - max(0, downScore[v]);
            upScore[v] = max(0, upScore[u] + removedContribution);
            dfs2(v, u, adj, weight, downScore, upScore, ans);
        }
    }

    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {
        vector<vector<int>> adj(n);
        for(auto &it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> weight(n); // convert from (0,1) to (-1,1)
        for(int i=0; i<n; i++) {
            if(good[i] == 1) {
                weight[i] = 1;
            } else {
                weight[i] = -1;
            }
        }
        vector<int> ans(n);
        vector<int> downScore(n);
        vector<int> upScore(n);
        dfs1(0, -1, adj, weight, downScore);
        dfs2(0, -1, adj, weight, downScore, upScore, ans);
        return ans;
    }
};