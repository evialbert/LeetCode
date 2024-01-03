class Solution {
public:
    long long mx = LLONG_MAX;

    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        map<int, set<string>> p;
        map<string, map<string, long long>> mp;

        for (int i = 0; i < original.size(); i++) {
            p[original[i].size() - 1].insert(original[i]);
            p[original[i].size() - 1].insert(changed[i]);

            if (mp[original[i]].find(changed[i]) != mp[original[i]].end())
                mp[original[i]][changed[i]] = min(mp[original[i]][changed[i]], 
                                                 (long long) cost[i]);
            else mp[original[i]][changed[i]] = cost[i];
        }
        
        for (auto& pos : p)
        for (auto& k : pos.second) {
            for (auto& i : pos.second) {
                if (!mp[i].count(k)) continue;
                for (auto& j : pos.second) {
                    if (!mp[k].count(j)) continue;
                    if (!mp[i].count(j)) mp[i][j] = mx;
                    mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
                }
            }
        }
        
        vector<long long> dp(source.size(), mx);
        for (int i = 0; i < source.size(); i++) {
            long long mc = mx;
            
            for (auto& b : p) {
                int a = b.first;

                if (i < a) continue;
                long long m1 = !(i - a) ? 0 : dp[i-a-1];
                string c = source.substr(i - a, a + 1), e = target.substr(i - a, a + 1);

                if (m1 != mx && mp[c].count(e)) {
                    mc = min(mc, mp[c][e] + m1);
                }
            }
            
            if (source[i] == target[i]) mc = min(mc, !i ? 0 : dp[i - 1]);
            dp[i] = mc;
        }
        
        return dp.back() == mx ? -1 : dp.back();
    }
};