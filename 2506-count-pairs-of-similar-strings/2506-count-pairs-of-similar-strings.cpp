class Solution {
public:
    int similarPairs(vector<string>& words) {
        auto maskIt = [](const string& word)
        {
            uint32_t res = 0;
            for(auto c : word)
            {
                uint32_t value = 1 << (c - 'a');
                res |= value;
            }
            return res;
        };
        unordered_map<uint32_t, int> counter;
        int res = 0;
        for(const auto& word : words)
        {
            auto mask = maskIt(word);
            auto exist = counter[mask];
            res += exist;
            ++counter[mask];
        }
        return res;
    }
};