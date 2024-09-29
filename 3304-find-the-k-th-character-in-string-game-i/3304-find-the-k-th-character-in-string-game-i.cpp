class Solution {
public:
    string next_char(string word) {
        string new_word = "";
        for (auto ch : word) {
            if (ch == 'z')
                new_word += 'a';
            else
                new_word += ch + 1;
        }
        return new_word;
    }
    char kthCharacter(int k) {
        string word = "a";
        while (word.length() < k) {
            word += next_char(word);
        }
        return word[k - 1];
    }
};