class Solution
{
public:
    vector<int> getSubarrayBeauty(vector<int> &nums, int k, int x)
    {
        int n = nums.size(), i, j, y;
        vector<int> count(50, 0), ans(n - k + 1, 0);
        for (i = 0; i < n; i++)
        {
            if (nums[i] < 0)
                count[nums[i] + 50]++;
            if (i - k >= 0 && nums[i - k] < 0)
                count[nums[i - k] + 50]--;
            y = 0;
            if (i - k + 1 >= 0)
            {
                for (j = 0; j < 50; j++)
                {
                    y += count[j];
                    if (y >= x)
                    {
                        ans[i - k + 1] = j - 50;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};