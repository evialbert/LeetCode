class Solution {
  public int maxProductDifference(int[] nums) {
        int len = nums.length;
        int min = Integer.MAX_VALUE;
        int secondmin = Integer.MAX_VALUE - 1;
        int max = Integer.MIN_VALUE;
        int secondmax = Integer.MIN_VALUE - 1;
        for (int i = 0; i < len; i++) {
            if (nums[i] < min) {
                secondmin = min;
                min = nums[i];
            } else if (secondmin > nums[i]) {
                secondmin = nums[i];
            }
            if (nums[i] > max) {
                secondmax = max;
                max = nums[i];
            } else if (secondmax < nums[i]) {
                secondmax = nums[i];
            }
        }
        return max * secondmax - min * secondmin;
    }
}