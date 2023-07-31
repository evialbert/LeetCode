class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
      auto const n = static_cast<int>(std::size(nums));

		auto current = 0;
		for (auto i = 0; i != n; ++i)
		{
			if (current > nums[i]) { return false; }

			nums[i] -= current;
			current += nums[i];
			if (i >= k - 1) { current -= nums[i - k + 1]; }
		}

		return current == 0;
    }
};