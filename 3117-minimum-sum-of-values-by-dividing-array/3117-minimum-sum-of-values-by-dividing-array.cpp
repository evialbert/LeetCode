class Solution {
    vector<vector<unordered_map<int, int>>> dp;
    int help(vector<int>& nums, vector<int>& andValues, int i, int j,
             int currValue) {
        int n = nums.size();
        int m = andValues.size();
        if (i >= n) {
            if (j >= m) {
                return 0;
            } else {
                return 1e7;
            }
        } else if (j >= m) {
            return 1e7;
        }
        if (dp[i][j].count(currValue)) {
            return dp[i][j][currValue];
        }
        int sumIncluded = 1e7;
        if ((currValue & nums[i]) == andValues[j]) {
            sumIncluded =
                nums[i] + help(nums, andValues, i + 1, j + 1, ((1 << 20) - 1));
        }
        int sumExcluded = help(nums, andValues, i + 1, j, currValue & nums[i]);

        return dp[i][j][currValue] = min(sumIncluded, sumExcluded);
    }

public:
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        int n = nums.size();
        dp.resize(n, vector<unordered_map<int, int>>(10));
        int ans = help(nums, andValues, 0, 0, ((1 << 20) - 1));
        if (ans == 1e7) {
            return -1;
        }
        return ans;
    }
};