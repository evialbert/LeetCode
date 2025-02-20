class Solution {
    public int sumOfGoodNumbers(int[] nums, int k) {
        int sum = 0;
        boolean[] left = new boolean[nums.length];
        boolean[] right = new boolean[nums.length];
        for (int i = 0; i < nums.length; i++) {
            if (i - k < 0) {
                left[i] = true;
            } else {
                if (nums[i] > nums[i - k]) {
                    left[i] = true;
                }
            }
        }
        for (int i = nums.length - 1; i >= 0; i--) {
            if (i + k >= nums.length) {
                right[i] = true;
            } else {
                if (nums[i] > nums[i + k]) {
                    right[i] = true;
                }
            }
        }
        for (int i = 0; i < nums.length; i++) {
            if (left[i] && right[i]) {
                sum += nums[i];
            }
        }
        return sum;
    }
}