class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> pos;
        for(int i = 0; i < n; i++) pos[nums[i]] = i;
        sort(nums.begin(), nums.end());
        long long ans = n;
        for(int i = 1; i < n; i++) {
            if(pos[nums[i]] < pos[nums[i - 1]]) ans += n - i;
        }
        return ans;
    }
};