class Solution {
    public int countPartitions(int[] nums) {
        int p = 0, sum1, sum2;
        for (int i = 0; i < nums.length - 1; i++) {
            sum1 = 0;
            sum2 = 0;
            for (int k = 0; k <= i; k++)
                sum1 += nums[k];
            for (int j = i + 1; j < nums.length; j++)
                sum2 += nums[j];
            if ((sum2 - sum1) % 2 == 0 || (sum2 - sum1) == 0)
                p++;
        }
        return p;
    }
}