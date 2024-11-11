class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n=nums.size();
        unordered_map<int, int> f;
        vector<pair<int, int>> actions;

        for (auto x : nums) {
            f[x]++;
            actions.push_back({x - k, +1});
            actions.push_back({x + k + 1, -1});
        }

        set<int> timestamps;
        for (auto action : actions) {
            timestamps.insert(action.first);
        }
        for (auto c : f) {
            timestamps.insert(c.first);
        }
        sort(actions.begin(), actions.end());

        int index = 0,overlap = 0, maxi = 0;

        for (int t : timestamps) {
            while (index < actions.size() && actions[index].first <= t) {
                overlap += actions[index].second;
                index++;
            }

            int currentCount = f.count(t) ? f[t] : 0;
            int possibleCount = currentCount + min(numOperations, overlap - currentCount);
            maxi = max(maxi, possibleCount);
        }

        return maxi;
    }
};