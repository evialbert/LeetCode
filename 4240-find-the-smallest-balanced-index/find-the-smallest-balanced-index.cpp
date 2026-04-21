class Solution
{
public:
    int smallestBalancedIndex(vector<int> &nums)
    {
        int n = nums.size();
        vector<long long> prod(n + 1, 1); // n+1 because we need prod[n] value as 1 too

        // long long sum = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            // If overflow, mark as LLONG_MAX (can never equal any valid left sum)
            if (prod[i + 1] == LLONG_MAX || prod[i + 1] > LLONG_MAX / nums[i])
                prod[i] = LLONG_MAX;
            else
                prod[i] = prod[i + 1] * nums[i];
        }
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (sum == prod[i + 1])
                return i;
            sum = sum + nums[i];
        }

        return -1;
    }
};