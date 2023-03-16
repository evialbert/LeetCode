class Solution {
public:
	int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
		long long ans = 1;
		long long i = 0, sum = 0;
		for (int j = 0; j < nums.size(); ++j) {
			sum += nums[j];
			while ((j - i + 1) * nums[j] - sum > k) sum -= nums[i++];
			ans = max(ans, j - i + 1);
		}
		return ans;
	}
};