class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        
        // build adj
        vector<vector<int>> adj(n);
        vector<int> outdegree(n);
        
        for (int u = 0; u < n; u++) {
            for (int v : graph[u]) {
                adj[v].push_back(u);
                outdegree[u]++;
            }
        }
        
        // topo sort
        queue<int> q;
        
        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            auto t = q.front();
            q.pop();
            
            ans.push_back(t);
            
            for (int v : adj[t]) {
                if (--outdegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};