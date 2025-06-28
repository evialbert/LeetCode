class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> numsWithIndices;
        for (int i = 0; i < nums.size(); i++) {
            numsWithIndices.push_back({nums[i], i});
        }
        sort(numsWithIndices.begin(), numsWithIndices.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.first > b.first;
             });

        vector<pair<int, int>> topK(numsWithIndices.begin(), numsWithIndices.begin() + k);
        sort(topK.begin(), topK.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second < b.second;
             });

        vector<int> result;
        for (auto& p : topK) {
            result.push_back(p.first);
        }
        return result;
    }
};