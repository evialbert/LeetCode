class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.size()) return false;
        int letterCount[26] = {0}, oddCount = 0;
        for (char c : s) {
            oddCount += (++letterCount[c - 'a'] & 1) ? 1 : -1;
        }return oddCount <= k;
    }
};