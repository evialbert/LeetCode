class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    int n = groupSizes.size();
    vector<vector<int>> ans;
    unordered_map<int, vector<int>> mp;

    for (int i = 0; i < n; i++) {
        mp[groupSizes[i]].push_back(i);
    }

    for (auto it : mp) {
        vector<int> group;
        for (int i : it.second) {
            group.push_back(i);
            if (group.size() == it.first) {
                ans.push_back(group);
                group.clear();
            }
        }
    }

    return ans;
}

};