class Solution
{
public:
    bool process(int node, int par, int dst, vector<int> &count, vector<int> adj[])
    {
        if (node == dst)
            return true;
        for (auto i : adj[node])
        {
            if (i != par)
            {
                if (process(i, node, dst, count, adj))
                {
                    count[i]++;
                    return true;
                }
            }
        }
        return false;
    }

    int dp[51][2];
    int dfs(int node, int par, bool par_taken, vector<int> &cnt, vector<int> &price, vector<int> adj[])
    {
        if (dp[node][par_taken] != -1)
            return dp[node][par_taken];

        int childs = 0;
        for (auto i : adj[node])
            if (i != par)
                childs++;

        if (childs == 0)
        {
            if (par_taken)
                return dp[node][par_taken] = cnt[node] * (price[node]);
            return dp[node][par_taken] = cnt[node] * (price[node] / 2);
        }

        if (par_taken)
        {
            int ans = 0;
            for (auto i : adj[node])
                if (i != par)
                    ans += dfs(i, node, false, cnt, price, adj);
            ans += cnt[node] * price[node];
            return dp[node][par_taken] = ans;
        }

        int ans1 = 0;
        int ans2 = 0;
        for (auto i : adj[node])
        {
            if (i != par)
            {
                ans1 += dfs(i, node, false, cnt, price, adj);
                ans2 += dfs(i, node, true, cnt, price, adj);
            }
        }
        ans1 += cnt[node] * (price[node]);
        ans2 += cnt[node] * (price[node] / 2);
        return dp[node][par_taken] = min(ans1, ans2);
    }

    int minimumTotalPrice(int n, vector<vector<int>> &edges, vector<int> &price, vector<vector<int>> &trips)
    {
        memset(dp, -1, sizeof(dp));
        vector<int> adj[n];
        for (auto i : edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        vector<int> cnt(n);
        for (auto i : trips)
        {
            cnt[i[0]]++;
            process(i[0], -1, i[1], cnt, adj);
        }

        return dfs(0, -1, false, cnt, price, adj);
    }
};