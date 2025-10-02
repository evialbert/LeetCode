class Solution {
    public boolean partitionArray(int[] nums, int k) {
        int size = nums.length;
        if (size % k != 0) {
            return false;
        }
        int min = size / k;
        int max = 0;
        for (int n : nums) {
            max = Math.max(max, n);
        }
        int[] arr = new int[max + 1];
        for (int n : nums) {
            if (++arr[n] > min) {
                return false;
            }
        }
        return true;
    }
}