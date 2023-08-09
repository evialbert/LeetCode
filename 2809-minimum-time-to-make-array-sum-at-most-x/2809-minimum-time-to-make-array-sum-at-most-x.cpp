class Solution {
public:
    int minimumTime(vector<int>& nums, vector<int>& delta, int x) {
        int n = nums.size();

        vector<vector<int>> arr(n, vector<int>(2));
        for (int i = 0; i < n; ++i) {
            arr[i][0] = delta[i];
            arr[i][1] = nums[i];
        }
        std::sort(arr.begin(), arr.end());
        
        int sumNums = 0, sumDelta = 0;
        for (int i = 0; i < n; ++i) {
            delta[i] = arr[i][0];
            nums[i] = arr[i][1];
            sumNums += nums[i];
            sumDelta += delta[i];
        }
        
        if (sumNums <= x) return 0;
        
        vector<int> dp(n, 0);
        int curMax = 0;
        for (int i = 0; i < n; ++i) {
            curMax = std::max(curMax, nums[i] + delta[i]);
            dp[i] = curMax;
            if (dp[i] >= sumNums + sumDelta - x) return 1;
        }

        int sum = 0;
        for (int i = 2; i <= n; ++i) {
            sum = sumNums + i * sumDelta;
            
            curMax = 0;
            vector<int> tempDp(n, 0);
            for (int j = i - 1; j < n; ++j) {
                int val = nums[j] + i*delta[j];
                curMax = std::max(curMax, val + dp[j - 1]);
                if (curMax >= sum - x) return i;
                tempDp[j] = curMax;
            }
            for (int j = 0; j < n; ++j) dp[j] = tempDp[j];
        }
        
        return -1;
    }
};