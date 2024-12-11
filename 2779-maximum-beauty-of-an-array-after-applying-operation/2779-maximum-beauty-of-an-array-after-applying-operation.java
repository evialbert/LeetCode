class Solution {
    public int maximumBeauty(int[] nums, int k) {
        Arrays.sort(nums); // Sort the array
        int maxBeauty = 0;
        int left = 0;

        // Sliding window to find maximum overlapping range
        for (int right = 0; right < nums.length; right++) {
            // Ensure the range [nums[left]-k, nums[right]+k] is valid
            while (nums[right] - nums[left] > 2 * k) {
                left++;
            }
            // Update the maximum beauty
            maxBeauty = Math.max(maxBeauty, right - left + 1);
        }
        return maxBeauty;
    }
}