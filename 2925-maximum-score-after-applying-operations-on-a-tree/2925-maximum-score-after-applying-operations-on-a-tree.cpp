class Solution {
public:
    using ll= long long int;
    long long dfs(int node,int parent,vector<vector<int>>&adj,vector<int>&values){
        ll child=0;
        ll count_of_child=0;
        for(auto &it:adj[node]){
            if(it==parent) continue;
            child++;
            count_of_child+= dfs(it,node,adj,values);
}
        return child==0?ll(values[node]) : min(ll(values[node]),count_of_child);
}
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        ll n = values.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n - 1; i++){
            int u = edges[i][0], v= edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ll ans=0;
        for(int i = 0; i < n; i++) ans += values[i];
        return ans - dfs(0, -1,adj, values);
    }
};