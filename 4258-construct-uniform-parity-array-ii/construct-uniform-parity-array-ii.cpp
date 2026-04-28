class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        long long even = -1;
        long long odd = -1;
        long long n = nums1.size();
        for (int i = 0; i < n; i++) {
            if ((nums1[i] % 2) == 0) {
                if (even == -1 || nums1[i] < nums1[even])
                    even = i;
            } else {
                if (odd == -1 || nums1[i] < nums1[odd])
                    odd = i;
            }
        }
        if ((even != -1) && (odd != -1)) {
            if ((nums1[even] - nums1[odd] >= 1))
                return true;
            else
                return false;
        }
        return true;
    }
};