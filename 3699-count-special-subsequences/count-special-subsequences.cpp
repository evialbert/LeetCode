class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        vector<vector<double>> sr(nums.size(), vector<double>(nums.size()));
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 2; j < nums.size(); j++) {
                sr[i][j] = (double)nums[j] / nums[i];
            }
        }
        unordered_map<double, int> mp;
        long long ans = 0;
        for (int i = nums.size() - 5; i >= 0; i--) {
            for (int j = 0; j < nums.size(); j++) {
                mp[sr[i+2][j]]++;
            }
            for (int j = i - 2 ; j>=0; j--) {
                ans += mp[(double)nums[j] / nums[i]];
            }
        }
        return ans;
    }
};