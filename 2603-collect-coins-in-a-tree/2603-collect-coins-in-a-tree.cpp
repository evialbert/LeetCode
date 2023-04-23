class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size(), totEdg = 2 * edges.size(), del = 0;
        set<int> adj[n];
        queue<int> q;
        for(auto &e : edges) adj[e[0]].insert(e[1]), adj[e[1]].insert(e[0]);
        for(int i = 0; i<n; ++i) if(adj[i].size() == 1 && !coins[i]) q.push(i);
        while(q.size()){
            int nn = q.front(); q.pop();
            if(!adj[nn].size()) continue;
            int par = *adj[nn].begin();
            adj[par].erase(adj[par].find(nn));
            del++;
            adj[nn].erase(adj[nn].find(par));
            del++;
            if(adj[par].size() == 1 && !coins[par]) q.push(par);
        }
        for(int i = 0; i < n; ++i) if(adj[i].size() == 1) q.push(i);
        for(int i = 0; i< 2; ++i){
            int sz = q.size();
            while(sz--){
                int nn = q.front(); q.pop();
                if(!adj[nn].size()) continue;
                int par = *adj[nn].begin();
                adj[par].erase(adj[par].find(nn));
                del++;
                adj[nn].erase(adj[nn].find(par));
                del++;
                if(adj[par].size() == 1) q.push(par);
            }
        }
        return totEdg - del;
    }
};