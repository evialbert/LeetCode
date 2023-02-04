class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n = queries[0].size();
        unordered_map<int,unordered_map<char,unordered_set<int>>> m;
        for (int i = 0; i < dictionary.size(); ++i) {
            for (int j = 0; j < n; ++j) {
                m[j][dictionary[i][j]].insert(i);
            }
        }
        
        vector<string> result;
        for (const string& query : queries) {
            vector<int> counter(dictionary.size());
            for (int i = 0; i < n; ++i) {
                if (m[i].find(query[i]) == m[i].end())
                    continue;

                for (int dictIndex : m[i][query[i]])
                    counter[dictIndex]++;
            }
            for (int i = 0; i < dictionary.size(); ++i) {
                if (counter[i] >= n - 2) {
                    result.push_back(query);
                    break;
                }
            }
        }
        return result;
    }
};