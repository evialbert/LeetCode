class Solution {
    public:    
   vector<int> zArray(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    
    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    
    return z;
}
public:
    int minStartingIndex(string s, string pattern) {
        string a = pattern + '#' + s;
        int n = s.size(), m = pattern.size();
        string b = s + '#' + pattern;
        reverse(b.begin(), b.end());
        
        vector<int> zforward = zArray(a);
        vector<int> zback = zArray(b);
    
        for (int i = m + 1; i < n + m + 1; i++) {
            if (i + m > n + m + 1) break;
            int id = i - m - 1;
            int x = zforward[i];
            if (x >= m - 1) return id;
            x++;
            int req = m - x;
            int newid = id + m - 1;
            newid = n - 1 - newid;
            newid = m + 1 + newid;
            if (zback[newid] >= req) return id;
        }
        return -1;

    }
};