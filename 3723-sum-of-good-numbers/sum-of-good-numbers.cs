public class Solution {
    public int SumOfGoodNumbers(int[] nums, int k) {
        int n = nums.Length;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            bool flag = true;
            if (i - k >= 0 && nums[i] <= nums[i - k]) {
                flag = false;
            }
            if (i + k < n && nums[i] <= nums[i + k]) {
                flag = false;
            }
            if (flag) {
                sum += nums[i];
            }
        }

        return sum;
    }
}