class Solution {
public:
    void bfs2(int s, vector<int>& ans, vector<vector<int>>& adj, int k){
        vector<int> vis(adj.size(), 0);
        queue<pair<int, int>> q;
        q.push({s, 0});
        vis[s]=1;
        while(!q.empty()){
            pair<int, int> top = q.front();
            q.pop();
            int node = top.first;
            int dist = top.second;
            if(dist<=k){
                ans[s]++;
            }else{
                continue;
            }
            for(int ngb: adj[node]){
                if(ngb==s || vis[ngb]!=0) continue;
                q.push({ngb, dist+1});
                vis[ngb]=1;
            }
            vis[node]=2;
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;
        vector<vector<int>> adj1(n, vector<int>()), adj2(m, vector<int>());
        for(auto edge: edges1){
            int u = edge[0];
            int v = edge[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        for(auto edge: edges2){
            int u = edge[0];
            int v = edge[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
        vector<int> t2kminus1(m, 0);
        int maxT2 = 0;
        for(int i=0; i<m; i++){
            bfs2(i, t2kminus1, adj2, k-1);
            maxT2 = max(maxT2, t2kminus1[i]);
        }
        cout<<maxT2<<endl;
        vector<int> ans(n, maxT2);
        for(int i=0; i<n; i++){
            bfs2(i, ans, adj1, k);
        }
        return ans;
    }
};