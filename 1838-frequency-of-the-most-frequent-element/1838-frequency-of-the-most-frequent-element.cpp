class Solution {
public:
	int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, left = 0;
        long long sum = 0;
        sort(nums.begin(), nums.end());
        for (int right = 0; right < n; right++) {
            sum += nums[right];
            long long canMakeSum = sum + k, maxSum = (1LL) * nums[right] * (1LL) * (right - left + 1);
            while(maxSum > canMakeSum) {
                sum -= nums[left];
                left++;
                canMakeSum = sum + k;     
                maxSum = (1LL) * nums[right] * (1LL) * (right - left + 1);
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};