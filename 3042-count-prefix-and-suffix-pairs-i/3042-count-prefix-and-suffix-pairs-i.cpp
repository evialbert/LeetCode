class Solution {
public:
    int countPrefixSuffixPairs(const vector<string>& words)
    {
        int result = 0;
        
        for(size_t i = 0; i < words.size() - 1; ++i) {
            for(size_t j = i + 1; j < words.size(); ++j) {
                if(words[j].size() < words[i].size()) continue;
                bool found = true;
                size_t diff = words[j].size() - words[i].size();
                for(size_t k = 0; k < words[i].size(); ++k) {
                    if(words[i][k] != words[j][k] or words[i][k] != words[j][diff + k]) {
                        found = false;
                        break;
                    }
                }
                if(found) ++result;
            }
        }

        return result;
    }
};