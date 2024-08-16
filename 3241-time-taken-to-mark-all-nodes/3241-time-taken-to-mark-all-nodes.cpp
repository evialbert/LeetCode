class Solution {
public:

    void dfs(vector<int> v[], int src, int vis[], int dp[]) {
        vis[src]=1;
        int maxm = 0;
        for (auto x: v[src]) {
            if(!vis[x]) {
                dfs(v, x, vis, dp);
                if (x%2==0) {
                    maxm = max(maxm, 2+dp[x]);
                } else {
                    maxm = max(maxm, 1+dp[x]);
                }
            }
        }
        dp[src] = maxm;
    }
    
    void dfs2(vector<int> v[], int src, int par, int val, int dp[], vector<int> &res, int vis[]) {
        vis[src] = 1;
        int maxm = 0;
        if (par != -1) {
            maxm = val + (par%2==0 ? 2 : 1 );
        }
        int pp = maxm;
        vector<int> max1, max2;
        for (int i=0;i<v[src].size();++i) {
            int x = v[src][i];
            if (x == par)continue;
            max1.push_back(dp[x] + (x%2==0 ? 2 : 1));
            max2.push_back(dp[x] + (x%2==0 ? 2 : 1));
        }
        for (int i=0;i<max1.size();++i) {
            maxm = max(maxm, max1[0]);
            if (i==0)continue;
            max1[i]=max(max1[i], max1[i-1]);
            maxm = max(max1[i], maxm);
            
        }
        for (int i=max2.size()-2; i>=0;--i) {
            max2[i]=max(max2[i], max2[i+1]);
        }
        res[src] = maxm;
        maxm = pp;
        int ind = 0;
        for (int i=0; i<v[src].size(); ++i) {
            int x = v[src][i];
            if (x == par)continue;
            int zz = 0;
            if (ind>0)zz = max(zz, max1[ind-1]);
            if (ind<max2.size()-1) zz = max(zz, max2[ind+1]);
            dfs2(v, x, src, max(zz, pp), dp, res, vis);
            ind++;
        }
    }

    vector<int> timeTaken(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> v[n+1];
        for (auto x: edges) {
            int a = x[0];
            int b = x[1];
            v[a].push_back(b);
            v[b].push_back(a);
        }
        int dp[n+1];
        memset(dp, 0, sizeof(dp));
        vector<int> res(n+1);
        int vis[n+1];
        memset(vis, 0, sizeof(vis));
        dfs(v, 0, vis, dp);
        memset(vis, 0, sizeof(vis));
        dfs2(v, 0, -1, 0, dp, res, vis);
        return res;
    }
};