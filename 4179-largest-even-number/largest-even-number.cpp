class Solution {
public:
    string largestEven(string s) {
        int n = s.size();
        string x = "";

        int lastTwo = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '2') lastTwo = i;
        }

        if (lastTwo == -1) return "";

        for (int i = 0; i <= lastTwo; i++) {
            x += s[i];
        }

        return x;
    }
};