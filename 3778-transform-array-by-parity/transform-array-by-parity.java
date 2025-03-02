class Solution {
    public int[] transformArray(int[] nums) {
        int j = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] % 2 == 0) {
                nums[j++] = 0;
            }
        }
        while (j < nums.length) {
            nums[j++] = 1;
        }
        return nums;
    }
}