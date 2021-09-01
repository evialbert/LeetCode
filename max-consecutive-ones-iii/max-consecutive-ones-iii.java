class Solution {
    public int longestOnes(int[] nums, int k) {
        int left = 0, numberOfFlippedZeros = 0, maxNumberOfOnes = 0;
        for (int right = 0; right < nums.length; right++) {
            numberOfFlippedZeros += nums[right] == 0 ? 1 : 0;
            if (numberOfFlippedZeros <= k) {
                maxNumberOfOnes = Math.max(maxNumberOfOnes, right - left + 1);
            }
            while (numberOfFlippedZeros > k) {
                numberOfFlippedZeros -= nums[left++] == 0 ? 1 : 0;
            }
        }
        return maxNumberOfOnes;
    }
}