class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int sum = 0, n = nums.size(), i = 0, j = 0, res = n + 1;
        unordered_map<int, int> count;
        while (j < n) {
            count[nums[j]]++;
            if (count[nums[j]] == 1)
                sum += nums[j];
            j++;
            while (sum >= k) {
                res = min(res, j - i);
                count[nums[i]]--;
                if (count[nums[i]] == 0)
                    sum -= nums[i];
                i++;
            }
        }
        return (res == n + 1 ? -1 : res);
    }
};