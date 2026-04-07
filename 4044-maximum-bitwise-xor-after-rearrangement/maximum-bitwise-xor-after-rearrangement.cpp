class Solution {
public:
    string maximumXor(string s, string t) {
        vector<int> c(2, 0);
        for (auto& b : t)
            c[b - '0']++;
        string res = "";
        for (auto& b : s) {
            int x = 1 - (b - '0');
            if (c[x] > 0) {
                res += '1';
                c[x]--;
            } else {
                res += '0';
                c[1 - x]--;
            }
        }
        return res;
    }
};