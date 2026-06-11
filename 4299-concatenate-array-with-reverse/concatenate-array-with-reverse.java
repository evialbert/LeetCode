class Solution {
    public int[] concatWithReverse(int[] nums) {

        int n = nums.length;

        int[] arr = new int[2 * n];

        int count = 0;

        // Copy elements in original order
        for (int i = 0; i < n; i++) {
            arr[count] = nums[i];
            count++;
        }

        // Copy elements in reverse order
        for (int i = n - 1; i >= 0; i--) {
            arr[count] = nums[i];
            count++;
        }

        return arr;
    }
}