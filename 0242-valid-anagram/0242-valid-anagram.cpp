class Solution {
public:
    bool isAnagram(string s, string t) {
        if (t.length() != s.length()) {
            return false;
        }
        int sarr[26] = {0};
        int tarr[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            sarr[s[i] - 'a']++;
            tarr[t[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (sarr[i] != tarr[i]) {
                return false;
            }
        }
        return true;
    }
};