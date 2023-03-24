class Solution {
    void dfs(int node, int prnt, vector<pair<int, int>> adj[], int &ans) {
        for(auto ad : adj[node]) {
            if(ad.first == prnt) continue;
            if(ad.second) ans++;
            dfs(ad.first, node, adj, ans);
        }
    }
    
public:
    int minReorder(int n, vector<vector<int>>& c) {
        vector<pair<int, int>> adj[n];
        for(auto e : c) adj[e[0]].push_back({e[1], 1});
        for(auto e : c) adj[e[1]].push_back({e[0], 0});
        
        int ans = 0;
        dfs(0, -1, adj, ans);
        return ans;
    }
};