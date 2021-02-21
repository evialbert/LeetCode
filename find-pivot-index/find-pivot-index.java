class Solution {
    public int pivotIndex(int[] nums) {
        int sum = IntStream.of(nums).sum();
        int l = 0;
        int r = sum;
        for (int i = 0; i < nums.length; ++i) {
            r -= nums[i];
            if (l == r) return i;
            l += nums[i];
        }
        return -1;
    }
}