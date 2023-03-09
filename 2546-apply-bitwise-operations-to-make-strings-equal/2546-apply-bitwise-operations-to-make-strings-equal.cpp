class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        if (s == target) {
        return true;
    }
    int n = s.length();
    if (s == string(n, '0') || target == string(n, '0')) {
    return false;
    }
    return true;

    }
};