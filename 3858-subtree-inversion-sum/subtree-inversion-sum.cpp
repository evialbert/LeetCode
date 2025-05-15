class Solution {
public:
    long long subtreeInversionSum(vector<vector<int>>& edges, vector<int>& nums, int k) {
        int n = edges.size() + 1;
        vector<vector<int>> g(n);
        for(auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(2, vector<long long>(k + 1, LLONG_MIN)));

        auto go = [&](auto&& go, int node, int parent, bool flipped, int flipDist) -> long long {
            if(flipDist > k)
                flipDist = k;
            
            if(dp[node][flipped][flipDist] != LLONG_MIN)
                return dp[node][flipped][flipDist];

            int sign = flipped ? -1 : 1;
            
            // dont flip
            long long df = sign * nums[node];
            for(auto& child : g[node]) {
                if(child == parent)
                    continue;
                df += go(go, child, node, flipped, flipDist + 1);
            }

            // flip if can
            if(flipDist == k) {
                long long f = sign * -1 * nums[node];
                for(auto& child : g[node]) {
                    if(child == parent)
                        continue;
                    f += go(go, child, node, !flipped, 1);
                }

                df = max(df, f);
            }

            return dp[node][flipped][flipDist] = df;
        };

        return go(go, 0, -1, false, k);
    }
};