class Solution
{
public:
    int solve(int ind, vector<int> &nums, int &k, int op1, int op2, vector<vector<vector<int>>> &dp)
    {
        if (ind == nums.size())
        {
            return 0;
        }

        if (dp[ind][op1][op2] != -1)
            return dp[ind][op1][op2];

        int opt1 = 0;
        if (op1 > 0)
        {
            opt1 = (nums[ind]) / 2 + solve(ind + 1, nums, k, op1 - 1, op2, dp);
        }
        int opt2 = 0;
        if (nums[ind] >= k and op2 > 0)
        {
            opt2 = k + solve(ind + 1, nums, k, op1, op2 - 1, dp);
        }

        int opt3 = 0;
        int half = ((nums[ind] + 1) / 2);
        if (half >= k and op1 > 0 and op2 > 0)
        {
            opt3 = nums[ind] / 2 + k + solve(ind + 1, nums, k, op1 - 1, op2 - 1, dp);
        }

        int opt4 = 0;
        if (nums[ind] >= k and op1 > 0 and op2 > 0)
        {
            opt4 = k + (nums[ind] - k) / 2 + solve(ind + 1, nums, k, op1 - 1, op2 - 1, dp);
        }

        int opt5 = solve(ind + 1, nums, k, op1, op2, dp);

        return dp[ind][op1][op2] = max({opt1, opt2, opt3, opt4, opt5});
    }
    int minArraySum(vector<int> &nums, int k, int op1, int op2)
    {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(op1 + 1, vector<int>(op2 + 1, -1)));
        return sum - solve(0, nums, k, op1, op2, dp);
    }
};