class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> dict;
        for (int i : nums) {
            if (dict.count(i)) {
                dict[i]++;
            } else {
                dict[i] = 1;
            }
        }
        
        vector<int> res;
        int compare = nums.size() / 3;
        for (auto pair : dict) {
            if (pair.second > compare) {
                res.push_back(pair.first);
            }
        }
        
        return res;
    }
};