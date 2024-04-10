class Solution {
    
    void dfs(int node, vector<vector<pair<int, int>>> &adj, vector<bool> &vis, int &res, vector<int> &A){
        for(auto &x:adj[node]){
            res &= x.second;
            if(!vis[x.first]){
                A.push_back(x.first);
                vis[x.first] = 1;
                dfs(x.first, adj, vis, res, A);
            }
        }
    }

    
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {

        //adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for (auto &x: edges) {
            adj[x[0]].push_back(make_pair(x[1], x[2]));
            adj[x[1]].push_back(make_pair(x[0], x[2])); 
        }
        
        vector<bool> vis(n);
        vector<pair<int, int>> mp(n);
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                vis[i] = 1;
                int res = INT_MAX;
                vector<int>A = {i};
                dfs(i, adj, vis, res, A);
                
                for(int &x:A) mp[x] = {res, i};
            }
        }
        
        int m = query.size();
        vector<int> ans(m, -1);
        for(int i = 0; i<m; i++){
            auto q = query[i];
            if(q[0]==q[1]) ans[i] = 0;
            else if(mp[q[0]].second == mp[q[1]].second) ans[i] = mp[q[0]].first;
        }
        
        return ans;
        
    }
};