class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        ss >> word;

        int count = 0;
        for (char& ch : word) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                count++;
            }
        }

        string ans = word;

        while (ss >> word) {
            ans += " ";
            int sum = 0;

            for (char& ch : word) {
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                    sum++;
                }
            }

            if (sum == count) {
                reverse(word.begin(), word.end());
            }

            ans += word;
        }

        return ans;
    }
};