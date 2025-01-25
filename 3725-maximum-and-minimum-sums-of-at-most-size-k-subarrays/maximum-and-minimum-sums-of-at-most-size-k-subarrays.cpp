class Solution {
public:
    long long calc(int l, int r, int k, long long value) {
        long long ans = 0;
        if (l > r) swap(l, r);
        for (int j = 0; j <= l && k - j - 1 >= 0; ++j) {
            ans += value * min(k-j, r+1);
        }
        return ans;
    }
    long long minMaxSubarraySum(vector<int>& nums, int k) {
        const int n = (int)nums.size();
        vector<int> ri(n, n), li(n, -1), RI(n, n), LI(n, -1);
        vector<int> minStack, maxStack;
        for (int i = 0; i < n; ++i) {
            while(!minStack.empty() && nums[minStack.back()] > nums[i]) {
                ri[minStack.back()] = i;
                minStack.pop_back();
            }
            while(!maxStack.empty() && nums[maxStack.back()] < nums[i]) {
                RI[maxStack.back()] = i;
                maxStack.pop_back();
            }
            minStack.push_back(i);
            maxStack.push_back(i);
        }
        minStack.clear(), maxStack.clear();
        for (int i = n-1; i>= 0; --i) {
            while(!minStack.empty() && nums[minStack.back()] >= nums[i]) {
                li[minStack.back()] = i;
                minStack.pop_back();
            }
            while(!maxStack.empty() && nums[maxStack.back()] <= nums[i]) {
                LI[maxStack.back()] = i;
                maxStack.pop_back();
            }
            minStack.push_back(i);
            maxStack.push_back(i);
        }

        long long ans = 0LL;
        for (int i = 0; i < n; ++i) {
            ans += calc(i - li[i] - 1, ri[i] - i - 1, k, nums[i]);
            ans += calc(i - LI[i] - 1, RI[i] - i - 1, k, nums[i]);
        }

        return ans;
    }
};