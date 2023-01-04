class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long n = nums.size(), ans = 0, s = 0;
        vector<long long> pre;
        for (int i = 0; i < n; i++) s += nums[i], pre.push_back(s);
        for (int i = 0; i < n; i++) {
            long long l = 1, r = n - i, id = 0;
            while (l <= r) {
                long long mid = (l + r) / 2, q = pre[i + mid - 1] - (i ? pre[i - 1] : 0ll);
                if (mid * q < k) id = mid, l = mid + 1;
                else r = mid - 1;
            }
            ans += id;
        }
        return ans;
    }
};