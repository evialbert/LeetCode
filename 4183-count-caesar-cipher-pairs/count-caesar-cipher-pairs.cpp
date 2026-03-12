class Solution {
public:
    using ll = long long;
    long long countPairs(vector<string>& words) {
        unordered_map<string, int> count;
        ll res = 0;
        for (auto& w : words) {
            res += count[w];
            count[w]++;
            for (int i = 1; i < 26; i++) {
                string tmp = w;
                for (auto& c : tmp) {
                    c = (c - 'a' + i) % 26 + 'a';
                }
                count[tmp]++;
            }
        }
        return res;
    }
};