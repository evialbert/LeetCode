class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> pairs;  
        unordered_map<string, int> wordmap;

        for (int i = 0; i < words.size(); i++) {
            wordmap[words[i]] = i;
        }

        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            for (int j = 0; j <= word.size(); j++) {
                string prefix = word.substr(0, j);
                string suffix = word.substr(j);

                // If prefix is a palindrome, check if the reverse of the suffix exists
                if (ispalin(prefix)) {
                    string reversedSuffix = suffix;
                    reverse(reversedSuffix.begin(), reversedSuffix.end());
                    if (wordmap.find(reversedSuffix) != wordmap.end() && wordmap[reversedSuffix] != i) {
                        pairs.push_back({wordmap[reversedSuffix], i});
                    }
                }

                // If suffix is a palindrome, check if the reverse of the prefix exists
                if (j != word.length() && ispalin(suffix)) {
                    string reversedPrefix = prefix;
                    reverse(reversedPrefix.begin(), reversedPrefix.end());
                    if (wordmap.find(reversedPrefix) != wordmap.end() && wordmap[reversedPrefix] != i) {
                        pairs.push_back({i, wordmap[reversedPrefix]});
                    }
                }
            }
        }
        return pairs;
    }

    bool ispalin(const string& word) {
        int left = 0;
        int right = word.size() - 1;  
        while (left < right) {
            if (word[left++] != word[right--]) {
                return false;
            }
        }
        return true;
    }
};