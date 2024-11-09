class Solution {
public:
   int find(vector<int> &ds, int i) {
    return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
}
int minimumHammingDistance(vector<int>& s, vector<int>& t, vector<vector<int>>& allowedSwaps) {
    int sz = s.size(), res = 0;
    vector<int> ds(sz, -1);
    for (auto &sw: allowedSwaps) {
        int i = find(ds, sw[0]), j = find(ds, sw[1]);
        if (i != j) {
            if (ds[i] > ds[j])
                swap(i, j);
            ds[i] += ds[j];
            ds[j] = i;
        }
    }
    vector<unordered_multiset<int>> cycles(sz);
    for (auto i = 0; i < sz; ++i)
        if (s[i] != t[i])
            cycles[find(ds, i)].insert(s[i]);
    for (auto i = 0; i < sz; ++i) {
        if (s[i] != t[i]) {
            auto &cycle = cycles[find(ds, i)];
            auto it = cycle.find(t[i]);
            if (it != end(cycle)) {
                cycle.erase(it);
            } else
                ++res;
        }
    }        
    return res;
}
};