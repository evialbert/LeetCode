class Solution {
public:
    bool isPossible(vector<int>& nums1, vector<int>& nums2, int diff, int k) {
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j] - diff) {
                i++;
                j++;
            } else {
                i++;
                k--;
                if (k < 0)
                    return false;
            }
        }
        return true;
    }
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        int maxi1 = *max_element(nums1.begin(), nums1.end());
        int maxi2 = *max_element(nums2.begin(), nums2.end());
        int mini1 = *min_element(nums1.begin(), nums1.end());
        int mini2 = *min_element(nums2.begin(), nums2.end());
        int lo = min(mini2 - mini1, mini2 - maxi1);
        int hi = max(mini2 - mini1, mini2 - maxi1);
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int ans = INT_MAX;
        for (int i = lo; i <= hi; i++) {
            if (isPossible(nums1, nums2, i, 2))
                return i;
        }
        
        return -1;
    }
};