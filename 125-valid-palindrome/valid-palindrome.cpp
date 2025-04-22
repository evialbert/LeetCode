class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;

        while (l < r) {
            while (l < r && !isalnum(s[l])) {
                l++;
            }
            while (r > l && !isalnum(s[r])) {
                r--;
            }
            if (l > r || tolower(s[l]) != tolower(s[r])) {
                return false;
            } else {
                l++;
                r--;
            }
        }
        return true;
    }
};