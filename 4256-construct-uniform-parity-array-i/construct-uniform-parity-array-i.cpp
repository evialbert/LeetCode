class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int o = 0;
        for (int& num:nums1) {
            if (num%2 != 0) o++;
        }

        if (o >= 0) return true;
        return false;
    }
};