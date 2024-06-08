class Solution {
public:
    string clearDigits(string s) {
        int n = s.length();
        int j = -1;

        for (int i = 0; i < n; i++) {
            int id = s[i] - '0';

            if (id >= 0 && id < 10) { // Check if s[i] is a digit
                while (j >= 0) {
                    if (s[j] != '-') { // Find the closest non-digit character to the left
                        s[j] = '-'; // Mark it for removal
                        break;
                    }
                    j--;
                }
                s[i] = '-'; // Mark the digit for removal
            } else {
                j = i; // Update j to the current non-digit character
            }
        }

        string ans = "";

        for (auto ch : s) {
            if (ch != '-') {
                ans += ch; // Construct the final result string excluding marked characters
            }
        }

        return ans;
    }
};