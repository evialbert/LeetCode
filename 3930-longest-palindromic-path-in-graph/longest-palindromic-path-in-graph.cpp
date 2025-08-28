class Solution {
    vector<vector<int>>adj;
    string input;
    int res = 1;
    vector<vector<vector<bool>>>dp;
    void dfs(int node1,int node2,int mask){
        if(dp[node1][node2][mask])return;
        dp[node1][node2][mask] = 1;
        int cnt = __builtin_popcountll(mask);
        res = max(res,cnt);
        for(auto u : adj[node1]){
            if(mask&(1<<u))continue;
            for(auto v : adj[node2]){
                if(u==v || mask&(1<<v))continue;
                if(input[u] == input[v]){
                    dfs(u,v,mask|(1<<u)|(1<<v));
                }
            }
        }
    }
public:
    int maxLen(int n, vector<vector<int>>& edges, string label) {
        input = label;
        adj.resize(n);
        set<pair<int,int>>ed;
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            ed.insert({u,v});
            ed.insert({v,u});
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dp.assign(n,vector<vector<bool>>(n,vector<bool>(1<<n,0)));
        for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               if(i==j || (ed.count({i,j}) && input[i] == input[j])){
                   int mask = (1<<i)|(1<<j);
                   dfs(i,j,mask);
               }
           }
        }
        return res;
















        
    }
};