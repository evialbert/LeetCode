class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int u, int p, int po, int &k, vector<int> adj[], vector<int> &cost){
        if(po > 14)
            return 0;
        if(dp[u][po] != -1)
            return dp[u][po];
        int res1 = floor(cost[u]/pow(2, po)) - k;
        int res2 = floor(cost[u]/pow(2, po+1));
        for(auto v : adj[u])
            if(v != p){
                res1 += dfs(v, u, po, k, adj, cost);
                res2 += dfs(v, u, po+1, k, adj, cost);
            }
        dp[u][po] = max(res1, res2);
        return dp[u][po];
    }
    int maximumPoints(vector<vector<int>> &edges, vector<int> &cost, int k) {
        int n = edges.size() + 1;
        vector<int> adj[n];
        for(auto x : edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        dp = vector<vector<int>> (n+1, vector<int> (15, -1));
        return dfs(0, -1, 0, k, adj, cost);
    }
};