class Solution {
    public int longestNiceSubarray(int[] nums) {
        int longest = 1;
        int l = 0;
        int r = 0;
        while (r < nums.length - 1) {
            r++;
            if ((nums[r] & nums[r - 1]) == 0) {
                while (!checkAll(nums, l, r)) {
                    l++;
                }
                longest = Math.max(longest, r - l + 1);
            } 
            else l = r;
        }
        return longest;
    }

    public boolean checkAll(int[] nums, int start, int end) {
        for (int i = start; i < end; i++) {
            if ((nums[end] & nums[i]) != 0) return false;
        }
        return true;
    }
}