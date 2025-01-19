class Solution {
    public int maxAdjacentDistance(int[] nums) {
        int maxDiff = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length; i++) {
            int nextIndex = (i + 1) % nums.length;
            int diff1 = nums[nextIndex] - nums[i];
            int diff2 = nums[i] - nums[nextIndex];
            maxDiff = Math.max(maxDiff, Math.abs(diff1));
            maxDiff = Math.max(maxDiff, Math.abs(diff2));
        }
        
        return maxDiff;
    }
}