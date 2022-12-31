class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int maxLen = 0;
        unordered_set<string> words;
        for (const auto& word : wordDict) {
            words.insert(word);
            maxLen = max(maxLen, (int)word.size());
        }
        vector<bool> validExcl(s.size() + 1, false);
        validExcl[0] = true;
        for (int i = 0; i <= s.size(); ++i) {
            if (validExcl[i]) { // [s[0], s[i - 1]] has a valid break
                for (int j = 1; j <= maxLen && i + j <= s.size(); ++j) {
                    if (words.count(s.substr(i, j))) {
                        validExcl[i + j] = true;
                    }
                }
            }
        }
        return validExcl[s.size()];
    }
};