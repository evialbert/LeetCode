class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length(), b = 0;
        for (char c : s) if (c == '1') b++;
        string t = "1" + s + "1";
        int m = t.length(), r = b;
        
        for (int i = 1; i < m - 1; ) {
            if (t[i] == '1') {
                int j = i;
                for (; j < m && t[j] == '1'; j++);
                if (t[i - 1] == '0' && t[j] == '0') {
                    int a = 0, c = 0, k;
                    for (k = i - 1; k >= 0 && t[k] == '0'; k--) a++;
                    for (k = j; k < m && t[k] == '0'; k++) c++;
                    r = max(r, b + a + c);
                }
                i = j;
            } else i++;
        }
        return r;
    }
};