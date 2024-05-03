class Solution {
    public int addedInteger(int[] nums1, int[] nums2) {
        int nums1Total = 0, nums2Total = 0;
        for(int i=0; i<nums1.length; i++) {
            nums1Total += nums1[i];
            nums2Total += nums2[i];
        }

        return (nums2Total - nums1Total)/nums1.length;
    }
}