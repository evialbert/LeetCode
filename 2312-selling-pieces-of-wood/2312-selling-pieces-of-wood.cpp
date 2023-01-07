class Solution {
public:
    using ll = long long;
    ll memo[201][201]{}, mp[201][201]{};
    ll sellingWood(int m, int n, vector<vector<int>>& P) {
        for(auto &p : P) mp[p[0]][p[1]] = p[2];
        return help(m, n);
    }

    ll help(int m, int n) {
        ll res = memo[m][n];
        if(res) return res-1;
        if(mp[m][n]) res = mp[m][n];
        for(int i = 1; i <= m/2; i++) res = max(res, help(i, n)+help(m-i, n));
        for(int i = 1; i <= n/2; i++) res = max(res, help(m, i)+help(m, n-i));
        memo[m][n] = res+1;
        return res;
    }
};