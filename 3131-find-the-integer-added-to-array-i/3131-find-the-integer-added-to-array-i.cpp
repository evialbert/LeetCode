class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        int max1 = *max_element(nums1.begin(), nums1.end());       
        int max2 = *max_element(nums2.begin(), nums2.end());  
        
        int ans = max2-max1;

        // if (min1 > min2)  ansc = -ansc;
        
        return ans;
    }
};