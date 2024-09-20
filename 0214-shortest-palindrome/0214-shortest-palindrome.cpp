class Solution {
public:
    string shortestPalindrome(string s) {
        string t(s.rbegin(), s.rend());

        int maxLen = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.compare(0, s.length() - i, t, i, s.length() - i) == 0) {
                maxLen = s.length() - i;
                break;
            }
        }

        return t.substr(0, s.length() - maxLen) + s;
    }
};