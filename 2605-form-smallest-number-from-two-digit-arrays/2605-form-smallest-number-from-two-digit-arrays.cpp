class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for(int i=0; i<nums1.size(); i++) {
            for(int j=0; j<nums2.size(); j++) {
                if(nums1[i] == nums2[j]) return nums1[i];
            }
        }
        int first = *min_element(nums1.begin(), nums1.end());
        int second = *min_element(nums2.begin(), nums2.end());
        int ans = min(first * 10 + second, second * 10 + first);
        return ans;
    }
};