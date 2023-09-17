struct Pair{
    int v;
    bool fake;
};

class Solution {
private:
    unordered_map<int,vector<Pair>> mp;
    map<pair<int,int>,int> dp;
private:
    int dfs(int cur, int prev){
        if(dp.count({cur, prev}))
            return dp[{cur, prev}];

        int hit = 0;
        for(auto& nei : mp[cur]){
            if(nei.v == prev)
                continue;
            if(nei.fake)
                hit++;
            hit += dfs(nei.v, cur);
        }

        return dp[{cur, prev}] = hit;
    }
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        // dp.clear();

        for(auto& e : edges){
            int a = e[0], b = e[1];
            mp[a].push_back({b, false});
            mp[b].push_back({a, true});
        }

        vector<int> ans(n, -1);
    
        for(int i=0; i<n; i++)
            ans[i] = dfs(i, -1);

        return ans;
    }
}; 