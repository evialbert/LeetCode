class Solution{
public:
    int minimizeArrayValue(vector<int> &nums)
    {
        long long sval = nums[0];
        long long maxval = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > maxval)
            {
                long long val = 1ll* maxval * i;

                if (nums[i] - maxval > val - sval) maxval = maxval + (nums[i] - maxval - val + sval + i) / (1ll + i);
                
            }
            sval = sval + nums[i];
        }
        return maxval;
    }
};