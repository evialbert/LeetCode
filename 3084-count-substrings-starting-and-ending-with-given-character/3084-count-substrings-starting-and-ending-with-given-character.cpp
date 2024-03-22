class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long ans = 0;
        long long countof = count(s.begin(), s.end(),c);
        return (countof*(countof+1))/2;
    }
};