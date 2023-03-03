class Solution {
public:
    long long anss = 0;
    long long max(long long a, long long b){
        return a>b?a:b;
    }
    void dfs2(int src, vector<int> v[], vector<int> &p, vector<int> &val, vector<int> &vis, long long par = 0){
        anss = max(anss, val[src]-p[src]);
        vis[src]=1;
        vector<pair<long long, int> > vv;
        for(auto x: v[src]){
            if(!vis[x]){
                vv.push_back(make_pair(val[x], x));
            }
        }
        vv.push_back(make_pair(par, -1));
        sort(vv.begin(), vv.end());
        reverse(vv.begin(), vv.end());
        anss = max(anss, vv[0].first);
        for(auto x: v[src]){
            if(vis[x])continue;
            if(vv[0].second == x){
                dfs2(x, v, p, val, vis, vv[1].first+p[src]);
            } else dfs2(x, v, p, val, vis, vv[0].first+p[src]);
        }
        
    }
    void dfs(int src, vector<int> v[], vector<int> &p, vector<int> &val, vector<int> &vis){
        vis[src]=1;
        long long ans = 0;
        for(auto x: v[src]){
            if(!vis[x]){
                dfs(x, v, p, val, vis);
                ans = max(ans, val[x]);
            }
        }
        val[src]=ans + p[src];
    }
    long long maxOutput(int n, vector<vector<int>>& e, vector<int>& p) {
        vector<int> v[n+1];
        for(int i=0;i<e.size();++i){
            v[e[i][0]].push_back(e[i][1]);
            v[e[i][1]].push_back(e[i][0]);
        }
        vector<int> val(n+1);
        vector<int> vis(n+1);
        dfs(0, v, p, val, vis);
        for(int i=0;i<=n;++i)vis[i]=0;
        dfs2(0, v, p, val, vis);
        return anss;
    }
};