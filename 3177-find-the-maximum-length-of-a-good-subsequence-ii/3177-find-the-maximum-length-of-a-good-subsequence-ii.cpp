class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> dp;
        vector<int> answer(k + 1);
        for (int i = 0; i < n; i++) {
            if (dp.find(nums[i]) == dp.end()) {
                dp[nums[i]] = vector<int>(k + 1, -1);
            }
            auto& state = dp[nums[i]];
            for (int j = k; j >= 0; j--) {
                if (state[j] != -1) {
                    state[j]++;
                } else if (j == 0) {
                    state[j] = 1;
                }
                if (j != 0) {
                    state[j] = max(state[j], answer[j - 1] + 1);
                }
                answer[j] = max(answer[j], state[j]);
            }
        }
        return answer[k];
    }
};