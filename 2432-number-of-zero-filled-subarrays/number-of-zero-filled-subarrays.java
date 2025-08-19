class Solution {
    public long zeroFilledSubarray(int[] nums) {
        long count = 0, zeros = 0;
        for (int num : nums) {
            if (num == 0) {
                zeros++;
                count += zeros;
            } else {
                zeros = 0;
            }
        }
        return count;
    }
}