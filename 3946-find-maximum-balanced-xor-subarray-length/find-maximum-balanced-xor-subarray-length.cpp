class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        map<pair<int, int>, int> m;
        int n = nums.size();
        int xr = 0, e = 0, o = 0, res = 0;
        for (int i = 0; i < n; i++) {
            xr ^= nums[i];
            e += (nums[i] % 2 == 0);
            o += (nums[i] % 2);
            int diff = e - o;
            if (xr == 0 && diff == 0)
                res = i + 1;
            if (m.find({xr, diff}) != m.end())
                res = max(res, i - m[{xr, diff}]);
            else
                m[{xr, diff}] = i;
        }
        return res;
    }
};