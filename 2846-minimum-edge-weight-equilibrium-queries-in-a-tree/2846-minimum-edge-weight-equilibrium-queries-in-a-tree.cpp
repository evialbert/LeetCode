class Solution {
public:
    vector<int> depth;
    int weights[10004][27];
    int par[10004][16];
    vector<vector<pair<int, int>>> g;
    void dfs(int src, int paren = -1)
    {
        for(auto [child, wt] : g[src])
        {
            if(child == paren)
                continue;

            weights[child][wt]++;
            for(int i = 0; i < 27; i++)
                weights[child][i] += weights[src][i];

            par[child][0] = src;
            depth[child] = depth[src] + 1;
            dfs(child, src);
        }
    }

    int lca(int a, int b)
    {
        if(depth[a] < depth[b])
            swap(a, b);
        
        int diff = depth[a] - depth[b];
        for(int i = 0; i < 16; i++)
            if(diff & (1 << i))
                a = par[a][i];

        if(a == b)
            return a;
        
        for(int i = 15; i >= 0; i--)
        {
            if(par[a][i] != par[b][i])
            {
                a = par[a][i];
                b = par[b][i];
            }
        }

        return par[a][0];
    }
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        depth.resize(n);
        g.resize(n);
        for(auto edge : edges)
        {
            g[edge[0]].push_back({edge[1], edge[2]});
            g[edge[1]].push_back({edge[0], edge[2]});
        }

        dfs(0);
        for(int i = 1; i < 16; i++)
        {
            for(int node = 0; node < n; node++)
            {
                int parent = par[node][i - 1];
                par[node][i] = par[parent][i - 1];
            }
        }

        vector<int> ans;
        for(auto query : queries)
        {
            int a = query[0];
            int b = query[1];

            int node = lca(a, b);
            int distance = depth[a] + depth[b] - 2 * depth[node];
            // cout << node << " " << distance << endl;
            int maxx = 0;
            for(int i = 0; i < 27; i++)
                maxx = max(maxx, abs(weights[a][i] + weights[b][i] - 2 * weights[node][i]));
            
            ans.push_back(distance - maxx);
        }

        return ans;
    }
};