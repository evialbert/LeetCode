class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        int n = s.size(); 

        // Starting from the end of the string
        for (int i = n-1; i >= 0; --i) {
            // Loop through all the possible characters that can be placed at the current position
            for (char ch = s[i]+1; ch < 'a' + k; ++ch) {
                // Check if the current character can be placed at this position
                if ((i == 0 || s[i-1] != ch) && (i <= 1 || s[i-2] != ch)) {
                    // If the current character can be placed, update the string and fill in the remaining positions
                    s[i] = ch; 
                    for (int j = i+1; j < n; ++j) {
                        // Loop through all the possible characters that can be placed at the remaining positions
                        for (char cand = 'a'; cand < 'a' + k; ++cand) {
                            // Check if the current character can be placed at this position
                            if (cand != s[j-1] && (j == 1 || cand != s[j-2])) {
                                // If the current character can be placed, update the string and break from the loop
                                s[j] = cand; 
                                break; 
                            }
                        }
                    }
                    // Return the updated string
                    return s; 
                }
            }
        }
        // If no such string is possible, return an empty string
        return ""; 
    }
};
