public class Solution {

    private int robHelper(int[] nums, int start, int end) {

        int include = 0;

        int exclude = 0;

        for (int i = start; i <= end; i++) {

            int tempInclude = include;

            int tempExclude = exclude;

            include = tempExclude + nums[i];

            exclude = Math.max(tempInclude, tempExclude);

        }

        return Math.max(include, exclude);

    }

    public int rob(int[] nums) {

        if (nums == null || nums.length < 1) return 0;

        int n = nums.length;

        if (n == 1) return nums[0];

        return Math.max(robHelper(nums, 0, n - 2), robHelper(nums, 1, n - 1));

    }

}