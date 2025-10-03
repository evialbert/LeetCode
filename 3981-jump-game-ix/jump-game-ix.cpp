

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, INT_MIN);
        vector<int> surfix(n, INT_MAX);
        int pre = 0;
        for (int i = 0; i < n; i++) 
        {
            prefix[i] = max(nums[i], pre);
            pre = prefix[i];
        }
        int sur = INT_MAX;
        for (int i = n - 1; i >= 0; i--)
        {
            surfix[i] = min(sur, nums[i]);
            sur = surfix[i];
        }
        vector<int> ans(n);
        int start = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == n - 1 || (prefix[i] <= surfix[i + 1]))
            {
                int end = i + 1;
                int mx = 0;
                for (int j = start; j < end; j++)
                {
                    mx = max(mx, nums[j]);
                }
                for (int j = start; j < end; j++)
                {
                    ans[j] = mx;
                }
                start = end;
            }
        }
        return ans;
    }
};