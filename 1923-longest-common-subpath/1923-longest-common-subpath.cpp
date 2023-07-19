class Solution {
public:
    int longestCommonSubpath(int n, vector<vector<int>>& ps) {
    int l = 0, r = min_element(begin(ps), end(ps), [](const auto& a, const auto &b){ return a.size() < b.size(); })->size();
    long long base = 100001, mod = 100000000019;
    while (l < r) {
        int m = (l + r + 1) / 2;
        unordered_set<long long> hs;
        for (int i = 0; i < ps.size() && (i == 0 || !hs.empty()); ++i) {
            long long hash = 0, d = 1;
            unordered_set<long long> hs1;
            for (int j = 0; j < ps[i].size(); ++j) {
                hash = (hash * base + ps[i][j]) % mod;
                if (j >= m)
                    hash = (mod + hash - d * ps[i][j - m] % mod) % mod;
                else
                    d = d * base % mod;    
                if (j >= m - 1 && (i == 0 || hs.count(hash)))
                    hs1.insert(hash);
            }
            swap(hs, hs1);
        }
        if (hs.empty())
            r = m - 1;
        else
            l = m;            
    }
    return l;
}
};