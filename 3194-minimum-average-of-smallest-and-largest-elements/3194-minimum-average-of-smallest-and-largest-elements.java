class Solution {
    public double minimumAverage(int[] nums) {
        double x = Double.MAX_VALUE;
        Arrays.sort(nums);
        for (int i = 0; i < nums.length / 2; i++) {
            x = Math.min(x, (nums[i] + nums[nums.length - 1 - i]) / 2.0);
        }
        return x;
    }
}