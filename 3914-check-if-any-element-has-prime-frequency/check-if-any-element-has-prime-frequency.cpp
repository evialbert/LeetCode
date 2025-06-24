class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int it : nums) {
            freq[it]++;
        }
        sort(nums.begin(), nums.end());
        int k = nums[n - 1];
        for (auto it : freq) {
            if (it.second <= 1)
                continue;
            bool found = false;
            for (int i = 2; i < it.second; i++) {
                if (it.second % i == 0) {
                    found = true;
                    break;
                }
            }
            if (!found)
                return true;
        }
        return false;
    }
};