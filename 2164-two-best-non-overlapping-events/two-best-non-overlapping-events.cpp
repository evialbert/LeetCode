class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int res = INT_MIN;
        sort(events.begin(), events.end(),
            [](const vector<int>& a, const vector<int>& b){
                return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
            });
        vector<int> start, suffix(events.size(), 0);
        for (int i = 0; i < events.size(); i++){
            start.push_back(events[i][0]);
        }
        suffix.back() = events.back()[2];
        for (int i = events.size() - 2; i >= 0; i--){
            suffix[i] = max(suffix[i + 1], events[i][2]);
        }
        for (int i = 0; i < events.size(); i++){
            int idx = lower_bound(start.begin(), start.end(), events[i][1] + 1) - start.begin();
            int value = events[i][2];
            if (idx < events.size())
                value += suffix[idx];
            res = max(res, value);
        }
        return res;
    }
};