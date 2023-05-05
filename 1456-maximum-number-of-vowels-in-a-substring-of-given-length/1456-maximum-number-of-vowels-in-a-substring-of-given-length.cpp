class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    int maxVowels(string s, int k) {
        int vowelCnt = 0;
        for (size_t i = 0; i < k; i++) {
            vowelCnt += isVowel(s[i]);
        }

        int ans = vowelCnt;
        for (size_t i = k; i < s.length(); i++) {
            vowelCnt += isVowel(s[i]);
            vowelCnt -= isVowel(s[i - k]);
            ans = max(ans, vowelCnt);
        }
        return ans;
    }
};