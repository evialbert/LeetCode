class Solution {
    vector<int> g[100005];
    int bobdist[100005], parent[100005];
    int ans = INT_MIN;
    
    void dfs(int u, int p = -1, int d = 1) {
        parent[u] = p;
        for(int v: g[u]) {
            if(v == p) continue;
            dfs(v, u, d+1);
        }
    }
    
    void dfs1(int u, vector<int> &amount, int p = -1, int d = 1, int score = 0) {
        if(d == bobdist[u]) {
            score += (amount[u]/2);
        } else if(d < bobdist[u]) {
            score += amount[u];
        } else if(bobdist[u] == 0) {
            score += amount[u];
        }
        
        int child = 0;
        for(int v: g[u]) {
            if(v == p) continue;
            child += 1;
            dfs1(v, amount, u, d+1, score);
        }
        
        if(child == 0) {
            ans = max(ans, score);
        }
    }
        
        
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        for(auto it: edges) {
            int u = it[0], v = it[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        dfs(0);
        
        // for(int i = 0; i <= 4; i++) 
        //     // cout << parent[i] << " ";
        // cout << endl;
        
        int d = 1;
        for(int v = bob; v != -1; v = parent[v]) {
            if(v == bob)
                bobdist[bob] = 1;
            else {
                bobdist[v] = 1 + d;
                d = 1 + d;
            }
            // cout << bobdist[v] << endl;
        }
        
        
        dfs1(0, amount);
        
        
        return ans;
    }
};