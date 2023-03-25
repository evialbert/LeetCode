class Solution {
public:
    int dfs(int idx,vector<vector<int>> &adj,vector<bool> &vis,int cnt)
    {
        vis[idx]=true;
        int ans=cnt;
        for(auto &child:adj[idx])
        {
            if(!vis[child])
                ans+=dfs(child,adj,vis,cnt);
        }
        return ans;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans=0;
        vector<bool> vis(n,false);
        vector<vector<int>> adj(n);
        for(auto &i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                int k=dfs(i,adj,vis,1);
                //cout<<i<<' '<<k<<'\n';
                ans += 1LL*(k)*(n-k);
            }
        }
        return ans/2;
        
    }
};