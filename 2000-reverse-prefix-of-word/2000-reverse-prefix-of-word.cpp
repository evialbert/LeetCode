class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.length();
        int j = 0;
        
        // Find the index of the target character
        for (int i = 0; i < n; i++) {
            if (word[i] == ch) {
                j = i;
                break;
            }
        }
        
        int i = 0;
        // Reverse the substring from the beginning up to the index
        while (i < j) {
            swap(word[i], word[j]);
            i++;
            j--;
        }
        
        return word;
    }
};