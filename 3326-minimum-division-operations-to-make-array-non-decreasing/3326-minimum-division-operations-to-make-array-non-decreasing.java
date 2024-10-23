class Solution {
  private static int greatestProperDivisor(int x) {
        int max=-1;
        for (int i = (int) Math.sqrt(x); i >= 2; i--) {
            if (x % i == 0) {
                max=Math.max(max,Math.max(i, x / i));
            }
        }
        return max; // If no proper divisor is found, return 1
    }


    public static int minOperations(int[] nums) {
        // Start with no operations
        int operations = 0;

        // Iterate through the nums array from the second last element
        for (int i = nums.length - 1; i > 0; i--) {
            // While the current element is greater than the next one, reduce it
            while (nums[i - 1] > nums[i]) {
                // Find the greatest proper divisor of nums[i - 1]
                int divisor = greatestProperDivisor(nums[i - 1]);

                // If we can't reduce it anymore, return -1 (impossible to make the array non-decreasing)
                if (divisor == -1) {
                    return -1;
                }

                // Perform the division
                nums[i - 1] = nums[i - 1]/ divisor;
                operations++;
            }
        }
        return operations;
    }
}