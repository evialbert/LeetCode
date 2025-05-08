class Solution {
public:
    string smallestPalindrome(string s) {
        int freqArr[26] = {0};
        int n = s.length();
        bool hasOddChar = (n%2 == 1);
        char oddChar;

        for (char c: s) {
            freqArr[c - 'a']++;
        }
        if (hasOddChar) {
            oddChar = s[ceil(n/2)];
        }

        int curr = 0;
        for (int i=0; i<26; i++) {
            int freq = freqArr[i];
            if (freq != 0) {
                while (freq > 1) {
                    s[curr] = 'a' + i;
                    s[n-curr-1] = 'a' + i;
                    freq -= 2;
                    curr++;
                }
            }
        }

        if (hasOddChar) {
            s[ceil(n/2)] = oddChar;
        }
        return s;
    }
};