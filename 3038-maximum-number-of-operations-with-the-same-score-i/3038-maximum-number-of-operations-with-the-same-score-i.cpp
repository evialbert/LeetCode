class Solution {
public:
    int maxOperations(vector<int>& nums) {
        vector<pair<int, int>> vec;
        for (int i = 0; i < nums.size(); i += 2) {
            if (i < nums.size() - 1) { 
                vec.push_back({nums[i], nums[i + 1]});
            }
        }
        vector<int> arr;
        for (auto it : vec) {
            arr.push_back(it.first + it.second);
        }
        int ans = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[0]) {
                ans++;
            } else {
                break;
            }
        }
        return ans;
    }
};