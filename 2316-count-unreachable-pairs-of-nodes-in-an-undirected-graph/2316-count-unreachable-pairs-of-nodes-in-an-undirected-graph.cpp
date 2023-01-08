class Solution {
public:
    int nodes;
    vector<bool> vis;
    
    void dfs(vector<vector<int>> &adj, int i){
       if(vis[i]) return;
       
        vis[i] = true;
        nodes++;
        
        for(auto x : adj[i]){
            dfs(adj,x);
        }
    }
    
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vis.resize(n,false);
        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        vector<int> v;
        
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(adj,i);
                v.push_back(nodes);
                nodes = 0;
            }
        }
        
        if(v.size()<=1) return 0;
        
        vector<long long> prefix(v.size());
        prefix[0] = v[0];
        for(int i=1; i<v.size(); i++){
            prefix[i] = prefix[i-1] + v[i];
        }
       
        long long ans = 0;
        for(int i=1; i<v.size(); i++){
            ans += v[i]*prefix[i-1];
        }
        
        return ans;
        
    }
};