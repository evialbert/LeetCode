class Solution {
struct pair_hash {
  size_t operator() (const pair<int, int>& p) const {
      return ((size_t)p.first << 32) | p.second;
  }
};

public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        auto result = 0;
        const auto size = dominoes.size();
        unordered_map<pair<int, int>, int, pair_hash> counter;
        for (auto i = 0; i < size; ++i) {
            ++counter[make_pair(min(dominoes[i][0], dominoes[i][1]), max(dominoes[i][0], dominoes[i][1]))];
        }
        for (const auto& pair : counter) {
            if (pair.second > 1) {
                result += pair.second * (pair.second - 1) / 2;
            }
        }
        return result;
    }
};
