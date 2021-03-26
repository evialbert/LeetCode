class Solution {
    public int totalHammingDistance(int[] nums) {
        int len = nums.length, sum = 0;
        int k = 0, c = 1, count = 0;
        while (k++ < 32) {
            count = 0;
            for (int i = 0; i < len; i++) {
                if ((nums[i] & c) != 0)
                    count += 1;
            }
            sum += count * (len-count);
            c = c << 1;
        }
        return sum;
    }
}
