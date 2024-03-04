class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size()+1;
        vector<int> ans(n, 0);
        vector<vector<pair<int, int>>> adj(n);
        for(auto it:edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        for(int i = 0; i < n; i++) {
            int prev = 0, ians = 0;
            if(adj[i].size() <= 1)
                continue;
            for(auto it:adj[i]) {
                int cur = dfs(it.first, i, it.second, signalSpeed, adj);
                ians += cur*prev;
                prev += cur;
            }
            ans[i] = ians;
        }
        return ans;
    }
    
    int dfs(int cur, int par, int len, int speed, vector<vector<pair<int, int>>>& adj) {
        int cnt = 0;
        for(auto it:adj[cur]) {
            if(it.first != par)
                cnt += dfs(it.first, cur, len+it.second, speed, adj);
        }
        if((len % speed) == 0)
            cnt++;
        return cnt;
    }
};