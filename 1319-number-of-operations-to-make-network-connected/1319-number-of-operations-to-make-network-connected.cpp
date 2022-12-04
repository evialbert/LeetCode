class Solution {
public:
    void dfs(int i, vector<int> adj[], vector<int> &vis) {
        vis[i]=1;
        for(auto x: adj[i]) {
            if(vis[x]==0) {
                dfs(x, adj, vis);
            }
        }
    }
    int noOfComp(int n, vector<int> adj[]) {
        int ans=0;
        vector<int> vis(n, 0);
        for(int i=0;i<n;i++) {
            if(vis[i]==0) {
                dfs(i, adj, vis);
                ans++;
            }
        }
        return ans;
    }
    int makeConnected(int n, vector<vector<int>>& a) {
        if(a.size() < n-1) return -1;
        vector<int> adj[n];
        for(auto x: a) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int ans=noOfComp(n, adj);
        return ans-1;
    }
};