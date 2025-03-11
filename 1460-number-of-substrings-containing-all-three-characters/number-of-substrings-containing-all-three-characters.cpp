class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        // Initialize ans to store the total count of valid substrings
        int ans = 0;

        // a, b, c denote the last occurrence of characters 'a', 'b', and 'c' respectively
        int a = -1, b = -1, c = -1; 

        for (int i = 0; i < n; i++) {

            // Update the last occurrence of the current character
            if (s[i] == 'a') a = i;
            else if (s[i] == 'b') b = i;
            else c = i;

            // Calculate the number of substrings ending at index 'i' that contain at least one 'a', 'b', and 'c'

            ans += (1 + min({a, b, c})); //Ensures all valid substrings till index 'i' are counted
        }

        return ans;
    }
};