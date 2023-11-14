class Solution {
public:
    int countPalindromicSubsequence(string s) {
        char c[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        int a = 0, t = 0;

        int l, r;
        for (char x : c) {
            for (l = 0; l < s.length() && s[l] != x; l++);
            if (l == s.length()) continue;
            for (r = s.length() - 1; r >= 0 && s[r] != x; r--);
            if (l >= r) continue;

            vector<bool> v(128, false);
            t = 0;
            for (int i = l + 1; i < r; i++) {
                if (!v[s[i]]) {
                    v[s[i]] = true;
                    t++;
                    if (t == 26) break;
                }
            }
            a += t;
        }
        return a;
    }
};