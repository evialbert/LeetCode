class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int len = nums.length;
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        
        for (int i = 0; i < len - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                i++;
                while (i < len) {
                    min = Math.min(min, nums[i]);
                    i++;
                }
            }
        }
        for (int i = len - 1; i > 0; i--) {
            if (nums[i] < nums[i - 1]) {
                i--;
                while (i >= 0) {
                    max = Math.max(max, nums[i]);
                    i--;
                }
            }
        }
        
        int left = nums.length;
        int right = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i] > min) {
                left = i;
                break;
            }
        }
        for (int i = len - 1; i >= 0; i--) {
            if (nums[i] < max) {
                right = i;
                break;
            }
        }
        return left < right ? right - left + 1 : 0;
    }
}