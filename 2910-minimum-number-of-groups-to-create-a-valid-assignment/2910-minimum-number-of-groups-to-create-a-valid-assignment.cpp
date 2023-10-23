class Solution {
  public:
    int minGroupsForValidAssignment(vector<int> &nums) {
        unordered_map<int, int> freq;
        for (int n: nums) ++freq[n];

        auto count = [&](int size) -> optional<int> {
            int ans = 0;
            for (auto &[_, v]: freq) {
                if (v % size > v / size) return nullopt;
                ans += v / (size + 1) + (v % (size + 1) > 0);
            }
            return {ans};
        };

        int search_max = freq.begin()->second;
        for (auto &[_, v]: freq) search_max = min(search_max, v);

        int min_groups = INT32_MAX;
        for (int n = 1; n <= search_max; ++n) {
            auto res = count(n);
            if (res)
                min_groups = min(min_groups, res.value());
        }

        return min_groups;
    }
};
