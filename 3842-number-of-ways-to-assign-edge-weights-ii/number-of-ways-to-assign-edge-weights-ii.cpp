class Solution {
    int n, LOG;
    vector<vector<pair<int,int>>> adj;  // (neighbor, weight)
    vector<vector<int>> up;             // up[k][v] = 2^k-th ancestor of v
    vector<int> depth;                  // depth[v] from root
    vector<int> dist;                   // dist[v] = sum of weights from root to v

    // 1) DFS from root=0 to fill depth[], dist[], and up[0][v]
    void dfs(int v, int p) {
        up[0][v] = p;
        for (auto &edge : adj[v]) {
            int to = edge.first, w = edge.second;
            if (to == p) continue;
            depth[to] = depth[v] + 1;
            dist[to]  = dist[v] + w;
            dfs(to, v);
        }
    }

    // 2) Compute LCA in O(log n)
    int lca(int a, int b) {
        if (depth[a] < depth[b]) 
            swap(a, b);
        // lift a up to the same depth as b
        int diff = depth[a] - depth[b];
        for (int k = 0; k < LOG; k++) {
            if (diff & (1 << k))
                a = up[k][a];
        }
        if (a == b) return a;
        // lift both up until their parents differ
        for (int k = LOG - 1; k >= 0; k--) {
            if (up[k][a] != up[k][b]) {
                a = up[k][a];
                b = up[k][b];
            }
        }
        // now they differ but have the same parent
        return up[0][a];
    }

    // 3) Distance between any two nodes in O(log n)
    int getDist(int a, int b) {
        int c = lca(a, b);
        // dist[a] + dist[b] - 2*dist[c]
        return dist[a] + dist[b] - 2 * dist[c];
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) 
    {
        int mod = 1e9 + 7;
        n = edges.size() + 1;       
        vector<vector<int>> dp(n,vector<int> (2, 0));
        dp[1][0] = 1;
        dp[1][1] = 1;
        for (int i = 2 ; i < n; i ++) {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % mod; 
        }
        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        adj.assign(n, {});
        for (auto &e : edges) {
            int u = e[0] - 1;              // if input is 1-indexed
            int v = e[1] - 1;
            int w = 1;                     // assume each edge weight = 1
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // 1) alloc tables
        up.assign(LOG, vector<int>(n, 0));
        depth.assign(n, 0);
        dist .assign(n, 0);

        // 2) run DFS from node 0
        dfs(0, 0);

        // 3) build binary‐lifting table
        for (int k = 1; k < LOG; k++) {
            for (int v = 0; v < n; v++) {
                up[k][v] = up[k-1][ up[k-1][v] ];
            }
        }
        
        vector<int> ans;
        for (auto &q : queries) {
            int u = q[0] - 1;
            int v = q[1] - 1;
            int dist = getDist(u,v);
            ans.push_back(dp[dist][1]) ;
        }
        return ans;
    }
};